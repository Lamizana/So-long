/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:30:44 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 14:16:24 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

static int	len_nb(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	nb_to_nbstr(char *nb_str, int nb, int len)
{
	int	signe;
	int	i;

	i = 0;
	signe = 0;
	if (nb < 0)
	{
		signe++;
		nb *= -1;
	}
	while (i < len)
	{
		nb_str[len - i - 1] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	if (signe == 1)
		nb_str[len - i] = '-';
	nb_str[i] = '\0';
}

char	*ft_itoa(int nb)
{
	char	*nb_str;
	int		signe;
	int		len;
	int		i;

	signe = 0;
	i = 0;
	len = len_nb(nb);
	nb_str = malloc(sizeof(char) * (len + 1));
	if (!nb_str)
		return (NULL);
	nb_to_nbstr(nb_str, nb, len);
	return (nb_str);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		write(fd, str, 1);
		str++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			write(fd, "-", 1);
			ft_putnbr_fd(-n, fd);
		}
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 10)
	{
		n = '0' + n;
		write(fd, &n, 1);
	}
}
