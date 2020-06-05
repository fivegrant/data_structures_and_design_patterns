#ifndef NODE
#define NODE
// Node
template <class T>
class Node{
  private: 
    T value; 
    Node *next = nullptr;

  public: 
    Node(T element): value(element){};
    Node(T element, Node *nextAddress): value(element), 
      next(nextAddress){};

    T getValue() const{
      return value;
    };

    Node* getNext() const{
      return next;
    };

    void setValue(T assign){
      value = assign; 
    };

    void setNext(Node *assign){
      next = assign;
    }

    void push(T element){
      setNext(new Node(getValue(), getNext()));
      setValue(element);
      };

    void enqueue(T element){
      if(getNext() == nullptr){
        setNext(new Node(element));
        }
      else{
      getNext()->enqueue(element);
        }
      };   

    T pop(){
      Node *old = next;
      T lost = getValue();
      value = next->value;
      setNext(getNext()->getNext());
      delete old;
      return lost;
      };

    int size(){
       return size(0);
       };

    int size(int current){
      if(getNext() == nullptr){
        return current + 1;
        }
      else{
        return getNext()->size(current + 1);
        }
      };



};

#endif
