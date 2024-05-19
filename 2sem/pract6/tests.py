from random import choice, randint

names = [
    "Ivanov",
    "Petrov",
    "Sidorov",
    "Smirnov",
    "Kuznetsov",
    "Popov",
    "Sokolov",
    "Lebedev",
    "Kozlov",
    "Novikov",
    "Morozov",
    "Pavlov",
    "Vasilev",
    "Volkov",
    "Alekseev",
    "Karpov",
    "Melnikov",
    "Nikolaev",
    "Orlov",
    "Bogdanov",
]

cpus = [
    "Intel I5",
    "Intel I3",
    "Intel I7",
    "Intel I5",
    "Intel I3",
    "Intel I7",
    "AMD Ryzen 3",
    "AMD Ryzen 5",
    "AMD Ryzen 7",
]
gpus = [
    "NVIDIA RTX3060",
    "NVIDIA RTX2090",
    "NVIDIA GTX1650",
    "NVIDIA GTX1050",
    "Radeon RX5500",
    "Intel HD Gra...",
    "Radeon RX450",
    "Radeon RX7500",
]

drives = ["SSD", "HDD"]
oses = ["Windows", "Windows", "Windows", "Monjaro", "Arch", "Ubuntu", "Fedora", "TempleOS"]

for i in range(8):
    res = [
        choice(names),
        choice(range(2, 11, 2)),
        choice(cpus),
        choice(range(8, 32, 8)),
        choice(gpus),
        choice(range(2, 16, 2)),
        choice(drives),
        randint(1, 4),
        choice(range(512, 4096, 512)),
        randint(2, 6),
        choice(oses),
    ]
    print(res)
