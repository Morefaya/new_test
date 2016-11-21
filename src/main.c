#include "test.h"

int	main(void)
{
	char	*str_1;
	char	*str_2;
	char	buff[5];
	int	ret;
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag ^= ICANON;
	term.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &term);
	str_1 = getenv("TERM");
	str_2 = NULL;
	ret = tgetent(str_2, str_1);
	while (42)
	{
		ft_printf("21_sh$> ");
		ft_bzero(buff, 5);
		if (read(0, buff, 4) <= 0)
			break ;
		ft_printf("\n%p\n", *((int*)buff));
	}
	free(str_2);
	//while (42);
	return (0);
}
