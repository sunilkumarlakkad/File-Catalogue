#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H
///////////////////////////////////////////////////////////////////////
// CommandLineParser.h - Parse the Commanl Line Arguments            //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 13.0						         //
// Platform:    Dell Inspiron N5010, Win7 Professional, SP1          //
// Application: Demonstration for CSE 687, Project #1, Spring 2015   //
// Author:      Sunilkumar Lakkad, Syracuse University               //
//              (315) 751-5834, lakkads1@gmail.com                   //
///////////////////////////////////////////////////////////////////////
/*
* Module Operations:
* ------------------
* This module defines the following class:
*   CommandLineParser  - three methods processCommandLinePath,
*   processCommandLinePattern, processCommandLineOption and 
*   processCommandlineTextparse and identify path, patterns, 
*   options and search text respectively
*/
/*
* Maintenance History:
* --------------------
* ver 1.0 : 10 Jan 2015
* - first release
*/
#include<iostream>
#include<vector>
using namespace std;

class CommandLineParser
{
public:
	string processCommandlinePath(int argc, char* argv[]);
	vector<string> processCommandlinePattern(int argc, char* argv[]);
	vector<string> processCommandlineOption(int argc, char* argv[]);
	string processCommandlineText(int argc, char* argv[]);
};
#endif