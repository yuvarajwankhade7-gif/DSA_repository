#include <iostream>
using namespace std;

class Graph
{
    int vertices, adj[20][20];

public:
    Graph()
    {
        vertices = 0;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
                adj[i][j] = 0;
        }
    }

    void createGraph()
    {
        int edges, source, destination;

        cout << "Enter number of vertices: ";
        cin >> vertices;

        cout << "Enter number of edges: ";
        cin >> edges;

        for (int i = 0; i < edges; i++)
        {
            cout << "Enter edge (source destination): ";
            cin >> source >> destination;

            if (source >= 0 && destination >= 0 &&
                source < vertices && destination < vertices)
            {
                adj[source][destination] = 1;
                adj[destination][source] = 1;
            }
            else
                cout << "Invalid vertex number.\n";
        }

        cout << "Graph created successfully.\n";
    }

    void displayMatrix()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }

    void DFS(int startVertex)
    {
        if (vertices == 0)
        {
            cout << "Graph is not created.\n";
            return;
        }

        if (startVertex < 0 || startVertex >= vertices)
        {
            cout << "Invalid starting vertex.\n";
            return;
        }

        int visited[20] = {0};
        int stack[20];
        int top = -1;

        stack[++top] = startVertex;

        cout << "\nDFS Traversal: ";

        while (top != -1)
        {
            int current = stack[top--];

            if (!visited[current])
            {
                cout << current << " ";
                visited[current] = 1;

                for (int i = vertices - 1; i >= 0; i--)
                {
                    if (adj[current][i] == 1 && !visited[i])
                        stack[++top] = i;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g;

    g.createGraph();
    g.displayMatrix();

    int start;
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;

    g.DFS(start);

    return 0;
}
