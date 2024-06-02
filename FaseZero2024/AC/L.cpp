#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> names;
    map<string, int> mp_name;
    map<int, string> mp_age;
    priority_queue<int> pq;

    string name;
    for (int i = 0; i < n; i++){
        cin >> name;
        mp_name[name] = 1;
        names.push_back(name);
    }

    for (int i = n - 1; i >= 0; i--){
        cin >> name;
        mp_name[name] = i;
        mp_age[i] = name;
        pq.push(i);
    }

    for (int i = 0; i < n; i++){
        // Ja visitei essa praga
        while (mp_name[mp_age[pq.top()]] == -1) {
            pq.pop();
        }

        cout << mp_age[pq.top()];

        if (i < n - 1){
            cout << " ";
        }
        // cout << "|";

        mp_name[names[i]] = -1;
    }
    cout << endl;
}
