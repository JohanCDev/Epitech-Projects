/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_output_lib
*/

#include "../Paladin.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(test_paladin, Paladin, .init = redirect_all_std)
{
    Paladin *pala = new Paladin("Gildas", 11);
    pala->attack();
    pala->attack();
    pala->special();
    pala->damage(50);
    pala->rest();
    pala->damage(100);
    pala->special();
    pala->attack();
    pala->damage(200);
    pala->rest();
    delete pala;
}