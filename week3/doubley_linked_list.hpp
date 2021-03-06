#include <string>
#include <vector>

// Linked List Class
template <class T>
class Link{
  public: 
    T value; 
    Link *next = nullptr; 
    Link *prev = nullptr; 
bool empty = true;
    Link() {};
    Link(T element): value(element), empty(false){};
    Link(T element, Link *address): value(element),next(address), empty(false){};    
    Link(T element, Link *nextAddress, Link *previousAddress): value(element), next(nextAddress), prev(previousAddress), empty(false){};

    T firstElement(){
      return value;
    };

    T lastElement(){
      return prev->value;
    };

    void insertAtHead(T element){
      if(not empty){
        next = new Link(value, next, this);
        value = element;
        if(prev == nullptr){
          prev = next;
          }
      }
      else{
        value = element;
        empty = false;
        }
      };

    void insertAtTail(T element){
      if(not empty){
        insertAtTail(element, nullptr, this);
        }
      else{
        value = element;
        empty = false;
        }
      };   

    void insertAtTail(T element, Link *previousAddress, Link *headElement){
      if(next == nullptr){
        next = new Link(element, nullptr, this);
	headElement->prev = next;
        }
      else{
        next->insertAtTail(element, this, headElement);
        }
      };   

    void insertAtIndex(int index, T element){
      if(index == getLength()){
        insertAtTail(element);
        }
      else{
        insertAtIndex(index, element, nullptr, this, 0);
	}
      };

    void insertAtIndex(int index, T element, Link *previousAddress, 
     Link *firstAddress, int current){
      if(index == 0){
        insertAtHead(element);
      }
      else if(index - 1 <= current){
        Link *space = next;
	next = new Link(element, next, this);
	space->prev = next;
        }
      else{
        next->insertAtIndex(index, element, this, firstAddress, current + 1);
        }
      };

    void removeFromHead(){
      if(getLength() <= 1){
        empty = true;
        }
      else{
        Link* old = next;
        value = next->value;
        next = next->next;
        delete old;
      }
      };

    void removeFromTail(){
      if(getLength() <= 1){
        empty = true;
        }
      else{
        if(next->next == nullptr){
          delete next->next;
          next = nullptr;
          }
        else{
          next->removeFromTail();
          }
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
       if(empty){
         return 0;
       }
       else{
         return getLength(0);
	 }
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
      if(empty){
        return std::vector<T> {};
        }
      else{
        return toArray(std::vector<T> {});
        }
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
      if(empty){
        value = next->value;
        next = next->next;
	empty = false;
      }
      else{
        return appendList(links, this);
        }
      };

    void appendList(Link *links, Link *headElement){ 
      if(next == nullptr){ 
        next = links;
	headElement->prev = next->prev;
	next->prev = this;
        }
      else{
        next->appendList(links, headElement);
        }
      };
};

