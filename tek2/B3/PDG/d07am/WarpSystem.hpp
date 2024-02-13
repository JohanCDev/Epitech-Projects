/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** WarpSystem
*/

#ifndef __WARP_SYSTEM__
#define __WARP_SYSTEM__

namespace WarpSystem
{
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool);

        private:
            bool _stability;
    };

    class Core {
        public:
            Core(QuantumReactor *reactor);
            ~Core();
            QuantumReactor *checkReactor();

        private:
            QuantumReactor *_coreReactor;
    };
}

#endif
