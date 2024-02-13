/*
** EPITECH PROJECT, 2022
** Day08
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    this->_exp = 0;
    this->_fingerprint = random();
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint() const
{
    return this->_fingerprint;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    this->_fingerprint = fingerprint;
}

size_t DroidMemory::getExp() const
{
    return this->_exp;
}

void DroidMemory::setExp(size_t exp)
{
    this->_exp = exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory &DroidMemory)
{
    this->_exp += DroidMemory._exp;
    this->_fingerprint = (DroidMemory._fingerprint ^ this->_fingerprint);
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &DroidMemory) const
{
    DroidMemory._exp += this->_exp;
    DroidMemory._fingerprint = (DroidMemory._fingerprint ^ this->_fingerprint);
    return DroidMemory;
}

DroidMemory &DroidMemory::operator+=(DroidMemory &DroidMemory)
{
    this->_exp += DroidMemory._exp;
    this->_fingerprint = (this->_fingerprint ^ DroidMemory._fingerprint);
    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    this->_exp += exp;
    this->_fingerprint = (this->_fingerprint ^ exp);
    return *this;
}

DroidMemory &DroidMemory::operator+(size_t exp) const
{
    DroidMemory droid;

    return droid.operator+=(exp);
}

DroidMemory &DroidMemory::operator+(DroidMemory &copy_Droid) const
{
    DroidMemory droid;

    return droid.operator+=(copy_Droid);
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &droid)
{
    return (os << "DroidMemory '" << droid.getFingerprint() << "', " << droid.getExp());
}

bool DroidMemory::operator==(DroidMemory &droid) const
{
    return (this->_fingerprint == droid._fingerprint &&
    this->_exp == droid._exp);
}

bool DroidMemory::operator<(DroidMemory &droid) const
{
    return this->_exp < droid._exp;
}

bool DroidMemory::operator<(size_t exp) const
{
    return this->_exp < exp;
}

bool DroidMemory::operator<=(DroidMemory &droid) const
{
    return this->_exp <= droid._exp;
}

bool DroidMemory::operator<=(size_t exp) const
{
    return this->_exp <= exp;
}

bool DroidMemory::operator>(DroidMemory &droid) const
{
    return this->_exp > droid._exp;
}

bool DroidMemory::operator>(size_t exp) const
{
    return this->_exp > exp;
}

bool DroidMemory::operator>=(DroidMemory &droid) const
{
    return this->_exp >= droid._exp;
}

bool DroidMemory::operator>=(size_t exp) const
{
    return this->_exp >= exp;
}
