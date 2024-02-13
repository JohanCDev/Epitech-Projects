/*
** EPITECH PROJECT, 2022
** nmobjdump
** File description:
** getters
*/

#include "objdump.h"

int get_flags_address_64(Elf64_Ehdr *elf, Elf64_Shdr *shdr)
{
    int value = 0;

    if (elf->e_type == ET_EXEC)
        value |= 0x02;
    if (elf->e_type == ET_DYN)
        value |= 0x40 | 0x10;
    if (elf->e_phnum > 0)
        value |= 0x100;
    if (elf->e_type == ET_REL)
        value |= 0x01;
    for (int i = 0; i < elf->e_shnum; i++)
        if (shdr[i].sh_type == SHT_SYMTAB)
            value |= 0x10;
    return value;
}
