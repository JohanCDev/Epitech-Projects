/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaNurseList
*/

#ifndef __KOALANURSELIST__
#define __KOALANURSELIST__

#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
        KoalaNurseList(KoalaNurse *);
        ~KoalaNurseList();
        bool isEnd();
        void append(KoalaNurseList *);
        KoalaNurse *getFromID(int);
        KoalaNurseList *remove(KoalaNurseList *);
        KoalaNurse *getContent();
        KoalaNurseList *getNext();
        KoalaNurseList *removeFromID(int);
        void dump();

    private:
        KoalaNurse *data;
        KoalaNurseList *next;
};

#endif