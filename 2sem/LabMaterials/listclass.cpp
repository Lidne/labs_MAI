#include <iostream>

using namespace std;

class Node {
    Node *next;
    void initN(int d, Node *n = NULL);
    void deleteN();

   public:
    int data;

    void printNode() {
        cout << this << " ";
        cout << data << " ";
        cout << next << endl;
    }

    bool hasNext() {
        return next != NULL;
    }

    void setNext(Node *node) {
        next = node;
    }

    Node *getNext() {
        return next;
    }

    Node() {
        cout << "defcon\n";  // default constructor
        data = 0;
        next = NULL;
        printNode();
    }

    Node(int d) {
        cout << "paramcon\n";
        data = d;
        next = NULL;
        printNode();
    }

    Node(Node &n) {
        cout << "copycon\n";
        data = n.data;
        next = NULL;
        printNode();
    }

    ~Node() {
        deleteN();
        cout << "destr\n";
        cout << this << endl;
    }
};

void Node::initN(int d, Node *n) {
    data = d;
    this->next = next;
}

void Node::deleteN() {
    data = 0;
    next = NULL;
}

class LinkedList {
    Node *head;

   public:
    // bool isEmptyList(Node *head);
    // void printNode(Node *ptn);
    // void printList(Node *head);
    // void AppEnd(Node *&head, int val);
    // void AppBeg(Node *&head, int val);
    // void AppEnd(Node *&head, Node* n);
    // void AppBeg(Node *&head, Node* n);
    // void deleteList(Node *&head);
    // Node *findNode(Node *head, int val);
    // Node *findPrev(Node *head, Node *ptn);
    // Node *findNext(Node *head, Node *ptn);
    // void insertNext(Node *ptn, int val);
    // void insertNext(Node *ptn, Node *newList);

    bool isEmptyList(Node *head) {
        return head->hasNext() == NULL;
    }

    // эта функция была на доске, но она в целом бесполезна
    void printNode(Node *ptn) {
        ptn->printNode();
    }

    void printNode(unsigned int index) {
        unsigned int i = 0;
        Node *ptn = this->head;
        while (ptn->hasNext() and i < index) {
            ptn = ptn->getNext();
            i++;
        }
        ptn->getNext()->printNode();
    }

    void printList(Node *head) {
        Node *ptn = head;
        while (ptn->hasNext()) {
            ptn->printNode();
            ptn = ptn->getNext();
        }
    }

    void printList() {
        Node *ptn = this->head;
        while (ptn->hasNext()) {
            ptn->printNode();
            ptn = ptn->getNext();
        }
        ptn->printNode();
    }

    void AppEnd(Node *head, int val) {
        Node *ptn = head;
        while (ptn->hasNext()) {
            ptn = ptn->getNext();
        }
        Node *tail = new Node(val);
        ptn->setNext(tail);
    }

    void AppEnd(Node *head, Node *n) {
        Node *ptn = head;
        cout << ptn->getNext() << endl;
        while (ptn->hasNext()) {
            ptn = ptn->getNext();
        }
        ptn->setNext(n);
    }

    void AppEnd(int val) {
        Node *ptn = this->head;
        while (ptn->hasNext()) {
            ptn = ptn->getNext();
        }
        Node *tail = new Node(val);
        ptn->setNext(tail);
    }

    void AppEnd(Node *n) {
        Node *ptn = this->head;

        while (ptn->hasNext()) {
            ptn = ptn->getNext();
        }
        ptn->setNext(n);
    }

    void deleteList(Node *&head) {
        Node *ptn = head, *tmp = NULL;
        while (ptn->hasNext()) {
            tmp = ptn->getNext();
            delete ptn;
            ptn = tmp;
        }
    }

    void deleteList() {
        Node *ptn = this->head, *tmp = NULL;
        while (ptn->hasNext()) {
            tmp = ptn->getNext();
            delete ptn;
            ptn = tmp;
        }
        ptn = NULL;
        tmp = NULL;
    }

    Node *findNode(Node *head, int val) {
        Node *ptn = head;
        while (ptn->hasNext()) {
            if (ptn->data == val) {
                return ptn;
            }
            ptn = ptn->getNext();
        }
        return NULL;
    }

    Node *findNode(int val) {
        Node *ptn = this->head;
        while (ptn->hasNext()) {
            if (ptn->data == val) {
                return ptn;
            }
            ptn = ptn->getNext();
        }
        return NULL;
    }

    Node *findPrev(Node *head, Node *n) {
    }

    void insertNext(Node *ptn, int val) {
        Node *next = ptn->getNext();
        Node *new_next = new Node(val);
        new_next->setNext(next);
        ptn->setNext(new_next);
    }

    void insertNext(Node *ptn, Node *head) {
        Node *next = ptn->getNext();
        Node *tail = head;
        while (tail->hasNext()) {
            tail = tail->getNext();
        }
        tail->setNext(next);
        ptn->setNext(head);
    }

    LinkedList() {
        cout << "deflistcon" << endl;
        this->head = NULL;
    }

    LinkedList(Node *head) {
        cout << "headcon" << endl;
        this->head = head;
    }

    ~LinkedList() {
        deleteList();
    }
};

int main() {
    Node *head = new Node(10);
    Node *n1 = new Node(11);
    Node *n2 = new Node(12);
    Node *n3 = new Node(13);
    Node *n4 = new Node(14);
    Node *n2_1 = new Node(121);
    LinkedList list = LinkedList(head);

    list.AppEnd(n1);
    list.AppEnd(n2);
    list.AppEnd(n3);
    list.AppEnd(n4);
    list.printList();
    cout << endl;
    list.insertNext(n2, 121);
    list.printList();
}