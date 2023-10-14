#include <bits/stdc++.h>
using namespace std;
int vertices = 10;
vector<vector<pair<int,int>>> graph(vertices);

vector<int> lazy_dijkstra(){
    vector<int> distance(vertices, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0});
    while(!pq.empty()){
        auto [cur_dis, cur_node] = pq.top();
        pq.pop();

        if(distance[cur_node] != -1) continue;
        distance[cur_node] = cur_dis;

        for(auto [next_node, weight]: graph[cur_node]){
            int new_dis = cur_dis + weight;
            pq.push({new_dis, next_node});
        }
    }
    return distance;
}

int main(){
    // complete graph
    for(int i = 0; i < vertices; i++){
        for(int j = i + 1; j < vertices; j++){
            graph[i].push_back({j, 1});
            graph[j].push_back({i, 1});
        }
    }

    auto distance = lazy_dijkstra();

    for(auto &x : distance){
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}