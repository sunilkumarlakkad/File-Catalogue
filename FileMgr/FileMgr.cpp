///////////////////////////////////////////////////////////////////////
// FileMgr.cpp - Build File Catalog path and patterns                //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 13.0						         //
// Platform:    Dell Inspiron N5010, Win7 Professional, SP1          //
// Application: Demonstration for CSE 687, Project #1, Spring 2015   //
// Author:      Sunilkumar Lakkad, Syracuse University               //
//              (315) 751-5834, lakkads1@gmail.com                   //
///////////////////////////////////////////////////////////////////////

#include "FileMgr.h"
#include <iostream>
using namespace std;
int FileMgr::numberOfDirectories = 0;
int FileMgr::numberOfFiles = 0;

	// -------< find different files from directories based on /s option >------

void FileMgr::find(const string& path)
{
	numberOfDirectories++;
	string fullPath = FileSystem::Path::getFullFileSpec(path);;
	for (auto patt : patterns_)
	{
		vector<string> files = FileSystem::Directory::getFiles(fullPath, patt);
		for (auto f : files)
		{
			store_.save(f, fullPath);
			numberOfFiles++;
		}

		if (s_)
		{
			vector<string> dirs = FileSystem::Directory::getDirectories(fullPath);

			// remove "." and ".." from dirs
			auto iter = std::find(std::begin(dirs), std::end(dirs), ".");
			if (iter != std::end(dirs))
				dirs.erase(iter);
			iter = std::find(std::begin(dirs), std::end(dirs), "..");
			if (iter != std::end(dirs))
				dirs.erase(iter);

			for (auto d : dirs)
				find(FileSystem::Path::fileSpec(fullPath, d));
		}
	}
}

void FileMgr::search(const string& path, vector<string> patterns, bool s)
{
	path_ = path;
	patterns_ = patterns;
	s_ = s;
	find(path_);
}

		// --------< buils catalog using path, pattern and value of s >--------

map<string, set<string>> FileMgr::buildCatalogue(const string& path, vector<string> patterns, bool s)
{
	DataStore ds;
	FileMgr fm(ds);
	fm.search(path, patterns, s);
	return ds.store;
}

int FileMgr::fetchNumberOfFiles()
{
	return numberOfFiles;
}

int FileMgr::fetchNumberOfDirectories()
{
	return numberOfDirectories;
}

#ifdef TEST_FILEMGR

int main()
{
	std::cout << "\n  Testing FileMgr class";
	std::cout << "\n =======================\n";

	DataStore ds;
	FileMgr fm(ds);
	vector<string> pattern;
	pattern.push_back("*.cpp");
	pattern.push_back("*.txt");
	bool s = true;

	map<string, set<string>> result = FileMgr::buildCatalogue("../", pattern, s);

	ostream_iterator< string > output(cout, "\n");
	map<string, set<string>>::iterator it;

	for (it = result.begin(); it != result.end(); ++it)
	{
		cout << "\nFileName:" << it->first << "\nPath:";
		set<string> value = result[it->first];
		copy(value.begin(), value.end(), output);
	}

	int x = FileMgr::fetchNumberOfFiles();
	int y = FileMgr::fetchNumberOfDirectories() / pattern.size();
	cout << "\n\nNumber of files found: " << x;
	cout << "\n\nNumber of Directories found: " << y;
	cout << "\n\n";
	return 0;
}
#endif
