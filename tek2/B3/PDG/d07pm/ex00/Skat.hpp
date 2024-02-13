/*
** EPITECH PROJECT, 2022
** Day07P
** File description:
** Skat
*/

#ifndef __SKAT__
#define __SKAT__

#include <string>

class Skat {
    public:
        Skat(const std::string = "bob", int = 15);
        ~Skat();
        int &stimPaks();
        const std::string &name();
        void shareStimPaks(int, int &);
        void addStimPaks(unsigned int);
        void useStimPaks();
        void status();

    protected:
    private:
        std::string _name;
        int _stimPaks;
};

#endif
