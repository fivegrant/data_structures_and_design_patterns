#include "./queue.hpp"
#include <cstdlib>
#include <iostream>

class Logger{
  protected:
    int value = 0;
    int update_count = 0;
    int comparisons = 0;
  
  public:
    Logger(){}

    void count_comparison(){
      comparisons += 1;
    }

    void save(int incoming){
      value = incoming;
      update_count += 1;
    }

    int reveal(){
      return value;
    }

    int* results(){
      return new int[comparisons, update_count];
    }
};

int* generate1000(char choice){
  static int result [1000] = {0};
  for(int i = 0; i < 1000; i++){
    if(choice == '?'){
      result[i] = rand() % 1000;
    }
    else if(choice == 'i'){
      result[i] = 1000 - i;
    }
    else{
      result[i] = i;
    }
  }

  return result;
}


int* bubble_sort(int* source, int size){
  Logger log = Logger();
  bool swapped = true;
  while(swapped){
    swapped = false;
    for(int i = 0; i < size-1; i++){
      log.count_comparison();
      if(source[i] > source[i+1]){
        swapped = true;
	log.save(source[i]);
	source[i] = source[i+1];
	source[i+1]= log.reveal();
      }
    }
  }
  return log.results();
};

int* merge_sort(int* source, int size, Logger *log = new Logger(), int start = 0){
  int finish = start + size;
  if(size == 2){
    log->count_comparison();
    if(source[start] > source[start+1]){
	log->save(source[start]);
	source[start] = source[start+1];
	source[start+1]= log->reveal();
      }
  }
  else if(size > 1){
    int middle = size/2;
    std::cout << size << "-LEFT\n";
    merge_sort(source, middle, log, start);
    std::cout << size << "-RIGHT\n";
    merge_sort(source, size - middle, log, middle);

    Queue<int> left_queue = Queue<int>();
    Queue<int> right_queue = Queue<int>();

    for(int i = start; i < finish; i++){
      if(middle > i){
        left_queue.enqueue(source[i]);
      }
      else{
        right_queue.enqueue(source[i]);
      }
      log->save(0);
    }
    for(int i = start; i < finish; i++){
      log->count_comparison();
      if(right_queue.isEmpty()){
        source[i] = left_queue.dequeue();
      }
      else if (left_queue.isEmpty()){
        source[i] = right_queue.dequeue();
      }
      else if(left_queue.front() > right_queue.front()){
        std::cout << left_queue.front() << " > " << right_queue.front()<<"\n";
        source[i] = right_queue.dequeue();
      }
      else{
        std::cout << left_queue.front() << " < " << right_queue.front()<<"\n";
        source[i] = left_queue.dequeue();
      }
    }
  }
  return log->results();
};

int* quick_sort(int* source, int size, Logger *log = new Logger(), int start = 0){
  int finish = start + size;
  if(size == 2){
    log->count_comparison();
    if(source[start] > source[start+1]){
	log->save(source[start]);
	source[start] = source[start+1];
	source[start+1]= log->reveal();
      }
  }
  else if(size > 1){
    int middle = size/2;
    quick_sort(source, middle, log, start);
    quick_sort(source, size - middle, log, middle);

    Queue<int> left_queue = Queue<int>();
    Queue<int> right_queue = Queue<int>();

    int middle_value;
    for(int i = start; i < finish; i++){
      if(middle > i){
        left_queue.enqueue(source[i]);
      }
      else if(middle == i){
        middle_value = source[i];
      }
      else{
        right_queue.enqueue(source[i]);
      }
      log->save(0);
    }
    bool write_middle = false;
    for(int i = start; i < finish; i++){
      log->count_comparison();
      if(write_middle){
        write_middle = false;
	source[i] = middle_value;
      }
      else if (left_queue.isEmpty()){
        source[i] = right_queue.dequeue();
      }
      else{
        source[i] = left_queue.dequeue();
	write_middle = left_queue.isEmpty();
      }
    }
    quick_sort(source, middle, log, start);
    quick_sort(source, size - middle, log, middle);
  }
  return log->results();
};

