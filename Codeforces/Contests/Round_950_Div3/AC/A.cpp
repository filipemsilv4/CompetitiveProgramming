#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        lli n, m;
        cin >> n >> m;

        vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
        map<char,int> mp;
        priority_queue<int> pq;

        for (const auto &l : letters){
            mp[l] = 0;
        }

        for (int i = 0; i < n; i++){
            char tmp;
            cin >> tmp;
            mp[tmp]++;
        }

        for (const auto &l : letters){
            pq.push(mp[l] * -1);
        }

        int ans = 0;
        while ((pq.top() * -1) < m){
            int oq_falta = m - (pq.top() * -1);
            ans += oq_falta;
            pq.pop();
            pq.push((oq_falta + m) * -1);
        }

        cout << ans << endl;
    }
}
