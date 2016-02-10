///////////////////////////////////////////////////////////////////////
// Executive.cpp - Manage all Packages of File Catalogue             //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 13.0						         //
// Platform:    Dell Inspiron N5010, Win7 Professional, SP1          //
// Application: Demonstration for CSE 687, Project #1, Spring 2015   //
// Author:      Sunilkumar Lakkad, Syracuse University               //
//              (315) 751-5834, lakkads1@gmail.com                   //
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<sstream>
#include<list>
#include<iterator>
#include<regex>

#include"Executive.h"
#include"..\CommandLineParser\CommandLineParser.h"
#include"..\FileMgr\FileMgr.h"
#include"..\DataStore\DataStore.h"
#include"..\TestSearch\TextSearch.h"
#include"..\Display\Display.h"
using namespace std;

		// ---------< continous read search text for text search >---------

void Executive::continuousTextSearch(const string& path, bool s)
{
	string newText = "";
	string newPattern = "";
	vector<string> patterns;
	Executive ex;

	while (true)
	{
		patterns.erase(patterns.begin(), patterns.end());
		cout << "========================================================================" << endl;
		cout << "\tEnter New Text and Pattern for new Search Opretion:" << endl;
		cout << "========================================================================" << endl ;
		cout << "\t\t   For Quit Please press ENTER:\n";
		cout << "You can search sunil, syracuse, hii to see out put and Functionality\n";
		cout << "\nEnter New Text(Format==>ODD PROJECT1): ";
		getline(cin, newText);
		if (newText.size() == 0)
			break;

		cout << "\nEnter New Patterns(Format==>*.cpp *.obj): ";
		getline(cin, newPattern);
		cout << endl;
		istringstream iss(newPattern);
		vector<string> tokens{ istream_iterator < string > {iss},
			istream_iterator < string > {} };

		regex r("[A-Za-z\\*]+\\.[A-Za-z\\*]+$");
		for (string tok : tokens)
		{
			if (regex_match(tok, r))
				patterns.push_back(tok);
		}
		if (patterns.size() == 0)
			patterns.push_back("*.*");

		map<string, set<string>> catalog1 = FileMgr::buildCatalogue(path, patterns, s);
		ex.textSearchMain(catalog1, newText);
	}
}

void Executive::textSearchMain(map<string, set<string>> catalog, const string& text)
{
	Display dis;
	TextSearch ts;
	vector<string> fileContainsText = ts.search(catalog, text);
	dis.displayFilesContainsText(catalog, fileContainsText, text);
}

#ifdef TEST_EXECUTIVE
int main(int argc, char* argv[])
{
	bool s = false;
	bool d = false;
	bool f = false;
	CommandLineParser clp;
	Display dis;
	Executive ex;

	string path = clp.processCommandlinePath(argc, argv);
	if (path.compare("") == 0)
		path = FileSystem::Directory::getCurrentDirectory();

	vector<string> options = clp.processCommandlineOption(argc, argv);
	for (string op : options)
	{
		if (op.compare("/s") == 0 || op.compare("/S") == 0)
			s = true;
		if (op.compare("/d") == 0 || op.compare("/D") == 0)
			d = true;
		if (op.compare("/f") == 0 || op.compare("/F") == 0)
			f = true;
	}

	vector<string> patterns = clp.processCommandlinePattern(argc, argv);
	if (patterns.size() == 0)
		patterns.push_back("*.*");

	string text = clp.processCommandlineText(argc, argv);

	map<string, set<string>> catalog = FileMgr::buildCatalogue(path, patterns, s);
	
	dis.displayCommandLineArgument(path, patterns, options, text);

	if (d)
		dis.displayDuplicateFiles(catalog);

	if (f)
		ex.textSearchMain(catalog, text);

	if (options.size() == 0) //for file catalog summary
		dis.displayCatalogSummary(FileMgr::fetchNumberOfFiles(), FileMgr::fetchNumberOfDirectories() / patterns.size());
	if (!d & !f & s)
		dis.dispayRequirementOfS(catalog);

	ex.continuousTextSearch(path, s);
}
#endif