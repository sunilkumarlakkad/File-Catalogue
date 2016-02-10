#ifndef FILEMGR_H
#define FILEMGR_H
///////////////////////////////////////////////////////////////////////
// FileMgr.h - Build File Catalog path and patterns                  //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 13.0						         //
// Platform:    Dell Inspiron N5010, Win7 Professional, SP1          //
// Application: Demonstration for CSE 687, Project #1, Spring 2015   //
// Author:      Sunilkumar Lakkad, Syracuse University               //
//              (315) 751-5834, lakkads1@gmail.com                   //
///////////////////////////////////////////////////////////////////////
/*
* Module Operations:
* ------------------
* This Package first get a arguments from Executive and build collect 
* file catalogue, these builded catalogue passedto Executive for procedure.
*/
/*
* Maintenance History:
* --------------------
* ver 1.0 : 10 Jan 2015
* - first release
*/


#include <vector>
#include <string>
#include <list>

#include "FileSystem.h"
#include "..\DataStore\DataStore.h"

using namespace std;
class FileMgr
{
public:
	using iterator = DataStore::iterator;
	using patterns = vector < string > ;

	FileMgr(DataStore& store) : store_(store){}

	void find(const string&path);
	iterator begin() { return store_.begin(); }
	iterator end() { return store_.end(); }

	static map<string, set<string>> buildCatalogue(const string& path, vector<string> patterns, bool s);
	void search(const string& path, vector<string> patterns, bool s);
	static int fetchNumberOfFiles();
	static int fetchNumberOfDirectories();

private:
	DataStore& store_;
	string path_;
	patterns patterns_;
	bool s_;
	static int numberOfFiles;
	static int numberOfDirectories;
};
#endif
