#ifndef pythTraits_hpp
#define pythTraits_hpp
template <typename T>
class PythTraits;

template<>
class PythTraits<char>
{
public:
    typedef unsigned int PType;
};

template<>
class PythTraits<unsigned char>
{
public:
    typedef unsigned int PType;
};

template<>
class PythTraits<short>
{
public:
    typedef unsigned int PType;
};

template<>
class PythTraits<unsigned short>
{
public:
    typedef unsigned int PType;
};

template<>
class PythTraits<int>
{
public:
    typedef unsigned long PType;
};

template<>
class PythTraits<unsigned int>
{
public:
    typedef unsigned long PType;
};

template<>
class PythTraits<float>
{
public:
    typedef double PType;
};

template<>
class PythTraits<double>
{
public:
    typedef long double PType;
};

#endif //pythTraits_hpp
