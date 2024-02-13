/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_output_lib
*/

#include "../Priest.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(test_priest, Priest, .init = redirect_all_std)
{
    Priest *pri = new Priest("Gildas", 11);
    pri->attack();
    pri->attack();
    pri->special();
    pri->damage(50);
    pri->rest();
    pri->damage(100);
    pri->special();
    pri->attack();
    pri->damage(200);
    pri->rest();
    delete pri;
}