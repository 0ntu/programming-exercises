#include <iostream>
#include <stdexcept>

int factorial(int number)
{
  int output {number};

  for(int i = (number-1); i>0; --i) {
    output = output*i;
  }

  return output;
}

int numPermutations(int objects, int sample)
{
  // Guard Statements
  if(!(sample >= 0) || !(objects >= sample)) {
    throw std::runtime_error("Please enter n >= r >= 0");
  }

  //Compute Permutations & return
  return (factorial(objects))/(factorial(objects-sample));
}

int numCombinations(int objects, int sample)
{
  if(!(sample >= 0) || !(objects >= sample)) {
    throw std::runtime_error("Please enter n >= r >= 0");
  }

  return (numPermutations(objects, sample))/(factorial(sample));
}

int main()
{
  try {
    std::cout << "Permutations: " << numPermutations(3, 2) << '\n';
    std::cout << "Combinations: " << numCombinations(3, 2) << '\n';
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << '\n';
  }
}
