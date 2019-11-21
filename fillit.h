/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:08:51 by cshawnee          #+#    #+#             */
/*   Updated: 2019/11/17 16:17:35 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_tris
{
	int				cord[8];
	char			abc;
	int				y_shift;
	int				x_shift;
	struct s_tris	*next;
}					t_tris;
typedef struct		s_map
{
	char		**arr;
}					t_map;

# define I_PIECE (int [8]) {0,0,0,1,0,2,0,3}
# define IH_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]) {0,0,1,0,0,1,1,1}
# define L_PIECE (int [8]) {0,0,0,1,0,2,1,2}
# define LR_PIECE (int [8]) {0,0,1,0,2,0,0,1}
# define LD_PIECE (int [8]) {0,0,1,0,1,1,1,2}
# define LL_PIECE (int [8]) {2,0,0,1,1,1,2,1}
# define J_PIECE (int [8]) {1,0,1,1,0,2,1,2}
# define JR_PIECE (int [8]) {0,0,0,1,1,1,2,1}
# define JD_PIECE (int [8]) {0,0,1,0,0,1,0,2}
# define JL_PIECE  (int [8]) {0,0,1,0,2,0,2,1}
# define T_PIECE (int [8]) {1,0,0,1,1,1,2,1}
# define TR_PIECE (int [8]) {0,0,0,1,1,1,0,2}
# define TD_PIECE (int [8]) {0,0,1,0,2,0,1,1}
# define TL_PIECE (int [8]) {1,0,0,1,1,1,1,2}
# define S_PIECE (int [8]) {1,0,2,0,0,1,1,1}
# define SR_PIECE (int [8]) {0,0,0,1,1,1,1,2}
# define Z_PIECE (int [8]) {0,0,1,0,1,1,2,1}
# define ZR_PIECE (int [8]) {1,0,0,1,1,1,0,2}

int					validator(int *tetro);
int					tabcmp(int *tetro, int *arr);
int					*shift_col(int *tetro);
int					*shift_row(int *tetro);
int					charchecker(char *buff);
int					*ttcheck(char *buff, int *map);
int					maincheck(char *buff, int size);
t_tris				*checker(char *file);
void				shift_x(t_tris *cord, int n);
void				shift_y(t_tris *cord, int n);
t_tris				*zero_cord(t_tris *block);
t_tris				*piecemaker(char *buff, char abc);
t_tris				*makeblocks(char *buff, int size);
int					number(t_tris *list);
int					ft_sqrt(int nb);
t_map				*map_maker(int size);
void				solution(t_tris *blockslist);
void				print(t_map *map, int map_size);
void				free_map(t_map *map, int map_size);
int					collisions(t_map *map, t_tris *block);
void				replace(t_tris *block, t_map *map, char abc);
int					border(t_tris *block, int map_size, char z);
int					answer(t_map *map, t_tris *block, int map_size);
void				freeman(t_tris *node);

#endif
