
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
	bld.recurse('challenges/3n+1Problem')


