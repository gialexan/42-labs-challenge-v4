/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:54:31 by coder             #+#    #+#             */
/*   Updated: 2023/01/15 11:00:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECODER_H
# define DECODER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/types.h>
# include <bsd/string.h>

# define ASCII 256
# define BLOCK_SIZE 4096
# define FILENAME "/usr/bin/ls"
# define IPC_RESULT_ERROR (-1)

typedef unsigned char	t_char;
typedef unsigned int	t_int;

typedef struct s_list
{
	t_char			chr;
	int				event;
	struct s_list	*next;
	struct s_list	*left;
	struct s_list	*right;
}	t_list;

typedef struct s_memory
{
	key_t	key;
	int		id_block;
	t_int	*map_block;
}	t_memory;

typedef struct s_data
{
	FILE	*file;
	int		bits;
	char	*decode_txt;
	t_char	byte;
	t_char	mask;
	t_list	*list;
}	t_data;

/* Frequency.c */
void	fill_frequency_table(t_memory *memory, t_int *table);
void	build_frequency_list(t_data *data, t_int *table);

/* Linkedlist_utils.c */
t_list	*new_node(int chr, int event);
t_list	*remove_first_node(t_data *data);
void	add_front(t_list **list, t_list *node);

/* Insertion_sort.c */
void	insertion_sort(t_data *data, t_list *node);

/* Tree_utils.c */
void	build_tree(t_data *data);

/* Compress.c */
void	decompress(t_data *data);

/* Memory.c */
key_t	key_block(char *filename);
int		detach_block(t_int *map_block);
int		shared_block_id(key_t key, int size);
t_int 	*shared_block_map(int id_block);

#endif