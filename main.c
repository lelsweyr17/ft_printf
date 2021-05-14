#include <stdio.h>

#define PRINT ft_printf

int             ft_printf(char const *s, ...);

int main()
{
    int		a = -2;
	int		b = 5;
	char	c = '\0';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 12345678;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	// ft_printf("%%\n\n");

/*	ft_printf("%%**%s**-d%%0*d%-12s0*@\n", r, p, r, r, i, r, i, r, i);
	printf("%%**%s**-d%%0*d%-12s0*@\n\n", r, p, r, r, i, r, i, r, i);*/

	// ft_printf("   return ---- %d\n", ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
	// printf("   return ---- %d\n\n", printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));

	// ft_printf("   return ---- %d\n", ft_printf("%p, %x, %6p, %x", (void *)1, 1, NULL, 0));
	// printf("   return ---- %d\n\n", printf("%p, %x, %6p, %x", (void *)1, 1, NULL, 0));

	// ft_printf("   return ---- %d\n", ft_printf("%p, %x, %p, %x, %p, %x", (void *)207038912, 207038912, (void *)1, 1, NULL, 0));
	// printf("   return ---- %d\n\n", printf("%p, %x, %p, %x, %p, %x", (void *)207038912, 207038912, (void *)1, 1, NULL, 0));

	// ft_printf("   return ---- %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
	// printf("   return ---- %d\n\n", printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));

	// ft_printf("%-5c\n", '\0');
	// printf("%-5c\n\n", '\0');

/*	ft_printf("   return ---- %d\n", ft_printf("%.0p", 0));
	printf("   return ---- %d\n\n", printf("%.0u", 0));*/

	// ft_printf("   return ---- %d\n", ft_printf("%*x, %X\n", k, k, j));
	// printf("   return ---- %d\n\n", printf("%*x, %X\n", k, k, j));

	// ft_printf("   return ---- %d\n", ft_printf("%0*p", 20, n));
	// printf("   return ---- %d\n\n", printf("%0*p", 20, n));
	
/*	ft_printf("   return : %d\n", ft_printf("%015.p", p));
	printf("   return : %d\n", printf("%015p", p));*/

	/*ft_printf("   return ---- %d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	printf("   return ---- %d\n\n", printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));*/

/*	PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42));		//have to correct this one
	printf(" --- Return : %d\n\n", printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42));
*/
/*	PRINT(" --- Return : %d\n", PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42));		//have to correct this one
	printf(" --- Return : %d\n\n", printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42));

	PRINT(" --- Return : %d\n", PRINT("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42));		//have to correct this one
	printf(" --- Return : %d\n\n", printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42));

	PRINT(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
	printf(" --- Return : %d\n\n", printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); 

	PRINT(" --- Return : %d\n", PRINT("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
	printf(" --- Return : %d\n\n", printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d));*/
    return 0;
}
