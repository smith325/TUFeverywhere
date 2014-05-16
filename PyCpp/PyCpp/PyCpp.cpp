// PyC.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fstream>
#include <fstream>
#include <iostream>
#include "PyCpp.h"
#include <string>
#include <stdio.h>
#include <cstdio>



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
	// root
	char* root = Py_TUF_urllib_urlretrieve("http://192.168.1.3:8001/metadata/root.json");
	//char newRootFile[] = "C:/Users/Sarah/Documents/GitHub/TUFeverywhere/PyCpp/PyCpp/metadata/current/root.json";
	char newRootFile[] = "C:/Users/Sarah/Desktop/PyCpp/metadata/current/root.json";
	int newRoot = rename(root, newRootFile);
	if(newRoot != 0){
		printf("error: \n"+newRoot);
	}

	// timestamps
	char* timestamp = Py_TUF_urllib_urlretrieve("http://192.168.1.3:8001/metadata/timestamp.json");
	//char newTimestampFile[] = "C:/Users/Sarah/Documents/GitHub/TUFeverywhere/PyCpp/PyCpp/metadata/current/timestamp.json";
	char newTimestampFile[] = "C:/Users/Sarah/Desktop/PyCpp/metadata/current/timestamp.json";
	int newTS = rename(timestamp, newTimestampFile);
	if(newTS != 0){
		printf("error: \n"+newTS);
	}
	
	// targets
	char* targets = Py_TUF_urllib_urlretrieve("http://192.168.1.3:8001/metadata/targets.json");
	//char newTimestampFile[] = "C:/Users/Sarah/Documents/GitHub/TUFeverywhere/PyCpp/PyCpp/metadata/current/timestamp.json";
	char newTargetsFile[] = "C:/Users/Sarah/Desktop/PyCpp/metadata/current/targets.json";
	int newTarg = rename(targets, newTargetsFile);
	if(newTarg != 0){
		printf("error: \n"+newTarg);
	}

	// snapshot
	char* snapshot = Py_TUF_urllib_urlretrieve("http://192.168.1.3:8001/metadata/snapshot.json");
	//char newTimestampFile[] = "C:/Users/Sarah/Documents/GitHub/TUFeverywhere/PyCpp/PyCpp/metadata/current/timestamp.json";
	char newSnapshotFile[] = "C:/Users/Sarah/Desktop/PyCpp/metadata/current/snapshot.json";
	int newSnap = rename(snapshot, newSnapshotFile);
	if(newSnap != 0){
		printf("error: \n"+newSnap);
	}
}



