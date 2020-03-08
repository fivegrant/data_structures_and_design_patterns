#include <string>
#include <vector>

// Linked List Class
template <class T>
class Link{
  public: 
    T value; 
    Link *next = nullptr; 
    Link *prev = nullptr; 
    Link() {};
    Link(T element): value(element){};
    Link(T element, Link *nextAddress): value(element), next(nextAddress){};
    Link(T element, Link *nextAddress, Link *previousAddress): value(element), next(nextAddress), prev(previousAddress){};

    T getFirstElement(){
      return value;
    };

    T getLastElement(){
      return prev->value;
    };

    void insertAtHead(T element){
      next = new Link(value, next, this);
      value = element;
      };

    void insertAtTail(T element){
      insertAtTail(element, nullptr, this);
      };   

    void insertAtTail(T element, Link *previousAddress, Link *firstElement){
      if(next == nullptr){
        next = new Link(element);
	next->prev = previousAddress;
	firstElement->prev = this;
        }
      else{
        next->insertAtTail(element, this, firstElement);
        }
      };   

    void insertAtIndex(int index, T element){
      insertAtIndex(index, element, nullptr, 0);
      };

    void insertAtIndex(int index, T element, Link *previousAddress, int current){
      if(index - 1 <= current){
        insertAtHead(element);
        }
      else{
        next->insertAtIndex(index, element, this, current + 1);
        }
      };

    void removeFromHead(){
      Link* old = next;
      value = next->value;
      next = next->next;
      delete old;
      };

    void removeFromTail(){
      if(next->next == nullptr){
        delete next->next;
        next = nullptr;
        }
      else{
        next->removeFromTail();
        }
      };

    void removeFromIndex(int index){
      removeFromIndex(index, this, 0);
      };

    void removeFromIndex(int index, Link *previousAddress, int current){
      if(index == 0){
        removeFromHead();
       }
      else if(index - 1 <= current ){
        Link* old = next;
        next = next->next;
	prev = previousAddress;
        delete old;
        }
      else{
        next->removeFromIndex(index, this, current + 1);
        }
      };

     int getLength(){
       return getLength(0);
       };

    int getLength(int current){
      if(next == nullptr){
        return current + 1;
        }
      else{
        return next->getLength(current + 1);
        }
      };

    int search(T element) const{
      return search(element, 0);
      };

    int search(T element, int current) const{
      if(element == value){
        return current;
        }
      if(next == nullptr){
        return -1;
        }
      else{
        return next->search(element, current + 1);
        }
      };

    std::vector<int> searchAll(T element) const{
      return searchAll(element, 0, std::vector<int> {});
      };

    std::vector<int> searchAll(T element, int current, std::vector<int> collection) const{
      if(element == value){
        collection.push_back(current);
        }
      if(next == nullptr){
        return collection;
        }
      else{
        return next->searchAll(element, current + 1, collection);
        }
      };

    std::vector<T> toArray() const{
      return toArray(std::vector<T> {});
      };

    std::vector<T> toArray(std::vector<T> collection) const{  
      collection.push_back(value);
      if(next == nullptr){
        return collection;
        }
      else{
        return next->toArray(collection);
        }
      };

    void appendList(Link *links){ 
      if(next == nullptr){ 
        next = links;
        }
      else{
        next->appendList(links);
        }
      };

    void appendList(Link *links, Link *firstElment){ 
      if(next == nullptr){ 
        next = links;
        }
      else{
        next->appendList(links);
        }
      };
};

