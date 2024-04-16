#!/bin/bash

# Завершает программу если не указано нужное количество аргументов
if [ $# -lt 2 ]; then
    echo "Usage: <script> <in> <n>"
    exit 1
fi

in=$1
size=$2
in_size=$(wc -c $in | awk '{print $1}')
let "n=$size/$in_size"
out="concatenated_file.txt"

# Проверяет существует ли файл
if [ ! -f $in ]; then
    echo "Input file does not exist!"
    exit 1
fi

# Выполняем конкатенацию файла
for ((i=1; i<=$n; i++)); do
    cat $in >> $out
done

echo ""
echo "Выполнил конкатенацию $in $n раз.
Результат записан в $out"
