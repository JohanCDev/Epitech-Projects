/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** Borg
*/

#ifndef __BORG__
#define __BORG__

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation
{
    namespace Starfleet {
        class Captain;
        class Ship;
        class Ensign;
    }
    class Ship;
}


namespace Borg {
    class Ship {
        public:
            Ship(int = 20, int = 20);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore();
            bool move(int, Destination);
            bool move(int);
            bool move(Destination);
            bool move();
            void setShield(int);
            int getShield();
            int getWeaponFrequency();
            void setWeaponFrequency(int);
            short getRepair();
            void setRepair(short);
            void fire(Federation::Starfleet::Ship *);
            void fire(Federation::Ship *);
            void repair();


        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *core;
            Destination _location;
            Destination _home;
            int _shield;
            int _weaponFrequency;
            short _repair;
    };
}

#endif
