#ifndef DATASTORE_H
#define DATASTORE_H
///////////////////////////////////////////////////////////////////////
// DataStore.h - Manage Data storage of File Catalogue               //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 13.0						         //
// Platform:    Dell Inspiron N5010, Win7 Professional, SP1          //
// Application: Demonstration for CSE 687, Project #1, Spring 2015   //
// Author:      Sunilkumar Lakkad, Syracuse University               //
//              (315) 751-5834, lakkads1@gmail.com                   //
///////////////////////////////////////////////////////////////////////
/*
* Maintenance History:
* --------------------
* ver 1.0 : 10 Jan 2015
* - first release
*/

#include <string>
#include<map>
#include<set>
using namespace std;

class DataStore
{
	friend class FileMgr;
public:
  using iterator = map<string,set<string>> ::iterator;

  void save(const string& filename, const string& path);
  map<string, set< string >> fetch();

  iterator begin() { return store.begin(); }
  iterator end() { return store.end(); }

private:
	map<string, set<string>> store; 
};
#endif
