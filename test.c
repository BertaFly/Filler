#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "includes/filler.h"

void	create_map(char **map, t_param *data)
{
	char	*line;
	int		i;

	line = NULL;
	get_next_line(0, &line);
	line = ft_strchr(line, ' ');
	data->map_row = ft_atoi(&line[1]);
	line = ft_strrchr(line, ' ');
	data->map_col = ft_atoi(&line[1]);
	i = -1;
	while (++i < data->map_row)
		map[i] = ft_strnew(data->map_col);
	ft_strdel(line);
}

void	fill_map(char **map, t_param *data)
{
	int		i;
	char	*line;

	line = NULL;
	i = -1;
	while (++i < data->map_row)
	{
		get_next_line(0, &line);
		ft_strcpy(map[i], &line[4]);
		ft_strdel(line);
	}
}

void	init_param(t_param *data)
{
	data->my_tern = 0;
	data->map_row = 0;
	data->map_col = 0;
	data->piece_row = 0;
	data->piece_col = 0;
}

void	record_piece(char **piece, t_param *data)
{
	char	*line;
	int		i;

	line = NULL;
	if (piece != NULL)
		free(piece);
	get_next_line(0, &line);
	line = ft_strchr(line, ' ');
	data->piece_row = ft_atoi(&line[1]);
	line = ft_strchr(line, ' ');
	data->piece_col = ft_atoi(&line[1]);
	ft_strdel(line);
	i = -1;
	while (++i < data->piece_row)
	{
		piece[i] = ft_strnew(data->piece_col);
		get_next_line(0, &line);
		piece[i] = ft_strcpy(line);
		ft_strdel(line);
	}
}

void	find_coord(char **map, char **piece, t_param *data, int **xy)
{
	xy[0] = ;
	xy[1] = ;
}

void	print_coord(int *coordinates)
{
	ft_putnbr(coordinates[0]);
	write(1, " ", 1);
	ft_putnbr(coordinates[1]);
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	char	*line;
	t_param	data;
	char	**map;
	char	**piece;
	int		*xy;

	init_param(&data);
	line = NULL;
	get_next_line(0, &line);
	line = ft_strchr(line, 'p');
	data.my_tern = ft_atoi(&line[1]);
	ft_strdel(line);
	create_map(map, &data);
	piece = NULL;
	xy = sizeof(int) * 2;
	while (1)
	{
		get_next_line(0, &line);
		ft_strdel(line);
		fill_map(map, &data);
		record_piece(piece, &data);
		find_coord(map, piece, &data, &xy);
		print_coord(xy);
	}
	free(map);
	return (0);
}