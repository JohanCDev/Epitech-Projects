/*
** EPITECH PROJECT, 2022
** Day08
** File description:
** DroidMemory
*/

#ifndef __DROIDMEMORY__
#define __DROIDMEMORY__

#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();
        size_t getFingerprint() const;
        void setFingerprint(size_t fingerprint);
        size_t getExp() const;
        void setExp(size_t exp);

        DroidMemory &operator<<(DroidMemory &);
        DroidMemory &operator>>(DroidMemory &) const;
        DroidMemory &operator+=(DroidMemory &);
        DroidMemory &operator+=(size_t);
        DroidMemory &operator+(DroidMemory &) const;
        DroidMemory &operator+(size_t) const;
        bool operator==(DroidMemory &) const;
        bool operator!=(DroidMemory &) const;
        bool operator<(DroidMemory &) const;
        bool operator<(size_t) const;
        bool operator>(DroidMemory &) const;
        bool operator>(size_t) const;
        bool operator<=(DroidMemory &) const;
        bool operator<=(size_t) const;
        bool operator>=(DroidMemory &) const;
        bool operator>=(size_t) const;

    private:
        size_t _fingerprint;
        size_t _exp;
};

std::ostream &operator<<(std::ostream &, const DroidMemory &);

#endif

