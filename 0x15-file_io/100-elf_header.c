#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ck_elf(unsigned char *ei_id);
void pt_magic(unsigned char *ei_id);
void pt_class(unsigned char *ei_id);
void pt_data(unsigned char *ei_id);
void pt_version(unsigned char *ei_id);
void pt_abi(unsigned char *ei_id);
void pt_osabi(unsigned char *ei_id);
void pt_type(unsigned int e_type, unsigned char *ei_id);
void pt_entry(unsigned long int e_entry, unsigned char *ei_id);
void clo_elf(int elf);

/**
* ck_elf - Checks if a file is an ELF file.
* @ei_id: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file - exit code 98.
*/
void ck_elf(unsigned char *ei_id)
{
int idx;

for (idx = 0; idx < 4; idx++)
{
if (ei_id[idx] != 127 &&
ei_id[idx] != 'E' &&
ei_id[idx] != 'L' &&
ei_id[idx] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* pt_magic - Prints the magic numbers of an ELF header.
* @ei_id: A pointer to an array containing the ELF magic numbers.
*
* Description: Magic numbers are separated by spaces.
*/
void pt_magic(unsigned char *ei_id)
{
int idx;

printf("  Magic:   ");

for (idx = 0; idx < EI_NIDENT; idx++)
{
printf("%02x", ei_id[idx]);

if (idx == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
* pt_class - Prints the class of an ELF header.
* @ei_id: A pointer to an array containing the ELF class.
*/
void pt_class(unsigned char *ei_id)
{
printf("  Class:                             ");

switch (ei_id[EI_CLASS])
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
printf("<unknown: %x>\n", ei_id[EI_CLASS]);
}
}

/**
* pt_data - Prints the data of an ELF header.
* @ei_id: A pointer to an array containing the ELF class.
*/
void pt_data(unsigned char *ei_id)
{
printf("  Data:                              ");

switch (ei_id[EI_DATA])
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
printf("<unknown: %x>\n", ei_id[EI_CLASS]);
}
}

/**
* pt_version - Prints the version of an ELF header.
* @ei_id: A pointer to an array containing the ELF version.
*/
void pt_version(unsigned char *ei_id)
{
printf("  Version:                           %d",
ei_id[EI_VERSION]);

switch (ei_id[EI_VERSION])
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
* @ei_id: A pointer to an array containing the ELF version.
*/
void pt_osabi(unsigned char *ei_id)
{
printf("  OS/ABI:                            ");

switch (ei_id[EI_OSABI])
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
printf("<unknown: %x>\n", ei_id[EI_OSABI]);
}
}

/**
* pt_abi - Prints the ABI version of an ELF header.
* @ei_id: A pointer to an array containing the ELF ABI version.
*/
void pt_abi(unsigned char *ei_id)
{
printf("  ABI Version:                       %d\n",
ei_id[EI_ABIVERSION]);
}

/**
* pt_type - Prints the type of an ELF header.
* @e_type: The ELF type.
* @ei_id: A pointer to an array containing the ELF class.
*/
void pt_type(unsigned int e_type, unsigned char *ei_id)
{
if (ei_id[EI_DATA] == ELFDATA2MSB)
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
* @ei_id: A pointer to an array containing the ELF class.
*/
void pt_entry(unsigned long int e_entry, unsigned char *ei_id)
{
printf("  Entry point address:               ");

if (ei_id[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}

if (ei_id[EI_CLASS] == ELFCLASS32)
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

ck_elf(header->ei_id);
printf("ELF Header:\n");
pt_magic(header->ei_id);
pt_class(header->ei_id);
pt_data(header->ei_id);
pt_version(header->ei_id);
pt_osabi(header->ei_id);
pt_abi(header->ei_id);
pt_type(header->e_type, header->ei_id);
pt_entry(header->e_entry, header->ei_id);

free(header);
clo_elf(o);
return (0);
}
