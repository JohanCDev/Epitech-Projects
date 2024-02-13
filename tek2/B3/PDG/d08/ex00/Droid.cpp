/*
** EPITECH PROJECT, 2022
** Day08
** File description:
** Droid
*/

#include "Droid.hpp"
#include <iostream>

/* Constructors */

Droid::Droid(std::string serial): _energy(50), _attack(25), _toughness(15)
{
    this->_id = serial;
    this->_status = new (std::string)("Standing by");
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &copy): _energy(copy._energy), _attack(copy._attack), _toughness(copy._toughness), _status(new (std::string)(*copy._status))
{
    this->_id = copy._id;
    std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

/* Destructor */

Droid::~Droid()
{
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

/* Operators */

bool Droid::operator==(const Droid &droid) const
{
    return (droid._attack == this->_attack &&
            droid._energy == this->_energy &&
            droid._id == this->_id &&
            droid._status == this->_status &&
            droid._toughness == this->_toughness);
}

bool Droid::operator!=(const Droid &droid) const
{
    return (!(this->operator==(droid)));
}

Droid &Droid::operator<<(size_t &charge)
{
    if ((100 - this->_energy) > charge) {
        charge -= charge;
        this->_energy += charge;
    } else {
        charge -= (100 - this->_energy);
        this->_energy += (100 - this->_energy);
    }
    return *this;
}

Droid& Droid::operator=(Droid const &droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    delete this->_status;
    this->_status = new std::string(*droid._status);
    return *this;
}

/* Setters */

void Droid::setEnergy(size_t energy)
{
    this->_energy = energy;
}

void Droid::setId(std::string id)
{
    this->_id = id;
}

void Droid::setStatus(std::string *status)
{
    this->_status = status;
}

/* Getters */

std::string Droid::getId() const
{
    return this->_id;
}

size_t Droid::getEnergy() const
{
    return this->_energy;
}

size_t Droid::getAttack() const
{
    return this->_attack;
}

size_t Droid::getToughness() const
{
    return this->_toughness;
}

std::string *Droid::getStatus() const
{
    return this->_status;
}

std::ostream &operator<<(std::ostream &os, const Droid &droid)
{
    return (os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy());
}