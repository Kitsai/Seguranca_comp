#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>

std::array<int, 26> textFrequency = {0};
std::array<float, 26> ptFrequency = {
    13.9, 1.0,  4.4, 5.4, 12.2, 1.0, 1.2, 0.8, 6.9, 0.4, 0.1, 2.8, 4.2,
    5.3,  10.8, 2.9, 0.9, 6.9,  7.9, 4.9, 4.0, 1.3, 0.0, 0.3, 0.0, 0.4};

void CountCharacters(std::string text) {
  for (auto c : text) {
    unsigned idx = std::tolower(c) - 'a';
    textFrequency[idx]++;
  }
}

std::string TestFrequency(std::string text, unsigned max) {
  std::string newText = "Possibility with " + std::to_string(max + 'a') + ": ";
  int shift = (-max + 26) % 26;
  for (auto c : text)
    newText += ((std::tolower(c) - 'a' + shift) % 26) + 'a';
  return newText;
}
std::string FrequencyAnalysis(std::string cypherText) {
  unsigned max = *std::max_element(textFrequency.begin(), textFrequency.end());
  std::string result = "";
  for (int i = 0; i < 26; i++)
    if (textFrequency[i] == max)
      result += TestFrequency(cypherText, i);
  return result;
}

int main() {
  std::string cypherText;
  std::cout << "Input Cypher Text: ";
  std::cin >> cypherText;
  std::cout << FrequencyAnalysis(cypherText);
}
