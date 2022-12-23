#include "arrobject.h"
#include <fstream>
#include "filesize.h"
#include <string.h>
#include <assert.h>
// #include <filesize.h>
arrfile::arrfile(char * filename){
    std::ifstream fileread(filename);
    _size = file_size(filename);
    _ptr = new char[_size];
    fileread.read(_ptr,sizeof(char) * _size);
}

arrfile::arrfile(int size,char *ptr){
    memcpy((void *)_ptr,(void *)ptr,sizeof(char) * size);
    _size = size;
    delete [] ptr;    
}

arrfile arrfile::operator^(arrfile & rightoperator){
    assert(_size == rightoperator.size());
    char * pointer = new char[_size];
    int size = _size;
    for(int i = 0;i < _size;i++){
        pointer[i] = _ptr[i] ^ rightoperator[i];
    }
    arrfile object(size,pointer);
    return object;
}

char& arrfile::operator[](int index){
    assert(index < _size);
    return _ptr[index];
}