///////////////////////////////////////////////////////////////////////
// CommandLineParser.cpp - Parse the Commanl Line Arguments          //
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
#include<iterator>
#include<regex>

#include"CommandLineParser.h"
#include"..\FileMgr\FileSystem.h"
using namespace std;

		// ---------------< process commandline to get path >------------------

string CommandLineParser::processCommandlinePath(int argc, char* argv[])
{
	string path = "";	
		string temp = argv[1];
		if (FileSystem::Directory::exists(temp) || temp.find("../") != string::npos || temp.find("./") != string::npos || temp.find(":/") != string::npos)
		{
			path = FileSystem::Path::getFullFileSpec(temp);
		}
	return path;
}

		// ----------------< process commandline to get options >-------------------	

vector<string> CommandLineParser::processCommandlineOption(int argc, char* argv[])
{
	vector<string> options;
	for (int i = 1; i < argc; ++i)
	{
		string temp = argv[i];
		if (temp.find("/s") != string::npos || temp.find("/d") != string::npos || temp.find("/f") != string::npos || temp.find("/S") != string::npos || temp.find("/F") != string::npos || temp.find("/D") != string::npos)
		{
			if (temp.find("/f") != string::npos || temp.find("/F") != string::npos)
				options.push_back(temp.substr(0,2));
			else
				options.push_back(temp);
		}
	}
	return options;
}

		// -----------------< process commandline to get patterns >------------------

vector<string> CommandLineParser::processCommandlinePattern(int argc, char* argv[])
{
	vector<string> patterns;
	regex r("[A-Za-z\\*]+\\.[A-Za-z\\*]+$");
	for (int i = 1; i < argc; ++i)
	{
		if (regex_match(argv[i], r))
			patterns.push_back(argv[i]);		
	}
	return patterns;
}

		// -----------------< process commandline to get search text >------------------

string CommandLineParser::processCommandlineText(int argc, char* argv[])
{
	string text = "";
	for (int i = 1; i < argc; ++i)
	{
		string temp = argv[i];
		if (temp.find("/f") != string::npos || temp.find("/F") != string::npos)
		{
			text = temp.substr(2,temp.length()-1);
			break;
		}
	}
	return text;
}

#ifdef TEST_COMMANDLINEPARSER
int main(int argc, char* argv[])
{
	cout << argc <<endl;
	string ar[] = { "*.cpp","../../", "/f","/fsunil" };

	CommandLineParser clp;
	string path = clp.processCommandlinePath(argc, argv);
	cout << "Path is equel:" << path << endl;

	vector<string> option = clp.processCommandlineOption(argc, argv);
	for (auto op : option)
		cout << "option:" << op << endl;

	vector<string> pattern = clp.processCommandlinePattern(argc, argv);
	for (auto patt: pattern)
		cout << "pattern:" << patt << endl;

	string text1 = clp.processCommandlineText(argc, argv);
	cout << "Text is equel:" << text1 << endl;
}
#endif