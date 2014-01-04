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
	dll();

	string line;
	getline(cin,line);

	return 0;
}
void dll(){
	startUp();
	sayHi();
}



