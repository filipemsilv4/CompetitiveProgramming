#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

typedef struct trip {
    int a, b, c;
} tri;

vector<tri> cicl;
bool visited[4001];

void dfs(vector<vector<bool> > &warrior_mat, vector<vector<int> > &warrior_list, int pos, int pai){
    if (visited[pos]) return;
    visited[pos] = true;

    for (int i = 0; i < warrior_list[pos].size(); i++){
        // se meu pai conhece meu filho, tripla!
        if (warrior_mat[pai][warrior_list[pos][i]]){
            tri n;
            n.a = pai;
            n.b = pos;
            n.c = warrior_list[pos][i];
            cicl.push_back(n);
        }
        dfs(warrior_mat, warrior_list, warrior_list[pos][i], pos);
    }

    return;
}

int main(){
    int n, m; // node, edge
    cin >> n >> m;

    memset(visited, 0, sizeof(visited));

    vector<vector<bool> > warrior_mat(n+1, vector<bool>(4001));
    vector<vector<int> > warrior_list(n+1);

    for(int i = 1, a, b; i <= m; i++){
        cin >> a >> b;
        warrior_mat[a][b] = true;
        warrior_mat[b][a] = true;

        warrior_list[a].push_back(b);
        warrior_list[b].push_back(a);
    }

    dfs(warrior_mat, warrior_list, 1, 1);

    int ans = INT_MAX;
    for (int i = 0; i < cicl.size(); i++){
        int sum = cicl[i].a + cicl[i].b + cicl[i].c;
        if (sum < ans) ans = sum;
    }

    cout << ans << endl;

}
