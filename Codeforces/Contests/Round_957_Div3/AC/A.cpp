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
        int a, b, c;
        cin >> a >> b >> c;

        priority_queue<int> pq;
        pq.push(a * -1);
        pq.push(b * -1);
        pq.push(c * -1);

        for (int i = 1; i <= 5; i++){
            int top = pq.top();
            pq.pop();
            top--;
            pq.push(top);
        }

        lli ans = 1;
        while (!pq.empty()) {
            ans *= (pq.top() * -1);
            pq.pop();
        }

        cout << ans << endl;
    }
}
