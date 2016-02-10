///////////////////////////////////////////////////////////////////////
// DataStore.cpp - Manage Data storage of File Catalogue             //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 13.0						         //
// Platform:    Dell Inspiron N5010, Win7 Professional, SP1          //
// Application: Demonstration for CSE 687, Project #1, Spring 2015   //
// Author:      Sunilkumar Lakkad, Syracuse University               //
//              (315) 751-5834, lakkads1@gmail.com                   //
///////////////////////////////////////////////////////////////////////

#include "DataStore.h"
#include<iostream>
#include<map>
#include<set>
using namespace std;

		// ---< store unique filename and their paths using map & set >---	

void DataStore::save(const string& filename, const string& path)
{
	if (store.find(filename) == store.end())
	{
		set<string> paths;
		paths.insert(path);
		store[filename] = paths;
	}
	if (store.find(filename) != store.end())
	{
		set<string> temp = store[filename];
		temp.insert(path);
		store[filename] = temp;
	}
}

map<string,set< string >> DataStore::fetch()
{
	return store;
}

#ifdef TEST_DATASTORE

int main()
{
  DataStore ds;
  ds.save("one", "../TESTFOLDER");
  ds.save("two", "../TESTFOLDER/Dir1");
  ds.save("one", "../TESTFOLDER/Dir1");

  map<string,set<string>> catalog=ds.fetch();

  ostream_iterator< string > output(cout, "\n|");
  map<string, set<string>>::iterator it;

  for (it = catalog.begin(); it != catalog.end(); ++it)
  {
	  set<string> value = catalog[it->first];
		  cout << "_______________________________________" << endl;
		  cout << "|  " << "FileName: " << it->first << endl;
		  cout << "----------------------------------------" << endl;
		  cout << "|" << "Path:\n|";
		  copy(value.begin(), value.end(), output);
		  cout << "----------------------------------------" << endl;
  }
  std::cout << "\n\n";
  return 0;
}

#endif
