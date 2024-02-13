/*
** EPITECH PROJECT, 2022
** Day07P
** File description:
** KreogCom
*/

#ifndef __KREOGCOM__
#define __KREOGCOM__

class KreogCom {
    public:
        KreogCom(int, int, int);
        ~KreogCom();
        void addCom(int, int, int);
        void removeCom();
        KreogCom *getCom() const;
        void ping() const;
        void locateSquad() const;

    private:
        const int m_serial;
        int _pos_x;
        int _pos_y;
        KreogCom *_next;
};

#endif
