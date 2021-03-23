#include "dictionary.hpp"

int main()
{
  int loopInput = 0;
  vector<vector<string>> globalDictData;
  vector<string> globalDictName;

  while (loopInput != 5)
  {
    cin >> loopInput;

    switch (loopInput)
    {
    case 1:
    {

      vector<string> loadedDict;

      string path;
      cin >> path;

      try
      {
        LoadDictionary(path, loadedDict);

        globalDictData.push_back(loadedDict);
        globalDictName.push_back(path);
      }
      catch (string err)
      {
        cout << err << endl;
      }

      break;
    }
    case 2:
    {
      string substr;
      cin >> substr;

      FindSubWord(substr, globalDictData);
      break;
    }

    case 3:
    {
      string userInput;
      cin >> userInput;

      RemoveWord(userInput, globalDictData);
      break;
    }
    case 4:
    {
      PrintDictsStatistics(globalDictData, globalDictName);
      break;
    }
    case 5:
    {
      break;
    }
    }
  }

  return 0;
}
