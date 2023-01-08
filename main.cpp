#include <iostream>
#include <vector>
#include "arrobject.h"
using namespace std;
#define P 5



int main(){
    decision root(4);
    search(0,1,4,root);
    for(auto &p:root.blocktoread){
        cout << p.first << " " << p.second << endl;
    }
    for(int i = 0;i < root.maxsize;i++){
        cout << root.diagornot[i] << endl;
    }
    // auto vec = diagcheck(2,2,P);
    // vec = linecheck(2,2,P);
    // for(auto & p: vec){
    //     cout << p.first << " " << p.second << endl;
    // }
    // getbaseline();
    // return 0;
    // arrfile file("./files/test");
    // for(int i = 0;i < 1024 * 1024 * 256;i++){
    //     file[i] += 1;
    // }
    // arrfile **array = getcheckblock(file,P);
    // for(int i = 0;i < P - 1;i++){
    //     for(int j = 0;j < P + 1;j++){
    //         cout << i  << " "<< j << " " << array[i][j].size() << endl;
    //     }
    // }
    // char * filenamelist[6] = {"files/datablock_1","files/datablock_2","files/datablock_3","files/datablock_4","files/linecheck","files/diagcheck"};
    // for(int i = 0;i < P+1;i++){
    //     vector<arrfile *> list;
    //     for(int j = 0;j < P - 1;j++){
    //         list.push_back(&array[j][i]);
    //     }
    //     cout << "save" << filenamelist[i] << endl;
    //     save(list,filenamelist[i]);
    // }
    // cout << file.size() << endl;
}