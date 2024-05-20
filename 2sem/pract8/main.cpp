#include <iostream>

#include "list.h"

int main() {
  LinkedList list;

  list.append(.1f);
  list.append(.2f);
  list.append(.3f);
  list.appbeg(.4f);

  list.print();
  std::cout << "Length: " << list.length() << std::endl;
  std::cout << "isSorted: " << list.isSorted() << std::endl;
  list.del(.4f);
  std::cout << std::endl;
  list.print();
  std::cout << "Length: " << list.length() << std::endl;
  std::cout << "isSorted: " << list.isSorted() << std::endl;

  return 0;
}