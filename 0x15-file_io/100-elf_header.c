#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ck_elf(unsigned char *e_ident);
void pt_magic(unsigned char *e_ident);
void pt_class(unsigned char *e_ident);
void pt_data(unsigned char *e_ident);
void pt_version(unsigned char *e_ident);
void pt_abi(unsigned char *e_ident);
void pt_osabi(unsigned char *e_ident);
void pt_type(unsigned int e_type, unsigned char *e_ident);
void pt_entry(unsigned long int e_entry, unsigned char *e_ident);
void clo_elf(int elf);

/**
* ck_elf - does checks ELF file.
* @e_ident: is pointer.
*
* Description: If not ELF file - exit code 98.
*/
void ck_elf(unsigned char *e_ident)
{
int idx;

for (idx = 0; idx < 4; idx++)
{
if (e_ident[idx] != 127 &&
e_ident[idx] != 'E' &&
e_ident[idx] != 'L' &&
e_ident[idx] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* pt_magic - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: Magic numbers are separated by spaces.
*/
void pt_magic(unsigned char *e_ident)
{
int idx;

printf("  Magic:   ");

for (idx = 0; idx < EI_NIDENT; idx++)
{
printf("%02x", e_ident[idx]);

if (idx == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
* pt_class - Prints the class of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void pt_class(unsigned char *e_ident)
{
printf("  Class:                             ");

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* pt_data - Prints the data of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void pt_data(unsigned char *e_ident)
{
printf("  Data:                              ");

switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
* pt_version - Prints the version of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void pt_version(unsigned char *e_ident)
{
printf("  Version:                           %d",
e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
* pt_osabi - Prints the OS/ABI of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void pt_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");

switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
* pt_abi - Prints the ABI version of an ELF header.
* @e_ident: A pointer to an array containing the ELF ABI version.
*/
void pt_abi(unsigned char *e_ident)
{
printf("  ABI Version:                       %d\n",
e_ident[EI_ABIVERSION]);
}

/**
* pt_type - Prints the type of an ELF header.
* @e_type: The ELF type.
* @e_ident: A pointer to an array containing the ELF class.
*/
void pt_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf("  Type:                              ");

switch (e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}

/**
* pt_entry - Prints the entry point of an ELF header.
* @e_entry: The address of the ELF entry point.
* @e_ident: A pointer to an array containing the ELF class.
*/
void pt_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:               ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}

if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);

else
printf("%#lx\n", e_entry);
}

/**
* clo_elf - Closes an ELF file.
* @elf: The file descriptor of the ELF file.
*
* Description: If the file cannot be closed - exit code 98.
*/
void clo_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", elf);
exit(98);
}
}

/**
* main - Displays the information contained in the
*        ELF header at the start of an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: If the file is not an ELF File or
*              the function fails - exit code 98.
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int o, r;

o = open(argv[1], O_RDONLY);
if (o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
clo_elf(o);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
clo_elf(o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

ck_elf(header->e_ident);
printf("ELF Header:\n");
pt_magic(header->e_ident);
pt_class(header->e_ident);
pt_data(header->e_ident);
pt_version(header->e_ident);
pt_osabi(header->e_ident);
pt_abi(header->e_ident);
pt_type(header->e_type, header->e_ident);
pt_entry(header->e_entry, header->e_ident);

free(header);
clo_elf(o);
return (0);
}


