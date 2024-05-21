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
    for (int i = 0; i < nItems; ++i) {
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

void readFromFile(const char* filename, Record table[], int n) {
    std::ifstream data(filename);
    if (!data) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    for (int j = 0; j < n; ++j) {
        Record rec;
        data >> rec.lastName >> rec.coreNum >> rec.cpu >> rec.ram >> rec.gpu >> rec.vram >> rec.mem >> rec.drives >> rec.total >> rec.periphery >> rec.os;
        table[j] = rec;
    }
    data.close();
}

int main(int argc, char* argv[]) {
    const char* filename = argv[1];
    // if (*argv[2] == '1') {
    //   addRecord(filename, TEST1, sizeof(TEST1) / sizeof(TEST1[0]));
    // } else if (*argv[2] == '2') {
    //   addRecord(filename, TEST2, sizeof(TEST2) / sizeof(TEST2[0]));
    // } else if (*argv[2] == '3') {
    //   addRecord(filename, TEST3, sizeof(TEST3) / sizeof(TEST3[0]));
    // }
    const char* in = argv[2];
    int n = 8;
    Record recs[n];
    readFromFile(in, recs, n);
    addRecord(filename, recs, sizeof(recs) / sizeof(recs[0]));
    print(filename);
}