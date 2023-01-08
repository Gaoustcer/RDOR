#include "arrobject.h"
#include <iostream>
#include "readdecode.h"
using namespace std;
#define P 5
int main(){

    arrfile ** array = getarray(P);
    // array[0][4].save("files/04baseline");
    arrfile checkfile[4];
    for(int i = 0;i < 4;i++){
        checkfile[i] = std::move(array[0][i]);
        for(int j = 1;j < 4;j++){
            checkfile[i] + array[j][i];
        }
    }
    arrfile check = std::move(checkfile[0]);
    for(int j = 1;j < 4;j++){
        check + checkfile[j];
    }
    // checkfile.save("files/0reconstruct");
    // arrfile check = std::move(checkfile[0] ^ checkfile[1] ^ checkfile[2] ^ checkfile[3]);
    check.save("files/check");
    // for(int i = 1;i < P - 1; i++){
    //     checkfile ^ array[0][i];
    // }
    // checkfile.save("files/04check");
    return 0;
    // arrfile first = std::move(array[0][5]);
    // for(int i = 1;i < P - 1;i++){
    //     first + array[i][5];
    // }
    // first.save("files/getarray5");
    // return 0;
    
    arrfile * recover = decode(P,0);
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