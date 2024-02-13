/*
** EPITECH PROJECT, 2022
** Day06
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void convert(float value, std::string scale)
{
    float res;

    if (!scale.compare("Celsius")) {
        res = 9.0 / 5.0 * value + 32;
        std::cout << std::setw(16) << std::fixed << res << std::setw(16) << "Fahrenheit" << std::endl;
    } else if (!scale.compare("Fahrenheit")) {
        res = 5.0 / 9.0 * (value - 32);
        std::cout << std::setw(16) << std::fixed << res << std::setw(16) << "Celsius" << std::endl;
    }
}

int main(int argc, char **argv)
{
    float temp;
    std::string scale;

    std::cin >> temp >> scale;
    std::cout.precision(3);
    convert(temp, scale);
    return 0;
}
