#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

std::string FormatPlainText(std::string plainText) {
  std::string newText = "";
  for (auto c : plainText)
    if (isalpha(c))
      newText += toupper(c);
  return newText;
}

struct Dimensions {
  unsigned columns;
  unsigned rows;
};

unsigned ComputeRows(unsigned length, unsigned charsPerRow) {
  if (length % charsPerRow)
    return (length / charsPerRow) + 1;
  else
    return (length / charsPerRow);
}

std::string ApplyCypher(std::string text, const Dimensions &dimensions) {
  std::string newText = "";
  srand(time(0));

  for (int i = 0; i < dimensions.columns; i++) {
    for (int j = 0; j < dimensions.rows; j++) {
      if (i + j * dimensions.columns < text.length())
        newText += text[i + j * dimensions.columns];
      else
        newText += (rand() % 26) + 'A';
    }
  }

  return newText;
}

std::string ColumnCypher(std::string plainText, unsigned charsPerRow) {
  std::string cleanText = FormatPlainText(plainText);

  const Dimensions matrixDimensions = {
      charsPerRow,
      ComputeRows(cleanText.length(), charsPerRow),
  };

  return ApplyCypher(cleanText, matrixDimensions);
}

int main() {
  unsigned charsPerRow;
  std::string plainText;
  std::cout << "How many characters per row? ";
  std::cin >> charsPerRow;
  std::cout << std::endl << "Enter the plain Text: ";
  std::getline(std::cin, plainText);
  std::getline(std::cin, plainText);
  std::cout << ColumnCypher(plainText, charsPerRow) << std::endl;
}
