/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** Stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stack>
#include <string>

class Stack {
    public:
        Stack();
        ~Stack();
        void push(double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();
        class Error : public std::exception {
            public:
                Error(std::string message) : _message(message) {}
                const char* what() const throw() {return _message.c_str();}
            private:
                std::string _message;
        };

    protected:
    private:
        std::stack<double> stack;
};

#endif /* !STACK_HPP_ */
