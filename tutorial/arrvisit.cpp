#include <iostream>
using namespace std;
class object{
public:
    object(){
        ptr = new int[10];
    }
    ~object(){
        delete [] ptr;
    }
    int & operator[](int index){
        return ptr[index];
    }
    int * ptr;
};

int main(){
    object arr;
    arr[1] = 1024;
    cout << arr[1] << endl;
}