///////////////////////////////////////////////////////////////////////
// TextSearch.cpp - collect filename which contains search text      //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 13.0						         //
// Platform:    Dell Inspiron N5010, Win7 Professional, SP1          //
// Application: Demonstration for CSE 687, Project #1, Spring 2015   //
// Author:      Sunilkumar Lakkad, Syracuse University               //
//              (315) 751-5834, lakkads1@gmail.com                   //
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<vector>

#include"TextSearch.h"

using namespace std;

	// ---< collect files and one path from buils catalog for searching opreation >---

vector<string> TextSearch::search(map<string, set<string>> catalog, const string& text)
{
	map<string, set<string>>::iterator it;
	vector<string> fileContainsText;
	string filename = "";
	string pathname = "";

	for (it = catalog.begin(); it != catalog.end(); ++it)
	{

		filename = it->first;
		std::set<string> value = catalog[it->first];
		set<string>::iterator iter;

		for(iter = value.begin(); iter != value.end(); ++iter)
		{
			pathname = *iter;
			break;
		}
		if(textSearch(pathname+"\\"+filename, text))
		{
			fileContainsText.push_back(it->first);
		}
	}	
	return fileContainsText;
}

		//--------< open file and search given text >-------

bool TextSearch::textSearch(const string& filePath, const string& text)
{
	ifstream file(filePath);
	string search_str = text;
	string line;
	bool isFind = false;
	int line_number = 0;
	while (std::getline(file, line))
	{
		line_number++;
		if (line.find(search_str) != std::string::npos)
		{
			isFind = true;
			break;
		}
	}
	return isFind;
}

#ifdef TEST_TEXTSEARCH
int main(int argc, char* argv[])
{
	map<string, set<string>> catalog;
	set<string> set1, set2;
	set1.insert("../TESTFOLDER");
	set1.insert("../TESTFOLDER/Dir1");
	set2.insert("../TESTFOLDER/Dir1/Dir11");
	catalog["one"] = set1;
	catalog["two"] = set2;

	string text = "sunil";
	TextSearch ts;
	vector<string> filenames=ts.search(catalog,text);
	cout << endl;
}
#endif