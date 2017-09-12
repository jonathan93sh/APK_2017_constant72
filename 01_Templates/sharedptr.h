#ifndef SHAREDPTR_H
#define SHAREDPTR_H

template<typename T>
class SharedPtr
{
public:
    // gøre vores constructor explicit, da vi ikke ønsker at der skal ske
    explicit SharedPtr(T* t)
        :ptr_(nullptr), count_(nullptr)
    {
        count_ = new size_t;
        (*count_) = 1;
        ptr_ = t;
    }

    explicit SharedPtr(const SharedPtr<T>& other)
        :ptr_(nullptr), count_(nullptr)
    {
        count_ = new size_t;
        (*count_) = 1;
        this->operator =(other);
    }


    SharedPtr &operator=(T * t)
    {
        return *this = SharedPtr<T>(t);
    }

    SharedPtr &operator=(const SharedPtr<T>& other)
    {
        *(other.count_) += *count_;
        delete count_;
        count_ = other.count_;
        delete ptr_;
        ptr_ = other.ptr_;
        return *this;
    }

    ~SharedPtr()
    {
        if((*count_) == 1)
        {
            delete ptr_;
            delete count_;
        }
        else
        {
            (*count_)--;
        }
    }


    T& operator*()
    {
        return *ptr_;
    }

    T* operator->()
    {
        return ptr_;
    }

    size_t count()
    {
        return *count_;
    }
private:
    size_t * count_;
    T * ptr_;
};


#endif // SHAREDPTR_H
