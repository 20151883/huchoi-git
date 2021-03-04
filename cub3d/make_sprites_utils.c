#include "cub3d.h"

void	sort_sprites(t_syn *p_syn)
{
	ft_mergesort(p_syn, p_syn->sprites, 0, p_syn->num_of_sprite - 1);
}

double	compute_dis(t_syn *p_syn, double *sprite)
{
	double	ret;
	double	x_pos;
	double	y_pos;

	x_pos = sprite[0];
	y_pos = sprite[1];
	ret = (x_pos - p_syn->tri.pos[0]) * (x_pos - p_syn->tri.pos[0]);
	ret += (y_pos - p_syn->tri.pos[1]) * (y_pos - p_syn->tri.pos[1]);
	ret = sqrt(ret);
	return (ret);
}

void	ft_merge(t_syn *p_syn, double **arr, int start, int end)
{
	double	*temp[end - start + 1];
	int		idx;
	int		left;
	int		right;
	int		mid;

	mid = (start + end) / 2;
	idx = 0;
	left = start;
	right = mid + 1;
	while (left <= mid && right <= end)
	{
		if (compute_dis(p_syn, arr[left]) > compute_dis(p_syn, arr[right]))
			temp[idx++] = arr[left++];
		else
			temp[idx++] = arr[right++];
	}
	while (left <= mid)
		temp[idx++] = arr[left++];
	while (right <= end)
		temp[idx++] = arr[right++];
	idx = start - 1;
	while (++idx <= end)
		arr[idx] = temp[idx - start];
}

void	ft_mergesort(t_syn *p_syn, double **arr, int start, int end)
{
	int	mid;

	if (start == end)
		return ;
	mid = (start + end) / 2;
	ft_mergesort(p_syn, arr, start, mid);
	ft_mergesort(p_syn, arr, mid + 1, end);
	ft_merge(p_syn, arr, start, end);
}

void	init_for_sprite(t_syn *p_syn, int i)
{
	p_syn->spriteX = p_syn->sprites[i][0] - p_syn->tri.pos[0];
	p_syn->spriteY = p_syn->sprites[i][1] - p_syn->tri.pos[1];
	p_syn->invDet = 1.0 / (p_syn->tri.plane[0] * p_syn->tri.dir[1] - \
			p_syn->tri.dir[0] * p_syn->tri.plane[1]);
	p_syn->transformX = p_syn->invDet * (p_syn->tri.dir[1] * \
			p_syn->spriteX - p_syn->tri.dir[0] * p_syn->spriteY);
	p_syn->transformY = p_syn->invDet * (-p_syn->tri.plane[1] * \
	p_syn->spriteX + p_syn->tri.plane[0] * p_syn->spriteY);
	p_syn->spriteScreenX = (int)((p_syn->R[0] / 2) * \
			(1 + p_syn->transformX / p_syn->transformY));
	p_syn->spriteHeight = abs((int)(H / (p_syn->transformY)));
	p_syn->drawStartY = -p_syn->spriteHeight / 2 + H / 2;
	if (p_syn->drawStartY < 0)
		p_syn->drawStartY = 0;
	p_syn->drawEndY = p_syn->spriteHeight / 2 + H / 2;
	if (p_syn->drawEndY >= H)
		p_syn->drawEndY = H - 1;
	p_syn->spriteWidth = abs((int)(H / (p_syn->transformY)));
	p_syn->drawStartX = -p_syn->spriteWidth / 2 + p_syn->spriteScreenX;
	if (p_syn->drawStartX < 0)
		p_syn->drawStartX = 0;
	p_syn->drawEndX = p_syn->spriteWidth / 2 + p_syn->spriteScreenX;
	if (p_syn->drawEndX >= p_syn->R[0])
		p_syn->drawEndX = p_syn->R[0] - 1;
}
