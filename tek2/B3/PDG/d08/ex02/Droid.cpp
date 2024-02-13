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
    this->_BattleData = new DroidMemory();
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &copy): _energy(50), _attack(copy._attack), _toughness(copy._toughness), _status(new (std::string)(*copy._status))
{
    this->_id = copy._id;
    this->_BattleData = new DroidMemory();
    this->_BattleData->setExp(copy._BattleData->getExp());
    this->_BattleData->setFingerprint(copy._BattleData->getFingerprint());
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
    return *this->_status == *(droid._status);
}

bool Droid::operator!=(const Droid &droid) const
{
    return !(*this == droid);
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
    this->_energy = 50;
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

bool Droid::operator()(std::string const *task, size_t exp)
{
	std::string *tmp = new std::string(*task);
    if (this->_energy <= 10) {
        this->_energy = 0;
        this->setStatus(new std::string("Battery Low"));
        return false;
    } else {
        this->_energy -= 10;
        if (*this->_BattleData >= exp) {
            *tmp += " - Completed!";
            this->setStatus(tmp);
            this->_BattleData->setExp(this->_BattleData->getExp() + exp / 2);
            return true;
        } else {
            *tmp += " - Failed!";
            this->setStatus(tmp);
            this->_BattleData->setExp(this->_BattleData->getExp() + exp);
            return false;
        }
    }
    return false;
}