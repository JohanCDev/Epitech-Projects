/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** Command
*/

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <map>
#include <string>
#include <functional>

class Command {
    public:
        Command();
        ~Command();
        void registerCommand(const std::string& name, const std::function<void()>& function);
        void executeCommand(const std::string& name);
        class Error : public std::exception {
            public:
                Error(std::string message) : _message(message) {}
                const char* what() const throw() {return _message.c_str();}
            private:
                std::string _message;
        };

    protected:
    private:
        std::map<std::string, std::function<void()>> _map;
};

#endif /* !COMMAND_HPP_ */
