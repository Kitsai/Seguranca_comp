#include <cctype>
#include <iostream>
#include <string>

/// aplica o shift de fato seguindo uma logica muito similar a encriptacao
std::string MakeShift(std::string text, int shift) {
  std::string newText = "\nShift " + std::to_string(shift) + ": ";
  for (auto c : text)
    if (!isalpha(c))
      newText += c;
    else
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
  std::getline(std::cin, cypherText);
  std::cout << std::endl << BruteForce(cypherText) << std::endl;
}

/// Como temos poucas possibilidades a verificacao do forca bruta é fácil e pode
/// ser bem relevante Esse tipo de ataque garante que você ira conseguir tanto o
/// valor de shift quanto o texto em claro.
/// Apesar de ser uma abordagem que não retorne uma resposta direta ele é
/// simples de ser verificado e rapido de executar. Logo é uma abordagem muito
/// boa para essa cifra.
