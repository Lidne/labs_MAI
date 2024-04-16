#include <iostream>

using namespace std;

struct Point
{
    float x;
    float y;
};

Point operator+(Point p1, Point p2)
{
    Point res;
    res.x = p1.x + p2.x;
    res.y = p1.y + p2.y;
    return res;
}

struct Stack
{
    int length;
    int *data;
    int top;
};

bool isEmptyStack(const Stack &s)
{
    return (s.top == -1);
}

void newStack(Stack &s, int l)
{
    if (l < 0)
        throw -1;
    s.length = l;
    s.top = -1;
    if (!l)
        s.data = NULL;
    else
        s.data = new int[l];
}

Stack newStack(int l)
{
    if (l < 0)
        throw -1;
    Stack res;
    res.length = l;
    res.top = -1;
    if (!l)
        res.data = NULL;
    else
        res.data = new int[l];
    return res;
}

void deleteStack(Stack &s)
{
    if (s.length == 0)
        return;
    s.length = 0;
    delete[] s.data;
    s.data = NULL;
    s.top = -1;
}

void copyStack(Stack &sd, Stack ss)
{
    if (ss.top < sd.length)
    {
        for (int i = 0; i <= ss.top; ++i)
        {
            sd.data[i] = ss.data[i];
        }
        sd.top = ss.top;
    }
    else
    {
        deleteStack(sd);
        sd = newStack(ss.length);
    }
}

void resizeStack(Stack &s)
{
    Stack tempS = newStack(s.length + 10);
    copyStack(tempS, s);
    deleteStack(s);
    s = tempS;
}

void pushStack(Stack &s, int e)
{
    s.top++;
    if ((s.length == 0) || (s.top == s.length))
        resizeStack(s);
    s.data[s.top] = e;
}

int pullStack(Stack &s)
{
    if (isEmptyStack(s))
        throw -1;
    int tmp = s.data[s.top];
    s.top--;
    return tmp;
}

int topStack(Stack s)
{
    if (isEmptyStack(s))
        throw -1;
    return s.data[s.top];
}

void printStack(Stack s)
{
    if (s.length == 0) cout << "Список пустой" << endl;
    for (int i = s.length - 1; i >= 0; --i)
    {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack stack = newStack(10);
    Stack stack2 = newStack(10);
    for (int i=0;i<stack.length;++i)
    {
        pushStack(stack, i);
    }
    // printStack(stack);
    // printStack(stack2);


    for (int i=0; i<stack.length;i++) {
        int tmp = pullStack(stack);
        // cout << "top: " << stack.top << endl;
        cout << tmp << endl;
        pushStack(stack2, tmp);
    }
    copyStack(stack, stack2);
    printStack(stack);
}