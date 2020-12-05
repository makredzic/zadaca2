#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> loadWords(const std::string& words) {
  std::ifstream dictionaryFile(words);
  std::vector<std::string> dictionary;
  std::string word;
  while (dictionaryFile >> word) {
    dictionary.push_back(std::move(word));
  }
  return dictionary;
}


std::vector<std::string> HammingDistance (const std::vector<std::string> & dictionary, const std::string& usersWord) {
  std::vector<std::string> words;

  for (int i=0; i<dictionary.size(); ++i) {
    int j=0;

    if (usersWord.size() == dictionary.at(i).size()) {
      for (int k=0; k<usersWord.size(); ++k) {
        if(usersWord.at(k) != dictionary.at(i).at(k)) {
          j++; 
          if (j<2) words.push_back(dictionary.at(i));
        } 
      }
    }

  }

  return words;

}

int main() { 

  std::vector<std::string> dictionary = loadWords("../zad1/words.txt");
  std::string usersWord;

  std::cout << "Insert a word: ";
  std::cin >> usersWord;

  std::vector<std::string> results = HammingDistance(dictionary, usersWord);

  if (results.size() != 0) {
    for (std::string &word : results) std::cout << word << std::endl;
  } else std::cout << "Couldn't find words with distance less than 2." << std::endl;


  return 0;
}
