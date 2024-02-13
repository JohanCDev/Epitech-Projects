/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** Borg
*/

#include "Borg.hpp"
#include <iostream>
#include "Federation.hpp"

Borg::Ship::Ship(int, int)
{
    this->_maxWarp = 9;
    this->_side = 300;
    this->_home = Destination::UNICOMPLEX;
    this->_location = _home;
    this->_shield = 100;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::checkCore()
{
    std::cout << (this->core->checkReactor()->isStable() ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->core = core;
}

bool Borg::Ship::move()
{
    if (this->core->checkReactor()->isStable() == true) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int warp)
{
    if (warp <= this->_maxWarp)
        return move();
    return false;
}

bool Borg::Ship::move(Destination d)
{
    if (d != this->_location)
        return true;
    return false;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (move(d) && warp <= this->_maxWarp) {
        this->_location = d;
        return true;
    } else
        return move(warp);
}

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Borg::Ship::getShield()
{
    return this->_shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

void borg_printFire(int gwFrequency)
{
    std::cout << "Firing on target with " << gwFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - this->_weaponFrequency);
    borg_printFire(this->_weaponFrequency);
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    borg_printFire(this->_weaponFrequency);
}

void Borg::Ship::repair()
{
    if (this->_repair > 0) {
        this->_repair--;
        this->_shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting furthur instructions." << std::endl;
    }
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
}