/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_output_lib
*/

#include "../Peasant.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(test_peasant, Peasant, .init = redirect_all_std)
{
    Peasant *peasant = new Peasant("Gildas", 11);
    peasant->attack();
    peasant->attack();
    peasant->special();
    peasant->damage(50);
    peasant->rest();
    peasant->damage(100);
    peasant->special();
    peasant->attack();
    peasant->damage(200);
    peasant->rest();
    delete peasant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas tosses a stone.\nGildas is out of power.\nGildas doesn't know any special move.\nGildas takes 50 damage.\nGildas takes a nap.\nGildas is out of combat.\nGildas is out of combat.\nGildas is out of combat.\nGildas is out of combat.\nGildas is out of combat.\nGildas is back to his crops.\n");
}