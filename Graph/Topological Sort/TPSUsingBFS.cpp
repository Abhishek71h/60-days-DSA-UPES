#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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

    void topologicalSortUsingBFS(int n, vector<int>& ans) {
        queue<int>q;
        unordered_map<int, int> indegree;

        // indegree calculation
        for(auto node: adjList) {
            int src = node.first;
            for(auto neighbour: node.second) {
                indegree[neighbour]++;
            }
        }

        // put all nodes inside queue, which has indegree 0
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS Logic
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto neighbour: adjList[frontNode]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
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

    vector<int>ans;
    g.topologicalSortUsingBFS(n, ans);

    cout << "Printing Topological Sort using BFS called Kahn's Algorithm" << endl;
    for(auto i: ans) {
        cout << i << " ";
    }
    return 0;
}