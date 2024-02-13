/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_output_lib
*/

#include "../Knight.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(test_knight, Knight, .init = redirect_all_std)
{
    Knight *knight = new Knight("Arthur", 70);
    knight->attack();
    knight->special();
    knight->rest();
    knight->special();
    knight->special();
    knight->attack();
    knight->attack();
    knight->attack();
    knight->special();
    knight->damage(100);
    knight->attack();
    knight->special();
    knight->rest();
    delete knight;
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\nArthur vows to protect the kingdom.\nArthur strikes with his sword.\nArthur impales his enemy.\nArthur eats.\nArthur impales his enemy.\nArthur impales his enemy.\nArthur strikes with his sword.\nArthur strikes with his sword.\nArthur is out of power.\nArthur is out of power.\nArthur is out of combat.\nArthur is out of combat.\nArthur is out of combat.\nArthur is out of combat.\nArthur takes off his armor.\nArthur is back to his crops.\n");
}