#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "includes/filler.h"

char	**create_map(t_param *data)
{
	char	*line;
	char 	**map;
	int		i;

	line = NULL;
	get_next_line(0, &line);
	// printf("line %s\n", line);
	line = ft_strchr(line, ' ');
	data->map_row = ft_atoi(&line[1]);
	// printf("rows on map = %d\n", data->map_row);

	line = ft_strrchr(line, ' ');
	data->map_col = ft_atoi(&line[1]);
	// printf("cols on map = %d\n", data->map_col);

	i = -1;
	map = (char**)malloc(sizeof(char *) * data->map_row);
	while (++i < data->map_row)
	{
		map[i] = ft_strnew(data->map_col);
		// printf("success\n");
	}
	// free(line);
	return (map);
}

void	fill_map(char **map, t_param *data)
{
	int		i;
	char	*line;

	line = NULL;
	i = -1;
	printf("enter map\n");
	// printf("touch map %s\n", map[0]);

	while (++i < data->map_row)
	{
		get_next_line(0, &line);
		// printf("line %s\n", line);
		// if (map[0] != NULL)
		// 	printf("UPS");
		// if (map[0] == NULL)
		// 	printf("UPS2");
		ft_strcpy(map[i], &line[4]);
		// free(line);
	}
	// i = -1;
	// while (++i < data->map_row)
	// 	printf("%s\n", map[i]);
}

void	init_param(t_param *data)
{
	data->my_tern = 0;
	data->map_row = 0;
	data->map_col = 0;
	data->piece_row = 0;
	data->piece_col = 0;
	data->pic_x = NULL;
	data->pic_y = NULL;
	data->stars = 0;
}

void	collect_coodr(t_param *data, char **piece, int i)
{
	int		z;
	int		x;

	i = -1;
	data->stars = 0;
	while (++i < data->piece_row)
	{
		z = -1;
		while (piece[i][++z] != '\0')
		{
			if (piece[i][z] == '*')
			{
				// printf("found star on = [%d:%d]\n", i, z);
				data->stars++;
			}
		}
	}
	printf("stars initianny %d\n", data->stars);
	if (data->pic_x != NULL)
	{
		free(data->pic_x);
		free(data->pic_y);
	}
	data->pic_x = malloc(sizeof(int) * data->stars);
	data->pic_y = malloc(sizeof(int) * data->stars);
	x = -1;
	i = -1;
	while (++i < data->piece_row)
	{		
		if(ft_strchr(piece[i], '*') != NULL)
		{
			z = -1;
			while(piece[i][++z] != '\0')
			{
				if (piece[i][z] == '*')
				{
					data->pic_x[++x] = z;
					data->pic_y[x] = i;
				}
			}
		}
	}
}

char	**record_piece(char **cur_piece, t_param *data)
{
	char	**piece;
	char	*line;
	int		i;

	line = NULL;
	if (cur_piece != NULL)
		ft_strdel(cur_piece);
	get_next_line(0, &line);
	line = ft_strchr(line, ' ');
	data->piece_row = ft_atoi(&line[1]);
	line = ft_strrchr(line, ' ');
	data->piece_col = ft_atoi(&line[1]);
	// free(line);
	i = -1;
	piece = malloc(sizeof(char *) * data->piece_row);
	while (++i < data->piece_row)
	{
		piece[i] = ft_strnew(data->piece_col);
		get_next_line(0, &line);
		piece[i] = ft_strcpy(piece[i], line);
		// free(line);
	}
	collect_coodr(data, piece, i);
	// printf("stars %d\n", data->stars);
	i = -1;
	while (++i < data->stars)
	{
		printf("2 coords: by x = %d\n", data->pic_x[i]);
		printf("2 coords: by y = %d\n", data->pic_y[i]);
		printf("\n");
	}
	return (piece);
}

// int change_my_spot(int *cur_x, int *cur_y, char **map, t_param *data)
// {
// 	int prev_x = *cur_x;
// 	int prev_y = *cur_y;
// 	// int i = -1;

// 	while (prev_y < data->map_row && stop == 0)
// 	{
// 		int k = data->map_col;
// 		while (--k > -1)
// 		{
// 			if (map[prev_y][k] == me)
// 			{
// 				my_spot_x = k;
// 				*cur_y = prev_y;
// 				stop = 1;
// 			}
// 		}
// 		prev_y++;
// 	}

