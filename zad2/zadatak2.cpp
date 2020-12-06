#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "hamming.h"

std::vector<std::string> loadWords(const std::string& words) {
  std::ifstream dictionaryFile(words);
  std::vector<std::string> dictionary;
  std::string word;
  while (dictionaryFile >> word) {
    dictionary.push_back(std::move(word));
  }
  return dictionary;
}


std::vector<std::string> getResults (const std::vector<std::string> & dictionary, const std::string& usersWord) {
  std::vector<std::string> words;

// Returns the Hamming distance (int) between the 2 arguments
// Returns -1 if the words are not equal length
// int x = hammingDistance("Hello", "Hrllo");

  for (const std::string & word : dictionary) {
    short x = hammingDistance(word, usersWord);
    if (x != -1 && x < 2) words.push_back(usersWord);
  } 

  return words;

}

int main() { 

  std::vector<std::string> dictionary = loadWords("../zad1/words.txt");
  std::string usersWord;

  std::cout << "Insert a word: ";
  std::cin >> usersWord;

  std::vector<std::string> results = getResults(dictionary, usersWord);

  if (results.size() != 0) {
    for (const std::string &word : results) std::cout << word << std::endl;
  } else std::cout << "Couldn't find words with distance less than 2." << std::endl;


  return 0;
}
