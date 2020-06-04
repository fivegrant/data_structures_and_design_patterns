//Queue 
#include "./node.hpp"
template <class T>
class Queue{
  private:
    Node<T> *content = nullptr;

  public: 
  bool isEmpty() const{
    return content == nullptr;
  };
  
  T front() const{
    return content->getValue();
  };

  void enqueue(T element){
    if(isEmpty()){
      content = new Node<T>(element);
    }
    else{
      content->enqueue(element);
    }
  };

  T dequeue(){
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
      for(int i = 0; i < size() + 1; i++){
        content->pop();
      }
      Node<T>* old = content;
      content = nullptr;
      delete old;
    }
  };


};
