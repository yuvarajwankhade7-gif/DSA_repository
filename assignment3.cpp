#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void createList()
    {
        int n, value;

        if (head != NULL)
        {
            cout << "\nList already created.\n";
            return;
        }

        cout << "\nEnter number of nodes: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "\nInvalid number of nodes.\n";
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> value;

            Node *newNode = new Node;
            newNode->data = value;
            newNode->next = NULL;

            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newNode;
            }
        }

        cout << "\nLinked List Created Successfully.\n";
    }

    void insertEnd(int value)
    {
        if (head == NULL)
        {
            cout << "\nCreate the Linked List first.\n";
            return;
        }

        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "\nNode Inserted Successfully.\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\nLinked List: ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "\nLinked List is Empty.\n";
            return;
        }

        Node *temp = head;
        Node *previous = NULL;

        if (head->data == value)
        {
            head = head->next;
            delete temp;
            cout << "\nNode Deleted Successfully.\n";
            return;
        }

        while (temp != NULL && temp->data != value)
        {
            previous = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "\nValue not found.\n";
            return;
        }

        previous->next = temp->next;
        delete temp;

        cout << "\nNode Deleted Successfully.\n";
    }
};

int main()
{
    LinkedList L;
    int choice, value;

    do
    {
        cout << "\n\n========== LINKED LIST MENU ==========";
        cout << "\n1. Create Linked List";
        cout << "\n2. Display Linked List";
        cout << "\n3. Insert at End";
        cout << "\n4. Delete Node";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            L.createList();
            break;

        case 2:
            L.display();
            break;

        case 3:
            cout << "\nEnter value to insert: ";
            cin >> value;
            L.insertEnd(value);
            break;

        case 4:
            cout << "\nEnter value to delete: ";
            cin >> value;
            L.deleteNode(value);
            break;

        case 5:
            cout << "\nProgram Ended.\n";
            break;

        default:
            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
