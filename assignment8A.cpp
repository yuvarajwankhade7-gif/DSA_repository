#include <iostream>
using namespace std;

class Node
{
public:
    int vertex;
    Node *next;

    Node(int v)
    {
        vertex = v;
        next = NULL;
    }
};

class Graph
{
public:
    int vertices;
    Node *adj[20];
    int queue[20], front, rear;
    bool visited[20];

    Graph(int v)
    {
        vertices = v;

        for (int i = 0; i < vertices; i++)
        {
            adj[i] = NULL;
            visited[i] = false;
        }

        front = -1;
        rear = -1;
    }

    void addEdge(int src, int dest)
    {
        Node *newNode = new Node(dest);
        newNode->next = adj[src];
        adj[src] = newNode;

        newNode = new Node(src);
        newNode->next = adj[dest];
        adj[dest] = newNode;
    }

    void enqueue(int vertex)
    {
        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }

        queue[rear] = vertex;
    }

    int dequeue()
    {
        int vertex = queue[front];
        front++;
        return vertex;
    }

    void BFS(int start)
    {
        for (int i = 0; i < vertices; i++)
            visited[i] = false;

        front = -1;
        rear = -1;

        visited[start] = true;
        enqueue(start);

        cout << "BFS Traversal: ";

        while (front <= rear)
        {
            int current = dequeue();
            cout << current << " ";

            Node *temp = adj[current];

            while (temp != NULL)
            {
                int next = temp->vertex;

                if (!visited[next])
                {
                    visited[next] = true;
                    enqueue(next);
                }

                temp = temp->next;
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.BFS(0);

    return 0;
}
