struct Record {
  char lastName[16];     // фамилия
  unsigned int coreNum;  // кол-во ядер в цп
  char cpu[16];  // производитель цп (я не понял что такое тип цп)
  unsigned int
      ram;  // ОЗУ в ГБ, потому что кто использует меньше 2ГБ на рабочем компе
  char gpu[16];            // название видеоадаптера
  unsigned int vram;       // память видеоадаптера
  char mem[8];             // тип накопителя
  unsigned int drives;     // кол-во накопителей
  unsigned int total;      // суммарная память в ГБ
  unsigned int periphery;  // кол-во периферии
  char os[16];             // ОС
};

void addRecord(const char* filename, const Record items[],
               unsigned long long nItems);
void print(const char* filename);

const Record TEST1[] = {
    {"Nikolaev", 6, "AMD Ryzen 3", 16, "NVIDIA GTX1050", 4, "HDD", 2, 2048, 5,
     "Ubuntu"},
    {"Melnikov", 2, "AMD Ryzen 5", 8, "Radeon RX5500", 8, "HDD", 2, 1024, 4,
     "Arch"},
    {"Vasilev", 8, "AMD Ryzen 7", 24, "NVIDIA GTX1650", 6, "SSD", 4, 3072, 3,
     "Windows"},
    {"Alekseev", 2, "Intel I7", 24, "NVIDIA GTX1050", 4, "SSD", 1, 2560, 6,
     "Fedora"},
    {"Popov", 8, "AMD Ryzen 3", 8, "Radeon RX7500", 12, "SSD", 4, 512, 6,
     "Ubuntu"},
    {"Petrov", 10, "Intel I3", 24, "Radeon RX5500", 8, "SSD", 4, 512, 4,
     "Windows"},
    {"Nikolaev", 10, "Intel I3", 16, "Radeon RX450", 4, "HDD", 4, 3584, 6,
     "Fedora"},
    {"Petrov", 2, "Intel I3", 24, "Radeon RX5500", 8, "SSD", 1, 2560, 6,
     "Windows"},
};

const Record TEST2[] = {{"Volkov", 10, "Intel I7", 16, "NVIDIA GTX1650", 6,
                         "SSD", 4, 2048, 5, "Fedora"},
                        {"Petrov", 2, "Intel I5", 8, "Intel HD Gra...", 6,
                         "SSD", 3, 1024, 2, "Monjaro"},
                        {"Karpov", 6, "Intel I5", 16, "NVIDIA RTX2090", 14,
                         "HDD", 3, 3584, 5, "Windows"},
                        {"Sidorov", 8, "Intel I3", 8, "Radeon RX7500", 6, "HDD",
                         4, 512, 5, "Monjaro"},
                        {"Pavlov", 6, "Intel I7", 16, "Radeon RX5500", 12,
                         "HDD", 2, 1024, 5, "Fedora"},
                        {"Alekseev", 6, "Intel I5", 16, "Radeon RX450", 6,
                         "SSD", 3, 2560, 3, "Fedora"},
                        {"Ivanov", 8, "Intel I5", 8, "Intel HD Gra...", 4,
                         "HDD", 1, 3584, 2, "TempleOS"},
                        {"Karpov", 4, "Intel I5", 8, "Radeon RX7500", 4, "SSD",
                         2, 3584, 4, "Windows"}};

const Record TEST3[] = {{"Alekseev", 8, "AMD Ryzen 3", 8, "NVIDIA GTX1650", 2,
                         "SSD", 3, 1024, 5, "Arch"},
                        {"Karpov", 10, "AMD Ryzen 7", 24, "Radeon RX5500", 12,
                         "HDD", 4, 512, 4, "Fedora"},
                        {"Sokolov", 4, "AMD Ryzen 3", 16, "Radeon RX450", 8,
                         "SSD", 4, 1536, 2, "Ubuntu"},
                        {"Popov", 4, "Intel I5", 8, "NVIDIA RTX2090", 12, "HDD",
                         4, 1536, 4, "Fedora"},
                        {
                            "Sokolov",
                            2,
                            "Intel I3",
                            8,
                            "NVIDIA RTX2090",
                            10,
                            "HDD",
                            3,
                            3072,
                            5,
                            "Ubuntu",
                        },
                        {"Morozov", 10, "Intel I7", 24, "Radeon RX450", 8,
                         "SSD", 2, 2560, 6, "Windows"},
                        {"Ivanov", 6, "Intel I5", 8, "NVIDIA RTX3060", 6, "SSD",
                         2, 2048, 6, "Fedora"},
                        {"Kozlov", 4, "Intel I5", 8, "Radeon RX5500", 12, "SSD",
                         4, 2048, 3, "TempleOS"}};
