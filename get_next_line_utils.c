/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:11:09 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/09 21:29:04 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		l;
	char	*ptr;

	ptr = (char *)s;
	l = ft_strlen(s);
	i = 0;
	while (i <= l)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

char	*create_malloc_of_strjoin(char *s1)
{
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr3;
	size_t	len_s1;
	size_t	len_s2;
	size_t	count;

	count = 0;
	s1 = create_malloc_of_strjoin(s1);
	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr3 = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr3)
		return (NULL);
	while (count++ < len_s1)
		ptr3[count -1] = s1[count -1];
	count = 0;
	while (count++ < len_s2)
		ptr3[len_s1 + count -1] = s2[count -1];
	ptr3[len_s1 + count -1] = '\0';
	free(s1);
	return (ptr3);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*s1;
	size_t	i;

	s1 = (char *)s;
	i = 0;
	if (start >= ft_strlen(s) || len == 0 || s == 0)
	{	
		ptr = malloc(sizeof(char) * 1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && s1[start])
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
