#include <iostream>
#include <string.h>
using namespace std;
class object{
public:
    object(int size){
        cout << "initial the arr\n";
        ptr = new int[size];
        _size = size;
    }
    object(object & ob){
        cout << "copy object\n";
        _size = ob._size;
        ptr = new int[_size];
        memcpy(ptr,ob.ptr,sizeof(int) * _size);
    }
    object(object && ob){
        cout << "move copy function\n";
        _size = ob._size;
        ptr = ob.ptr;
        ob._size = 0;
        ob.ptr = nullptr;
    }
    ~object(){
        // _size = 0;
        if(_size != 0)
            delete [] ptr;
        _size = 0;
    }
    int * ptr;
    int _size;


};
object & retobj(){
    
}
int main(){
    object obj(4);
    
    object && rightref = std::move(obj);
    object anotherobj(std::move(obj));
    // int n = 3;
    // object * ptr = new object[3]{1,2,3};
}