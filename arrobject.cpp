#include "arrobject.h"
#include <fstream>
#include "filesize.h"
#include <string.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <utility>
#include <set>

// #include <filesize.h>
arrfile::arrfile(char * filename){
    std::ifstream fileread(filename);
    _size = file_size(filename);
    _ptr = new char[_size];
    fileread.read(_ptr,sizeof(char) * _size);
}

arrfile::arrfile(int size,char *ptr){
    // std::cout << "copy memory\n";
    _ptr = new char[size];
    memcpy((void *)_ptr,(void *)ptr,sizeof(char) * size);
    // std::cout << "copy from pointer\n";
    _size = size;

    // delete [] ptr;    
}
arrfile::arrfile(std::vector<arrfile *>& vecarrfile){
    int arrsize = vecarrfile.size();
    assert(arrsize != 0);
    *this = *vecarrfile[0];

    for(int i = 1;i < arrsize; i++){
        *this ^ *vecarrfile[i];
    }

}

arrfile::arrfile(int size){
    _ptr = new char[size];
    _size = size;
}

arrfile& arrfile::operator^(arrfile & rightoperator){
    assert(_size == rightoperator.size());
    for(int i = 0;i < _size;i++){
        _ptr[i] = _ptr[i] ^ rightoperator[i];
    }
    return *this;
    // char * pointer = new char[_size];
    // int size = _size;
    // for(int i = 0;i < _size;i++){
    //     pointer[i] = _ptr[i] ^ rightoperator[i];
    // }
    // arrfile object(size,pointer);
    // return object;
}


arrfile::arrfile(){
    _size = 0;
    _ptr = nullptr;
}
char& arrfile::operator[](int index){
    assert(index < _size);
    return _ptr[index];
}
arrfile & arrfile::operator=(arrfile & rightvalue){
    // directly copy function
    _size = rightvalue._size;
    _ptr = new char[_size];
    memcpy(_ptr,rightvalue._ptr,sizeof(char) * _size);
    return *this;
}
arrfile & arrfile::operator=(arrfile && rightvalue){
    // std::cout << "Rightvalue copy" << std::endl;
    _ptr = rightvalue._ptr;
    _size = rightvalue._size;
    rightvalue._size = 0;
    rightvalue._ptr = nullptr;
    return *this;
}

arrfile * separate(arrfile & file,int number){
    int dividesize = file.size()/number;
    // std::cout << "divide size is" << dividesize << std::endl;
    arrfile * array = new arrfile[number];
    for(int i = 0;i < number;i++){
        char * pointer = file._ptr + i * dividesize;
        // std::cout << "The pointer of " << i << std::endl;
        arrfile instance(dividesize,pointer);
        // std::cout << "Initial the object\n";
        array[i] = std::move(arrfile(dividesize,pointer));
        // std::cout << "copy of part " << i << std::endl;
    }
    return array;
    // assert(file.size() % number == 0);
    // int _size = file.size()/number;
    // arrfile * arrptr = new arrfile;
    // arrfile * filepointer = new arrfile[4];
}
arrfile::arrfile(arrfile && file){
    _size = file._size;
    _ptr = file._ptr;
    file._size = 0;
    file._ptr = nullptr;
}
arrfile & arrfile::operator+(arrfile & rightvalue){
    char * ptr = new char[rightvalue.size() + this->size()];
    int size = _size + rightvalue.size();
    memcpy((void *)ptr,_ptr,sizeof(char) * _size);
    memcpy((void *)(ptr + _size),rightvalue._ptr,sizeof(char) * rightvalue.size());
    delete [] _ptr;
    _size = size;
    _ptr = ptr;
    return *this; 
}
arrfile::~arrfile(){
    if(_size != 0){
        delete [] _ptr;
    }
    _size = 0;
}

