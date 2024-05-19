#include <fstream>
#include <iomanip>
#include <iostream>

#include "item.h"

void addRecord(const char* filename, const Record items[],
               unsigned long long nItems) {
  std::ofstream db(filename, std::ios::binary);
  if (!db) {
    std::cerr << "Error opening file" << std::endl;
    return;
  }
  // добавляем нулевой байт для обозначения конца "строки"
  for (int i = 0; i < nItems; ++i) {
    // items[i].lastName[sizeof(items[i].lastName) - 1] = '\0';
    // items[i].cpu[sizeof(items[i].cpu) - 1] = '\0';
    // items[i].gpu[sizeof(items[i].gpu) - 1] = '\0';
    // items[i].mem[sizeof(items[i].mem) - 1] = '\0';
    // items[i].os[sizeof(items[i].os) - 1] = '\0';
    db.write(reinterpret_cast<const char*>(&items[i]), sizeof(items[i]));
  }
  db.close();
}

void print(const char* filename) {
  std::ifstream db(filename, std::ios::binary);
  if (!db) {
    std::cerr << "Error opening file" << std::endl;
    return;
  }

  std::cout << std::left << std::setw(16) << "Last Name" << std::setw(8)
            << "Cores" << std::setw(16) << "CPU" << std::setw(8) << "RAM"
            << std::setw(16) << "GPU" << std::setw(8) << "VRAM" << std::setw(16)
            << "DType" << std::setw(8) << "DNumber" << std::setw(8) << "Memory"
            << std::setw(8) << "Periphery" << std::setw(16) << "OS"
            << std::endl;
  std::cout << "---------------------------------------------------------------"
               "---------------------------------------------------------------"
            << std::endl;
  Record rec;

  while (db.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
    std::cout << std::left << std::setw(16) << rec.lastName << std::setw(8)
              << rec.coreNum << std::setw(16) << rec.cpu << std::setw(8)
              << rec.ram << std::setw(16) << rec.gpu << std::setw(8) << rec.vram
              << std::setw(16) << rec.mem << std::setw(8) << rec.drives
              << std::setw(8) << rec.total << std::setw(8) << rec.periphery
              << std::setw(16) << rec.os << std::endl;
  }

  db.close();
}

int main(int argc, char* argv[]) {
  const char* filename = argv[1];
  if (*argv[2] == '1') {
    addRecord(filename, TEST1, sizeof(TEST1) / sizeof(TEST1[0]));
  } else if (*argv[2] == '2') {
    addRecord(filename, TEST2, sizeof(TEST2) / sizeof(TEST2[0]));
  } else if (*argv[2] == '3') {
    addRecord(filename, TEST3, sizeof(TEST3) / sizeof(TEST3[0]));
  }
  print(filename);
  return 1;
}