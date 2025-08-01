/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:30:47 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/01 14:51:59 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Calculates length of a string (const char *)
 * 
 * @param s [in] String to calculate length with (const char *)
 * @return ssize_t Length of string; Highest index of string: '\0'
 *
 * @warning 42 student
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * @brief Malloc space for hex conversion using number (long)
 * 
 * @param n [in] Pointer value as a number (long).
 * @return char * New malloced string.
 *
 * @note Caller must free().
 * @warning 42 student
 * @see ft_itoa() ft_ui_to_hex()
 */
char	*ft_malnumlen(long n)
{
	long	temp;
	char	*chrp;
	ssize_t	count;

	temp = n;
	count = 0;
	if (temp == 0 || temp < 0)
		count++;
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	chrp = malloc(count + 1);
	if (!chrp)
		return (NULL);
	return (chrp);
}

/**
 * @brief String reverse and free original string
 * 
 * @param s [in] String to be reversed and freed
 * @return char * New malloced string in reverse
 *
 * @note Caller must free().
 * @warning 42 student
 * @see ft_itoa() ft_uitoa()
 */
char	*ft_free_strrev(char *s)
{
	char	*result;
	char	*temp;
	size_t	slen;
	size_t	sign;

	sign = 0;
	slen = ft_strlen(s);
	result = malloc(slen + 1);
	if (!result)
	{
		free(s);
		return (NULL);
	}
	temp = result;
	if (s[0] == '-')
	{
		*temp++ = '-';
		sign++;
	}
	while (slen > sign)
		*temp++ = s[slen-- - 1];
	*temp = '\0';
	free(s);
	return (result);
}
