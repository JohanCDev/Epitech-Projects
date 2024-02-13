/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** Federation
*/

#include "Federation.hpp"
#include <iostream>
#include "Borg.hpp"

void printStart(std::string name)
{
    std::cout << "USS " << name << ": ";
}

void printInfoShip(std::string name, int length, int width, short maxWarp, int photonTorpedo)
{
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
    if (photonTorpedo)
        std::cout << "Weapons are set: " << photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship()
{
    this->_length = 239;
    this->_width = 132;
    this->_name = "Entreprise";
    this->_maxWarp = 6;
    this->_home = Destination::EARTH;
    this->_location = _home;
    this->_shield = 100;
    this->_photonTorpedo = 0;
    printInfoShip(this->_name, this->_length, this->_width, this->_maxWarp, this->_photonTorpedo);
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_home = Destination::EARTH;
    this->_location = _home;
    this->_shield = 100;
    this->_photonTorpedo = torpedo;
    printInfoShip(this->_name, this->_length, this->_width, this->_maxWarp, this->_photonTorpedo);
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->core = core;
    printStart(this->_name);
    std::cout << "The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    printStart(this->_name);
    std::cout << "The core is " << (this->core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

bool Federation::Starfleet::Ship::move()
{
    if (this->core->checkReactor()->isStable() == true) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= this->_maxWarp)
        return move();
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != this->_location)
        return true;
    return false;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (move(d) && warp <= this->_maxWarp) {
        this->_location = d;
        return true;
    } else
        return move(warp);
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    target->setShield(target->getShield() - 50);
    this->_photonTorpedo--;
    std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (this->_photonTorpedo < torpedoes) {
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
        return;
    }
    std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    target->setShield(target->getShield() - 50 * torpedoes);
    this->_photonTorpedo -= torpedoes;
    std::cout << this->_name << ": No more torpedo to fire, " << this->captain->getName() << "!" << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    this->captain = captain;
    std::cout << this->captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

int Federation::Starfleet::Ship::getShield()
{
    return this->_shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    this->_home = Destination::VULCAN;
    this->_location = _home;
    std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::checkCore()
{
    std::cout << this->_name << ": The core is " << (this->core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

bool Federation::Ship::move()
{
    if (this->core->checkReactor()->isStable() == true) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= this->_maxWarp)
        return move();
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != this->_location)
        return true;
    return false;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (move(d) && warp <= this->_maxWarp) {
        this->_location = d;
        return true;
    } else
        return move(warp);
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return this->core;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return this->_name;
}

int Federation::Starfleet::Captain::getAge()
{
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}