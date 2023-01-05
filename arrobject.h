#include <vector>

class arrfile{
public:
    int _size;
    char * _ptr;
    arrfile();
    arrfile(char * filename);// open file and write the content into object
    arrfile(int size,char * ptr); // allocate a space with size and memcpy from ptr
    arrfile(int size); // allocate a space with size memory
    arrfile(std::vector<arrfile *>& );
    arrfile& operator^(arrfile &rightoperator);
    char& operator[](int index);
    int size(){
        return _size;
    }
    // void moveptr(char * ptr){
    //     _ptr =  ptr;
    // }
    arrfile(arrfile &&);
    ~arrfile();
    arrfile & operator=(arrfile &&);
    arrfile & operator=(arrfile &);
    arrfile & operator+(arrfile &);
    void save(const char*);
};
#define P 5
arrfile * separate(arrfile &,int);
arrfile ** getcheckblock(arrfile &,int dividenum = P);
void save(std::vector<arrfile*> &,const char *);
void getbaseline();