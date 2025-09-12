/*
g++ -std=c++17 -Wall -pedantic -o bin/out BUGLIFE.cpp && ./bin/out
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

using namespace std;

vector<vector<lli>> adj;
vector<lli> color;

bool bfs_bipartite(lli start){
    queue<lli> q;
    q.push(start);

    color[start] = 1;

    while (!q.empty()){
        lli u = q.front();
        q.pop();
        
        // visit neighbours
        for (auto v : adj[u]){
            if (color[v] == 0){
                color[v] = (color[u] == 1 ? 2 : 1);
                q.push(v);
            } else if (color[v] == color[u]) return false;
        }
    }

    return true;
}

int main(){
    lli t;
    cin >> t;
    for (lli it = 1; it <= t; it++){
        lli num_bugs, interactions;
        cin >> num_bugs >> interactions;

        adj.assign(num_bugs + 1, {});
        color.assign(num_bugs + 1, 0);

        for (lli i = 0, a, b; i < interactions; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout << "Scenario #" << it << ":\n";

        bool suspicious = false;
        for (lli i = 1; i <= num_bugs; i++){
            if (color[i] != 0) continue;

            if (!bfs_bipartite(i)){
                cout << "Suspicious bugs found!\n";
                suspicious = true;
                break;
            }
        }

        if (suspicious) continue;

        cout << "No suspicious bugs found!\n";
    }
}
