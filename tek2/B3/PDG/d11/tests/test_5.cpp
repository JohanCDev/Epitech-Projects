/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_output_lib
*/

#include "../ex05/Toy.hpp"
#include "../ex05/Woody.hpp"
#include "../ex05/Buzz.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>

void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_base, Woody, .init = redirect_all_std)
{
    Woody woo("woo", "./tests/woody.txt");
    Buzz buzz("woo", "./tests/buzz.txt");
    Toy to;
    Buzz buzzInv("woo", "Invalid-file");
    Woody wooBis = woo;
    std::cout << woo;
    woo.speak("Hey Man");
    woo.speak_es("YIHA");
    buzz.speak_es("Hola chica");
    to.getType();
    buzz.setAscii("aoizgjr");
    buzz.setAscii("./tests/woody.txt");
}

Test(test_picture, Picture, .init = redirect_all_std)
{
    Picture();
    Picture("zuhg");
    Picture("buzz.txt");

}