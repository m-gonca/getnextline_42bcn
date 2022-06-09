/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:57:40 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/09 19:31:31 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*	1 -> get next line recibe un fd desde la funcion open, y chequea si existe
		el buffersize y el fd.
	2 -> si hay error devuelve null y si funciona devuelve el str leido.
	3 -> Para ello coge el fd y lo lleva a ft_fill, donde guarda en un variable
		estatica llamada buffer, lo que ha leido, y devuelve el string leido 
		buffer junto lo que quedaba en stock. Esta funcion lee de tantos en
		tantos buffersize, hasta que en uno de esos buffersize encuentra un 
		salto de linea.
	4 --> devolvemos el string cortado en el salto de linea con con ft_get_line
	5 --> cogemos lo que nos quedaba de string despues del salto de linea 
		y lo guardamos con ft_cut_line en stock para la proxima vez que 
		se llame a la funcion
*/

char	*ft_fill(int fd, char *stock)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_strchr(buffer, '\n') == NULL && read_bytes != 0)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free (buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stock = NULL;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	stock = ft_fill(fd, stock);
//	printf("%s\n", stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
//	printf("\n%s\n", line);
	stock = ft_cut_line(stock);
//	printf("\n%s\n", stock);
//	printf("%s\n", line);
	return (line);
}

// int main(void)
// {
// 	int	fd;
	
// 	//fd = '\0';
// 	fd = open("1.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);	
// }