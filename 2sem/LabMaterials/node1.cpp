#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void print(Node *ptn)
{
    while (ptn != NULL)
    {
        cout << ptn->data << endl;
        ptn = ptn -> next;
    }
};

int pop(Node *head, int n) {
    int res = 0;
    Node *ptn = head;
    for (int i = 0; i < n-1; i++) {
        if (ptn->next == NULL) {
            throw -1;
        }
        ptn = ptn->next;
    }
    if (ptn->next == NULL) {
        throw -1;
    } else {
        res = ptn -> next -> data;
        delete ptn->next;
        return res;
    }
}

int main() {
    Node* head1 = new Node;
    head1->data = 0;
    head1->next = NULL;

    Node* ptn = head1;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        ptn->next = new Node;
        ptn = ptn->next;
        ptn->data = i * i;
        ptn->next = NULL;
    }

    Node* head2 = NULL;
    Node* temp = NULL;
    head2 = new Node;
    head2->data = 0;
    head2->next = NULL;

    for (int i = 1; i < n; i++) {
        temp = new Node;
        temp->data = i * i;
        temp->next = head2;
        head2 = temp;
    }

    cout<<"first"<<endl;
    print(head1);
    pop(head1, n-2);

    cout<<"pop"<<endl;
    print(head1);
    cout<<"second"<<endl;
    print(head2);

    while (head1 != NULL) {
        ptn = head1->next;
        delete head1;
        head1 = ptn;
    }

    while (head2 != NULL) {
        temp = head2->next;
        delete head2;
        head2 = temp;
    }


    return 0;
}