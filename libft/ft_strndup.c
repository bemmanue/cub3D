/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:27:00 by bemmanue          #+#    #+#             */
/*   Updated: 2022/03/29 19:47:59 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new;
	size_t	index;

	if (!s1)
		return (NULL);
	new = malloc(sizeof (char) * (n + 1));
	if (!new)
		return (NULL);
	index = 0;
	while (index < n && s1[index])
	{
		new[index] = s1[index];
		index++;
	}
	while (index < n)
		new[index++] = '1';
	new[index] = '\0';
	return (new);
}
