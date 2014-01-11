README
=======

### Introduction:

This project is an interface between C and TUF (Python). It's purpose is to be able to call TUF commands from C, without needing to have Python installed on the user's computer. TUF is a universal secure software update system (https://github.com/theupdateframework/tuf).


### Inlcuding TUF in your project:
- ```include "dllmain.h";```
- Link against inprocsrvr_d.lib
- Use the available TUF commands (below) to configure TUF and check for updates
- Compile your C or C++ project into an executable
- Make sure all the required TUF dll/dependencies are distributed with the application
- Make sure the TUF webserver is configured and available to distribute updates
- Run your new executable and make sure it is able to contact the webserver


### Available TUF Commands:

```C
/* MUST BE CALLED FIRST */
void Py_TUF_startUp();

int Py_TUF_configure(char*, char*, char*);

/* TUF Deconfigure function.  Takes a <TUF Configure> object as it's only argument */
int Py_TUF_deconfigure(PyObject*);

/* urllib_tuf urlopen() function.  Takes a URL to open and returns the data retrieved as a char* */
char* Py_TUF_urllib_urlopen(char*);

/* urllib_tuf urlretrieve() function.  Takes a URL to fetch and stores it in /tmp/.  The file name is returned as a char* */
char* Py_TUF_urllib_urlretrieve(char*);

/* urllib2_tuf urlopen() function.  Takes a URL to open and returns the data retrieved as a char* */
char* Py_TUF_urllib2_urlopen(char*);
```