#include <unistd.h>

void ft_putchar(char g)

{
	write (1, &g, 1);
}

void ft_write_comb(int t, int y, int last)
{
	ft_putchar(48 + t/10);
	ft_putchar(48 + t%10);
	ft_putchar(' ');
	ft_putchar(48 + y/10);
	ft_putchar(48 + y%10);
	if (last)q
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void ft_print_comb2(void)
{
	int t;
	int y;
	int last;

	t = 0;
	while (t <= 99)
	{
		y =  t+1;
		while (y <=99)
		{
			last =!(t==98 && y== 99);
			ft_write_comb(t, y, last);
			y++;
		}
		t++;
	}
}


int main(void)
{
	ft_print_comb2();
}












