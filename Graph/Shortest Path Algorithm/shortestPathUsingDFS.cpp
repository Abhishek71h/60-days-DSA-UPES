// It is a directed Graph
#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;
class Graph {
    public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int src, int dest, int weight, bool direction) {
        adjList[src].push_back({dest, weight});
        if(direction == 0) {
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

    void topologicalSortUsingDFS(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
        visited[src] = true;
        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour.first]) {
                topologicalSortUsingDFS(neighbour.first, visited, ans);
            }
        }
        ans.push(src);
    }

    void shortestPathUsingDFS(int dest, stack<int>& ans, int n) {
        vector<int>dist(n, INT_MAX);

        int src = ans.top();
        ans.pop();
        dist[src] = 0;

        for(auto neighbour: adjList[src]) {
            if(dist[src] + neighbour.second < dist[neighbour.first]) {
                dist[neighbour.first] = dist[src] + neighbour.second;
            }
        }

        while(!ans.empty()) {
            int topElement = ans.top();
            ans.pop();

            if(dist[topElement] != INT_MAX) {
                for(auto neighbour: adjList[topElement]) {
                    if(dist[topElement] + neighbour.second < dist[neighbour.first]) {
                        dist[neighbour.first] = dist[topElement] + neighbour.second;
                    }
                }
            }
        }

        cout << "Printing Shortest Path: " << endl;
        for(int i=0; i<n; i++) {
            cout << i << " -> " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g;
    int n = 5;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,0);

    cout << "Printing Adjacency List" << endl;
    g.printAdjacencyList();
    cout << endl;

    unordered_map<int, bool>visited;
    stack<int>ans;
    g.topologicalSortUsingDFS(0, visited, ans);
    int src = 0;
    int dest = 3;
    g.shortestPathUsingDFS(dest, ans, n);

    return 0;
}

// T.C -> O(V + E)