/*
 * ****************************************************************************
 * Copyright (c) 2013, PyInstaller Development Team.
 * Distributed under the terms of the GNU General Public License with exception
 * for distributing bootloader.
 *
 * The full license is in the file COPYING.txt, distributed with this software.
 * ****************************************************************************
 */


/*
 * Bootloader for a DLL 
 */
#ifndef DLLMAIN_H
#define DLLMAIN_H
#define DLLExport __declspec(dllimport)

// MyCFuncs.h
#ifdef __cplusplus
extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif

DLLExport void Py_TUF_startUp();
extern int _fileLength;

/* TUF Configure function.  Takes <Path to tuf.interposition.json>, <>, <> */
DLLExport int Py_TUF_configure(char*, char*, char*);
/* TUF Deconfigure function.  Takes a <TUF Configure> object as it's only argument */
//DLLExport int Py_TUF_deconfigure(PyObject*);
/* urllib_tuf urlopen() function.  Takes a URL to open and returns the data retrieved as a char* */
DLLExport char* Py_TUF_urllib_urlopen(char*);
/* urllib_tuf urlretrieve() function.  Takes a URL to fetch and stores it in /tmp/.  The file name is returned as a char* */
DLLExport char* Py_TUF_urllib_urlretrieve(char*);
/* urllib2_tuf urlopen() function.  Takes a URL to open and returns the data retrieved as a char* */
DLLExport char* Py_TUF_urllib2_urlopen(char*);

#ifdef __cplusplus
}
#endif

#endif