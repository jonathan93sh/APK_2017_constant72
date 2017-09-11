#ifndef MYARRAY_HPP
#define MYARRAY_HPP

#include <exception>

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

    void fill(const T& item)
    {
        T * tmp = new T[size_ + 1];

        for(auto i = 0; i < size_; i++)
            tmp[i] = data_[i];

        delete[] data_;

        data_ = tmp;

        data_[size_++] = item;
    }

    const T * const begin() const
    {
        return (size_ == 0 ? nullptr : &data_[0]);
    }

    const T * const end() const
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
        T& ref = this->operator [](i);
        return ref;

    }

    size_t size() const
    {
        return size_;
    }

private:


    T * data_;
    size_t size_;
};



#endif // MYARRAY_HPP
