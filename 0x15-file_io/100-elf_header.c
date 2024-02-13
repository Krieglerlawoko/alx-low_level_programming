/*
 * File: 100-elf_header.c
 * Auth: Judge K Lawoko
 */

#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks fo ELF file.
 * @e_ident: Points to array containing ELF magic numbers.
 *
 * Description: If the file is not an ELF file exits.
 */
void check_elf(unsigned char *e_ident)
{
	int a;

	for (a = 0; a < 4; a++)
	{
		if (e_ident[a] != 127 &&
		    e_ident[a] != 'E' &&
		    e_ident[a] != 'L' &&
		    e_ident[a] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Magic numbers of an ELF header printd.
 * @e_ident: Points to array containing ELF magic numbers.
 *
 * Description: Magic numbers separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int a;

	printf("  Magic:   ");

	for (a = 0; a < EI_NIDENT; a++)
	{
		printf("%02x", e_ident[a]);

		if (a == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Class of an ELF header printd.
 * @e_ident: Points to array containing ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Data of an ELF header printd.
 * @e_ident: Points to array containing ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - Version of an ELF header printd.
 * @e_ident: Points to array containing ELF version.
 */
void print_version(unsigned char *e_ident)
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
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
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
 * print_abi - ABI version of an ELF header printd.
 * @e_ident: Points to array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Type of an ELF header printd.
 * @e_type: ELF type.
 * @e_ident: Points to array containing ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Entry point of an ELF header printd.
 * @e_entry: Address of ELF entry point.
 * @e_ident: Points to array containing ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
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
 * close_elf - ELF file closed.
 * @elf: File descriptor of ELF file.
 *
 * Description: exit code 98 if can't be closed.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Info contained in the Elf
 *        header displayed.
 * @argc: No. of arguments supplied to the program.
 * @argv: Array of pointers to arguments.
 *
 * Return: 0 for success.
 *
 * Description: ELF File or exit code 98 for
 *              fail.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *hd;
	int a, k;

	a = open(argv[1], O_RDONLY);
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	hd = malloc(sizeof(Elf64_Ehdr));
	if (hd == NULL)
	{
		close_elf(a);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	k = read(a, hd, sizeof(Elf64_Ehdr));
	if (k == -1)
	{
		free(hd);
		close_elf(a);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(hd->e_ident);
	printf("ELF Header:\n");
	print_magic(hd->e_ident);
	print_class(hd->e_ident);
	print_data(hd->e_ident);
	print_version(hd->e_ident);
	print_osabi(hd->e_ident);
	print_abi(hd->e_ident);
	print_type(hd->e_type, hd->e_ident);
	print_entry(hd->e_entry, hd->e_ident);

	free(hd);
	close_elf(a);
	return (0);
}
