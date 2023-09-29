#include<bits/stdc++.h>
using namespace std;

// Count paths (backtracking)
int dfs(string node, string target, unordered_map<string, vector<string> > adjList, set<string>&visited) 
{
    if (visited.count(node)) return 0;
    if (node == target) return 1;

    int count = 0;

    visited.insert(node);
    for (string neighbor: adjList[node])  count += dfs(neighbor, target, adjList, visited);
    return count;
}

// Shortest path from node to target.
int bfs(string node, string target, unordered_map<string, vector<string> > adjList) 
{
    set<string> visit;
    queue<string> queue;

    visit.insert(node);
    queue.push(node);

    int length = 0;

    while (queue.size()) 
    {
        int l = queue.size();

        for (int i = 0; i < l; i++) 
        {
            string curr = queue.front();
            queue.pop();

            if (curr == target) return length;
            for (string neighbor: adjList[curr]) 
            {
                if (visit.count(neighbor) == 0) 
                {
                    visit.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        length++;
    }
    return length;
}

int main()
{
    // Given directed edges, build an adjacency list

    vector<vector<string> > edges = { {"A","B"}, {"B","C"}, {"B","E"}, {"C","E"}, {"E","D"}};

    unordered_map<string, vector<string> > adjList;
    for (vector<string> edge:  edges) 
    {
        string src = edge[0], dst = edge[1];
        adjList[src].push_back(dst);
    }

    //printing the adj list
    for(auto p : adjList)
    {
        cout<<p.first<<" : ";
        for(int i=0; i<p.second.size(); i++) cout<<p.second[i]<<"\t";
        cout<<endl;
    }

    /*
    GRAPH
             A->B->C
                | /
                V
                E->D
    */

   //dfs
    set<string>s;
    cout<<endl;
    cout<<"Number of paths from A to E : "<<dfs("A","E",adjList,s)<<endl;
    cout<<endl;
    
    //bfs
    cout<<endl;
    cout<<"Shortest distance from A to E : "<<bfs("A","E",adjList)<<endl;
    cout<<endl;
    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/clone-graph/
    https://leetcode.com/problems/course-schedule/
    */
}