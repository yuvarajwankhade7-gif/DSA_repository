#include <iostream>
using namespace std;

class Binary
{
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };

    Node *root;

public:
    Binary()
    {
        root = NULL;
    }

    Node* create()
    {
        int value;

        cout << "Enter node value (-1 for no node): ";
        cin >> value;

        if (value == -1)
            return NULL;

        Node *newNode = new Node;
        newNode->data = value;

        cout << "Enter left child of " << value << ": ";
        newNode->left = create();

        cout << "Enter right child of " << value << ": ";
        newNode->right = create();

        return newNode;
    }

    void build()
    {
        cout << "\nCreate Binary Tree\n";
        root = create();
    }

    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    void inorderdisplay()
    {
        cout << "\nInorder Traversal:\n";
        inorder(root);
    }

    void preorderdisplay()
    {
        cout << "\nPreorder Traversal:\n";
        preorder(root);
    }

    void postorderdisplay()
    {
        cout << "\nPostorder Traversal:\n";
        postorder(root);
    }
};

int main()
{
    Binary b;
    int choice;

    b.build();

    do
    {
        cout << "\n---- Binary Tree Menu ----";
        cout << "\n1. Inorder Traversal";
        cout << "\n2. Preorder Traversal";
        cout << "\n3. Postorder Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.inorderdisplay();
            break;

        case 2:
            b.preorderdisplay();
            break;

        case 3:
            b.postorderdisplay();
            break;

        case 4:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 4);

    return 0;
}
