

#include "../minitalk.h"

int		str_checker(char *str)
{
	int	i;

	i = 0
	while (str[i] != 0)
	{
		if (str[i] >= 0 && str[i] <= 255)
			i++;
		else
			return (0);
	}
	return (1);
}
