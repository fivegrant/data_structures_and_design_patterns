#include <string>
#include <vector>

// Linked List Class
template <class T>
class Link{
  public: 
    T value; 
    Link *next = nullptr; 
    Link() {};
    Link(T element): value(element){};
    Link(T element, Link *address): value(element),next(address){};

    T firstElement(){
       return value;
      }

    T lastElement(){
      if(next == nullptr){
        return value;
        }
      else{
        return next->lastElement();
        }
      }

    void insertAtHead(T element){
      next = new Link(value, next);
      value = element;
      };

    void insertAtTail(T element){
      if(next == nullptr){
        next = new Link(element);
        }
      else{
      next->insertAtTail(element);
        }
      };   

    void insertAtIndex(int index, T element){
      insertAtIndex(index, element, 0);
      };

    void insertAtIndex(int index, T element, int current){
      if(index == 0){
        insertAtHead(element);
      }
      else if(index - 1 <= current ){
	next = new Link(element, next);
        }
      else{
        next->insertAtIndex(index, element, current + 1);
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
      removeFromIndex(index, 0);
      };

    void removeFromIndex(int index, int current){
      if(index == 0){
        removeFromHead();
       }
      else if(index - 1 <= current ){
        Link* old = next;
        next = next->next;
        delete old;
        }
      else{
        next->removeFromIndex(index, current + 1);
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
};
