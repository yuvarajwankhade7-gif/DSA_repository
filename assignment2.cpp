#include <iostream>
using namespace std;

class Queue
{
private:
    int queue[5];
    int size;
    int front;
    int rear;

public:
    Queue()
    {
        size = 5;
        front = -1;
        rear = -1;
    }

    void insert(int value)
    {
        if (rear == size - 1)
        {
            cout << "\nQueue is Full.\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;
        cout << "\nElement Inserted Successfully.\n";
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty.\n";
            return;
        }

        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue obj;
    int value;

    cout << "Enter 1st element: ";
    cin >> value;
    obj.insert(value);

    cout << "Enter 2nd element: ";
    cin >> value;
    obj.insert(value);

    cout << "Enter 3rd element: ";
    cin >> value;
    obj.insert(value);

    cout << "Enter 4th element: ";
    cin >> value;
    obj.insert(value);

    cout << "Enter 5th element: ";
    cin >> value;
    obj.insert(value);

    obj.display();

    return 0;
}
