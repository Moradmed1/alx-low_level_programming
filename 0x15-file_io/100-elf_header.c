#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ch_elf(unsigned char *p_id);
void pr_magic(unsigned char *p_id);
void pt_class(unsigned char *p_id);
void pt_data(unsigned char *p_id);
void pt_ver(unsigned char *p_id);
void pt_abi(unsigned char *p_id);
void pt_osabi(unsigned char *p_id);
void pt_type(unsigned int e_type, unsigned char *p_id);
void pt_entry(unsigned long int e_entry, unsigned char *p_id);
void clo_elf(int elf);

/**
 * ch_elf – does Checks if a file is an ELF file.
 * @p_id: is A pointer to magic numbers.
 *
 * Description: If not an ELF file - exit code 98.
 */
void ch_elf(unsigned char *p_id)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (p_id[idx] != 127 &&
		    p_id[idx] != 'E' &&
		    p_id[idx] != 'L' &&
		    p_id[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * pr_magic – deos Prints the magic nbrs of an ELF header.
 * @p_id: is A pointer to magic numbers.
 *
 * Description: Magic nbr separated by spaces.
 */
void pr_magic(unsigned char *p_id)
{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", p_id[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * pt_class – does Prints class of an ELF hr.
 * @p_id: is A pointer to ELF class.
 */
void pt_class(unsigned char *p_id)
{
	printf(" Class: ");

	switch (p_id[EI_CLASS])
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
		printf("<unknown: %x>\n", p_id[EI_CLASS]);
	}
}

/**
 * pt_data – does Prints   data ELF header.
 * @p_id: is A pointer to an array ELF class.
 */
void pt_data(unsigned char *p_id)
{
	printf(" Data: ");

	switch (p_id[EI_DATA])
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
		printf("<unknown: %x>\n", p_id[EI_CLASS]);
	}
}

/**
 *  * pt_ver – does Prints the ver of ELF header.
 *   * @p_id: is pointer to an array ELF ver.
 *    */
void pt_ver(unsigned char *p_id)
{
	 printf(" Version: %d",
			  p_id[EI_VERSION]);

	switch (p_id[EI_VERSION])
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
 * pt_osabi – does Prints the OS/ABI of ELF header.
 * @p_id: is pointer to an array ELF version.
 */
void pt_osabi(unsigned char *p_id)
{
	printf(" OS/ABI: ");

	switch (p_id[EI_OSABI])
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
		printf("<unknown: %x>\n", p_id[EI_OSABI]);
	}
}

/**
 * pt_abi – does Prints the ABI ver elf.
 * @p_id: is pointer to an array ELF ABI version.
 */
void pt_abi(unsigned char *p_id)
{
	printf(" ABI Version: %d\n",
		p_id[EI_ABIVERSION]);
}

/**
 * pt_type – does Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @p_id: is pointer to an array  ELF class.
 */
void pt_type(unsigned int e_type, unsigned char *p_id)
{
	if (p_id[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

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
 * pt_entry – does Prints  entry point of ELF head.
 * @e_entry: is address of ELF entry point.
 * @p_id: is pointer to an array ELF class.
 */
void pt_entry(unsigned long int e_entry, unsigned char *p_id)
{
	printf(" Entry point address: ");

	if (p_id[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (p_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * clo_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If cant be closed - exit code 98.
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
 * main – does Displays the info contained in the
 * ELF header at the start of an ELF file.
 * @argc: is nbr of arg supplied to the program.
 * @argv: An array of pointers to the args.
 *
 * Return: 0.
 *
 * Description: If is not an ELF File or
 * the function fails - exit code 98.
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

	ch_elf(header->p_id);
	printf("ELF Header:\n");
	pr_magic(header->p_id);
	pt_class(header->p_id);
	pt_data(header->p_id);
	pt_ver(header->p_id);
	pt_osabi(header->p_id);
	pt_abi(header->p_id);
	pt_type(header->e_type, header->p_id);
	pt_entry(header->e_entry, header->p_id);

	free(header);
	clo_elf(o);
	return (0);
}
