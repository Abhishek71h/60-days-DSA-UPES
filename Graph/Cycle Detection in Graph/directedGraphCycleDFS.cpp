/* Detecting cycle in the undirected Graph by the help of DFS Traversal
0 -- 1 -- 3
|
2 -- 4
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

    bool checkCyclicDirectedGraphUsingDfs(int src, int parent, unordered_map<int,bool>& visited, unordered_map<int, bool>& dfsVisited) {
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto nbr: adjList[src]) {
            if(!visited[nbr]) {
                bool checkNextAns = checkCyclicDirectedGraphUsingDfs(nbr, src, visited, dfsVisited);
                if(checkNextAns == true) return true;
            }
            else if(visited[nbr] == true && dfsVisited[nbr] == true) {
                return true;
            }
        }
        // Backtrack
        dfsVisited[src] = false;
        return false;
    }
};

int main() {
    Graph g;

    int n = 5;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,0,1);

    cout << endl;
    g.printAdjacencyList();
    cout<<endl;

    bool ans = false;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            int parent = -1;
            ans = g.checkCyclicDirectedGraphUsingDfs(i, -1, visited, dfsVisited);
            if(ans == true) break;
        }
    }
    if(ans == true) cout << "Cycle is Present" << endl;
    if(ans == false) cout << "Cycle is Absent" << endl;

    return 0;
}