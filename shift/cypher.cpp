#include <cctype>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>

/// @brief cpp mod takes root mod so -x mod y results in a negative number. This
/// function makes it always return a postive value
int floorMod(int x, int y) {
  x %= y;
  if (x < 0)
    x += y;
  return x;
}

std::string CypherText(std::string plainText, int shift) {
  /// Se cria uma string nova que serao concatenados os novos caracteres
  std::string cypherText = "";

  for (auto c : plainText) {
    if (isalpha(c))
      /// usando a funcao de mod criada os caracteres sao jogados para lowercase
      /// para simplificar entao e aplicada o shift e feito o modulo desse
      /// valor. feito isso e somado noavamente o valor para voltarem para a
      /// escala ascii
      cypherText += floorMod((std::tolower(c) - 'a' + shift), 26) + 'a';
    else
      cypherText += c;
  }

  return cypherText;
}

int main() {
  int shift;
  std::string plainText;

  /// Recebemos os valores de shift e o plaintext
  /// Que sao passados para a funcao que ira encriptar o texto
  std::cout << "Input shift number: ";
  std::cin >> shift;
  std::cout << std::endl << "Input text to be cyphered: ";
  std::getline(std::cin, plainText);
  std::getline(std::cin, plainText);
  std::cout << std::endl << CypherText(plainText, shift) << std::endl;
}
