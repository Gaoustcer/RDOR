#include <iostream>
using namespace std;
class simpleclass{
public:
    simpleclass(){
        cout << "create the class\n";
        // 
        ptr = new int[10];
        for(int i = 0;i < 10;i++){
            ptr[i] = i;
        }
    }
    ~simpleclass(){
        cout << "deconstruct the class\n";
        delete [] ptr;
    }
    void operator=(simpleclass & obj){
        ptr = new int[10];
        cout << "copy construct\n";
    }
    simpleclass operator+(simpleclass & rightop){
        simpleclass obj;
        for(int i = 0;i < 10;i ++){
            obj.ptr[i] += rightop.ptr[i];
        }
        return obj;
    }

    int * ptr;
};

// simpleclass & retref(){
//     simpleclass object;
//     return object;
// }

int main(){
    simpleclass inst1,inst2;
    
    // retref();
    // cout << "after call";
}
//     simpleclass obj;
//     obj = retref();
//     return 0;
// }

