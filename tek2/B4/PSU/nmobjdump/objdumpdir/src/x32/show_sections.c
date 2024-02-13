/*
** EPITECH PROJECT, 2022
** nmobjdump
** File description:
** show_sections_64
*/

#include "objdump.h"
#include <string.h>
#include <stdio.h>

bool print_a_sec_32(char const *tabinfo, void *data, Elf32_Shdr *shdr, int i)
{
    unsigned char *value;
    uint32_t oct = 0;
    bool printed_enter = false;
    printf("Contents of section %s:\n", &tabinfo[shdr[i].sh_name]);
    while (oct < shdr[i].sh_size) {
        oct % 16 == 0 ? printf(" %06x", (uint32_t)(shdr[i].sh_addr + oct)) : 0;
        oct % 4 == 0 ? printf(" ") : 0;
        value = data + shdr[i].sh_offset + oct;
        printf("%02x", *value);
        printed_enter = show_ascii_values_32(&oct, data, shdr, i);
    }
    if (oct % 16) {
        print_spaces(oct);
        show_value_char((void*)(data + shdr[i].sh_offset + oct - (oct % 16)),
        (oct % 16));
        while (oct++ % 16)
            printf(" ");
    }
    return printed_enter;
}

bool is_valid_obj32(Elf32_Ehdr *elf, char const *strtab, Elf32_Shdr *shdr,
int i)
{
    if (elf->e_type == ET_REL &&
    (!strcmp(&strtab[shdr[i].sh_name], ".text") ||
    !strcmp(&strtab[shdr[i].sh_name], ".rodata") ||
    !strcmp(&strtab[shdr[i].sh_name], ".comment") ||
    !strcmp(&strtab[shdr[i].sh_name], ".eh_frame")))
        return true;
    return false;
}

bool is_valid_ex32(Elf32_Ehdr *elf, char const *strtab, Elf32_Shdr *shdr,
int i)
{
    if (elf->e_type == ET_EXEC
    && strcmp(&strtab[shdr[i].sh_name], ".symtab")
    && strcmp(&strtab[shdr[i].sh_name], ".bss")
    && strcmp(&strtab[shdr[i].sh_name], ".strtab")
    && strcmp(&strtab[shdr[i].sh_name], ".shstrtab"))
        return true;
    return false;
}

bool is_valid_so32(Elf32_Ehdr *elf, char const *strtab, Elf32_Shdr *shdr,
int i)
{
    char const *name = &strtab[shdr[i].sh_name];
    return (elf->e_type == ET_DYN && (!strcmp(name, ".note.gnu.build-id")
    || !strcmp(name, ".gnu.hash") || !strcmp(name, ".dynsym")
    || !strcmp(name, ".dynstr") || !strcmp(name, ".gnu.version")
    || !strcmp(name, ".gnu.version_r") || !strcmp(name, ".rela.dyn")
    || !strcmp(name, ".rela.plt") || !strcmp(name, ".init")
    || !strcmp(name, ".plt") || !strcmp(name, ".text")
    || !strcmp(name, ".fini") || !strcmp(name, ".eh_frame_hdr")
    || !strcmp(name, ".eh_frame") || !strcmp(name, ".init_array")
    || !strcmp(name, ".fini_array") || !strcmp(name, ".dynamic")
    || !strcmp(name, ".got") || !strcmp(name, ".got.plt")
    || !strcmp(name, ".comment") || !strcmp(name, ".gnu.build.attributes")));
}

void show_sections_32(t_objd *metadata, char const *tabinfo)
{
    for (int i = 0; i <= metadata->elf32->e_shnum; i++) {
        if (metadata->shdr32[i].sh_size &&
        (is_valid_obj32(metadata->elf32, tabinfo, metadata->shdr32, i) ||
        is_valid_ex32(metadata->elf32, tabinfo, metadata->shdr32, i))) {
            print_a_sec_32(tabinfo, metadata->content, metadata->shdr32, i)
            == true ? 0 : printf("\n");
        }
    }
}
