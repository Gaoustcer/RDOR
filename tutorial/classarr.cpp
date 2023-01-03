#include <iostream>
#include <vector>

using namespace std;
class object{
public:
    object(){
        cout << "class create\n";
    }
    ~object(){
        cout << "class deconstruct\n";
    }
};

int main(){
    
    vector<object> vec;
    // object obj;
    vec.push_back(object());
}