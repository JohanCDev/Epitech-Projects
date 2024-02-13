/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** Admiral
*/

#ifndef __ADMIRAL__
#define __ADMIRAL__

#include <string>
#include "Federation.hpp"

namespace Federation {
    namespace Starfleet {
        class Admiral {
            public:
                Admiral(std::string);
                ~Admiral();
                bool (Federation::Starfleet::Ship::*movePtr)(Destination) = &Federation::Starfleet::Ship::move;
                void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *) = &Federation::Starfleet::Ship::fire;
                bool move(Federation::Starfleet::Ship *, Destination);
                void fire(Federation::Starfleet::Ship *, Borg::Ship *);

            private:
                std::string _name;
        };
    }
}

#endif
