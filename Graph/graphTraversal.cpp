#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph {
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
        if(direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void bfs(int src, unordered_map<int, bool>& visited1) {
        queue<int> q;

        q.push(src);
        visited1[src] = true;

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            // insert neighbours
            for(auto neighbour: adjList[frontNode]) {
                if(!visited1[neighbour]) {
                    q.push(neighbour);
                    visited1[neighbour] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool>& visited2) {
        cout << src << " ";
        visited2[src] = true;
        for(auto neighbour: adjList[src]) {
            if(!visited2[neighbour]) {
                dfs(neighbour, visited2);
            }
        }
    }
};
int main() {
    Graph g;

    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 4, 0);

    cout << "Printing BFS Traversal" << endl;
    unordered_map<int, bool> visited1;
    g.bfs(0, visited1);

    cout << endl;
    cout << "Printing DFS Traversal" << endl;
    unordered_map<int, bool> visited2;
    g.dfs(0, visited2);
}