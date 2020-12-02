#include <iostream>
#include <fstream>
#include <vector>

using std::string;

std::vector<string> loadWords(const string & fileName) {

std::ifstream dictionaryFile(fileName);
std::vector<string> dictionary;
std::string word;

while (dictionaryFile >> word) {
  dictionary.push_back(std::move(word));
}

return dictionary;
}

std::vector<string> over25chars(const std::vector<string>& dictionary) {
  std::vector<string> temp;

  for (string w : dictionary) if (w.length() > 25) temp.push_back(w);
  return temp;

}


int main() {

  std::vector<string> dictionary = loadWords("words.txt");
  auto wordsOver25 = over25chars(dictionary);

  std::cout << "Words over 25 characters: \n";
  for (auto x : wordsOver25) std::cout << x << std::endl; 
  


  return 0;
}

