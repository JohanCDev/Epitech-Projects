/*
** EPITECH PROJECT, 2022
** Day10PM
** File description:
** Errors
*/

#ifndef __ERRORS_HPP__
#define __ERRORS_HPP__

#include <string>

class NasaError : public std::exception
{
private:
    std::string _message;
    std::string _component;

public:
    NasaError(std::string const &, std::string const & = "Unknown");
    virtual ~NasaError() throw(){};
    std::string const &getComponent() const;
    const char *what() const throw() { return _message.c_str(); };
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
        virtual ~MissionCriticalError() throw() {};
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
        virtual ~LifeCriticalError() throw() {};
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
        virtual ~UserError() throw() {};
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        virtual ~CommunicationError() throw() {};
};

#endif