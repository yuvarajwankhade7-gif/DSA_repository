#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int vertices;
    vector<int> adj[20];

public:
    Graph(int v)
    {
        vertices = v;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start)
    {
        bool visited[20] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int next : adj[current])
            {
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
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
