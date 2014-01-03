// PyC.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "PyCpp.h"
#include <string>
#include <stdio.h>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//exec_pycode();
	dll();
	return 0;
}
void dll(){
	startUp();
	//sayHi();
}

void exec_pycode()
{
  /**FILE* file;
  file = fopen("example_client.py","r");
  string line;
  
  ifstream inFile("example_client.py");
  cout << "test" << endl;
  while (getline(inFile,line)){
	  cout << line << endl;
  }
  inFile.close();
  /**/
  char pySearchPath[] = "Python27";
  Py_SetPythonHome(pySearchPath);
  Py_Initialize();

  PyObject* PyFileObject = PyFile_FromString("example_client.py", "r");
  PyRun_SimpleFileEx(PyFile_AsFile(PyFileObject), "example_client.py", 1);


  PyRun_SimpleString("print('hello world')");
  //PyRun_SimpleFile(file, "example_client.py");
  PyRun_SimpleString("raw_input('press enter to exit')");
  Py_Finalize();
  string name;
  getline(cin,name);
}


