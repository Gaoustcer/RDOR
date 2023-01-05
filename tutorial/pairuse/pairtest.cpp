#include <iostream>
#include <utility>
using namespace std;
int main(){
    pair<int,int> T;
    T = make_pair(1,2);
    cout << T.first;
    cout << T.second;
}