/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:06:44 by mlavanan          #+#    #+#             */
/*   Updated: 2015/12/18 13:00:30 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define BUF_SIZE 1024

void	ft_printmap(char **map, int j);
int		main(int argc, char **argv);
void	ft_remap(char ***tetro, char **map, int i, int j);
int		ft_checkmap(char ***tetro, char **map, char ***tmp, int i);
void	ft_map(char ***tetro, char **map, int i, int j);
void	ft_fillit(char ***tetro, int i, int j, int k);
char	***ft_moveright(char ***tmp, char *map, int i);
char	***ft_movedown(char ***tmp, char ***tetro, char *map, int i);
char	**ft_setupleft(char **mtetro);
char	***ft_malloctmp(char ***tmp, int count, int j);
void	ft_cpy(char ***tmp, char ***tetro, int i, int j);
char	**ft_mapcpy(char **map, char ***tmp, int i);
int		ft_tmpmodif(char ***tetro, char **map, char ***tmp, int i);
void	ft_tetro(char *str);
int		ft_countallchar(char *tetro, int nbbsp, int nbdi, int nbpo);
char	**ft_maprm(char **map, int i);
void	ft_reload(char **tmp, char **tetro, int count);
int		ft_checkreadlen(int ret);
int		ft_checkforshape(char *tetro, int i, int nbdi);
int		ft_islshape(char *tetro, int i, int nbdi);

#endif
