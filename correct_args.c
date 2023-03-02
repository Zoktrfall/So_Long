#include "so_long.h"

int	print_one_argument_error(void)
{
	write(1, "Error\nPlease Enter A Map Name\n", 30);
	return (1);
}

void	print_warning(void)
{
	write(1, "Only The First File Would Be Used\n", 34);
}

int	print_file_error(void)
{
	write(1, "Error\nMap Should Be A (*.ber) File\n", 35);
	return (1);
}

int	check_ber(char *arg, char *ber)
{
	size_t	len_arg;
	size_t	len_ber;

	len_arg = ft_strlen(arg);
	len_ber = ft_strlen(ber);
	if (len_arg == len_ber)
		return (1);
	while (len_ber > 0)
	{
		--len_arg;
		--len_ber;
		if (arg[len_arg] != ber[len_ber])
			return (1);
	}
	if (arg[--len_arg] == ' ' || arg[--len_arg] == '\t')
		return (1);
	len_ber = ft_strlen(ber);
	len_ber--;
	while (arg[len_arg] == ber[len_ber])
		len_ber--;
	if (len_ber == 0)
		return (1);
	return (0);
}

int	correct_arguments(int argc, char **argv)
{
	if (argc == 1)
		return (print_one_argument_error());
	if (argc > 2)
		print_warning();
	if (check_ber(argv[1], ".ber"))
		return (print_file_error());
	return (0);
}
