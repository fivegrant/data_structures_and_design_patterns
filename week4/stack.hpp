// Stack
#include "./node.hpp"
template <class T>
class Stack{
  private:
    Node<T> *content = nullptr;

  public: 
  bool isEmpty() const{
    return content == nullptr;
  };
  
  T peek() const{
    return content->getValue();
  };

  void push(T element){
    if(isEmpty()){
      content = new Node<T>(element);
    }
    else{
      content->push(element);
    }
  };

  T pop(){
    if(content->getNext() == nullptr){
      T value = content->getValue();
      delete content;
      content = nullptr;
      return value;
    }
    else{
      return content->pop();
    }
  };

  int size() const{
    if(isEmpty()){
      return 0;
    }
    else{
      return content->size();
    }
  };

  void clear(){
    if(isEmpty()){
      return;
    } 
    else{
      for(int i = 0; i < size(); i++){
        content->pop();
      }
      Node<T>* old = content;
      content = nullptr;
      delete old;
    }
  };
};
