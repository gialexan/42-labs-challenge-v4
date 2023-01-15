/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 05:52:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 05:27:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static int	size_encode(t_data *data, t_char *text)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (text[++i] != '\0')
		size += strlen(data->dictionary[text[i]]);
	return (size + 1);
}

void	encode(t_data *data, t_char *text)
{
	int	i;
	int size;

	i = -1;
	size = size_encode(data, text);
	data->encode_txt = malloc(size * sizeof(char));
	while (text[++i] != '\0')
		strncat(data->encode_txt, data->dictionary[text[i]], data->height_tree);
}