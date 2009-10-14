# Copyright 2009 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import sys

IDL_SOURCES=['source/WebGrowl.idl']
SOURCES=['source/WebGrowl.cc', 'source/plugin.cc']
STATIC_GLUE_SOURCES=['common.cc', 'npn_api.cc', 'static_object.cc', 'main.cc']

env = Environment(
    ROOT = '../../Documents/nixysa-read-only/',
    NIXYSA_DIR = '$ROOT/nixysa',
    STATIC_GLUE_DIR = '$NIXYSA_DIR/static_glue/npapi',
    NPAPI_DIR = '$ROOT/third_party/npapi/include',
    GLUE_DIR = 'glue',
    CPPPATH=['.', '$STATIC_GLUE_DIR', '$NPAPI_DIR', '$GLUE_DIR' , '../../growl/gntp-send/headers/' , "./headers/" ],
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
                  ['$STATIC_GLUE_DIR/' + f for f in STATIC_GLUE_SOURCES] , LIBS=["growl++","growl"])
