/*
g++ -std=c++17 -Wall -pedantic -o bin/out TreeDiameter.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <string>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define MAXN 2*100005

using namespace std;

vector<lli> adj[MAXN];
vector<bool> visited(MAXN);

pair<lli,lli> bfs(lli start){
    queue<pair<lli, lli>> q; // pair<node, dist>
    q.push({start, 0});

    lli max_distance = 0;
    lli max_distance_index = start;

    while (!q.empty()){
        auto curr = q.front();
        q.pop();

        visited[curr.first] = true;

        if (curr.second > max_distance){
            max_distance = curr.second;
            max_distance_index = curr.first;
        }

        lli u = curr.first;
        for (auto v : adj[u]){
            if (visited[v]) continue;
            q.push({v, curr.second + 1});
        }
    }

    return {max_distance_index, max_distance};
}

int main(){
    lli  n;
    cin >> n;

    for (lli i = 1, a, b; i < n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto ans = bfs(1);
    visited.assign(MAXN, false);
    ans = bfs(ans.first);

    cout << ans.second << "\n";
}
