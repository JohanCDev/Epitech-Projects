/*
** EPITECH PROJECT, 2022
** tekSpice
** File description:
** ParserError
*/

#ifndef PARSERERROR_HPP_
#define PARSERERROR_HPP_

#include <exception>
#include <string>

namespace nts::Parser::error
{
    class ParserError : std::exception {
        public:
            ParserError(std::string const &message = "Unknown Error") { this->_what = message; }
            ~ParserError() override = default;
            const char *what() const noexcept override { return this->_what.c_str(); }

        protected:
            std::string _what;
        private:
    };

    class FileNotOpened : public ParserError {
        public:
            FileNotOpened(std::string const &message) : ParserError(message) {};
            virtual ~FileNotOpened() throw() {};
    };

    class EmptyFileContent : public ParserError {
        public:
            EmptyFileContent(std::string const &message) : ParserError(message) {};
            virtual ~EmptyFileContent() throw() {};
    };
}

#endif /* !PARSERERROR_HPP_ */
