#include "arrobject.h"
#include "readdecode.h"
#include <iostream>
#include <vector>
#include <utility>

arrfile **getarray(int dividenumber){
    // default dividenumber = 5
    char * datafilelist[4] = {"files/datablock_1","files/datablock_2","files/datablock_3","files/datablock_4"};
    char * checkfilelist[2] = {"files/linecheck","files/diagcheck"};
    arrfile ** array;
    arrfile * datafile = new arrfile[dividenumber - 1];
    arrfile * checkinfile = new arrfile[2];
    for(int i = 0;i < 2;i++){
        checkinfile[i] = std::move(arrfile((char *)checkfilelist[i]));
    }
    for(int i = 0;i < dividenumber - 1;i++){
        datafile[i] = std::move(arrfile(datafilelist[i]));
    }
    std::cout << "read datafile and checkinfile\n";
    array = new arrfile*[dividenumber - 1];
    for(int i = 0;i < dividenumber - 1;i++){
        array[i] = new arrfile[dividenumber + 1];
    }
    // dividedatablock
    for(int i = 0; i < dividenumber - 1;i++){
        arrfile * list = separate(datafile[i], dividenumber - 1);
        for(int j = 0; j < dividenumber - 1;j++){
            array[j][i] = std::move(list[j]);
        }
    }
    std::cout << "datafile read\n";
    for(int i = dividenumber - 1;i < dividenumber + 1;i++){
        arrfile * list = separate(checkinfile[i - (dividenumber - 1)],dividenumber - 1);
        for(int j = 0;j < dividenumber - 1;j++){
            array[j][i] = std::move(list[j]);
        }
    }
    std::cout << "checkinfileread\n";
    return array;

}
arrfile * decode(int P,int recoverid){
    // recoverid = 0,1,2,3,4,5
    arrfile * recoverarray = new arrfile[P - 1];
    arrfile ** array = getarray(P);
    decision decide(P -1);
    search(0,recoverid,P - 1,decide);
    std::vector<std::vector<std::pair<int,int>>> recoverplan;
    for(int i = 0;i < decide.maxsize;i++){
        std::vector<std::pair<int,int>> vec;
        if(decide.diagornot[i]){
            vec = diagcheck(i,recoverid,P);
        }
        else{
            vec = linecheck(i,recoverid,P);
        }
        // for(int j = 0;j < vec.size();j++){
        //     std::cout << vec[j].first << " " << vec[j].second << "  ";
        // }
        // std::cout << std::endl;
        recoverplan.push_back(vec);
    }
    for(int i = 0;i < P - 1;i++){
        std::vector<std::pair<int,int>> vecrec = recoverplan[i];
        std::vector<arrfile*> arrvec;
        
        for(auto& p:vecrec){
            arrvec.push_back(&array[p.first][p.second]);
            std::cout << p.first << " " << p.second << "  ";
        }
        std::cout << std::endl;
        recoverarray[i] = std::move(arrfile(arrvec));
    }
    // arrfile recover();
    // for(int i = 1;i < P - 1;i++){
    //     // recoverarray
    //     recoverarray[0] += recoverarray[i];
    // }
    return recoverarray;

}
