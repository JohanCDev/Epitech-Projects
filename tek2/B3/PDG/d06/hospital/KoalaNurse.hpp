/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaNurse
*/

#ifndef __KOALA_NURSER__
#define __KOALA_NURSER__

#include <string>
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int ID);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *koala);
        std::string readReport(std::string filename);
        void timeCheck();
        int getID();

    private:
        int _ID;
        bool _is_working;
};

#endif
