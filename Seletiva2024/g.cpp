#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int dfs(vector<vector<int> > &edges, vector<bool> &has_cat, int onde_to, int cat_count, int still_ok){
    if (has_cat[onde_to]) cat_count++;
    else cat_count = 0;
    if (cat_count > still_ok) return 0;

    if (edges[onde_to].empty())
        return 1;

    int ans = 0;
    for (int k = 0; k < edges[onde_to].size(); k++){
        int i = edges[onde_to][k];
        ans += dfs(edges, has_cat, i, cat_count, still_ok);
    }

    return ans;
}

int main(){
    int n, m; // total vertices, max allowed cats
    cin >> n >> m;

    vector<bool> has_cat(n+1);
    for (int i = 1, tmp; i <= n; i++){
        cin >> tmp;
        if (tmp == 1) has_cat[i] = true;
        else has_cat[i] = false;
    }

    vector<vector<int> > edges(n);
    for (int i = 1, x, y; i < n; i++){
        cin >> x >> y;
        edges[x].push_back(y);
    }

    cout << dfs(edges, has_cat, 1, 0, m) << endl;
}
