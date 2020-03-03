#include <vector>

// Linked List Class
template <class T>
class Link{
  private:
    T value; 
    Link *next; 
  public: 
    Link() {};
    Link(T element): value(element){};
    Link(T element, T *address): value(element),next(address){};
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(int index, T element);
    void insertAt(int index, T element, int current);
    void removeFromHead();
    void removeFromTail();
    void removeFrom(int index);
    void removeFrom(int index, int current);
    int length();
    int length(int current);
    int search(T element) const;
    int search(T element, int current) const;
    std::vector<int> searchAll(T element) const;
    std::vector<int> searchAll(T element, int current, std::vector<int> collection) const;
    std::vector<T> toArray() const;
    std::vector<T> toArray(std::vector<T> collection) const;
    void append(Link *links);
};