// 	return (1); // if nothing possible
// 	return (0);
// }

int		*find_coord(char **map, t_param *data)
{
	// printf("start find coord\n");
	int i;
	char me;
	int my_spot_x;
	int my_spot_y;
	int retx;
	int rety;
	int m_row = data->map_row;
	int m_col = data->map_col;
	int ar_end = data->stars;
	int *xy = NULL;

	if (data->my_tern == 1)
		me = 'O';
	else
		me = 'X';
	int stop = 0;
	int try = 0;
	printf("RAZ\n");
	printf("me: %c\n", me);
	i = -1;
	while (1)
	{
		printf("*** counter rows %d****\n", i);
		while (stop == 0 && ++i < data->map_row)
		{
			int k = data->map_col;
			while (stop == 0 && --k > -1)
			{
				if (map[i][k] == me)
				{
					my_spot_x = k;
					my_spot_y = i;
					stop = 1;
				}
			}
		}
	printf("DVA\n");
	printf("try dot: [%d:%d]\n", my_spot_y, my_spot_x);
		retx = my_spot_x - data->pic_x[try];
		printf("my_spot_x(%d) - data->pic_x[try](%d[%d]) = retx(%d)\n", my_spot_x, data->pic_x[try], try, retx);
		rety = my_spot_y - data->pic_y[try];
		printf("my_spot_y(%d) - data->pic_y[try](%d[%d]) = rety(%d)\n", my_spot_y, data->pic_y[try], try, rety);
		
		int ok = -1;
		int z = 0;
		int me_tot = 0;
	printf("TRI\n");
	printf("posible returning dot: [%d:%d]\n", rety, retx);

		while(++ok < data->stars)
		{
			int y = rety + data->pic_y[z];
			printf("y = %d\n", y);
			int x = retx + data->pic_x[z];
			printf("x = %d\n", x);

			if (data->pic_x[ar_end - 1] > m_col || data->pic_y[ar_end - 1] > m_row || data->pic_x[z] + retx < 0 || data->pic_y[z] + rety < 0)
			{
				printf("in long condition\n");
				break ;
			}
			if (map[y][x] == me)
				me_tot++;
			if (map[y][x] != '.' && map[y][x] != me)
			{
				printf("wrong symbols\n");
				break ;
			}
			else
				z++;
			printf("me total  = %d\n", me_tot);
		}
		printf("okeys: %d\n", ok);
	printf("CHETYRE\n");

		if (ok == data->stars && me_tot == 1)
		{
			xy = malloc(sizeof(int) * 2);
			xy[0] = rety;
			xy[1] = retx;
			return (xy);
		}
		else
			try++;
		printf(">>>>>>>>>TRY %d\n", try);
		if (try == ar_end)
		{
			stop = 0;
			try = 0;
			printf("SURPRIZE\n");
		}
	printf("PYAT'\n");

	}
	return (xy); //NULL	
	// printf("tipa nashel coordinatu\n");
}

void	print_coord(int *coordinates)
{
	// printf("in printing coord\n");
	ft_putnbr(coordinates[0]);
	write(1, " ", 1);
	ft_putnbr(coordinates[1]);
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*line;
	t_param	data;
	char	**map;
	char	**piece;
	int		*xy;
	// int i;

	init_param(&data);
	line = NULL;
	get_next_line(0, &line);
	line = ft_strchr(line, 'p');
	data.my_tern = ft_atoi(&line[1]);
	// ft_strdel(&line);
	printf("my tern = %d\n", data.my_tern);
	piece = NULL;
	map = NULL;
	while (1)
	{
		if (map != NULL)
			ft_strdel(map);
		map = create_map(&data);
		printf("useless string:\n");
		get_next_line(0, &line);
		// ft_strdel(&line);
		printf("before filling \n");
		fill_map(map, &data);
		piece = record_piece(piece, &data);
		// i = -1;
		// while (data.piece_row > ++i)
		// 	printf("%s\n", piece[i]);
		xy = find_coord(map, &data);
		print_coord(xy);
		// free(xy);
	}
	// free(map);
	return (0);
}