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
	Py_TUF_startUp();
	useTUF();

	string line;
	printf("hit enter to quit\n");
	getline(cin,line);

	return 0;
}
void useTUF()
{
	printf("trying to configure tuf\n");
	char * config = "local.json";
	if(!Py_TUF_configure(config,"./","./")){
		printf("TUF error\n");
	}

	char * result = Py_TUF_urllib_urlopen("http://192.168.1.7:8001/metadata/timestamp.txt");
}



