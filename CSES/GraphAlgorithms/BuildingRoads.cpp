/*
g++ -std=c++17 -o bin/out BuildingRoads.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <stack>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

vector<vector<lli> > roads;
vector<bool> visited;

void dfs(lli v){
    stack<lli> st;
    st.push(v);
    
    while (!st.empty()){
        lli curr = st.top();
        st.pop();
        if (!visited[curr]){
            visited[curr] = true;

            for (auto u : roads[curr]){
                st.push(u);
            }
        }
    }
}

int main(){
    lli n, m; // cities, roads
    cin >> n >> m;
    
    roads.clear();
    roads.assign(n + 1, vector<lli>());
    
    visited.clear();
    visited.assign(n + 1, false);
    
    for (lli i = 1; i <= m; i++){
        lli a, b;
        cin >> a >> b;
        // means that there's a road between a and b
        
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    
    vector<lli> connected_comps;
    for (lli i = 1; i <= n; i++){
        if (!visited[i]) connected_comps.push_back(i);
        dfs(i);
    }

    cout << connected_comps.size() - 1 << "\n";
    for (lli i = 0, j = 1; j < connected_comps.size(); i++, j++){
        cout << connected_comps[i] << " " << connected_comps[j] << "\n";
    }
}
