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

void show_flags_info_32(Elf32_Ehdr *elf, Elf32_Shdr *shdr)
{
    bool p = false;
    if (elf->e_type == ET_EXEC)
        p ? printf(", EXEC_P") : (printf("EXEC_P"), p = true);
    if (elf->e_type == ET_REL)
        p ? printf(", HAS_RELOC") : (printf("HAS_RELOC"), p = true);
    if (elf->e_type == ET_DYN)
        p ? printf(", HAS_SYMS DYNAMIC") : printf("HAS_SYMS DYNAMIC"), p = true;
    for (int i = 0; i < elf->e_shnum; i++)
        if (shdr[i].sh_type == SHT_SYMTAB)
            p ? printf(", HAS_SYMS") : (printf("HAS_SYMS"), p = true);
    if (elf->e_phnum > 0)
        p ? printf(", D_PAGED") : (printf("D_PAGED"), p = true);
}

bool show_ascii_values_32(uint32_t *oct, void *data, Elf32_Shdr *shdr, int i)
{
    if (++(*oct) % 16 == 0) {
        show_value_char((void*)(data + shdr[i].sh_offset + *oct - 16), 16);
        printf("\n");
        return true;
    }
    return false;
}

char const *get_machine_type_32(Elf32_Ehdr *elf)
{
    switch (elf->e_machine) {
    case EM_X86_64:
    case EM_386:
        return "i386";
    default:
        return "unknown";
    }
}

void show_file_info_32(t_objd *metadata, char const *tabinfo)
{
    printf("\n%s:\tfile format %s\n", metadata->filename, "elf64-x86-32");
    printf("architecture: %s, flags 0x%08x:\n",
    get_machine_type_32(metadata->elf32),
    get_flags_address_32(metadata->elf32, metadata->shdr32));
    show_flags_info_32(metadata->elf32, metadata->shdr32);
    printf("\nstart address 0x%08lx\n\n", (size_t)(metadata->elf32->e_entry));
    show_sections_32(metadata, tabinfo);
}
