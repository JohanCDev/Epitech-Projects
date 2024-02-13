/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** SickKoalaList
*/

#ifndef __SICKKOALALIST__
#define __SICKKOALALIST__

#include <string>
#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *);
        ~SickKoalaList();
        bool isEnd();
        void append(SickKoalaList *);
        SickKoala *getFromName(std::string);
        SickKoalaList *remove(SickKoalaList *);
        SickKoala *getContent();
        SickKoalaList *getNext();
        SickKoalaList *removeFromName(std::string);
        void dump();

    private:
        SickKoala *data;
        SickKoalaList *next;
};

#endif