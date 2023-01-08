#include <vector>
#include <utility>
#include <set>
#pragma once
// #define P 5

class arrfile{
public:
    int _size;
    char * _ptr;
    arrfile();
    arrfile(char * filename);// open file and write the content into object
    arrfile(int size,char * ptr); // allocate a space with size and memcpy from ptr
    arrfile(int size); // allocate a space with size memory
    arrfile(std::vector<arrfile *>& );
    arrfile& operator^(arrfile &rightoperator);
    char& operator[](int index);
    int size(){
        return _size;
    }
    // void moveptr(char * ptr){
    //     _ptr =  ptr;
    // }
    arrfile(arrfile &&);
    ~arrfile();
    arrfile & operator=(arrfile &&);
    arrfile & operator=(arrfile &);
    arrfile & operator+(arrfile &);
    void save(const char*);
};
class decision{
public:
    std::set<std::pair<int,int>> blocktoread;
    int maxsize;
    // true means use diag check
    bool *diagornot;
    decision(int _maxsize);
    decision(decision &copy);
    decision& operator=(decision &);
    int size();
    void push(std::pair<int,int>&);
    // bool& operator[](int index){

    // }
};

arrfile * separate(arrfile &,int);
arrfile ** getcheckblock(arrfile &,int dividenum);
void save(std::vector<arrfile*> &,const char *);
void getbaseline();
std::vector<std::pair<int,int>> diagcheck(int x,int y,int p);
std::vector<std::pair<int,int>> linecheck(int,int,int);
void search(int x,int y,int maxlevel,decision& decide);
// void repair()