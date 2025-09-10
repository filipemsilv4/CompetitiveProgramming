/*
g++ -std=c++17 -Wall -pedantic -o bin/out BuildingTeams.cpp && ./bin/out
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
#define MAXN 100001

using namespace std;

vector<lli> adj[MAXN];
lli color[MAXN];

bool bfs_bipartite(lli start){
    queue<lli> q;
    q.push(start);

    color[start] = 1;

    while (!q.empty()){
        lli u = q.front();
        q.pop();

        for (auto v : adj[u]){
            if (color[v] == 0){
                color[u] == 1 ? color[v] = 2 : color[v] = 1;
                q.push(v);
            } else if (color[v] == color[u]) return false;
        }
    }

    return true;
}

int main(){
    lli n, m;
    cin >> n >> m;

    for (lli i = 1, a, b; i <= m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (lli i = 1; i <= n; i++){
        if (color[i] == 0){
            if (!bfs_bipartite(i)){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (lli i = 1; i <= n; i++){
        cout << color[i] << "\n";
    }
}
