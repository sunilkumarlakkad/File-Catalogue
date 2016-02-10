///////////////////////////////////////////////////////////////////////
// Display.cpp - display output on console			                 //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 13.0						         //
// Platform:    Dell Inspiron N5010, Win7 Professional, SP1          //
// Application: Demonstration for CSE 687, Project #1, Spring 2015   //
// Author:      Sunilkumar Lakkad, Syracuse University               //
//              (315) 751-5834, lakkads1@gmail.com                   //
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include"Display.h"
using namespace std;

			// ----------------< display arguments >----------------

void Display::displayCommandLineArgument(const string& path, vector<string> patterns, vector<string> options, const string& text)
{
	cout << "========================================================================" << endl;
	cout << "\t\tCommand Line Arguments Entered By User" << endl;
	cout << "========================================================================" << endl << endl;
	cout << " Path: " << path << endl;

	cout << " Option: ";
	for (auto op : options)
		cout << op << "\t";

	cout << "\n Pattern: ";
	for (auto patt : patterns)
		cout << patt << "\t";

	cout << "\n Search Text: " << text << endl <<endl;
}

		// ----------------< display duplicate files with their paths >----------------

void Display::displayDuplicateFiles(map<string, set<string>> catalog)
{
	cout << "========================================================================" << endl;
	cout << "\t\tDuplicate Files with differents Paths (/d or /D)" << endl;
	cout << "========================================================================" << endl <<endl;

	ostream_iterator< string > output(cout, "\n");
	map<string, set<string>>::iterator it;
	bool count = false;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		set<string> value = catalog[it->first];
		if (value.size() != 1 && value.size() != 0)
		{
			count = true;
			cout << "FileName: " << it->first << endl;
			cout << "Path:\n";
			copy(value.begin(), value.end(), output);
			cout << "\n\n";
		}

	}
	if (!count)
	cout << "No Duplicates Files Found!!\n\n" ;
}

void Display::dispayRequirementOfS(map<string, set<string>> catalog)
{
	cout << "========================================================================" << endl;
	cout << "\t\tFile Catalog for requiement of (/s or /S)" << endl;
	cout << "========================================================================" << endl << endl;

	ostream_iterator< string > output(cout, "\n");
	map<string, set<string>>::iterator it;
	bool count = false;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		set<string> value = catalog[it->first];
			count = true;
			cout << "FileName: " << it->first << endl;
			cout << "Path:\n";
			copy(value.begin(), value.end(), output);
		cout << "\n\n";
	}
	if (!count)
		cout << "No Files Found!!\n\n";
}

		// ----< display files with theris paths which contains search text >----

void Display::displayFilesContainsText(map<string, set<string>> catalog, vector<string> fileContainsText, const string& text)
{
	cout << "========================================================================" << endl;
	cout << "\t\t\tFiles with Text: \""<< text << "\"" << endl;
	cout << "========================================================================" << endl << endl;
	bool count = false;
	map<string, set<string>>::iterator it;
	ostream_iterator< string > output(cout, "\n");
	for (string fct : fileContainsText)
	{
		it = catalog.find(fct);
		if (it != catalog.end())
		{
			std::set<string> value = catalog[it->first];
			count = true;
				cout <<  "FileName: " << it->first << endl;
				cout  << "Path:\n";
				copy(value.begin(), value.end(), output);
				cout << "\n\n";
		}
	}
	if (!count)
		cout << "No Files Contains \""<< text <<"\"!!\n\n";
}

		// ----------------< display file catalog summary >----------------

void Display::displayCatalogSummary(int files, int directories)
{
	cout << "========================================================================" << endl;
	cout << "\t\tCatalog Summary (No Option)"<< endl;
	cout << "========================================================================" << endl << endl;

	cout << "Number of files found: " << files;
	cout << "\n\nNumber of Directories found: " << directories;

	cout << endl << endl;
}

#ifdef TEST_DISPLAY
int main(int argc, char* argv[])
{
	string path = "../TESTFOLDER";
	vector<string> patterns;
	vector<string> options;
	patterns.push_back("*.cpp");
	patterns.push_back("*.h");
	options.push_back("/d");
	options.push_back("/s");
	string text = "sunil";
	Display dis;
	dis.displayCommandLineArgument(path,patterns,options,text);

	map<string, set<string>> catalog;
	set<string> set1, set2;
	set1.insert("../TESTFOLDER");
	set1.insert("../TESTFOLDER/Dir1");
	set2.insert("../TESTFOLDER/Dir1/Dir11");
	catalog["one"] = set1;
	catalog["two"] = set2;
	dis.displayDuplicateFiles(catalog);

	vector<string> filename;
	filename.push_back("two");
	dis.displayFilesContainsText(catalog, filename,text);

	dis.displayCatalogSummary(8,4);
}
#endif