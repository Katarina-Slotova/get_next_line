/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:48:42 by kslotova          #+#    #+#             */
/*   Updated: 2021/12/22 12:52:13 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFF_SIZE 32
# define FD_MAX 8192
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int	get_next_line(const int fd, char **line);

#endif
