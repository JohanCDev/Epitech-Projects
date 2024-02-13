/*
** EPITECH PROJECT, 2022
** Day07P
** File description:
** Parts
*/

#ifndef __PARTS__
#define __PARTS__

#include <string>

class Arms {
    public:
        Arms(std::string = "A-01", bool = true);
        ~Arms();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;

    private:
        bool _functionnal;
        std::string _serial;
};

class Legs {
    public:
        Legs(std::string = "L-01", bool = true);
        ~Legs();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;

    private:
        bool _functionnal;
        std::string _serial;
};

class Head {
    public:
        Head(std::string = "H-01", bool = true);
        ~Head();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;

    private:
        bool _functionnal;
        std::string _serial;
};

#endif
