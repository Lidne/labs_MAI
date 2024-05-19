#include <fstream>
#include <iomanip>
#include <iostream>

#include "item.h"

void printNotWINTEL(const char* filename) {
  std::ifstream db(filename, std::ios::binary);
  if (!db) {
    std::cerr << "Error opening file" << std::endl;
    return;
  }
  std::cout << "Not WINTEL computers" << std::endl;
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
    if (!(rec.cpu[0] == 'I' && rec.os[0] == 'W'))
      std::cout << std::left << std::setw(16) << rec.lastName << std::setw(8)
                << rec.coreNum << std::setw(16) << rec.cpu << std::setw(8)
                << rec.ram << std::setw(16) << rec.gpu << std::setw(8)
                << rec.vram << std::setw(16) << rec.mem << std::setw(8)
                << rec.drives << std::setw(8) << rec.total << std::setw(8)
                << rec.periphery << std::setw(16) << rec.os << std::endl;
  }

  db.close();
}

int main(int argc, char* argv[]) {
  const char* filename = argv[1];
  printNotWINTEL(filename);
}