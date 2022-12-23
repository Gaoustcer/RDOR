#include <iostream>
using namespace std;

int global = 0;
class simpleclass{
public:
    simpleclass(){
        cout << "construct " << global << endl;
        // global ++;
        id = global;
        global ++;
    }
    ~simpleclass(){
        cout << "deconstruct " << id << endl;
    }
    // simpleclass(simpleclass &construct){
    //     cout << "copy construction function\n";
    //     id = construct.id;
    // }
    // simpleclass & operator=(simpleclass & rig){
    //     cout << "copy construct function\n";
    //     id = rig.id;
    // }
    int id;

};
int * retref(){
    int x = 10;
    cout << "local address " << &x << endl;
    return &x;
}
simpleclass retasnoclass(){
    simpleclass obj;
    return obj;
    // return simpleclass();
}

simpleclass returnclass(){
    simpleclass obj;
    // return simpleclass();
    return obj;
}
simpleclass & returnclassref(){
    simpleclass ref;
    return ref;
}
int main(){
    simpleclass obj = returnclass();
    // simpleclass obj = returnclass();
    // obj = returnclass;
    cout << "return object\n";
    simpleclass & ref = returnclassref();
    // simpleclass && ref = returnclass();
    // simpleclass leftvalue;
    // simpleclass rightvalue(returnclass());
    cout << "function return\n";
    cout << "ref id " << ref.id << endl;
    // simpleclass & obj = rightvalue;
    // int * ref = retref();
    // cout << ref << endl;
    // *ref = 1024;
    // cout << ref << endl;
}