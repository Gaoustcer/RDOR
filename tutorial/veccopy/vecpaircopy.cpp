#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(){
    vector<pair<int,int>> veca,vecb;
    veca.push_back(make_pair(1,2));
    vecb = veca;
    vecb.push_back(make_pair(2,3));
    cout << vecb.size() << " " << veca.size();
}