#include <iostream>
#include <string>

using namespace std;

class Node {
    Node *left;
    Node *right;

   public:
    string d;  // original string
    string s;  // atomic symbol of this node

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
        this->d = "";
        this->s = "";
        this->left = NULL;
        this->right = NULL;
    }

    Node(string d) {
        this->d = d;
        this->s = "";
        this->left = NULL;
        this->right = NULL;
    }

    Node(string d, Node *left, Node *right) {
        this->d = d;
        this->s = "";
        this->left = left;
        this->right = right;
    }

    Node(Node *left, Node *right) {
        this->d = "";
        this->s = "";
        this->left = left;
        this->right = right;
    }
};

class GrammTree {
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

    void insert(string d) {
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

    Node *find(Node *node, string d) {
        if (node == nullptr) return nullptr;
        if (node->d == d) return node;
        return find((node->d > d ? node->getLeft() : node->getRight()), d);
    }

    Node *find(string d) {
        return find(this->root, d);
    }

    Node *findPrev(Node *node, string d) {
        if (node == nullptr) return nullptr;
        if (node->d == d || node->getLeft() && node->getLeft()->d == d || node->getRight() && node->getRight()->d == d) return node;
        return findPrev((node->d > d ? node->getLeft() : node->getRight()), d);
    }

    Node *findPrev(string d) {
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

    void deleteNode(Node *head, string d) {
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
                string tmp = leftMin->d;
                deleteNode(head->getLeft(), leftMin->d);
                head->d = tmp;
            }
        }
        // cout << "deleted" << endl;
    }

    void deleteNode(string d) {
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

    bool levelMonotony(Node *node) {
        if (!node->getLeft() && !node->getRight()) return true;
        if ((bool)node->getLeft() != (bool)node->getRight()) return false;
        return levelMonotony(node->getLeft()) && levelMonotony(node->getRight());
    }

    bool levelMonotony() {
        return this->levelMonotony(this->root);
    }

    void insertSymb(Node *node) {
        cout << node->d << endl;
        if (node->d.length() <= 1) return;
        Node *l = new Node(node->d.substr(0, 1));
        Node *r = new Node(node->d.substr(1, 100));
        node->setLeft(l);
        insertSymb(l);
        node->setRight(r);
        insertSymb(r);
        cout << node->getLeft() << " " << node->getRight() << endl;
    }

    void parseEq() {
        if (this->root->d.empty()) {
            cout << "empty string" << endl;
            return;
        }
        string l = "", r = "";
        bool flag = false;
        for (int i = 0; i < this->root->d.length(); ++i) {
            if (this->root->d[i] == '+')
                flag = true;
            else if (flag)
                r += this->root->d[i];
            else
                l += this->root->d[i];
        }
        cout << l << ' ' << r << endl;
        Node *left = new Node(l);
        insertSymb(left);
        Node *right = new Node(r);
        insertSymb(right);
    }

    GrammTree(Node *root) {
        this->root = root;
        parseEq();
    }

    GrammTree(string d) {
        Node *rt = new Node(d);
        this->root = rt;
        parseEq();
    }
};


int main() {
    GrammTree *tree = new GrammTree("2ax+7ay");
    tree->print();
}