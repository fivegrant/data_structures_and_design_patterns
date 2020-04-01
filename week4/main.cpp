#include <iostream>
#include "isPalindrome.hpp"

int main(int argc, char* argv[] ){
  std::string input(argv[1]);
  if(isPalindrome(input)){
    std::cout << "True";
  }
  else{
    std::cout << "False";
  }
  return 0;
}
