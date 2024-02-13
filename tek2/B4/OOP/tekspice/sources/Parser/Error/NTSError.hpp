/*
** EPITECH PROJECT, 2022
** tekSpice
** File description:
** NTSError
*/

#ifndef NTSERROR_HPP_
#define NTSERROR_HPP_

#include <exception>
#include <string>
#include "ParserError.hpp"

namespace nts::Parser::error {
    class NTSError : public nts::Parser::error::ParserError
    {
        public:
            NTSError(std::string const &message = "Unknown Error") { this->_what = message; }
            virtual ~NTSError() override = default;

        private:
    };

    class BadFormat : public NTSError
    {
        public:
            BadFormat(std::string const &message) : NTSError(message){};
            virtual ~BadFormat() throw() {};
    };

    class InvalidLinkName : public NTSError
    {
        public:
            InvalidLinkName(std::string const &message) : NTSError(message){};
            virtual ~InvalidLinkName() throw() {};
    };
}

#endif /* !NTSERROR_HPP_ */
