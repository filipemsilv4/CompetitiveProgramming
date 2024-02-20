#include <iostream>
#include <queue>

using namespace std;

struct Compare{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }
};

int main(){
    int c, n; // num de caixas, num de clientes
    cin >> c >> n;

    // <int,int> -> index do caixa, tempo gasto em atendimento até então
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> caixas;

    for(int i = 0; i < c; i++){
        caixas.push({i, 0}); // To com sono, nem precisava pushar esse index kkkkkkk
    }

    int ans = 0;
    // as linhas estão ordenadas por entrada dos clientes na fila.
    int t, d; // momento q o cliente entra na fila, tempo de atendimento dele
    for (int i = 0; i < n; i++){
        cin >> t >> d;

        pair<int, int> cx = caixas.top();
        caixas.pop();

        if (cx.second - t > 20) ans++;

        // cx.second += d
        // Essa correção funciona e eu nao sei pq. TODO: Descobrir amanhã quando eu acordar
        cx.second = max(t, cx.second) + d;
        caixas.push(cx);
    }

    cout << ans << endl;
}