#include "cub3d.h"

unsigned	int	*get_color_from_img(t_syn *p_syn, int x, int y)
{
	char *dst;

	dst = p_syn->img.data_ptr + (p_syn->img.bpp / 8) * x + (p_syn->img.lenth * y);
	return ((unsigned int *)dst); 
}

void	ft_bdata(t_syn *s, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = s->R[1];
	while (--i > 0)
	{
		j = 0;
		while (j++ < s->R[0])
			write(fd, get_color_from_img(s, j, i), 4);
	}
}

void	ft_binfo(t_syn *s, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = s->R[0];
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = s->R[1];
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(t_syn *s, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = s->R[0] * s->R[1] * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int		ft_bitmap(t_syn *s)
{
	int		fd;

	//ft_bdraw(s);
	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bfile(s, fd);
	ft_binfo(s, fd);
	ft_bdata(s, fd);
	close(fd);
	return (1);
}