#include <iostream>
// #include <string>
#include <string.h>
using namespace std;
class object{
public:
    object(int * p,int _size){
        cout << "construct the class\n";
        ptr = p;
        size = _size;
    }
    ~object(){
        if(size){
            delete [] ptr;
            cout << "delete the object\n";
        }
    }
    object(object & rightvalue){
        cout << "This is direct copy function\n";
        size = rightvalue.getsize();
        ptr = new int[size];
        // cout << "copy size is" << size << endl;
        // for(int i = 0;i < size;i++){
        //     // rightvalue.ptr[i] += 1;
        //     ptr[i] = rightvalue.ptr[i];
        //     cout << i << endl;
        // }
        memcpy(ptr,rightvalue.ptr,sizeof(int) * size);
        cout << "finish directly copy\n";
    }
    object(object && rightvalue){
        cout << "This is move copy function\n";
        size = rightvalue.getsize();
        ptr = rightvalue.getpointer();
        rightvalue.size = 0;

    }
    object& operator=(object & rightvalue){
        cout << "This is normal assignment function\n";
        size = rightvalue.size;
        ptr = new int[size];
        memcpy(ptr,rightvalue.ptr,sizeof(int) * rightvalue.size);
        cout << "finish normal assignment function\n";
        return *this;
    }
    object& operator=(object &&rightvalue){
        cout << "This is move assignment function\n";
        size = rightvalue.size;
        ptr = rightvalue.ptr;
        rightvalue.size = 0;
        rightvalue.ptr = nullptr;
        return *this;
    }
    int getsize(){
        return size;
    }
    int * getpointer(){
        return ptr;
    }
    void setvalue(int _value){
        size = _value;
    }
    void setpointer(){
        ptr = nullptr;
    }
// private:
    int * ptr;
    int size;
};

int main(){
    int * ptr = new int[1024];
    object obj(ptr,1024);
    object anotherobj = std::move(obj);
    // object anotherobj(std::move(obj));
    // cout << obj.size << endl;
}