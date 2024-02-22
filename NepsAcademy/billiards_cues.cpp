#include <iostream>
#include <set>

using namespace std;

int main(){
    int c; // Queries
    cin >> c;

    set<int> stock;

    int len;
    int produced = 0;
    for (int i = 0; i < c; i++){
        cin >> len;
        
        // If in stock, continue
        if (stock.find(len) != stock.end()){
            stock.erase(len);
            continue;
        }

        // Add to stock, produced += 2
        stock.insert(len);
        produced += 2;
    }

    cout << produced << endl;

}