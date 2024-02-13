/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>

class Picture
{
    public:
        Picture();
        Picture(const std::string &);
        ~Picture();
        std::string data;
        bool getPictureFromFile(const std::string &);
        Picture &operator=(const Picture &);

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
