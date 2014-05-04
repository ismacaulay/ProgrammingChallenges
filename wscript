
top = '.'
out = '.build'

def options(opt):
   opt.add_option('-s', '--submission', action='store_true', default=False, help='Run submission')
   opt.add_option('-t', '--test', action='store_true', default=False, help='Run tests')
   opt.load('compiler_cxx programrunner')

def configure(conf):
   conf.load('compiler_cxx programrunner')
   conf.check(lib='pthread', uselib_store='pthread');

   conf.env.CXXFLAGS = ['--std=c++11', 
                        '-lm',
                        '-lcrypt',
                        '-pipe',
                        '-O2']

def build(bld):
   for wscript in bld.path.ant_glob('**/wscript'):
      bld.recurse(wscript.find_node('..').abspath())


