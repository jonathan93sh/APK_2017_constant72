#ifndef MYARRAY_HPP
#define MYARRAY_HPP

#include <exception>
#include <memory.h>
#include "sharedptr.h"


template<class T>
class MyArray
{
public:



    MyArray()
        :data_(nullptr), size_(0){}

    ~MyArray()
    {
        delete[] data_;
    }
    
    // for at løse ex. 1.4 laver vi vores assigment operator og copy-constuctor, som templates metoder.
    // dette gøre det muligt at kompileren selv kan finde ud af at lave en implicit cast af værdierne fra.
    // det andet array.
    template<typename T2>
    MyArray<T>(const MyArray<T2> &other)
    {
        this->operator =(other);
    }
    
    
    template<typename T2> 
    MyArray<T> &operator=(const MyArray<T2> &other)
    {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        for(auto i = 0; i < other.size(); i++)
        {
            this->fill(other[i]); // vil implicit caste typen
        }
        return *this;
    }

    void fill(const T& item)
    {
        T * tmp = new T[size_ + 1];

        for(auto i = 0; i < size_; i++)
            tmp[i] = data_[i];

        delete[] data_;

        data_ = tmp;

        data_[size_++] = item;
    }

    const T * begin() const
    {
        return (size_ == 0 ? nullptr : &data_[0]);
    }

    const T * end() const
    {
        return (size_ == 0 ? nullptr : &data_[size_-1]);
    }

    T& operator[](int i)
    {
        if( 0 <= i && i < size_)
        {
            return data_[i];
        }
        else
        {
            throw std::out_of_range ("out of index: ERROR");
        }

    }

    const T& operator[](int i) const
    {
        if( 0 <= i && i < size_)
        {
            return data_[i];
        }
        else
        {
            throw std::out_of_range ("out of index: ERROR");
        }

    }

    size_t size() const
    {
        return size_;
    }

private:


    T * data_;
    size_t size_;
};


template<class T>
class MyArray<T*>
{
public:




    MyArray()
        :data_(nullptr), size_(0){}

    ~MyArray()
    {
        for(auto i = 0; i < size_; i++)
        {
            delete data_[i];
        }
        delete[] data_;
    }


    template<typename T2>
    MyArray<T*>(const MyArray<T2*> &other)
    {
        this->operator =(other);
    }


    template<typename T2>
    MyArray<T*> &operator=(const MyArray<T2*> &other)
    {
        for(auto i = 0; i < size_; i++)
        {
            delete[] data_[i];
        }
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        for(auto i = 0; i < other.size(); i++)
        {
            this->fill(other[i]); // vil implicit caste typen
        }
        return *this;
    }

    // for løse problemet med fill, laver vi to overloads af metoden fill.
    // den ene tager en ekstra parameter hvor man beskrive størrelsen.
    // den anden bruger dependen name, og kan derfor kun bruges af objekter der har en gyldig copy-construtor.
 /*   void fill(const T* item, size_t size)
    {
        T ** tmp = new T*[size_ + 1];

        for(auto i = 0; i < size_; i++)
            tmp[i] = data_[i];

        delete[] data_;

        data_ = tmp;

        data_[size_++] = new T[size];
        memcpy(data_[size_-1],item,size);
    }*/

    void fill(T * item)
    {
        //size_t size = item->size();
        SharedPtr<T> ** tmp = new SharedPtr<T>*[size_ + 1];

        for(auto i = 0; i < size_; i++)
            tmp[i] = data_[i];

        delete[] data_;

        data_ = tmp;

        data_[size_++] = new SharedPtr<T>(item);
    }

    SharedPtr<T> * * begin() const
    {
        if (size_ == 0 )
        {
            return nullptr;
        }
        else
        {
            return &data_[0];
        }
        return (size_ == 0 ? nullptr : &data_[0]);
    }

    SharedPtr<T> * * end() const
    {
        if (size_ == 0 )
        {
            return nullptr;
        }
        else
        {
            return &data_[size_-1];
        }
        return (size_ == 0 ? nullptr : &data_[size_-1]);
    }


    /*SharedPtr<const T> & operator[](int i) const
    {
        if( 0 <= i && i < size_)
        {
            return data_[i].operator ->();
        }
        else
        {
            throw std::out_of_range ("out of index: ERROR");
        }

    }*/

    SharedPtr<T> & operator[](int i)
    {
        if( 0 <= i && i < size_)
        {
            return *data_[i];
        }
        else
        {
            throw std::out_of_range ("out of index: ERROR");
        }

    }



    size_t size() const
    {
        return size_;
    }

private:

    SharedPtr<T> ** data_;
    size_t size_;
};




template<typename T, typename V>
const T* myfind(const T* first,const T* last, const V& v)
{
    if(first == nullptr || last == nullptr || first > last)
        return nullptr;

    const T* ptr = first;
    while(ptr != last + 1)
    {
        if(*ptr == v)
        {
            return ptr;
        }
        ptr++;

    }
    return nullptr;
}

template < typename T, typename V>
T** myfind (T** first , T** last , const V& v)
{
    if(first == nullptr || last == nullptr || first > last)
        return nullptr;

    T** ptr = first;
    while(ptr != last + 1)
    {
        if(**(*ptr) == v)
        {
            return ptr;
        }
        ptr++;

    }
    return nullptr;
}




#endif // MYARRAY_HPP
