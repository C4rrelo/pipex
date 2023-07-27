#ifndef FT_PRITNF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putadress(size_t ptr, int *len);
void	ft_putnbr(int n, int *len);
void	ft_unsigned_nbr(unsigned int n, int *len);
void	ft_hexadecimal(unsigned int n, int *len, char choose);
int		ft_printf(const char *str, ...);

#endif