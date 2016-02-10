#ifndef FILEMGR_H
#define FILEMGR_H
/////////////////////////////////////////////////////////////////////////////
// FileMgr.h - Support managing of files and calling datastore             //
// ver 1.0                                                                 //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    Levovo Y40, Core i7, Windows 8                             //
// Application: Spring, 2015 : File Catalogue                              //
// Author:      Dhaval Dholakiya, Syracuse University                      //
//              (315) 447-7644, ddholaki@syr.edu                           //
/////////////////////////////////////////////////////////////////////////////
/*
* Module Operations:
* ==================
* This module provides search of the files in the directory
* Required Files:
* ===============
* FileSystem.h, FileSystem.cpp, DataStore.h, DataStore.cpp
*
* Maintenance History:
* ====================
* ver 1.0 : 10 Feb 15
* - first release
*/
#include "FileSystem.h"
#include "../DataStore/DataStore.h"
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////
// manages the files and calls DataStore to store the catalogue

class FileMgr
{
public:
	using iterator = DataStore::iterator;
	using patterns = std::vector<std::string>;
	FileMgr(const std::string& path, DataStore& ds, vector<string> options, vector<string> pattern);
	void subdirectorycheck();
	void search();
	void find(const std::string& path);
private:
	std::string path_;
	DataStore& store_;
	patterns patterns_;
	vector<string> options_;
	bool  recurse = false;
};
#endif
