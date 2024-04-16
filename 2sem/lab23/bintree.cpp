#include <iostream>

using namespace std;

class Node {
    Node *left;
    Node *right;

   public:
    float d;

    Node *getLeft() {
        return this->left;
    }

    Node *getRight() {
        return this->right;
    }

    void setLeft(Node *n) {
        this->left = n;
    }

    void setRight(Node *n) {
        this->right = n;
    }

    void print() {
        cout << d << endl;
    }

    Node() {
        this->d = 0.0f;
        this->left = NULL;
        this->right = NULL;
    }

    Node(float d) {
        this->d = d;
        this->left = NULL;
        this->right = NULL;
    }

    Node(float d, Node *left, Node *right) {
        this->d = d;
        this->left = left;
        this->right = right;
    }

    Node(Node *left, Node *right) {
        this->d = 0.0f;
        this->left = left;
        this->right = right;
    }
};

class BinTree {
    Node *root;

   public:
    void insert(Node *root, Node *node) {
        if (root->d <= node->d) {
            if (root->getRight() == nullptr) {
                root->setRight(node);
            } else {
                this->insert(root->getRight(), node);
            }
        }
        if (root->d > node->d) {
            if (root->getLeft() == nullptr) {
                root->setLeft(node);
            } else {
                this->insert(root->getLeft(), node);
            }
        }
    }

    void insert(Node *node) {
        if (this->root->d <= node->d) {
            if (this->root->getRight() == nullptr) {
                this->root->setRight(node);
            } else {
                this->insert(this->root->getRight(), node);
            }
        }
        if (this->root->d > node->d) {
            if (this->root->getLeft() == nullptr) {
                this->root->setLeft(node);
            } else {
                this->insert(this->root->getLeft(), node);
            }
        }
    }

    void insert(float d) {
        Node *node = new Node(d);
        if (this->root->d <= node->d) {
            if (this->root->getRight() == nullptr) {
                this->root->setRight(node);
            } else {
                this->insert(this->root->getRight(), node);
            }
        }
        if (this->root->d > node->d) {
            if (this->root->getLeft() == nullptr) {
                this->root->setLeft(node);
            } else {
                this->insert(this->root->getLeft(), node);
            }
        }
    }

    void print(const string &prefix, Node *node, bool isLeft) {
        if (node != nullptr) {
            cout << prefix;
            cout << "└──";
            cout << node->d << endl;

            print(prefix + (isLeft ? "│   " : "    "), node->getLeft(), true);
            print(prefix + (isLeft ? "│   " : "    "), node->getRight(), false);
        }
    }

    void print(Node *node) {
        print("", node, false);
    }

    void print() {
        print("", this->root, false);
    }

    Node *find(Node *node, float d) {
        if (node == nullptr) return nullptr;
        if (node->d == d) return node;
        return find((node->d > d ? node->getLeft() : node->getRight()), d);
    }

    Node *find(float d) {
        return find(this->root, d);
    }

    Node *findPrev(Node *node, float d) {
        if (node == nullptr) return nullptr;
        if (node->d == d || node->getLeft() && node->getLeft()->d == d || node->getRight() && node->getRight()->d == d) return node;
        return findPrev((node->d > d ? node->getLeft() : node->getRight()), d);
    }

    Node *findPrev(float d) {
        return findPrev(this->root, d);
    }

    Node *getMin(Node *node) {
        if (node == nullptr) return nullptr;
        if (node->getLeft() == nullptr) return node;
        return getMin(node->getLeft());
    }

    Node *getMax(Node *node) {
        if (node == nullptr) return nullptr;
        if (node->getRight() == nullptr) return node;
        return getMin(node->getRight());
    }

    void deleteNode(Node *head, float d) {
        if (head == nullptr)
            return;
        else if (head->d > d)
            deleteNode(head->getLeft(), d);
        else if (head->d < d)
            deleteNode(head->getRight(), d);
        else {
            if (head->getLeft() == nullptr && head->getRight() == nullptr) {
                Node *prev = this->findPrev(head->d);
                if (prev->getRight() == head) {
                    prev->setRight(nullptr);
                }
                if (prev->getLeft() == head) {
                    prev->setLeft(nullptr);
                }
                delete head;
                head = nullptr;
            } else if (head->getLeft() == nullptr || head->getRight() == nullptr) {
                Node *child;
                if (head->getLeft() == nullptr) {
                    child = head->getRight();
                    head->setRight(nullptr);
                } else {
                    child = head->getLeft();
                    head->setLeft(nullptr);
                }
                *head = *child;
                delete child;
                child = nullptr;
            } else {
                Node *leftMin = getMax(head->getLeft());
                float tmp = leftMin->d;
                deleteNode(head->getLeft(), leftMin->d);
                head->d = tmp;
            }
        }
        // cout << "deleted" << endl;
    }

    void deleteNode(float d) {
        deleteNode(this->root, d);
    }

    void symPrint(Node *node) {
        if (node == nullptr) return;
        symPrint(node->getLeft());
        node->print();
        symPrint(node->getRight());
    }

    void symPrint() {
        symPrint(this->root);
    }

    BinTree(Node *root) {
        this->root = root;
    }

    BinTree(int d) {
        Node *rt = new Node(d);
        this->root = rt;
    }

    bool levelMonotony(Node* node) {
        if (!node->getLeft() && !node->getRight()) return true;
        if ((bool)node->getLeft() != (bool)node->getRight()) return false;
        return levelMonotony(node->getLeft()) && levelMonotony(node->getRight()); 
    }

    bool levelMonotony() {
        return this->levelMonotony(this->root);
    }
};


int main() {
    BinTree tree = BinTree(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8.1f);
    tree.print();
    cout << (tree.levelMonotony() ? "убывание монотонно" : "убывание не монотонно") << endl;
    
    tree.deleteNode(3);
    tree.deleteNode(8.1f);
    tree.print();
    cout << (tree.levelMonotony() ? "убывание монотонно" : "убывание не монотонно") << endl;
}