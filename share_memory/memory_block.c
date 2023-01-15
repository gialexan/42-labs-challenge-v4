/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:26:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 03:11:43 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

key_t	key_block(char *filename)
{
	key_t key;
	
	key = ftok(filename, 0);
	if (key == IPC_RESULT_ERROR)
		return (IPC_RESULT_ERROR);
	return (key);
}

int	shared_block_id(key_t key, int size)
{
	int	id_block;

	id_block = shmget(key, BLOCK_SIZE, 0644 | IPC_CREAT);
	if(id_block == IPC_RESULT_ERROR)
		return (IPC_RESULT_ERROR);
	return (id_block);
}

int *shared_block_map(int id_block)
{
	int *map_block;

	map_block = (int *)shmat(id_block, NULL, 0);
	if (map_block == NULL)
		return (NULL);
	return (map_block);		
}

int	detach_block(int *map_block)
{
	if (shmdt(map_block) == IPC_RESULT_ERROR)
		return (1);
	return (0);
}