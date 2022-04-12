
#include "minitalk.h"

void	handle_char_signal(char c, int pid)
{
	int	i;

	i = 7;
	//printf("\n%c---%d---", c, c);
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		//printf("%d", (c >> i) & 1);
		sleep(0.1);
		i--;
	}
}	

void	send_string(t_pd_str *pds)
{
	int	i;

	i = 0;
	/*if (str_checker(pds->str) == 0)
	{
		write (1, "Non valid characters on the string", 34);
		free(pds->str);
		exit (0);
	}*/
	while (pds->str[i] != 0)
	{
		handle_char_signal(pds->str[i], pds->pid);
		i++;
	}
}

void	num_arg_error(void)
{
	write(1, "Incorrect number of arguments\n", 30);
	exit(0);
}

t_pd_str	*init_struct(char **argv)
{
	t_pd_str	*pds;

	pds = malloc(sizeof(t_pd_str));
	pds->pid = ft_atoi(argv[1]);
	pds->str = str_cpy(argv[2]);
	return (pds);
}

int	main(int argc, char **argv)
{
	t_pd_str	*pds;

	if (argc != 3)
		num_arg_error();
	pds = init_struct(argv);
	//printf("%d----%s", pds->pid, pds->str);
	while (1)
    {
         send_string(pds);
         sleep(1); 
    }
	return (0);
}