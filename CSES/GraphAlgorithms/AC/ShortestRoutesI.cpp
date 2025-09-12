/*
g++ -std=c++17 -Wall -pedantic -o bin/out ShortestRoutesI.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <string>
#include <climits>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define MAXN 100001
#define INF LLONG_MAX
#define pii pair<lli, lli> // {distance, vertex}

using namespace std;

vector<pair<lli, lli> > adj[MAXN]; // pair<neighbour, weight>
lli dist[MAXN];
lli n, m;

void dijkstra(lli start_node){
    for (lli i = 1; i <= n; ++i){
        dist[i] = INF;
    }
    dist[start_node] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start_node});

    while(!pq.empty()){
        lli d = pq.top().first;
        lli u = pq.top().second;
        pq.pop();

        if (d > dist[u]){
            continue;
        }

        for (auto &edge : adj[u]){
            lli v = edge.first;
            lli weight = edge.second;

            // relax
            if (dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for (lli i = 1, a, b, c; i <= m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    dijkstra(1);

    for (lli i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
}
