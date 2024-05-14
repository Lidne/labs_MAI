#include <iostream>

using namespace std;

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