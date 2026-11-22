#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node*& root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
        return;
    }

    if (value < root->data)
        insert(root->left, value);
    else if (value > root->data)
        insert(root->right, value);
}

void levelOrder(Node* root)
{
    if (root == NULL)
    {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        while (count--)
        {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }

        cout << endl;
    }
}

int height(Node* root)
{
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void printLeafNodes(Node* root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

Node* copyTree(Node* root)
{
    if (root == NULL)
        return NULL;

    Node* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

int main()
{
    Node* root = NULL;
    Node* newTree = NULL;

    int n, id;

    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Employee ID: ";
        cin >> id;

        insert(root, id);
    }

    cout << "\nOriginal Employee BST (Level Wise):\n";
    levelOrder(root);

    newTree = copyTree(root);

    cout << "\nNew Employee BST (Level Wise):\n";
    levelOrder(newTree);

    cout << "\nHeight of BST: " << height(root);

    cout << "\nLeaf Employee IDs: ";
    printLeafNodes(root);

    cout << endl;

    return 0;
}
