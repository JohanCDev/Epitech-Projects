/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

template<typename T>
class UniquePointer {
    public:
        UniquePointer(T *t = nullptr) {
            this->_ptr = t;
        };
        ~UniquePointer() {
            delete this->_ptr;
        };
        void reset()
        {
            delete this->_ptr;
            this->_ptr = nullptr;
        }
        T *get() const
        {
            return this->_ptr;
        }
        T &operator=(T *uptr) {
            if (this->_ptr == uptr)
                return *this->_ptr;
            this->reset();
            this->_ptr = uptr;
            return *this->_ptr;
        }
        T *operator->() const
        {
            return this->_ptr;
        }
        T *_ptr;

    protected:
    private:
};

#endif /* !UNIQUEPOINTER_HPP_ */