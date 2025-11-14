#include "utils.hpp"
#include <cstddef>
#include <vector>

using namespace std;

vector<string> splitString(string input) {
  vector<string> tokens;
  size_t i = 0;
  size_t prev = 0;
  while (i < input.size()) {
    if (input[i] == ' ') {
      tokens.push_back(input.substr(prev, i - prev));
      while (input[i] == ' ') {
        i++;
      }
      prev = i;
    } else {
      i++;
    }
  }

  if (i > prev) {
    tokens.push_back(input.substr(prev, i - prev));
  }

  return tokens;
}