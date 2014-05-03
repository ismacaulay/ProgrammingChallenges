
top = '.'
out = '.build'

def options(opt):
	opt.add_option('-s', '--submission', action='store_true', default=False,
		help='Run submission')
	opt.load('compiler_cxx programrunner')

def configure(conf):
   	conf.load('compiler_cxx programrunner')
   	conf.env.CXXFLAGS = ['--std=c++11', 
                        '-Wall', 
                        '-Wunused-parameter',
                        '-lm',
                        '-lcrypt',
                        '-pipe',
                        '-O2']

def build(bld):
   bld.recurse('tools')
   for wscript in bld.path.ant_glob('**/wscript'):
      bld.recurse(wscript.find_node('..').abspath())


