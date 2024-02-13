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
        enum ToyType { BASIC_TOY, ALIEN };
        Toy();
        Toy(ToyType, std::string, std::string);
        ~Toy();
        ToyType getType() const;
        std::string const &getName() const;
        std::string const &getAscii() const;
        void setName(std::string const & name);
        bool setAscii(std::string const & ascii);

    private:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
