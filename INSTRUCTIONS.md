MODIFICATIONS
==============



Pyinstaller
=============== 

### dllmain / COM Server
- This is the bootstap C code that interfaces with TUF and Python
- Simplified by removing unnecessary code from the COM Server 
- Fixed the bug in pyinstaller that append a backslash at the end of the executing directory path string (this bug made it not be a valid string)
- Fixed the bug where MEIPASS (current working directory, used as a search location for modules to be correctly imported) was not set
- Updated dllmain.c to reflect recent changes in main.c (fixed a memory error)
- Added Py_TUF commands to the C sourcecode (as described in the README)


### pyi_python C files
- Added missing python functions to the macros lists stored in these C files
- Exported a group of python functions to work with the rubygems code


### waf files
- This is the build script for bootloader
- Added compiler flags in order to produce debug symbols


### spec file
- Goal is to be able to import TUF
- Created a spec file to run analysis on the specified python source file



### waf build install
- Need to do this if making changes to dllmain
- ```python waf build install```


### build script
- Done after waf; Runs pyinstaller on spec file
- Grabs everything required to build a 3rd party application and build against the inprocsrvr_d.dll (all the dll's, inprocsrvr_d lib file, and the dllmain.h header)




TUF
====================

- Checked if a FrozenImporter (a replacement for imp / a class to find Python modules in the zLib archive in the dll) exists. If it does, load urllib under the alias urllib_tuf. Then, it will overwrite urllib's urlopen and urlretrieve functions. Did the same for urllib2 into urllib2_tuf.