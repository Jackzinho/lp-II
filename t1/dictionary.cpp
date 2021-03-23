#include "dictionary.hpp"

void LoadDictionary(string path, vector<string> &data)
{
  ifstream filereader;

  filereader.open(path);

  if (!filereader.is_open())
  {
    throw string("File could not be read!");
  }

  string tmp;

  while (getline(filereader, tmp))
  {
    data.push_back(tmp);
  }

  data.erase(data.begin());
}

void FindSubWord(string subWord, const vector<vector<string>> &data)
{
  for (vector<string> dict : data)
  {
    for (string str : dict)
    {
      size_t exists = str.find(subWord);

      if (exists != string::npos)
      {
        cout << str << endl;
      }
    }
  }
}

void RemoveWord(string subStr, vector<vector<string>> &data)
{
  for (int i = 0; i < data.size(); i++)
  {

    int index = 0;
    for (string str : data.at(i))
    {
      size_t exists = str.find(subStr);

      if (exists != string::npos)
      {
        data.at(i).erase(data.at(i).begin() + index);
      }

      index++;
    }
  }
}

void PrintDictsStatistics(const vector<vector<string>> &data, const vector<string> &names)
{
  cout << "Statistics:" << endl;

  for (int i = 0; i < names.size(); i++)
  {

    cout << names[i] << " -> " << data[i].size() << " words" << endl;
  }
}
