class arrfile{
public:
    int _size;
    char * _ptr;
    arrfile(char * filename);
    arrfile(int size,int * ptr);
    arrfile operator^(arrfile &rightoperator);
    char& operator[](int index);
    int size(){
        return _size;
    }
};