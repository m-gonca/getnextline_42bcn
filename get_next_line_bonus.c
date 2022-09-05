/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:57:40 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/13 17:23:22 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// /*	1 -> get next line recibe un fd desde la funcion open, y chequea si
// 		existe el buffersize y el fd.
// 	2 -> si hay error devuelve null y si funciona devuelve el str leido.
// 	3 -> Para ello coge el fd y lo lleva a ft_fill, donde guarda en un variable
// 		estatica llamada buffer, lo que ha leido, y devuelve el string leido 
// 		buffer junto lo que quedaba en stock. Esta funcion lee de tantos en
// 		tantos buffersize, hasta que en uno de esos buffersize encuentra un 
// 		salto de line:wa.
// 	4 --> devolvemos el string cortado en el salto de linea con con ft_get_line
// 	5 --> cogemos lo que nos quedaba de string despues del salto de linea 
// 		y lo guardamos con ft_cut_line en stock para la proxima vez que 
// 		se llame a la funcion
// */

char	*ft_get_line(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	line = ft_substr(stock, 0, i + 1);
	return (line);
}

char	*ft_cut_line(char *stock)
{
	size_t	len;
	size_t	i;
	char	*new_stock;

	i = 0;
	if (stock[0] == '\0')
		return (NULL);
	len = ft_strlen(stock);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	new_stock = ft_substr(stock, i + 1, len);
	free(stock);
	return (new_stock);
}

char	*ft_fill(int fd, char *stock)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (read_bytes != 0 && ft_strchr(buffer, '\n') == NULL)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (stock);
			free (buffer);
			return (NULL);
		}
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			stock = ft_strjoin(stock, buffer);
		}
	}
	free (buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stock[1024] = {NULL};

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock[fd] || !ft_strchr(stock[fd], '\n'))
		stock[fd] = ft_fill(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	line = ft_get_line(stock[fd]);
	if (!line)
	{
		free(stock[fd]);
		return (NULL);
	}
	stock[fd] = ft_cut_line(stock[fd]);
	return (line);
}
