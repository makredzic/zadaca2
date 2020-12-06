#include "hamming.h"

int hammingDistance(const std::string& s1, const std::string& s2) {
  short distance = 0;

  if (s1.length() != s2.length()) return -1;

  for (int i = 0; i < s1.length(); ++i) {
    if (tolower(s1[i]) != tolower(s2[i]))
      ++distance;
  }

  return distance;
}
