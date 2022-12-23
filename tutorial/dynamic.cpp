#include <iostream>
#include <stdlib.h>
// #include <stdio.h>#
#include <string.h>
#define N 1024
using namespace std;

class object{
public:
    object(int size,int *ptr){
        ptr = new int[size];
        _size = size;
        memcpy((void *)_ptr,(void *)ptr,sizeof(int)*size);
        delete [] ptr;

    }
    object(){
        _size = 0;
        _ptr = nullptr;
    }
    ~object(){
        if (_size != 0)
            delete [] _ptr;
    }
    object & operator+(object & rightvalue){
        if(rightvalue.getsize() == _size){
            int * ptr = new int[_size];
            for(int i = 0;i < _size;i++){
                ptr[i] = _ptr[i] + rightvalue[i];
            }
            
        }   
    }
    int getsize(){
        return _size;
    }
    int & operator[](int index){
        if (index < _size)
            return _ptr[index];
        // return 0;
        if (_size != 0){
            return _ptr[0];
        }
        else{
            int x = 0;
            return x;
        }
    }
private:
    int * _ptr;
    int _size;

};