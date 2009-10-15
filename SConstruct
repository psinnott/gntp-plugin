import os
import sys

IDL_SOURCES=['source/growl++.idl']
SOURCES=['source/growl++.cc', 'source/plugin.cc']
STATIC_GLUE_SOURCES=['common.cc', 'npn_api.cc', 'static_object.cc', 'main.cc']

env = Environment(
    ROOT = '../nixysa/',
    NIXYSA_DIR = '$ROOT/nixysa',
    STATIC_GLUE_DIR = '$NIXYSA_DIR/static_glue/npapi',
    NPAPI_DIR = '$ROOT/third_party/npapi/include',
    GLUE_DIR = 'glue',
    CPPPATH=['.', '$STATIC_GLUE_DIR', '$NPAPI_DIR', '$GLUE_DIR' , './headers/' , '../../growl/gntp-send/headers/' ],
	LIBPATH="../../growl/gntp-send/lib/"
)
env.Append(ENV={'PYTHON': sys.executable})
if sys.platform == 'win32':
  env.Append(CODEGEN = 'codegen.bat',
             CPPDEFINES = ['WIN32', 'OS_WINDOWS'])
elif sys.platform == 'darwin':
  env.Append(CODEGEN = 'codegen.sh',
             CPPDEFINES = ['XP_MACOSX', 'OS_MACOSX'],
             LINKFLAGS = '-framework CoreFoundation -framework IOKit')

else:
  env.Append(CODEGEN = 'codegen.sh',
             CPPDEFINES = ['OS_LINUX'])

def NixysaEmitter(target, source, env):
  bases = [os.path.splitext(s.name)[0] for s in source] + ['globals']
  targets = ['$GLUE_DIR/%s_glue.cc' % b for b in bases]
  targets += ['$GLUE_DIR/%s_glue.h' % b for b in bases]
  targets += ['$GLUE_DIR/hash', '$GLUE_DIR/parsetab.py']
  return targets, source

NIXYSA_CMDLINE = ' '.join([env.File('$NIXYSA_DIR/$CODEGEN').abspath,
                           '--output-dir=$GLUE_DIR',
                           '--generate=npapi',
                           '$SOURCES'])

env['BUILDERS']['Nixysa'] = Builder(action=NIXYSA_CMDLINE,
                                    emitter=NixysaEmitter)

AUTOGEN_OUTPUT = env.Nixysa(IDL_SOURCES)
AUTOGEN_CC_FILES = [f for f in AUTOGEN_OUTPUT if f.suffix == '.cc']

env.SharedLibrary( 'Growl', AUTOGEN_CC_FILES + SOURCES +
                  ['$STATIC_GLUE_DIR/' + f for f in STATIC_GLUE_SOURCES] , LIBS=["growl"])
