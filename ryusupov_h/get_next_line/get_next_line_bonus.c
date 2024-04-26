/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:14:13 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/26 14:15:29 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The function "*g_new_line" greturns the part of "buffer" until '\n' or '\0'
// The function "*remaining" returns part after '\n' if it exists
// The function "get_next_line" gets part of vars until \n or \0
// under the vars descriptor fd
//in the main functtion after opening the fie fd = 3, because
//0, 1, 2 is already in use.
#include "../ryusupov.h"

char	*read_data(t_struct *vars, char *buffer)
{
	char	temp[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (new_line(buffer) == -1 && i > 0)
	{
		i = read(vars->fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		temp[i] = '\0';
		buffer = ft_strjoin_gnl(buffer, temp);
		if (buffer == NULL || ft_strlen(buffer) == 0)
		{
			free(buffer);
			return (NULL);
		}
		if (new_line(buffer) != -1 || i == 0)
			break ;
	}
	return (buffer);
}

char	*g_new_line(t_struct *vars, char *buffer)
{
	char	*temp;
	char	*result;

	if (buffer == NULL || ft_strlen(buffer) == '\0')
	{
		return (NULL);
	}
	vars->new_l_buffer = new_line(buffer);
	if (vars->new_l_buffer >= 0)
	{
		result = ft_strndup(buffer, 0, vars->new_l_buffer + 1);
		return (result);
	}
	temp = ft_strndup(buffer, 0, ft_strlen(buffer));
	return (temp);
}

char	*remaining(t_struct *vars, char *buffer)
{
	char	*temp;

	temp = NULL;
	if (buffer == NULL || ft_strlen(buffer) == '\0')
	{
		free(buffer);
		return (NULL);
	}
	if (vars->new_l_buffer != -1)
		temp = ft_strndup(buffer, vars->new_l_buffer + 1, ft_strlen(buffer));
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10240];
	t_struct	*vars;
	char		*result;

	if (read(fd, NULL, 0) == -1)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	vars = get_t_struct(fd);
	buffer[fd] = read_data(vars, buffer[fd]);
	result = g_new_line(vars, buffer[fd]);
	buffer[fd] = remaining(vars, buffer[fd]);
	free(vars);
	return (result);
}

// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	if (argc < 2)
// 	{
// 		printf(COLOR_YELLOW"Usage: %s <file1> [<file2> ...]\n"RESET, argv[0]);
// 		return (1);
// 	}
// 	i = 1;
// 	while (i < argc)
// 	{
// 		fd = open(argv[i], O_RDONLY);
// 		if (fd == -1)
// 		{
// 			printf(COLOR_RED"Error opening file: <%s> "RESET, argv[i]);
// 			return (0);
// 		}
// 		printf(COLOR_GREEN"Reading from file: %s\n"RESET, argv[i]);
// 		while ((line = get_next_line(fd)) != NULL)
// 		{
// 			printf("%s\n", line);
// 			free(line);
// 		}
// 		close(fd);
// 		i++;
// 	}
// 	return (0);
// }
