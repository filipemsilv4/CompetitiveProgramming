#include <iostream>
#include <map>

using namespace std;

int main(){
    int c, n; // Total de programas instalados, total de programas disponíveis na internet
    cin >> c >> n;

    map<int, int> programs;
    map<int, int> inserted;

    for (int i = 0; i < c; i++){
        int p, v; // Programa, versao
        cin >> p >> v;

        programs[p] = v;
    }

    for (int i = 0; i < n; i++){
        int p, v;
        cin >> p >> v;

        if (programs.insert({p, v}).second == true || programs[p] < v){
            if (inserted.insert({p, v}).second == false && inserted[p] < v){
                inserted[p] = v;
            }
        }
    }

    //cout << "--------" << endl;
    for (auto m : inserted){
        cout << m.first << " " << m.second << "\n";
    }

}