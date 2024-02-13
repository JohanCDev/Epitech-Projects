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

        ToyType getType();
        std::string getName();
        std::string getAscii();

        void setName(std::string);
        bool setAscii(const std::string &);

        virtual void speak(const std::string &);

        Toy &operator=(const Toy &);
        Toy &operator<<(const char *);

    private:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

std::ostream &operator<<(std::ostream &, Toy &);

#endif /* !TOY_HPP_ */
