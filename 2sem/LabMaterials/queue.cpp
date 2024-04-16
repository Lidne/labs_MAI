#include <iostream>
using namespace std;

struct Queue {
    int length;
    int* data;
    int start;
    int depth;
};

bool isEmptyQueue(const Queue & q);
Queue newQueue(int len);
void deleteQueue(Queue & q);
void pushQueue(Queue & q, int k);
void resizeQueue(Queue & q, int dl);
int topQueue(const Queue & q);
void copyQueue(Queue & qd, const Queue & qs);
int pullQueue(Queue & q);

bool isEmptyQueue(const Queue & q) {
    return (q.depth == 0);
}

Queue newQueue(int len) {
    if (len < 0) throw - 1;
    Queue q;
    q.length = len;
    q.data = NULL;
    if (len > 0) q.data = new int [len];
    q.start = 0;
    q.depth = 0;
    return q;
}

void deleteQueue(Queue &q) {
    if (q.length != 0) delete [] q.data;
    q.data = NULL;
    q.depth = 0;
    q.start = 0;
    q.length = 0;
}

void pushQueue(Queue &q, int k) {
    if (q.length == q.depth) resizeQueue(q, 10);
    q.data[(q.start + q.depth) % q.length] = k;
    q.depth++;
}

int topQueue(const Queue &q) {
    if (q.depth == 0) throw -2;
    return q.data[q.start];
}

void resizeQueue(Queue &q, int dl=10) {
    Queue nq = newQueue(q.length + dl);
    copyQueue(nq, q);
    deleteQueue(q);
    q = nq;
}

int pullQueue(Queue &q) {
    if (isEmptyQueue(q)) throw -3;
    int k = q.data[q.start];
    q.depth--;
    q.start = (q.start + 1) % q.length;
    return k;
}

void copyQueue(Queue &qd, const Queue &qs) {
    if (qd.length < qs.length) resizeQueue(qd, qs.length - qd.length);
    for (int i = 0; i < qs.depth; i++) {
        qd.data[i] = qs.data[(qs.start + i) % qs.length];
        qd.start = 0;
        qd.depth = qs.depth;
    }
}

void printQueue(Queue q)
{
    if (q.length == 0) cout << "Очередь пустая " << endl;
    for (int i = q.length - 1; i >= 0; --i)
    {
        cout << q.data[i] << " ";
    }
    cout << endl;
}

// TODO: написать классы (стэк и очередь) с соблюдением трех столпов ООП
// через 
int main() {
    int Qlen = 5;
    Queue myQueue = newQueue(Qlen);
    for (int i = 0; i < Qlen; i++) {
        pushQueue(myQueue, i);
    };
    cout<<topQueue(myQueue);
    printQueue(myQueue);
    return 0;
}
