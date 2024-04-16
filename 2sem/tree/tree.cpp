#include <iostream>
#include <vector>

using namespace std;


class Node {
    Node* children[32];

    public:
     void print() {
        cout << sizeof(children) << endl;
    }
};


class Tree {
    int root;

};


int main() {
    Node* n = new Node();
    n->print();
}