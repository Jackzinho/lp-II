#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadDictionary(string path, vector<string> &data);

void FindSubWord(string subWord, const vector<vector<string>> &data);

void RemoveWord(string subStr, vector<vector<string>> &data);

void PrintDictsStatistics(const vector<vector<string>> &data, const vector<string> &names);