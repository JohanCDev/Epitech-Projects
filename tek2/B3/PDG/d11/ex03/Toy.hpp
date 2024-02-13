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
        enum ToyType { BASIC_TOY, ALIEN, BUZZ, WOODY };
        Toy();
        Toy(ToyType, std::string, std::string);
        virtual ~Toy();
        ToyType getType() const;
        std::string const &getName() const;
        std::string const &getAscii() const;
        void setName(std::string const &);
        bool setAscii(std::string const &);
        Toy &operator=(Toy const &);
        virtual void speak(std::string const &);

    private:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
