/*
** EPITECH PROJECT, 2022
** Day08
** File description:
** Droid
*/

#ifndef __DROID__
#define __DROID__

#include <string>

class Droid {
    public:
        Droid(std::string = "");
        Droid(const Droid &);
        ~Droid();
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        void setId(std::string);
        void setEnergy(size_t);
        void setStatus(std::string *);
        bool operator==(const Droid &) const;
        bool operator!=(const Droid &) const;
        Droid& operator=(Droid const &);
        Droid &operator<<(size_t &);

    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
};
std::ostream &operator<<(std::ostream &, const Droid &);

#endif
