#include <iostream>
using namespace std;
class object{
public:
    object(){
        cout << "create\n";
    }
    ~object(){
        cout << "deconstruct\n";
    }
    
};
object returnobject(){
    return object();
}
int main(){
    object value = returnobject();
    object obj;    
}