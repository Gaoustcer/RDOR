#include <iostream>
using namespace std;
class object{
public:
    ~object(){
        cout << "delete the class\n";
    }
};

object retobj(){
    object obj;
    cout << "function return\n";
    return obj;
}

int main(){
    object inst(retobj());
    cout << "main return\n";
}