/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:11:22 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/02 16:28:05 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*read_buffer(int fd, char *buffer);

char	*get_line(char *buffer);

char	*save_buffer(char *buffer);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin_and_free(char *buffer, char *s2);

char	*ft_strchr(const char *s, int c);

char	*check_buff(char *buffer);
#endif
