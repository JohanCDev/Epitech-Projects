/*
** EPITECH PROJECT, 2021
** B-MAT-200-NAN-2-1-106bombyx-johan.chrillesen
** File description:
** main
*/

#include "my.h"
#include <stdbool.h>
#include <math.h>

bool is_integar(double value)
{
    int casted = (int)value;

    return (casted == value);
}

bool check_if_nb_are_num(char **numbers)
{
    for (int i = 2; numbers[i]; i++) {
        if (!my_str_isnum(numbers[i], 1))
            return (0);
    }
    return (1);
}

int check_errors(int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-h")) {
        my_printf("USAGE\n\t./108trigo fun a0 a1 a2 ...\n\nDESCRIPTION\n\tfun\tfunction to be applied, among at least 'EXP', 'COS', 'SIN', 'COSH'\n\t\tand 'SINH'\n\tai\tcoeficients of the matrix\n");
        return (1);
    } else if (strcmp("EXP", argv[1]) && strcmp("COS", argv[1]) && strcmp("SIN", argv[1]) && strcmp("COSH", argv[1]) && strcmp("SINH", argv[1]))
        return (-1);
    else if (!is_integar(sqrt(argc - 2)))
        return (-1);
    if (!check_if_nb_are_num(argv)) {
        return (-1);
    }
    return (0);
}

int *fill_list(int *num_list, char *str)
{
    int index = 0;
    int i = 0;
    my_revstr(str);

    if (my_strlen(str) <= 1) {
        num_list[0] = my_getnbr(str);
        num_list[1] = -1;
        return (num_list);
    }
    while (str[i]) {
        num_list[index] = my_getnbr(&str[i]);
        i += my_strlen(my_itoa(num_list[index])) + 1;
        index++;
    }
    num_list[index - 1] = -1;
    return (num_list);
}

double compute_result(int *list, int x)
{
    double result = 0;
    int i = 0;

    while (list[i] != -1) {
        printf("list[%d] = %d\n", i, list[i]);
        result = (result * x) + (float) list[i];
        i++;
    }
    return (result);
}

int main(int argc, char **argv)
{
    int ret = check_errors(argc, argv);

    if (ret == -1)
        return (84);
    else if (ret == 1)
        return (0);
    
    return (0);
}