import os, subprocess, sys, shutil
from waflib.TaskGen import before, after, feature
from waflib import Options, Task, Utils, Logs, Errors

def options(opt):
   opt.add_option('--notest', action = 'store_true', default = False, help = 'Dont run tests')

@feature('programrunner')
@before('process_rule')
def remove_tests(self):
   if Options.options.notest:
      self.meths[:] = []

@feature('programrunner')
@after('apply_link')
def create_test_task(self):
   if not 'cxxprogram' in self.features:
      return

   self.default_install_path = None
   self.create_task('run_test', self.link_task.outputs)

import threading
testlock = threading.Lock()
class run_test(Task.Task):
   def runnable_status(self):
      status = super(run_test, self).runnable_status()
      if status != Task.SKIP_ME:
         return status

      if Options.options.notest:
         return status

      return Task.RUN_ME

   def run(self):
      status = 0
        
      filename = self.inputs[0].abspath()
      self.ut_exec = getattr(self, 'ut_exec', [filename])
      if getattr(self.generator, 'ut_fun', None):
         self.generator.ut_fun(self)

      try:
         paths = getattr(self.generator.bld, 'all_test_paths')

      except AttributeError:
         paths = os.environ.copy()

         linkPathList = []
         for group in self.generator.bld.groups:
            for task in group:
               if getattr(task, 'link_task', None):
                  linkPathList.append(task.link_task.outputs[0].parent.abspath())
                        
         def add_path(dct, path, var):
            dct[var] = os.pathsep.join(Utils.to_list(path) + [os.environ.get(var, '')])

         if sys.platform == 'win32':
            add_path(paths, linkPathList, 'PATH')
         elif sys.platform == 'darwin':
            add_path(paths, linkPathList, 'DYLD_LIBRARY_PATH')
            add_path(paths, linkPathList, 'LD_LIBRARY_PATH')
         else:
            add_path(paths, linkPathList, 'LD_LIBRARY_PATH')
         
         self.generator.bld.all_test_paths = paths

      cwd = getattr(self.generator, 'ut_cwd', '') or self.inputs[0].parent.abspath()
      proc = Utils.subprocess.Popen(self.ut_exec,
                                    cwd=cwd,
                                    env=paths,
                                    stderr=subprocess.STDOUT,
                                    stdout=Utils.subprocess.PIPE)
      (stdout, stderr) = proc.communicate()

      testTuple = (filename, proc.returncode, stdout, stderr)
      self.generator.utest_result = testTuple
        
      testlock.acquire()
      try:
         bld = self.generator.bld
         Logs.debug("ut: %r", testTuple)
         try:
            bld.utest_results.append(testTuple)
         except AttributeError:
            bld.utest_results = [testTuple]

         if not getattr(self.generator.bld, 'added_post_fun', False):
            self.generator.bld.add_post_fun(summary)
            self.generator.bld.added_post_fun = True

      finally:
         testlock.release()

def summary(bld):
   programOutput = getattr(bld, 'utest_results', [])

   if not programOutput:
      return

   for (f, code, output, err) in programOutput:
      testOutput = output.split('\n')

      if 'gtest' in testOutput[0]:
         printUnitTests(testOutput[1:])
      else:
         printSubmissionOutput(testOutput)
      # testFailed = False

      # for line in testOutput:
      #    if 'PASS' in line:
      #       Logs.pprint('GREEN', line)
      #       testFailed = False
      #    elif 'FAIL' in line:
      #       Logs.pprint('RED', line)
      #       testFailed = True
      #    elif testFailed:
      #       Logs.pprint('YELLOW', line)
      #    else:
      #       Logs.pprint('CYAN', line)
      #       testFailed = False

def printUnitTests(output):
   testFailed = False
   for line in output:
      if 'PASS' in line:
         Logs.pprint('GREEN', line)
         testFailed = False
      elif 'FAIL' in line:
         Logs.pprint('RED', line)
         testFailed = True
      elif testFailed:
         Logs.pprint('YELLOW', line)
      else:
         Logs.pprint('CYAN', line)
         testFailed = False

def printSubmissionOutput(output):
   for line in output:
      Logs.pprint('CYAN', line)



