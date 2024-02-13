/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** koaladoctorlist
*/

#ifndef __KOALADOCTORLIST__
#define __KOALADOCTORLIST__

#include <string>
#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *);
        ~KoalaDoctorList();
        bool isEnd();
        void append(KoalaDoctorList *);
        KoalaDoctor *getFromName(std::string);
        KoalaDoctorList *remove(KoalaDoctorList *);
        KoalaDoctor *getContent();
        KoalaDoctorList *getNext();
        KoalaDoctorList *removeFromName(std::string);
        void dump();

    private:
        KoalaDoctor *data;
        KoalaDoctorList *next;
};

#endif