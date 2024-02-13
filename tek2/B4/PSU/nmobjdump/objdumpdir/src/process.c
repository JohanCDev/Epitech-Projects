/*
** EPITECH PROJECT, 2022
** nmobjdump
** File description:
** process
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include "objdump.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

void free_all(t_objd *metadata)
{
    free(metadata->content);
    free(metadata->filename);
}

void process32(t_objd *metadata)
{
    metadata->shdr32 = (Elf32_Shdr*)(metadata->content +
    metadata->elf32->e_shoff);
    char *tabinfo = (char*)(metadata->content +
    metadata->shdr32[metadata->elf32->e_shstrndx].sh_offset);
    show_file_info_32(metadata, tabinfo);
}

void process64(t_objd *metadata)
{
    metadata->shdr = (Elf64_Shdr*)(metadata->content + metadata->elf->e_shoff);
    char *tabinfo = (char*)(metadata->content +
    metadata->shdr[metadata->elf->e_shstrndx].sh_offset);
    show_file_info_64(metadata, tabinfo);
}

bool process_single(char const *filename)
{
    t_objd metadata;

    metadata.content = open_and_read_file(filename);
    metadata.filename = strdup(filename);
    if (metadata.content == NULL || metadata.filename == NULL)
        return false;
    metadata.elf = (Elf64_Ehdr *) metadata.content;
    metadata.elf32 = (Elf32_Ehdr *) metadata.content;
    if (is_elf(metadata.elf) == false) {
        free_all(&metadata);
        return false;
    }
    metadata.is64 = metadata.elf->e_ident[4] == ELFCLASS32 ? false : true;
    if (metadata.is64)
        process64(&metadata);
    else
        process32(&metadata);
    free_all(&metadata);
    return true;
}

bool process_all(char **argv)
{
    bool has_an_error = false;
    for (int i = 0; argv[i]; i++) {
        printf("\n%s:\n", argv[i]);
        if (process_single(argv[i]) == false)
            has_an_error = true;
    }
    return has_an_error;
}
