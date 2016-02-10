#ifndef TEXTSEARCH_H
#define TEXTSEARCH_H
///////////////////////////////////////////////////////////////////////
// TextSearch.h - collect filename which contains search text        //
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

#include<iostream>
#include<map>
#include<set>
using namespace std;

class TextSearch
{
public:
	vector<string> search(map<string, set<string>> catalog, const string& text);
	bool textSearch(const string& filePath, const string& text);
};
#endif