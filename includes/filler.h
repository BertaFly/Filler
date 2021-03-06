/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:08:57 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/23 11:49:27 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_param
{
	int		my_tern;
	int		map_row;
	int		map_col;
	int		piece_row;
	int		piece_col;
	int		*pic_x;
	int		*pic_y;
	int		stars;
}				t_param;

#endif