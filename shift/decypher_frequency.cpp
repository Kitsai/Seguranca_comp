#include <array>
#include <cctype>
#include <iostream>
#include <string>

/// Array de frequencia de cada caracter do texto
/// seguindo a ideia de que a = 0 e assim podemos representar as letras
/// numericamente.
std::array<int, 26> textFrequency = {0};

/// Conta os caracteres no texto e insere no array de frequencia.
void CountCharacters(std::string text) {
  for (auto c : text) {
    if (isalpha(c)) {
      unsigned idx = std::tolower(c) - 'a';
      textFrequency[idx]++;
    }
  }
}

/// Calcula o indice de maiot frequencia no array.
unsigned MaxFrequency() {
  int idx = 0;
  for (int i = 0; i < 26; i++)
    if (textFrequency[i] > textFrequency[idx])
      idx = i;

  return idx;
}

/// Teste inicial com a letra a de base então a ideia é levar o caracter mais
/// frequente para a
std::string TestFrequencyForA(std::string text, char max) {
  std::string newText = "Possibility for a with " + std::to_string(max) + ": ";
  int shift = (-max + 26) % 26;
  for (auto c : text)
    if (!isalpha(c))
      newText += c;
    else
      newText += ((std::tolower(c) - 'a' + shift) % 26) + 'a';
  return newText + '\n';
}

/// Em alguns casos testar apenas o a não seria suficiente então como pelo menos
/// um segundo teste usamos a mesma lógica para o e sendo a segunda letra mais
/// frequente e com uma frequência semelhante.
std::string TestFrequencyForE(std::string text, char max) {
  std::string newText = "Possibility for e with " + std::to_string(max) + ": ";
  const int diff = 4 - max;
  int shift = (diff < 0) ? diff + 26 : diff;
  for (auto c : text)
    if (!isalpha(c))
      newText += c;
    else
      newText += ((std::tolower(c) - 'a' + shift) % 26) + 'a';
  return newText + '\n';
}

/// Responsável pela análise de frequencia do texto.
/// Inicialmente conta a frequencia dos caracteres no texto e em seguida retorna
/// o que tiver a maior frequencia;
std::string FrequencyAnalysis(std::string cypherText) {
  CountCharacters(cypherText);
  unsigned max = MaxFrequency();

  /// Feito isso criamos uma string de resultado e então será testada a
  /// frequencia tanto para "a" e "e" que são os caracteres mais comuns da
  /// lingua portuguesa.
  std::string result = "";
  for (int i = 0; i < 26; i++)
    /// Testa apenas as possibilidades onde a frequencia é maxima
    if (textFrequency[i] == textFrequency[max]) {
      result += TestFrequencyForA(cypherText, i);
      result += TestFrequencyForE(cypherText, i);
    }
  return result;
}

/// Recebe o texto cifrado e roda o algoritmo de decriptação.
int main() {
  std::string cypherText;
  std::cout << "Input Cypher Text: ";
  std::getline(std::cin, cypherText);
  std::cout << FrequencyAnalysis(cypherText);
}

/// A analise  de frequencia é uma abordagem mais complexa para resolver a shift
/// cypher a ideia é usar a ideia de que essa cifra não altera o alfabeto em si
/// apenas faz um shift então descobrir qual a letra de maior frequencia e usar
/// ela de base para o valor do shift. Porém essa abordagem diferente da
/// abordagem de força bruta não é 100% garantida uma fez que faz uso de
/// probabilidade para mitigar isso foi feito dois testes com as duas letras
/// mais frequentes da lingua portuguesa e esses testes são aplicados em todas
/// as letras do texto em claro que possuem a maior frequencia.
/// Ainda assim é possível que haja um caso onde não irá funcionar
/// especialmente em textos pequenos uma vez que quanto maior o texto
/// mais ele irá se aproximar à distribuição esperada.
/// Apesar de termos que calcular a frequencia usando essa abordagem
/// temos que percorrer o texto no minimo 3 vezes o que será o mais provavel e
/// no maximo 53 vezes. Mas dificilmente teremos tantos caracteres emptados pela
/// maior frequencia dessa forma. logo é muito provavél que essa abordagem tenha
/// que iterar pelo texto menos de 26 vezes sendo mais rápido do que a abordagem
/// força bruta.
