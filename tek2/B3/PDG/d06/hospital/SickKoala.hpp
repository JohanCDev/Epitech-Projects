/*
** EPITECH PROJECT, 2022
** Day06
** File description:
** SickKoala
*/

#ifndef __SICK_KOALA__
#define __SICK_KOALA__

#include <string>

class SickKoala {
    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string str);
        void overDrive(std::string str);
        std::string getName();

    private:
        std::string _name;
};

#endif
