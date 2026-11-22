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

        cout << "Enter number of roads: ";
        cin >> edges;

        for (int i = 0; i < edges; i++)
        {
            cout << "Enter road (source destination): ";
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

    void DFS(int start)
    {
        int visited[20] = {0};
        int stack[20];
        int top = -1;

        stack[++top] = start;

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
    cout << "\nEnter starting intersection: ";
    cin >> start;

    g.DFS(start);

    return 0;
}
