/*
** EPITECH PROJECT, 2022
** nmobjdump
** File description:
** print
*/

#include <elf.h>
#include "objdump.h"
#include "my.h"
#include <string.h>

void show_flags_info_64(Elf64_Ehdr *elf, Elf64_Shdr *shdr)
{
    bool p = false;
    if (elf->e_type == ET_EXEC)
        p ? printf(", EXEC_P") : (printf("EXEC_P"), p = true);
    if (elf->e_type == ET_REL)
        p ? printf(", HAS_RELOC") : (printf("HAS_RELOC"), p = true);
    for (int i = 0; i < elf->e_shnum; i++)
        if (shdr[i].sh_type == SHT_SYMTAB)
            p ? printf(", HAS_SYMS") : (printf("HAS_SYMS"), p = true);
    if (elf->e_type == ET_DYN)
        p ? printf(", DYNAMIC") : printf("DYNAMIC"), p = true;
    if (elf->e_phnum > 0)
        p ? printf(", D_PAGED") : (printf("D_PAGED"), p = true);
}

bool show_ascii_values_64(uint32_t *oct, void *data, Elf64_Shdr *shdr, int i)
{
    if (++(*oct) % 16 == 0) {
        show_value_char((void*)(data + shdr[i].sh_offset + *oct - 16), 16);
        printf("\n");
        return true;
    }
    return false;
}

char const *get_machine_type_64(Elf64_Ehdr *elf)
{
    switch (elf->e_machine) {
    case EM_X86_64:
    case EM_386:
        return "i386";
    default:
        return "unknown";
    }
}

void show_file_info_64(t_objd *metadata, char const *tabinfo)
{
    printf("\n%s:\tfile format %s\n", metadata->filename, "elf64-x86-64");
    printf("architecture: %s, flags 0x%08x:\n",
    get_machine_type_64(metadata->elf),
    get_flags_address_64(metadata->elf, metadata->shdr));
    show_flags_info_64(metadata->elf, metadata->shdr);
    printf("\nstart address 0x%016lx\n\n", (size_t)(metadata->elf->e_entry));
    show_sections_64(metadata, tabinfo);
}
