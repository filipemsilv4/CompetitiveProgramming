#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n; cin >> n;

    int biggest_size = n;

    priority_queue<int> pq;

    for (int i = 1, tmp; i <= n; i++){
        cin >> tmp;
        pq.push(tmp);

        while (!pq.empty() && pq.top() == biggest_size){
            biggest_size--;
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
}
