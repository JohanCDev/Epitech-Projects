/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** Federation
*/

#ifndef __FEDERATION__
#define __FEDERATION__

#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg
{
    class Ship;
}

namespace Federation
{
    namespace Starfleet
    {
        class Captain {
            public:
                Captain(std::string);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int);

            private:
                std::string _name;
                int _age;
        };
        class Ship {
            public:
                Ship(int, int, std::string, short, int = 0);
                Ship();
                ~Ship();
                void setupCore(WarpSystem::Core *);
                void checkCore();
                void promote(Federation::Starfleet::Captain *);
                bool move(int, Destination);
                bool move(int);
                bool move(Destination);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *);
                void fire(int, Borg::Ship *);

            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *core;
                Captain *captain;
                Destination _location;
                Destination _home;
                int _shield;
                int _photonTorpedo;
        };

        class Ensign {
            public:
                explicit Ensign(std::string);
                ~Ensign();

            private:
                std::string _name;
        };
    }

    class Ship {
        public:
            Ship(int, int, std::string);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore();
            bool move(int, Destination);
            bool move(int);
            bool move(Destination);
            bool move();
            WarpSystem::Core *getCore();

        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *core;
            Destination _location;
            Destination _home;
    };
}

#endif
