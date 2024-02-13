/*
** EPITECH PROJECT, 2022
** Day06
** File description:
** main
*/

#include <iostream>
#include <fstream>

void print_file(const char *file_name)
{
    std::ifstream f(file_name);

    if (f.is_open())
        std::cout << f.rdbuf();
    else
        std::cerr << "my_cat: " << file_name << ": No such file or directory" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
        print_file(argv[i]);
    return 0;
}
