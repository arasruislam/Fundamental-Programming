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

// print normal way value
void print_normal(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// print reverse value
void print_reverse(Node *tail)
{
    Node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->previous;
    }
    cout << endl;
}

// inset at any position
void insert_at_any_position(Node *head, int position, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;

    for (int i = 1; i <= position - 1; i++)
    {
        temp = temp->next;
    }
    // 1st step
    newNode->next = temp->next;
    temp->next = newNode;
    // 2nd step
    newNode->next->previous = newNode;
    newNode->previous = temp;
}

// print size
int size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// insert at head;
void insert_at_head(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->previous = newNode;

    head = newNode;
}

// insert at tail
void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->previous = tail;

    tail = newNode;
}

int main()
{
    // Node *head = NULL;
    // Node *tail = NULL;
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = c;

    // connection nodes
    head->next = a;
    a->previous = head;
    a->next = b;
    b->previous = a;
    b->next = c;
    c->previous = b;

    // takes input
    int position, value;
    cin >> position >> value;

    // apply condition for insert value at any position
    if (position == 0)
    {
        insert_at_head(head, tail, value);
    }
    else if (position == size(head))
    {
        insert_at_tail(head, tail, value);
    }
    else if (position >= size(head))
    {
        cout << "Invalid" << endl;
    }
    else
    {
        // print insert item at any position.
        insert_at_any_position(head, position, value);
    }

    // print left to right
    print_normal(head);
    // print right to left
    print_reverse(tail);

    return 0;
}