/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy : public Picture
{

    public:
        class Error
        {
            public:
                enum ErrorType {UNKNOWN, PICTURE, SPEAK};
                Error();
                ~Error();
                const std::string &what() const;
                const std::string &where() const;
                ErrorType type;
                std::string _what;
                std::string _where;
        };

        enum ToyType { BASIC_TOY, ALIEN, BUZZ, WOODY };
        Toy();
        Toy(ToyType, std::string, std::string);
        virtual ~Toy();
        ToyType getType() const;
        std::string const &getName() const;
        std::string const &getAscii() const;
        void setName(std::string const & name);
        bool setAscii(std::string const & ascii);
        Toy &operator=(Toy const &toy);
        virtual void speak(const std::string &message);
        virtual bool speak_es(const std::string &message);
        Toy &operator<<(const char *ascii);
        Toy::Error const &getLastError() const;
        Toy::Error _error;

    protected:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

std::ostream &operator<<(std::ostream &, Toy &);

#endif /* !TOY_HPP_ */
