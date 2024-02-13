/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"
#include "SickKoala.hpp"
#include <iostream>
#include <string>
#include <fstream>

void print_id(int id)
{
    std::cout << "Nurse " << id << ": ";
}

KoalaNurse::KoalaNurse(int ID)
{
    this->_ID = ID;
    this->_is_working = false;
}

KoalaNurse::~KoalaNurse()
{
    print_id(this->_ID);
    std::cout << "Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream f(filename);
    std::string drug_to_give = "";
    std::string patient_name = "";

    if (filename.substr(filename.find_last_of('.')) == ".report") {
        patient_name = filename.substr(0, filename.find("."));
        if (f.is_open())
            getline(f, drug_to_give);
    }
    if (drug_to_give != "") {
        print_id(this->_ID);
        std::cout << "Kreog! Mr." << patient_name << " needs a " << drug_to_give << "!" << std::endl;
    }
    return drug_to_give;
}

void KoalaNurse::timeCheck()
{
    if (!this->_is_working) {
        this->_is_working = true;
        print_id(_ID);
        std::cout << "Time to get to work!" << std::endl;
    } else {
        this->_is_working = false;
        print_id(this->_ID);
        std::cout << "Time to go home to my eucalyptus forest!" << std::endl;
    }
}

int KoalaNurse::getID()
{
    return this->_ID;
}