/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** Hospital
*/

#include "Hospital.hpp"
#include <iostream>

void printHospital()
{
    std::cout << "[HOSPITAL] ";
}

Hospital::Hospital()
{
    this->doctors = nullptr;
    this->nurses = nullptr;
    this->patients = nullptr;
}

Hospital::~Hospital()
{
}

void Hospital::addDoctor(KoalaDoctorList *doctor)
{
    if (this->doctors && this->doctors->getFromName(doctor->getContent()->getName()) == nullptr) {
        this->doctors->append(doctor);
        printHospital();
        std::cout << "Doctor " << doctor->getContent()->getName() << " just arrived!" << std::endl;
        doctor->getContent()->timeCheck();
    } else if (this->doctors == nullptr) {
        this->doctors = doctor;
        printHospital();
        std::cout << "Doctor " << doctor->getContent()->getName() << " just arrived!" << std::endl;
        doctor->getContent()->timeCheck();
    }
}

void Hospital::addNurse(KoalaNurseList *nurse)
{
    if (this->nurses && this->nurses->getFromID(nurse->getContent()->getID()) == nullptr) {
        this->nurses->append(nurse);
        printHospital();
        std::cout << "Nurse " << nurse->getContent()->getID() << " just arrived!" << std::endl;
        nurse->getContent()->timeCheck();
    } else if (this->nurses == nullptr) {
        this->nurses = nurse;
        printHospital();
        std::cout << "Nurse " << nurse->getContent()->getID() << " just arrived!" << std::endl;
        nurse->getContent()->timeCheck();
    }
}

void Hospital::addSick(SickKoalaList *sick)
{
    if (this->patients && this->patients->getFromName(sick->getContent()->getName()) == nullptr) {
        this->patients->append(sick);
        printHospital();
        std::cout << "Patient " << sick->getContent()->getName() << " just arrived!" << std::endl;
    } else if (this->patients == nullptr) {
        this->patients = sick;
        printHospital();
        std::cout << "Patient " << sick->getContent()->getName() << " just arrived!" << std::endl;
    }
}

void Hospital::removeAllLists()
{
    KoalaDoctorList *tmp_doc = this->doctors;
    KoalaNurseList *tmp_nur = this->nurses;
    SickKoalaList *tmp_pat = this->patients;
    while (tmp_nur) {
        this->nurses->remove(tmp_nur);
        tmp_nur = tmp_nur->getNext();
    }
    while (tmp_doc) {
        this->doctors->remove(tmp_doc);
        tmp_doc = tmp_doc->getNext();
    }
    while (tmp_pat) {
        this->patients->remove(tmp_pat);
        tmp_pat = tmp_pat->getNext();
    }
}

void Hospital::timeCheckAll()
{
    KoalaDoctorList *tmp_doc = this->doctors;
    KoalaNurseList *tmp_nur = this->nurses;
    while (tmp_nur) {
        tmp_nur->getContent()->timeCheck();
        tmp_nur = tmp_nur->getNext();
    }
    while (tmp_doc) {
        tmp_doc->getContent()->timeCheck();
        tmp_doc = tmp_doc->getNext();
    }
}

void Hospital::run()
{
    KoalaDoctorList *tmp_doc = this->doctors;
    KoalaNurseList *tmp_nur = this->nurses;
    SickKoalaList *tmp_pat = this->patients;
    printHospital();
    std::cout << "Work starting with:" << std::endl;
    this->doctors->dump();
    this->nurses->dump();
    this->patients->dump();
    std::cout << std::endl;

    while (tmp_pat) {
        tmp_doc->getContent()->diagnose(tmp_pat->getContent());
        tmp_nur->getContent()->giveDrug(tmp_nur->getContent()->readReport(tmp_pat->getContent()->getName() + ".report"), tmp_pat->getContent());
        tmp_pat = tmp_pat->getNext();
        if (tmp_doc->getNext())
            tmp_doc = tmp_doc->getNext();
        else
            tmp_doc = this->doctors;
        if (tmp_nur->getNext())
            tmp_nur = tmp_nur->getNext();
        else
            tmp_nur = this->nurses;
    }
    timeCheckAll();
    removeAllLists();
}
