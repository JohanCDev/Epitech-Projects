/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** hospital
*/

#ifndef __HOSPITAL__
#define __HOSPITAL__

#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"
#include "SickKoalaList.hpp"

class Hospital {
    public:
        Hospital();
        ~Hospital();
        void addDoctor(KoalaDoctorList *);
        void addSick(SickKoalaList *);
        void addNurse(KoalaNurseList *);
        void run();

    private:
        KoalaDoctorList *doctors;
        KoalaNurseList *nurses;
        SickKoalaList *patients;
        void timeCheckAll();
        void removeAllLists();
};

#endif

