#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *previous;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->previous = NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int value)
    {
        sz++;
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->previous = tail;
        tail = tail->next;
    }

    void pop()
    {
        sz--;
        Node *deleteNode = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
            delete deleteNode;
            return;
        }
        head->previous = NULL;
        delete deleteNode;
    }

    int front()
    {
        return head->value;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if (sz == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    myQueue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}