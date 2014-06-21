import os, subprocess, sys, shutil
from waflib.TaskGen import before, after, feature
from waflib import Options, Task, Utils, Logs, Errors

def options(opt):
   pass

@feature('programrunner')
@before('process_rule')
def remove_tests(self):
   pass

@feature('programrunner')
@after('apply_link')
def create_test_task(self):
   if not 'cxxprogram' in self.features:
      return

   self.default_install_path = None
   self.create_task('run_test', self.link_task.outputs)

#######################################################################
#
# Run executable
#
#######################################################################
import threading
lock = threading.Lock()
class run_test(Task.Task):
   def runnable_status(self):
      status = super(run_test, self).runnable_status()
      if status != Task.SKIP_ME:
         return status

      return Task.RUN_ME

   def run(self):
      filename = self.inputs[0].abspath()
      self.exe = getattr(self, 'exe', [filename])

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

         add_path(paths, linkPathList, 'LD_LIBRARY_PATH')
         self.generator.bld.all_test_paths = paths

      cwd = getattr(self.generator, 'cwd', '') or self.inputs[0].parent.abspath()

      inputFile = None;
      if Options.options.submission:
         try:
            inputFile = open(self.inputs[0].abspath().replace(".build/", "").rsplit('/', 1)[0] + '/input.txt')
         except:
            inputFile = None

      # Default is to run the tests!
      proc = Utils.subprocess.Popen(self.exe,
                                    cwd=cwd,
                                    env=paths,
                                    stderr=subprocess.STDOUT,
                                    stdout=Utils.subprocess.PIPE,
                                    stdin=inputFile)

      if Options.options.notests:
         # Dont run tests!
         proc = Utils.subprocess.Popen(self.exe,
                                       cwd=cwd,
                                       env=paths,
                                       stdout=Utils.subprocess.PIPE,
                                       stdin=inputFile);

      (stdout, stderr) = proc.communicate()

      outputTuple = (filename, proc.returncode, stdout, stderr)
      self.generator.output = outputTuple
        
      lock.acquire()
      try:
         bld = self.generator.bld
         try:
            bld.output.append(outputTuple)
         except AttributeError:
            bld.output = [outputTuple]

         if not getattr(self.generator.bld, 'added_post_fun', False):
            self.generator.bld.add_post_fun(printOutput)
            self.generator.bld.added_post_fun = True

      finally:
         lock.release()


#######################################################################
#
# Summary
#
#######################################################################
def printOutput(bld):
   programOutput = getattr(bld, 'output', [])

   if not programOutput:
      return

   if Options.options.notests:
      return 

   for (f, code, output, err) in programOutput:
      testOutput = output.split('\n')

      for line in testOutput:
         Logs.pprint('CYAN', line);

def printUnitTests(output):
   pass

def printSubmissionOutput(problem, output, outputFilePath):
   pass







