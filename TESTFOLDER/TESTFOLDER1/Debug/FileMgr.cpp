/////////////////////////////////////////////////////////////////////////////
// FileMgr.cpp - Support managing of files and calling datastore           //
// ver 1.0                                                                 //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    Levovo Y40, Core i7, Windows 8                             //
// Application: Spring, 2015 : File Catalogue                              //
// Author:      Dhaval Dholakiya, Syracuse University                      //
//              (315) 447-7644, ddholaki@syr.edu                           //
/////////////////////////////////////////////////////////////////////////////

#include "FileMgr.h"
#include "../DataStore/DataStore.h"
#include <iostream>

how are you
syracuse university

using namespace std;

//--------------<constructor of File Manager>----------------

FileMgr::FileMgr(const std::string& path, DataStore& ds, vector<string> options, vector<string> pattern) :
path_(path), store_(ds), options_(options), patterns_(pattern)
{

}

//--------------<checks if it has to do recursive search>----------------

void FileMgr:: subdirectorycheck()
{

	for (unsigned int k = 0; k < options_.size(); k++)
	{
		string test = options_[k];
		if (!(test.compare("/s")))
		{
			recurse = true;
		}
	}
}

//--------------<calls find function to search the directories>----------------

void FileMgr:: search()
{
	find(path_);
}

//--------------<finds all the directories and files according to given path>----------------

void FileMgr :: find(const std::string& path)
{
	for (auto patt : patterns_)											//searches for each pattern provided by user
	{
		std::vector<std::string> files = FileSystem::Directory::getFiles(path, patt);
		std::string path1 = FileSystem::Path::getFullFileSpec(path);
		store_.save(path1);
		for each (std::string file in files)
		{
			store_.save(file, path1);
		}
		vector<std::string> dirs = FileSystem::Directory::getDirectories(path, patt);

		if (recurse)														//recursive search
		{

			for (unsigned int i = 2; i < dirs.size(); i++)
			{
				string s = path1 + "\\" + dirs[i];
				find(s);
			}
		}
	}
}

//--------------<Test Stub>----------------

#ifdef TEST_FILEMGR

int main()
{
	DataStore ds;
	vector<string> s;
	s.push_back("*.*");
	string s3;
	vector<string>pattern;
	vector<string>options;
	options.push_back("/s");
	pattern.push_back("*.*");
	FileMgr fm(".", ds,options,pattern);

	fm.subdirectorycheck();
	fm.search();
	using Store = map < string, list<DataStore::PathIter> >;
	using iterator = Store::iterator;

	map <string, list<DataStore::PathIter>> val = ds.dispMap();
	
	for (iterator iter = val.begin(); iter != val.end(); ++iter)
	{
		cout << endl << "Files: ";

		cout << iter->first;


		cout << endl << "Path(s): ";
		DataStore::ListOfIters listofIter = iter->second;
		for (auto path = listofIter.begin(); path != listofIter.end(); ++path)
		{
			cout << **path << endl << "         ";
		}

	}  
	return 0;
}

#endif