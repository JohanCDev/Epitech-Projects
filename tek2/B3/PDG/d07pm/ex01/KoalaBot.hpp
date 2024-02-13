/*
** EPITECH PROJECT, 2022
** Day07P
** File description:
** KoalaBot
*/

#ifndef __KOALABOT__
#define __KOALABOT__

#include <string>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string = "Bob-01");
        ~KoalaBot();
        void setParts(const Arms &);
        void setParts(const Legs &);
        void setParts(const Head &);
        void swapParts(Arms &);
        void swapParts(Legs &);
        void swapParts(Head &);
        void informations() const;
        bool status() const;

    private:
        Head _Head;
        Arms _Arms;
        Legs _Legs;
        std::string _serial;
};

#endif