arrfile ** getcheckblock(arrfile & block,int dividenum){
    arrfile **result;
    // dividenum = 5
    // result is[4][6] (max index is [3][5])
    result = new arrfile*[dividenum - 1];
    for(int i = 0;i < dividenum -1; i++){
        result[i] = new arrfile[dividenum + 1];
    }
    // std::cout << "new result\n";
    arrfile * divideforwholefile = separate(block,dividenum - 1);
    // std::cout << "The first divide\n";
    for(int i = 0;i < dividenum -1; i++){
        // result[0,1,2,3][i] should be divided from divideforwholefile[i]
        arrfile * blockdivide = separate(divideforwholefile[i],dividenum - 1);
        for(int j = 0;j < dividenum - 1;j++){
            result[j][i] = std::move(blockdivide[j]);
        }
    }
    // generate line check for result[0-3][4]
    int linecheckid = dividenum - 1;
    for(int i = 0;i < dividenum - 1;i++){
        // forresult[i][4] = result[i][0] ^ result[i][1] ^ result[i][2] ^ result[i][3]
        std::vector<arrfile *> vec;
        for(int j = 0;j < dividenum - 1;j++){
            vec.push_back(&result[i][j]);
        }
        result[i][linecheckid] = std::move(arrfile(vec));
    }
    int trajcheckid = dividenum;
    // For diagonal check block we define
    // D_j = (d[i][r]|(i+r)mod p = j,0\leq i\leq p-2,0\leq r\leq p)
    for(int k = 0;k < dividenum - 1;k++){
        // diagnoal check are exists in array of D[4][5]
        std::vector<arrfile *> vec;
        for(int i = 0;i < dividenum - 1;i++){
            for(int j = 0;j < dividenum;j++){
                if((i+j)%dividenum == k){
                    vec.push_back(&result[i][j]);
                }
            }
        }
        result[k][trajcheckid] = std::move(arrfile(vec));
    }
    return result;
    // P = 5 then result should be a 4\times 5 blockarray,array[4][5]
    // array[0-3,i] should be the i divide
}

void save(std::vector<arrfile *> &vec,const char * name){
    assert(vec.size());
    arrfile file;
    file = *vec[0];
    for(int i = 1;i < vec.size();i++){
        file + *vec[i];
    }
    file.save(name);
}


void arrfile::save(const char*filename){
    std::ofstream outfile;
    outfile.open(filename);
    outfile.write(_ptr,sizeof(char) * _size);
    outfile.close();
}
void getbaseline(){
    char * checkblock[4] = {"files/datablock_1","files/datablock_2","files/datablock_3","files/datablock_4"};
    arrfile files[4];
    for(int i = 0;i < 4;i++){
        files[i] = std::move(arrfile(checkblock[i]));
    }
    for(int i = 1;i < 4;i++){
        files[0] ^ files[i];
    }
    files[0].save("files/baseline_linecheck");
}

std::vector<std::pair<int,int>> diagcheck(int x,int y,int p){
    // get diag check of d[x,y]
    // D_j = {d_{i,r}|(i+r) mod p = j}
    // default p is 5
    std::vector<std::pair<int,int>> vec;
    if((x+y)%p == p - 1){
        return vec;
    }
    for(int i = 0;i < P - 1;i++){
        for(int j = 0;j < P + 1;j++){
            if(i != x || j != y)
                if(((i+j)%p) == ((x+y)%p))
                    vec.push_back(std::make_pair(i,j));
        }
    }
    return vec;
}

std::vector<std::pair<int,int>> linecheck(int x,int y,int p){
    std::vector<std::pair<int,int>> vec;
    if(y == p){
        return vec;
    }
    for(int j = 0;j < p;j++){
        if(y != j)
            vec.push_back(std::make_pair(x,j));
    }
    return vec;
    // default p = 5
    // get linecheck
}

decision& decision::operator=(decision & obj){
    maxsize = obj.maxsize;
    diagornot = new bool[maxsize];
    memcpy((void *)diagornot,(void *)obj.diagornot,sizeof(bool) * maxsize);
    blocktoread = obj.blocktoread;
    return *this;
}

decision::decision(int _maxsize){
    maxsize = _maxsize;
    diagornot = new bool[maxsize];
}

decision::decision(decision & copy){
    maxsize = copy.maxsize;
    diagornot = new bool[maxsize];
    memcpy((void *)diagornot,(void *)copy.diagornot,sizeof(bool) * maxsize);
    blocktoread = copy.blocktoread;
}
int decision::size(){
    return blocktoread.size();
}

void decision::push(std::pair<int,int> &obj){
    blocktoread.insert(obj);
}

void search(int x,int y,int maxlevel,decision& decide){
    // level starts with 0 and if level == maxlevel the decide is returned.
    // maxlevel = 4
    // if(x == maxlevel){
    //     return decide;
    // }
    // level means blocktoread[0] has options
    auto diag = diagcheck(x,y,maxlevel + 1);
    decision diagdecide = decide,linedecide = decide;
    if(diag.size()){
        for(auto &p:diag){
            diagdecide.push(p);
        }
        diagdecide.diagornot[x] = true;
        search(x+1,y,maxlevel,diagdecide);
    }
    auto line = linecheck(x,y,maxlevel + 1);
    for(auto &p:line){
        linedecide.push(p);
    }
    search(x+1,y,maxlevel,linedecide);
    if(diag.size()){
        // if(diagdecide.size() <)
        decide = (diagdecide.size() < linedecide.size())?diagdecide:linedecide;
    }
    else{
        decide = linedecide;
    }
    // linedecide = search(x+1,y,maxlevel,linedecide);
    // return diagdecide;

}