/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogonzal <mogonzal@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:11:09 by mogonzal          #+#    #+#             */
/*   Updated: 2022/06/09 19:31:09 by mogonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (n > 0)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	if (src < dst)
	{
		while (len > 0)
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
	}
	else if (dst < src)
		ft_memcpy (dst, src, len);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr3;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr3 = (char *)ft_calloc(1,(len + 1));
	if (!ptr3)
		return (NULL);
	ft_memmove(ptr3, s1, ft_strlen(s1));
	ft_memmove(ptr3 + ft_strlen(s1), s2, ft_strlen(s2));
	return (ptr3);
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
		ptr = ft_calloc(1, 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && s1[start])
	{
		ptr[i] = s1[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_get_line(char *stock)
{
	int		i;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i])
	{
		if (stock[i] == '\n')
		{
			stock = ft_substr(stock, 0, i);
			break;
		}
		i++;
	}
	return (stock);
}

char	*ft_cut_line(char *stock)
{
	size_t len;
	size_t	i;

	len = ft_strlen(stock);
	i = 0;	
	while (stock[i])
	{
		if (stock[i] == '\n')
			break;
		i++;
	}
	stock = ft_substr(stock, i, len);
	return (stock);
}