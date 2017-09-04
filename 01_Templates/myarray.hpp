#ifndef MYARRAY_HPP
#define MYARRAY_HPP


template<class T>
class MyArray
{
public:
    MyArray();
    ~MyArray();
    void fill(const T&);
    T* begin();
    T* end();
    T& operator[](int i);
    size_t size();
};



#endif // MYARRAY_HPP
