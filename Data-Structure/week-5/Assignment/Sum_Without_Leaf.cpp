#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// takes input
Node *take_input()
{
    int value;
    cin >> value;
    Node *root;
    if (value == -1)
        root = NULL;
    else
        root = new Node(value);
    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        // First Step
        Node *pt = q.front();
        q.pop();

        // Second Step
        int l, r;
        cin >> l >> r;
        Node *newLeft;
        Node *newRight;
        if (l == -1)
            newLeft = NULL;
        else
            newLeft = new Node(l);
        if (r == -1)
            newRight = NULL;
        else
            newRight = new Node(r);

        pt->left = newLeft;
        pt->right = newRight;

        // Final Step
        if (pt->left)
            q.push(pt->left);
        if (pt->right)
            q.push(pt->right);
    }
    return root;
}

int sumNode(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 0;
    }
    int l = sumNode(root->left);
    int r = sumNode(root->right);

    return l + r + root->value;
}

int main()
{
    Node *root = take_input();
    cout << sumNode(root) << endl;

    return 0;
}