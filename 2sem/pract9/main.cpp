#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Record {
  int key;
  string data;
};

int binarySearch(Record table[], string data, int n) {
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (table[m].data[0] == data[0]) {
      return m;
    }
    if (table[m].data[0] >= data[0]) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

void print(Record table[], int n) {
  cout << left << "|" << setw(5) << "Key" << "|" << setw(20) << "Data" << "|"
       << endl;
  cout << "|-----|--------------------|" << endl;
  for (int i = 0; i < n; ++i) {
    cout << left << "|" << setw(5) << table[i].key << "|" << setw(20)
         << table[i].data << "|" << endl;
  }
  cout << "|-----|--------------------|" << endl;
}

void swap(Record* a, Record* b) {
  Record t = *a;
  *a = *b;
  *b = t;
}

int partition(Record arr[], int low, int high) {
  char pivot = arr[(low + high) / 2].data[0];
  int i = low;
  int j = high;

  while (1) {  // я понимаю это опасно, но без этого не работает
    while (arr[i].data[0] < pivot) i++;
    while (arr[j].data[0] > pivot) j--;
    if (i >= j) return j;
    swap(arr[i++], arr[j--]);
  }
}

void quickSort(Record table[], int low,
               int high) {  // low & high - нижняя и верхняя границы массива
  if (low < high) {
    int pi = partition(table, low, high);  //

    quickSort(table, low, pi);
    quickSort(table, pi + 1, high);
  }
}

const string TEXT[] = {"This is simple task", "Python is fun",
                       "I love to code",      "The weather is nice",
                       "I'm going home",      "She sings well",
                       "He plays guitar",     "The book is good",
                       "We're having fun",    "She's a great cook"};

int main() {
  const int n = 10;
  Record recs[n];
  for (int i = 0; i < n; ++i) {
    recs[i] = {i, TEXT[i]};
  }

  print(recs, n);
  cout << endl;
  quickSort(recs, 0, n - 1);
  print(recs, n);
  string m;
  while (m != ":wq") {
    getline(cin, m);
    int index = binarySearch(recs, m, n);
    if (index < 0) {
      cout << "Not found" << endl;
    } else {
      cout << endl
           << left << "|" << setw(5) << recs[index].key << "|" << setw(20)
           << recs[index].data << "|" << endl;
    }
  }
}