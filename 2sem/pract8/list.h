#ifndef LIST_D
#define LIST_D

class Node {
 public:
  float data;
  Node* next;
  Node* prev;

  Node(float data);
};

class LinkedList {
 private:
  Node* head;
  Node* tail;

 public:
  LinkedList();

  // Добавление элемента в конец списка
  void append(float data);
  // Добваление элемента в начало списка
  void appbeg(float data);
  // Удаление элемента
  void del(float data);
  // Вывод списка в консоль
  void print();
  // Возвращает длину списка
  int length();

  bool isSorted();
  bool isSorted(bool ni);

  ~LinkedList();
};
#endif