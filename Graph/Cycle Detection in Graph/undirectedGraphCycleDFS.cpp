/* Detecting cycle in the undirected Graph by the help of DFS Traversal
0 -- 1 -- 3
|
2 -- 4

0 -- 1
|    |
3 -- 2

DFS(0, -1)
  → neighbor 1 not visited → DFS(1, 0)
      → neighbor 2 not visited → DFS(2, 1)
          → neighbor 3 not visited → DFS(3, 2)
              → neighbor 0 visited, but 0 != parent(3 = 2) → return true
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph {
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected Graph
        // direction = 1 -> directed Graph
        adjList[u].push_back(v);
        if(direction == 0) {
            adjList[v].push_back(u);
        }
    }
    // unordered_map<int, list<pair<int, int>>> adjList;

    // void addEdge(int u, int v, int weight, bool direction) {
    //     adjList[u].push_back({v, weight});
    //     if(direction == 0) {
    //         adjList[v].push_back({u, weight});
    //     }
    // }

    void printAdjacencyList() {
        for(auto node: adjList) {
            cout << node.first << " -> ";
            for(auto neighbour: node.second) {
                cout <<neighbour << " ";
            }
            cout << endl;
        }
    }

    bool checkCyclicUsingDfs(int src, int parent, unordered_map<int,bool>& visited) {
        visited[src] = true;

        for(auto neighbour : adjList[src]) {
            if(!visited[neighbour]) {
                if(checkCyclicUsingDfs(neighbour, src, visited)) {
                    return true;
                }
            }
            else if(neighbour != parent) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g;

    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);
    cout << endl;
    g.printAdjacencyList();
    cout<<endl;

    bool ans = false;
    unordered_map<int,bool> visited;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            int parent = -1;
            ans = g.checkCyclicUsingDfs(i, -1, visited);
            if(ans == true) break;
        }
    }
    if(ans == true) cout << "Cycle is Present" << endl;
    if(ans == false) cout << "Cycle is Absent" << endl;

    return 0;
}