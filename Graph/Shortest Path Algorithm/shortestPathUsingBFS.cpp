// It is a undirected Graph
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;
class Graph {
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int src, int dest, bool direction) {
        adjList[src].push_back(dest);
        if(direction == 0) {
            adjList[dest].push_back(src);
        }
    }

    void printAdjacencyList() {
        for(auto& node: adjList) {
            cout << node.first << " -> ";
            for(auto& neighbour: node.second) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    void shortestPathUsingBFS(int src, int dest) {
        queue<int>q;
        unordered_map<int, bool> visistd;
        unordered_map<int, int>parent;

        // inital steps
        q.push(src);
        visistd[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for(auto neighbour: adjList[frontNode]) {
                if(!visistd[neighbour]) {
                    q.push(neighbour);
                    visistd[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }

        // store path in ans vector, after traversing in the parent array
        vector<int>ans;
        int node = dest;
        while(node != -1) {
            ans.push_back(node);
            node = parent[node];
        }
        reverse(ans.begin(), ans.end());

        cout << "Printing Shortest Path : " << endl;
        for(auto i: ans) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    int n = 10;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(0,5,0);
    g.addEdge(5,4,0);
    g.addEdge(0,6,0);
    g.addEdge(6,7,0);
    g.addEdge(7,8,0);
    g.addEdge(8,4,0);
    cout << "Printing Adjacency List" << endl;
    g.printAdjacencyList();
    cout << endl;

    int src = 0;
    int dest = 4;

    g.shortestPathUsingBFS(src, dest);

    return 0;
}

// T.C -> O(V + E)