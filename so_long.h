/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:48:24 by aomman            #+#    #+#             */
/*   Updated: 2022/03/25 16:04:04 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include"minilibx-linux/mlx.h"
# include<fcntl.h>

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*i_w;
	void	*i_d;
	char	*gcl;
	char	**spl;
	int		w;
	int		h;
	int		fd;
	int		i;
	int		j;
	int		wall;
	int		player;
	int		exit;
	int		coll;
	int		n_moves;
}	t_var;
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
void	valid_walls(t_var var);
void	check_map_file(t_var var);
void	valid_len(t_var var);
void	check_sides(t_var var);
void	check_full_comp(t_var var);
int		deal(int c, t_var *var);
void	draw_map(t_var *v);
int		ft_forword(t_var *var, int c);
int		ft_left(t_var *var, int c);
int		ft_right(t_var *var, int c);
int		ft_down(t_var *var, int c);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	check_ber(int argc, char **argv);
char	*ft_strrchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_exit(t_var *var, int c);
void	ft_free2(t_var var);
int		ft_exit_corss(void);
#endif
