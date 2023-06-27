#include "err.h"

void	ps_error()
{
	write(1, "Error\n", 6);
	exit(0);
}