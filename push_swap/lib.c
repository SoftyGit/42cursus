#include "lib.h"

int	ps_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static	int	ps_isblank(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ps_atoi(const char *str)
{
	size_t	ret;
	char	sign;

	ret = 0;
	sign = 1;
	while (ps_isblank(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - *(str++);
	while (ps_isdigit(*str))
		ret = ret * 10 + (*(str++) - '0');
	return (sign * ret);
}
