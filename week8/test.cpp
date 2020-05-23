#include "./sort.hpp"
#include <iostream>
#include <chrono>

void poop(int* ints, int size){
  for(int i = 0; i < size; i++){
    std::cout << ints[i] << " ";
  }
}

int main(){
  int *sorted = generate1000('S');
  int *random1 = generate1000('?');
  int *random2 = generate1000('?');
  int *random3 = generate1000('?');
  int *reverse1 = generate1000('!');
  int *reverse2 = generate1000('!');
  int *reverse3 = generate1000('!');

  int sorty1 [6] = {5, 1, 3, 1, 8, 2};
  int sorty2 [7] = {5, 1, 3, 1, 8, 2, 4};
  int sorty3 [6] = {5, 1, 3, 1, 8, 2};
  
  poop(sorty1, 6);
  std::cout << "\n";
  poop(sorty2, 7);
  std::cout << "\n";
  poop(sorty3, 6);
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";


  bubble_sort(sorty1, 6);
  merge_sort(sorty2, 7);
  quick_sort(sorty3, 6);

  poop(sorty1, 6);
  std::cout << "\n";
  poop(sorty2, 7);
  std::cout << "\n";
  poop(sorty3, 6);
  return 0;
}


