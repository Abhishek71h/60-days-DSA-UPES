/*By kahn's Algorithm --> Leetcode 207
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

class Solution {
public:
    bool topologicalSortUsingBFS(int n, unordered_map<int, list<int>>& adjList, int count) {
        queue<int>q;
        unordered_map<int,int>indegree;
        for(auto node: adjList) {
            int src = node.first;
            for(auto neighbour: node.second) {
                indegree[neighbour]++;
            }
        }
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            count++;
            for(auto neighbour: adjList[frontNode]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        if(count == n) {
            return true;
        }
        else return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        for(auto &node: prerequisites) {
            int u = node[0];
            int v = node[1];
            adjList[v].push_back(u);
        }
        int count = 0;
        return topologicalSortUsingBFS(numCourses, adjList, count);
    }
};