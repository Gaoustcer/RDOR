#include <set>
#include <utility>
#include <iostream>
using namespace std;

int main(){
    set<pair<int,int>> pairset;
    pair<int,int> x,y;
    x = make_pair(1,2);
    y = make_pair(1,2);
    pairset.insert(x);
    pairset.insert(y);
    cout << pairset.size() << endl;
}