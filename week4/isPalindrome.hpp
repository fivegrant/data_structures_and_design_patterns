#include <string>
#include "stack.hpp"
#include "queue.hpp"


bool isPalindrome(std::string palindrome){
  Queue<char> queue = Queue<char>();
  Stack<char> stack = Stack<char>();
  for(char c : palindrome){
    queue.enqueue(c);
    stack.push(c);
  }
  bool status = true;
  for(int i = 0; i < queue.size(); i++){
    if(queue.dequeue() != stack.pop()){
      status = false;
      break;
    }
  }
  return status;
}; 

