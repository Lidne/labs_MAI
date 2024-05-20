#include "list.h"

Node::Node(float data) {
  Node::data = data;
  next = nullptr;
  prev = nullptr;
}

LinkedList::LinkedList() {
  // Инициализация барьерных элементов
  head = new Node(.0f);
  tail = new Node(.0f);
  head->next = tail;
  tail->prev = head;
}

void LinkedList::append(float data) {
  Node* newNode = new Node(data);
  Node* last = tail->prev;

  last->next = newNode;
  newNode->prev = last;
  newNode->next = tail;
  tail->prev = newNode;
}

void LinkedList::appbeg(float data) {
  Node* newNode = new Node(data);
  Node* first = head->next;

  first->prev = newNode;
  newNode->next = first;
  newNode->prev = head;
  head->next = newNode;
}
// deleted = 5
// 0 5 0
void LinkedList::del(float data) {
  if (tail->prev->data == data &&
      tail->prev != head) {  // у хвоста всегда должен быть предыдущий элемент
    Node* deleted = tail->prev;
    if (deleted->prev != nullptr) {
      deleted->prev->next = tail;
      tail->prev = deleted->prev;
      delete deleted;
      return;
    }
  } else {
    Node* current = head->next;
    while (current != tail) {
      if (current->data == data) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        return;
      }
      current = current->next;
    }
  }
}

void LinkedList::print() {
  Node* current = head->next;
  while (current != tail) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
}

int LinkedList::length() {
  int l = 0;
  Node* current = head->next;
  while (current != tail) {
    l++;
    current = current->next;
  }
  return l;
}

bool LinkedList::isSorted() { LinkedList::isSorted(false); }

bool LinkedList::isSorted(bool ni) {  // ni - non increasing (невозрастающий).
                                      // По умолч - неубывающий
  Node* current = head->next;
  while (current->next != tail) {
    if ((!ni && current <= current->next) || (ni && current >= current->next)) {
      current = current->next;
    } else
      return false;
  }
  return true;
}