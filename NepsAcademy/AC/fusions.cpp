//AC
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int i){
    if (parent[i] == i) return i;
    return find(parent[i]);
}

void merge(int i, int j){
    i = find(i);
    j = find(j);

    parent[j] = i;
}

int main(){
    /*The first line contains two integers N and K, 
    indicating the number of banks and the number of 
    operations performed. The codes of each of the 
    N banks are initially integers from 1 to N.*/

    int N, K;
    cin >> N >> K;

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) parent[i] = i;

    /*Each of the following  K lines describes either 
    a merger between banks or a query.*/
    char op, ans;
    int b1, b2;
    for (int i = 0; i < K; i++){
        cin >> op >> b1 >> b2;
        // if F, merge
        if (op == 'F') merge(b1, b2);
        else {
            if (find(b1) == find(b2)) cout << 'S' << endl;
            else cout << 'N' << endl;
        }
    }
}