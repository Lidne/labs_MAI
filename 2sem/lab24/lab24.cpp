#include <iostream>

using namespace std;

class Node {
  Node *left;
  Node *right;

 public:
  string d;  // original string
  string s;  // atomic symbol of this node

  Node *getLeft() { return this->left; }

  Node *getRight() { return this->right; }

  void setLeft(Node *n) { this->left = n; }

  void setRight(Node *n) { this->right = n; }

  void print() { cout << d; }

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
  void print(const string &prefix, Node *node, bool isLeft) {
    if (node != nullptr) {
      cout << prefix;
      cout << "L__";
      cout << node->d << endl;

      print(prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
      print(prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
    }
  }

  void print(Node *node) { print("", node, false); }

  void print() { print("", this->root, false); }

  Node *deleteNode(Node *root, string d) {
    // пустой указатель или лист не с нужным значением
    if (root == nullptr || (root->getLeft() == nullptr &&
                            root->getRight() == nullptr && root->d != d))
      return nullptr;

    // если у узла один ребенок
    if (root->getLeft() == nullptr && root->getRight() != nullptr) {
      if (root->getRight()->d == d) {
        delete root->getRight();
        root->setRight(nullptr);
        root->d = "1";
        return new Node(d);
      }
      return deleteNode(root->getRight(), d);
    }
    if (root->getLeft() != nullptr && root->getRight() == nullptr) {
      if (root->getLeft()->d == d) {
        delete root->getLeft();
        root->setLeft(nullptr);
        root->d = "1";
        return new Node(d);
      }
      return deleteNode(root->getLeft(), d);
    }

    // удаление листа через родителя (левая ветвь)
    if (root->getLeft() != nullptr && root->getLeft()->getLeft() == nullptr &&
        root->getLeft()->getRight() == nullptr && root->getLeft()->d == d) {
      delete root->getLeft();
      root->setLeft(nullptr);
      // правая ветвь
      if (root->getRight() != nullptr &&
          root->getRight()->getLeft() == nullptr &&
          root->getRight()->getRight() == nullptr && root->getRight()->d == d) {
        delete root->getRight();
        root->setRight(nullptr);
      }
      return new Node(d);
    }

    // удаление листа через родителя (правая ветвь)
    if (root->getRight() != nullptr && root->getRight()->getLeft() == nullptr &&
        root->getRight()->getRight() == nullptr && root->getRight()->d == d) {
      delete root->getRight();
      root->setRight(nullptr);
      // левая ветвь
      if (root->getLeft() != nullptr && root->getLeft()->getLeft() == nullptr &&
          root->getLeft()->getRight() == nullptr && root->getLeft()->d == d) {
        delete root->getLeft();
        root->setLeft(nullptr);
      }
      return new Node(d);
    }
    
    // рекурсивное удаление
    Node *left = deleteNode(root->getLeft(), d);
    if (left != nullptr) return left;

    Node *right = deleteNode(root->getRight(), d);
    if (right != nullptr) return right;

    return nullptr;
  }

  Node *deleteNode(string d) { return deleteNode(this->root, d); }

  void symPrint(Node *node) { // вывод в строку
    if (node == nullptr) return;
    symPrint(node->getLeft());
    if (node->getLeft() == nullptr && node->getRight() == nullptr)
      node->print();
    symPrint(node->getRight());
  }

  void symPrint() { symPrint(this->root); }

  void insertSymb(Node *node) { // вставка узла
    if (node->d.length() <= 1) return;
    Node *l = new Node(node->d.substr(0, 1));
    Node *r = new Node(node->d.substr(1, 100));
    node->setLeft(l);
    insertSymb(l);
    node->setRight(r);
    insertSymb(r);
  }

  void parseEq() { // парсинг выражения
    if (this->root->d.empty()) {
      cout << "empty string" << endl;
      return;
    }
    string l = "", r = "";
    bool flag = false;
    // разбивка на 2 части (до + и после)
    for (int i = 0; i < this->root->d.length(); ++i) {
      if (this->root->d[i] == '+')
        flag = true;
      else if (flag)
        r += this->root->d[i];
      else
        l += this->root->d[i];
    }
    // cout << l << ' ' << r << endl;
    Node *left = new Node(l);
    this->root->setLeft(left);
    insertSymb(left);
    Node *right = new Node(r);
    this->root->setRight(right);
    insertSymb(right);
  }

  string commonFactors(Node *root, string res) {
    if (root == nullptr) return "";
    if (root->getLeft() == nullptr && root->getRight() == nullptr) {
      Node *node = deleteNode(this->root->getRight(), root->d);
      // cout << node->d << endl;
      if (node != nullptr) {
        string s = root->d;
        deleteNode(this->root->getLeft(), root->d);
        return res + s;
      }
      return "";
    }

    return commonFactors(root->getLeft(), res) +
           commonFactors(root->getRight(), res);
  }

  void commonFactors() { // нахождение общих множителей
    if (this->root->getLeft() == nullptr && this->root->getRight() == nullptr) {
      cout << this->root->d;
      return;
    }
    // слева от корня лист
    bool l = (this->root->getLeft()->getLeft() == nullptr &&
              this->root->getLeft()->getRight() == nullptr);
    // справа от корня лист
    bool r = (this->root->getRight()->getLeft() == nullptr &&
              this->root->getRight()->getRight() == nullptr);
    string s = "";
    if (l || r) {
      if (this->root->getLeft()->d == this->root->getRight()->d) { // если у корня 2 одинаковых ребенка
        s = "2(" + this->root->getLeft()->d + ")\n";
        cout << s;
        delete this->root->getLeft();
        delete this->root->getRight();
        this->root->setLeft(nullptr);
        this->root->setRight(nullptr);
        this->root->d = s;
        return;
      }
      if (l) { // удаление если слева лист
        Node *node =
            deleteNode(this->root->getRight(), this->root->getLeft()->d);
        if (node != nullptr) {
          s += node->d;
          this->root->getLeft()->d = "1";
        }
      }
      if (r) { // удаление если справа лист
        Node *node =
            deleteNode(this->root->getLeft(), this->root->getRight()->d);
        if (node != nullptr) {
          s += node->d;
          this->root->getRight()->d = "1";
        }
      }

    } else // выборка если все нормально
      s = commonFactors(this->root->getLeft(), "");
    cout << "result: " << s << "(";
    symPrint(this->root->getLeft());
    cout << " + ";
    symPrint(this->root->getRight());
    cout << ")\n";
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
  string inp = "";
  cin >> inp;
  GrammTree *tree = new GrammTree(inp);
  // GrammTree *tree = new GrammTree("2xx+x");
  tree->print();
  tree->commonFactors();
  tree->print();
}