#include <iostream>
using namespace std;

class obj{
public:
    int x;
    obj(){
        x = 1;
    }
    obj& operator+(obj& right){
        x += right.x;
        return *this;
    }

};
int main(){
    obj A,B;
    A+B;
    cout << A.x << endl;    
}