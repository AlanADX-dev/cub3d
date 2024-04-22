/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:50:18 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 12:00:41 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, int len);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	*ft_calloc(int nmemb, int size);
void	ft_bzero(void *s, int n);

# define BUFFER_SIZE 1000

#endif
