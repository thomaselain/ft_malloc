/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 14:55:18 by vvenance          #+#    #+#             */
/*   Updated: 2018/07/11 21:43:36 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free(char *save)
{
	if (!save)
		return (0);
	else
		free((void *)(save));
	save = NULL;
	return (0);
}

static char	*ft_strjoin_free(char const *s1, char const *s2)
{
	int		i;
	int		iparam;
	char	*str;

	i = 0;
	iparam = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = _MALLOCC(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[iparam] != '\0')
	{
		str[i++] = s1[iparam];
		iparam++;
	}
	iparam = 0;
	while (s2[iparam] != '\0')
	{
		str[i] = s2[iparam];
		i++;
		iparam++;
	}
	free((void *)(s1));
	str[i] = '\0';
	return (str);
}

static int	ft_init(int fd, t_save *save)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	save->save = NULL;
	save->fd = fd;
	ret = 0;
	ft_memset(buf, '\0', BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (save->save == NULL)
			save->save = ft_strdup(buf);
		else if (fd == 0 && save->save[0] == '\0' && buf[0] == '\n')
			return ((ft_free(save->save)));
		else
			save->save = ft_strjoin_free(save->save, buf);
		ft_memset(buf, '\0', BUFF_SIZE + 1);
	}
	if (ret == -1)
		return (-1);
	if (!save->save)
		return (0);
	return (1);
}

static int	get_line(t_save *save, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (save->save[i] != '\n' && save->save[i] != '\0')
		i++;
	if (i == 1 && save->save[i] != '\n')
		return (ft_free(save->save));
	if (save->save[i] == '\n' || (save->save[i] == '\0' && i != 0))
	{
		*line = ft_strsub(save->save, 0, i);
		tmp = ft_strsub(save->save, i + 1, (ft_strlen(save->save) - (i - 1)));
		if (save->save)
			ft_free(save->save);
		if (!line || !tmp)
			return (-1);
		save->save = ft_strdup(tmp);
		if (tmp)
			ft_free(tmp);
		return (1);
	}
	ft_free(save->save);
	save->save = NULL;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_save	save;
	int				ret;

	if (BUFF_SIZE < 1 || fd < 0)
		return (-1);
	if (!save.save || save.fd != fd)
	{
		if (save.fd != fd && save.save)
			ft_free(save.save);
		if ((ret = ft_init(fd, &save)) < 1)
			return (ret);
	}
	ret = get_line(&save, line);
	return (ret);
}
