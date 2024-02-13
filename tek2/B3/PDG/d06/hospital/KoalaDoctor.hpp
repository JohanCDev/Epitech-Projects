/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaDoctor
*/

#ifndef __KOALA_DOCTOR__
#define __KOALA_DOCTOR__

#include <string>
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();
        void diagnose(SickKoala *koala);
        void timeCheck();
        std::string getName();

    private:
        std::string _name;
        bool _is_working;
};

#endif