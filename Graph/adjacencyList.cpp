#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
class Graph {
    public:
    // unordered_map<int, list<int>> adjList;

    // void addEdge(int u, int v, bool direction) {
    //     // direction = 0 -> undirected Graph
    //     // direction = 1 -> directed Graph
    //     adjList[u].push_back(v);
    //     if(direction == 0) {
    //         adjList[v].push_back(u);
    //     }
    // }
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction) {
        adjList[u].push_back({v, weight});
        if(direction == 0) {
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjacencyList() {
        for(auto node: adjList) {
            cout << node.first << " -> ";
            for(auto neighbour: node.second) {
                cout <<"(" << neighbour.first << "," << neighbour.second << ")";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph g;

    g.addEdge(0,1,5,1);
    g.addEdge(1,2,8,1);
    g.addEdge(0,2,6,1);
    cout << endl;
    g.printAdjacencyList();
}