// AC

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct CompareByInt{
    bool operator()(const pair<string, int> &a, const pair<string, int> &b){
        return a.second < b.second;
    }
};

struct CompareByString{
    bool operator()(const pair<string, int> &a, const pair<string, int> &b){
        return a.first < b.first;
    }
};

int main(){
    int n, t; // alunos, times
    cin >> n >> t;

    vector<vector<pair <string, int>>> teams(t);
    priority_queue<pair<string,int>, vector<pair<string,int>>, CompareByInt> pq;

    for (int i = 0; i < n; i++){
        string s;
        int v;
        cin >> s >> v;
        pq.push({s,v});
    }

    for (int i = 0; i < t && !pq.empty(); i = (i + 1) % t){
        teams[i].push_back(pq.top());
        pq.pop();
    }

    for (int i = 0; i < t; i++){
        cout << "Time " << i + 1 << "\n";
        sort(teams[i].begin(), teams[i].end(), CompareByString());
        for (const auto u : teams[i]){
            cout << u.first << "\n";
        }
        cout << "\n";
    }

}