#include<iostream>

using namespace std;

template <typename T>
class SharedPointer {
    T* _ptr;
    int *_count;

public:
    SharedPointer(T* ptr) {
        this->_ptr = ptr;
        this->_count = new int(1);
    }
    SharedPointer() {
        this->_ptr = nullptr;
        this->_count = new int(0);
    }

    ~SharedPointer() {
        if(this->_count != nullptr) {
            (*this->_count)--;
            if(*this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }
    }

    SharedPointer(const SharedPointer<T>& other) {
        this->_ptr = other._ptr;
        this->_count = other._count;
        (*this->_count)++;
    }

    SharedPointer<T>& operator=(const SharedPointer<T>& other) {
        this->_ptr = other._ptr;
        this->_count = other._count;
        (*this->_count)++;
        return *this;
    }

    void reset() {
        if(this->_count != nullptr) {
            (*this->_count)--;
            if(*this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
            this->_count = nullptr;
            this->_ptr = nullptr;
        }
    }

    T *get()
    {
        return this->_ptr;
    }

    T* operator->() {
        return this->_ptr;
    }
};