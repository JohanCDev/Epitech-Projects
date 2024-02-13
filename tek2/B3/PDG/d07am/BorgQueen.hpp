/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** BorgQueen
*/

#ifndef __BORGQUEEN__
#define __BORGQUEEN__

#include "Borg.hpp"
#include "Federation.hpp"

namespace Borg {
    class BorgQueen {
            public:
                BorgQueen();
                ~BorgQueen();
                bool (Borg::Ship::*movePtr)(Destination) = &Borg::Ship::move;
                void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *) = &Borg::Ship::fire;
                void (Borg::Ship::*destroyPtr)(Federation::Ship *) = &Borg::Ship::fire;
                bool move(Borg::Ship *ship, Destination dest);
                void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
                void destroy(Borg::Ship *ship, Federation::Ship *target);

            private:
                std::string _name;
    };
}

#endif
