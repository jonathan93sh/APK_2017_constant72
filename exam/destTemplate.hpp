#ifndef destTemplate_hpp
#define destTemplate_hpp

#include "pythTraits.hpp"
#define MAX_DIM 5

template<int DIM, typename T>
class Position
{
    int Dim = DIM;
    T cor[DIM];
    typedef T Type;
};


template<typename T>
class SquareDiff
{
public:
    static T result(T* a, T* b)
    {
        return (*b - *a) * (*b -*a);
    }
    typedef T Type;
};



template<int DIM, typename T>
class AddSquareDiff
{
    static_assert(DIM < MAX_DIM, "Dimension is too large and could result in overflow.");
public:
    static typename PythTraits<T>::PType result(T* a, T* b)
    {
        return SquareDiff<T>::result(a,b)+AddSquareDiff<DIM-1,T>::result(a+1,b+1);
    }
    typedef T Type;
};

template<typename T>
class AddSquareDiff<1,T>
{
public:
    static typename PythTraits<T>::PType result(T* a, T* b)
    {
        return SquareDiff<T>::result(a,b);
    }
};

template<int DIM, typename T>
class Pythagroas
{
    public:
    static typename PythTraits<T>::PType result (T* a ,T* b)
    {
        return AddSquareDiff<DIM,T>::result(a,b);
    }
    typedef T Type;
};



template <int DIM, typename T>
inline typename PythTraits<T>::PType distance(T* a, T* b)
{
    return Pythagroas<DIM,T>::result(a,b);
}






#endif // destTemplate_hpp
