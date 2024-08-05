#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    unordered_set<int> a_set(n);
    vector<bool> repeated(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > n) a[i] = 1;
        if (a_set.count(a[i]) == 0){
            a_set.insert(a[i]);
        } else {
            repeated[i] = true;
        }
    }

    deque<int> dq;

    for(int i = 1; i <= n; i++){
        if (a_set.count(i) == 0) dq.push_back(i);
    }

    for(int i = 0; i < n; i++){
        if (repeated[i]){
            cout << dq.front();
            dq.pop_front();
        } else {
            cout << a[i];
        }
        cout << " ";
    }
    cout << endl;
}
