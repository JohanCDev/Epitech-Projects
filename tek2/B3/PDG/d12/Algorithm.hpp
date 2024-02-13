/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
};

template<typename T>
T const &min(T const &a, T const &b)
{
    return a < b ? a : b;
}

template<typename T>
T const &max(T const &a, T const &b)
{
    return b < a ? a : b;
}

template<typename T>
T const &clamp(T const &value, T const &min, T const &max)
{
    if (value < min)
        return min;
    else if (max < value)
        return max;
    return value;
}

#endif /* !ALGORITHM_HPP_ */
