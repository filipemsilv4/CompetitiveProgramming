#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;

    set<int> alunos;

    int a;
    for (int i = 0; i < n; i++){
        cin >> a;
        alunos.insert(a);
    }

    cout << alunos.size() << endl;
}