:run.bat
:
:runs parser code

echo off
cls
echo ************Demonstrating Requirement 3,8*****************
echo ---------------------------------------------------------- 
echo Searching with Sub Directories
"Debug/Executive.exe" "TESTFOLDER" "*.*" "/s" 

cls
echo ************Demonstrating Requirement 3,8*****************
echo ---------------------------------------------------------- 
echo Searching at location (Not Sub Directories)
"Debug/Executive.exe" "TESTFOLDER" "*.*" "/d"

cls
echo ************Demonstrating Requirement 5,8*****************
echo ---------------------------------------------------------- 
echo Searching Duplicate Files
"Debug/Executive.exe" "TESTFOLDER" "*.cpp" "*.txt" "/s" "/D"
cls
echo ************Demonstrating Requirement 6,8*****************
echo ---------------------------------------------------------- 
echo Searching files with search Text
"Debug/Executive.exe" "TESTFOLDER" "*.*" "/S" "/D" "/fsunil"

cls
echo ************Demonstrating Requirement 7,8*****************
echo ---------------------------------------------------------- 
echo Brief Summary 
"Debug/Executive.exe" "TESTFOLDER"


