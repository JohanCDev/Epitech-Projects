/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_output_lib
*/

#include "../Enchanter.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(test_Echanter, Enchanter, .init = redirect_all_std)
{
    Enchanter *enchant = new Enchanter("Gildas", 11);
    enchant->attack();
    enchant->attack();
    enchant->special();
    enchant->damage(50);
    enchant->rest();
    enchant->damage(100);
    enchant->special();
    enchant->attack();
    enchant->damage(200);
    enchant->rest();
    delete enchant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas learns magic from his spellbook.\nGildas doesn't know how to fight.\nGildas doesn't know how to fight.\nGildas is out of power.\nGildas takes 50 damage.\nGildas meditates.\nGildas is out of combat.\nGildas is out of combat.\nGildas is out of combat.\nGildas is out of combat.\nGildas is out of combat.\nGildas closes his spellbook.\nGildas is back to his crops.\n");
}

Test(test_echant50, Enchanter, .init = redirect_all_std)
{
    Enchanter *enchant = new Enchanter("Gildas", 50);
    enchant->special();
    delete enchant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas learns magic from his spellbook.\nGildas casts a fireball.\nGildas closes his spellbook.\nGildas is back to his crops.\n");
}