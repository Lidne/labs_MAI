#!/bin/bash
# Usage: lab21.sh <in> <n> <size>
in=$1
n=$2
size=$3
in_size=$( stat -f "%z" $in)
let "n2=$size/$in_size"
if (($n2 > $n))
then
    nn=$n
else
    nn=$n2
fi
out="concatenated_file.txt"

# Проверяет существует ли файл
if [ ! -f $in ]; then
    echo "Input file does not exist!"
    exit 1
fi

# Выполняем конкатенацию файла
for ((i=1; i<=$nn; i++)); do
    cat $in >> $out
done

echo ""
echo "Выполнил конкатенацию $in $nn раз.
Результат записан в $out"
