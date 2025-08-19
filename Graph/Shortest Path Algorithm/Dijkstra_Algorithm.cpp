#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;
class Graph {
    public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int src, int dest, int weight, bool direction) {
        adjList[src].push_back({dest, weight});
        if(direction == 1) {
            adjList[dest].push_back({src, weight});
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

    void shortestDistanceDijkstra(int src, int n) {
        vector<int>dist(n, INT_MAX);
        set<pair<int, int>> st;

        // initial steps
        dist[src] = 0;
        st.insert({0, src});

        while(!st.empty()) {
            // fetch the smallest element from set st
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin());

            // neighbour traverse
            for(auto neighbour: adjList[node]) {
                if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                    // finding entry in set
                    auto result = st.find({dist[neighbour.first], neighbour.first});
                    if(result != st.end()) {
                        st.erase(result);
                    }
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    st.insert({dist[neighbour.first], neighbour.first});
                }   
            }
        }

        cout << "Printing Shortest Path: " << endl;
        for(int i=0; i<n; i++) {
            if(dist[i] == INT_MAX) {
                cout << "INF   -> node " << i << endl;
            } 
            else {
                cout << dist[i] << "   -> node " << i << endl;
            }
        }
    }
};

int main() {
    Graph g;
    int n = 9;
    g.addEdge(6,3,2,1);
    g.addEdge(6,1,14,1);
    g.addEdge(3,1,9,1);
    g.addEdge(3,2,10,1);
    g.addEdge(1,2,7,1);
    g.addEdge(2,4,15,1);
    g.addEdge(4,3,11,1);
    g.addEdge(6,5,9,1);
    g.addEdge(4,5,6,1);
    
    cout << "Printing Adjacency List" << endl;
    g.printAdjacencyList();
    cout << endl;

    int src = 6;
    g.shortestDistanceDijkstra(src, n);
}