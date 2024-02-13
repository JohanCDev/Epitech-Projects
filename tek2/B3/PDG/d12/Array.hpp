/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <functional>
#include <exception>

template <typename T, size_t N>
class Array
{
    public:
	T *array;

       Array() {
            this->array = new T[N];
        }
        ~Array() {
            delete[] this->array;
        }
        T const &operator[](size_t index) const
        {
            if (index < 0 || index >= N)
                throw std::out_of_range("Out of range");
            return this->array[index];
        }
        T &operator[](size_t index)
        {
            if (index < 0 || index >= N)
                throw std::out_of_range("Out of range");
            return this->array[index];
        }
        std::size_t size() const
        {
            return N;
        }

        void forEach(const std::function<void(const T &)>& task) const
        {
            for (size_t i = 0; i < N; i++)
                task(this->array[i]);
        }

        template <typename U>
        Array<U, N> convert(const std::function<U(const T &)>& converter) const
        {
            Array<U, N> tmp;
            for (size_t i = 0; i < N; i++)
                tmp[i] = converter(this->array[i]);
            return tmp;
        }
};

template<typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const Array<T, N> &array)
{
    os << "[";
    size_t i = 0;
    for (; i < N - 1; i++) {
        os << array[i];
        os << ", ";
    }
    os << array[i];
    return os << "]";
}

#endif /* !ARRAY_HPP_ */
