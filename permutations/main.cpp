#include <iostream>
#include <stdexcept>

int factorial(int number) {
  if (number < 0)
    throw std::runtime_error("Factorial error");

  int output{number};

  for (int i = (number - 1); i > 0; --i) {
    output = output * i;
  }

  return output;
}

int numPermutations(int objects, int sample) {
  // Guard Statements
  if (!(sample >= 0) || !(objects >= sample)) {
    throw std::runtime_error("Please enter n >= r >= 0");
  }

  // Compute Permutations & return
  return (factorial(objects)) / (factorial(objects - sample));
}

int numCombinations(int objects, int sample) {
  // Guard Statements
  if (!(sample >= 0) || !(objects >= sample)) {
    throw std::runtime_error("Please enter n >= r >= 0");
  }

  // Compute Combinations & return
  return (numPermutations(objects, sample)) / (factorial(sample));
}

int main() {
  while (true) {

    std::cout << "Enter two numbers (seperated by whitespace)\n";
    int a, b;
    if (!(std::cin >> a >> b))
      throw std::runtime_error("Invalid Input: Not two integers");

    std::cout << "Enter 'p' to compute Permutations\nEnter 'c' to compute "
                 "Combinations\nEnter 'b' to compute both\n\n";
    bool perm = false;
    bool comb = false;

    // Bad way to test for input lol
    std::string test;
    std::cin >> test;

    if (test == "p")
      perm = true;
    else if (test == "c")
      comb = true;
    else if (test == "b") {
      perm = true;
      comb = true;
    } else
      throw std::runtime_error("Invalid Input: Bad Choice Selection");

    if (perm)
      std::cout << "Permutations: " << numPermutations(a, b) << '\n';
    if (comb)
      std::cout << "Combinations: " << numCombinations(a, b) << '\n';
  }
}
