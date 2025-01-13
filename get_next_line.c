/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetit <lupetit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:29:51 by lupetit           #+#    #+#             */
/*   Updated: 2025/01/08 17:48:57 by lupetit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_update_stash(char *stash)
{
    int     i;
    int     j;
    char    *new_stash;

    i = 0;
    if (!stash)
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    i++;
    new_stash = malloc(sizeof(char) * (ft_strlen(&stash[i]) + 1));
    if (!new_stash)
    {
        free(stash);
        return (NULL);
    }
    j = 0;
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}

static char	*ft_read_file(int fd, char *stash)
{
    char    *buffer;
    int     bytes_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
    {
        free(stash);
        return (NULL);
    }
    bytes_read = 1;
    while (!ft_strchr(stash, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(stash);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    return (stash);
}

char    *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = ft_read_file(fd, stash);
    if (!stash)
    {
        stash = NULL;
        return (NULL);
    }
    line = ft_extract_line(stash);
    if (!line)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    stash = ft_update_stash(stash);
    return (line);
}