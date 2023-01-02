#ifndef _CLASS_H
#define _CLASS_H

#include <iostream>
#include <fstream>
#include <sstream>

#include <windows.h>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
using namespace std;

class fileHelper
{
public:
    void csvCourseReader();
    void csvTimeReader();

public:
    static std::vector<std::vector<bool>> table;
    static std::vector<std::string> className;
};

class myReader
{
public:
    myReader(string dirc);
    int ReadLine(vector<string> &);
    int ReadLines();
    vector<vector<string>> ReadCSV();

private:
    const char* fileDirc;
    vector<vector<string>> data;
    vector<string> lines;
    string line;
};

#endif