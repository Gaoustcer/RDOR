#include "arrobject.h"
#include <iostream>
#include "readdecode.h"
using namespace std;
#define P 5
int main(){
    // test array read
    // arrfile ** array = getarray(P);
    // arrfile first = std::move(array[0][5]);
    // for(int i = 1;i < P - 1;i++){
    //     first + array[i][5];
    // }
    // first.save("files/getarray5");
    // return 0;
    
    arrfile * recover = decode(P,1);
    for(int i = 0;i < P - 1;i++){
        cout << recover[i].size() << endl;
    }
    arrfile file = std::move(recover[0]);
    for(int i = 1;i < P - 1;i++){
        file + recover[i];
    }
    
    file.save("./files/bestreadcheck1");


    // arrfile ** array = getarray(P);
    // // decision decide(4);
    // decision decide(P - 1);
    // search(0,1,P - 1,decide);

    // // for(int i = 0;i < decide.maxsize;i++){
    // //     cout << i << " " << decide.diagornot[i] << endl;
    // // }
    // for(auto &p:decide.blocktoread){
    //     cout << p.first << " " << p.second << endl;
    // }
    // cout << decide.blocktoread.size() << endl;
    

    
    

    // for(int i = 0;i < P - 1;i++){
    //     for(int j = 0;j < P + 1;j++){
    //         cout << array[i][j].size() << endl; 
    //     }
    // }
    
    return 0;
}