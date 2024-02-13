/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** BorgQueen
*/

#include "BorgQueen.hpp"

Borg::BorgQueen::BorgQueen()
{
}

Borg::BorgQueen::~BorgQueen()
{
}

void Borg::BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
{
    (*ship.*firePtr)(target);
}

void Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
    (*ship.*destroyPtr)(target);
}

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
    return (*ship.*movePtr)(dest);
}