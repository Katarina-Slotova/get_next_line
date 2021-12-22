/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:07:12 by kslotova          #+#    #+#             */
/*   Updated: 2021/12/09 14:56:08 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !sub_str)
		return (0);
		// if start is more than strlen(s) -- check for this condition
	while (s[i] && i < start + len)
	{
		sub_str[j] = s[i];
		i++;
		j++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}
