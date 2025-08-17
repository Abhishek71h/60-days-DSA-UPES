#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;
class Graph {
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void printadjList() {
        for(auto node: adjList) {
            cout << node.first << " -> ";
            for(auto neighbour: node.second) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    void topologicalSortDFS(int src, unordered_map<int, bool>& visited, stack<int>&ans) {
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                topologicalSortDFS(neighbour, visited, ans);
            }
        }
        // while returning from the loop, store the src node into stack
        ans.push(src);
    }
};

int main() {
    Graph g;

    int n = 8;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,6);
    g.addEdge(5,6);
    g.addEdge(6,7);
    cout << endl;
    g.printadjList();
    cout << endl;

    unordered_map<int, bool> visited;
    stack<int>ans;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            g.topologicalSortDFS(i, visited, ans);
        }
    }

    cout << "Printing Topological Sort Using DFS" << endl;
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}