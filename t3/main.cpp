#include "header.hpp"

void print_map(map<char, int> a);

int main(int argc, char const *argv[])
{
  map<char, int> caracters_freq;
  map<char, int> caracters_ascii;
  map<char, char> caracters_matches;
  stringstream hash;
  vector<int> ascii_vector;
  char c;
  string str;

  ifstream freq_file("frequencies.txt");
  if (!freq_file.is_open())
  {
    cout << "Erro, arquivo não foi encontrado" << endl;
    return 1;
  }

  while (getline(freq_file, str))
  {
    ascii_vector.push_back(stoi(str));
  }

  ifstream hash_file("hash.txt");
  if (!hash_file.is_open())
  {
    cout << "Erro, arquivo não foi encontrado" << endl;
    return 1;
  }

  while (hash_file.get(c))
  {
    if (c != '\n')
    {
      caracters_freq[c] += 1;
      hash << c;
    }
  }

  print_map(caracters_freq);

  ofstream alpha("alpha.txt");

  cout << "Digite um inteiro entre -50 e 50 para gerar o \"alpha.txt\": ";
  cin >> str;

  int i = 0;
  for (auto p : caracters_freq)
  {
    int ascii_value = i < ascii_vector.size() ? ascii_vector.at(i) : -1;
    caracters_ascii[p.first] = ascii_value;

    alpha << p.first << " " << (char)(ascii_value != -1 ? ascii_value + stoi(str) : ascii_value) << endl;
    i++;
  }

  ofstream decoded("decoded.txt");
  for (int a = -50; a <= 50; a++)
  {
    decoded << a << ": ";

    while (hash.get(c))
    {
      char out = caracters_ascii[c] != -1 ? caracters_ascii[c] + a : c;
      decoded << out;
    }

    decoded << endl
            << endl;

    hash.clear();
    hash.seekg(0, ios::beg);
  }

  decoded.close();
  decoded.clear();

  //Descriptografando manualmente

  cout << "Voce ja tem a tabela de conversao \"alpha-dictionary.txt\" pronta? (s/n)" << endl;
  cin >> str;

  if (str == "n") {
    return 0;
  }

  map<char, char> chars;

  ifstream dict("alpha-dictionary.txt");
  if (!dict.is_open())
  {
    cout << "Erro, arquivo não foi encontrado" << endl;
    return 1;
  }
  else
  {
    string str;
    while (getline(dict, str))
    {
      chars[str.at(0)] = str.at(2);
    }

    dict.close();
  }

  decoded.open("decoded.txt");

  while (hash.get(c))
  {
    if (c != '\n')
    {
      decoded << chars[c];
    }
  }

  decoded.close();

  return 0;
}

void print_map(map<char, int> a)
{
  for (auto p : a)
  {
    cout << "{ " << p.first << " : " << p.second << " }" << endl;
  }
}