/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** Stack
*/

#include "Stack.hpp"
#include <iostream>
#include <exception>

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(double value)
{
    this->stack.push(value);
}

double Stack::pop()
{
    double topElem;
    if (this->stack.size() == 0)
        throw Stack::Error("Empty stack");
    topElem = this->stack.top();
    this->stack.pop();
    return topElem;
}

double Stack::top() const
{
    if (this->stack.size() == 0)
        throw Stack::Error("Empty stack");
    return this->stack.top();
}

void Stack::add()
{
    double val1;
    double val2;
    if (this->stack.size() < 2)
        throw Stack::Error("Not enough operands");
    val1 = this->pop();
    val2 = this->pop();
    this->push(val1 + val2);
}

void Stack::sub()
{
    double val1;
    double val2;
    if (this->stack.size() < 2)
        throw Stack::Error("Not enough operands");
    val1 = this->pop();
    val2 = this->pop();
    this->push(val1 - val2);
}

void Stack::mul()
{
    double val1;
    double val2;
    if (this->stack.size() < 2)
        throw Stack::Error("Not enough operands");
    val1 = this->pop();
    val2 = this->pop();
    this->push(val1 * val2);
}

void Stack::div()
{
    double val1;
    double val2;
    if (this->stack.size() < 2)
        throw Stack::Error("Not enough operands");
    val1 = this->pop();
    val2 = this->pop();
    this->push(val1 / val2);
}