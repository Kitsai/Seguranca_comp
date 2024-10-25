#include <cctype>
#include <iostream>
#include <string>

/// aplica o shift de fato seguindo uma logica muito similar a encriptacao
std::string MakeShift(std::string text, int shift) {
  std::string newText = "\nShift " + std::to_string(shift) + ": ";
  for (auto c : text)
    newText += ((std::tolower(c) - 'a' + shift) % 26) + 'a';
  return newText + '\n';
}

/// Testa todas as possiveis variacoes possiveis e mostra todas tornando facil a
/// verificacao de qual seria a verdadeira
std::string BruteForce(std::string cypherText) {
  std::string plainText = "";
  for (int i = 0; i < 26; i++)
    plainText += MakeShift(cypherText, i);
  return plainText;
}

/// Recebe o cyphertext e passa ele para a funcao de decriptacao
int main() {
  std::string cypherText;

  std::cout << "Input the cypher text: ";
  std::cin >> cypherText;
  std::cout << std::endl << BruteForce(cypherText) << std::endl;
}
