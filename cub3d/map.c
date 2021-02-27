#include "cub3d.h"
#include "get_next_line.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

int get_end(char *buf, int start, int *p_flag);
int is_only_zero_blank_one(char *arr);
int check_first(char *buf, int *p_flag)
{
    if (strchr(buf, '0') != 0)
        return (-1);
    return (1);
}
/*int sub_get_start_func(char cur, char before)//this fuction will be incldued in get_start function..!!
{//this function is error check funcion // this function is compare just one character
    if ()
}*/
int check_last(char *buf)
{
    //printf("\n%s\n", buf);
    if (ft_strchr(buf, '0') != 0)
        return (-1);
    return (1);
}

/*int is_only_zero_blank_one(char *arr)
{
    int idx=0;
    while (arr[idx])
    {
        if (strchr("012 NEWS", arr[idx++]) == 0)
            return (-1);
    }
    return (1);
}*/

void get_dir(t_syn *p_syn, int idx)
{
    p_syn->tri.pos[1] = idx;
    p_syn->tri.dir[0] = 0;
    p_syn->tri.dir[1] = 0;
    p_syn->tri.plane[0] = 0;
    p_syn->tri.plane[1] = 0;
    if (add_line[idx] == 'N')
    {
        p_syn->tri.dir[0] = -1;
        p_syn->tri.plane[1] = 0.66;
    }
    if (add_line[idx] == 'E')
    {
        p_syn->tri.dir[1] = 1;
        p_syn->tri.plane[0] = 0.66;
    }
    if (add_line[idx] == 'W')
    {
        p_syn->tri.dir[1] = -1;
        p_syn->tri.plane[0] = 0.66;
    }
    if (add_line[idx] == 'S')
    {
        p_syn->tri.dir[0] = 1;
        p_syn->tri.plane[1] = 0.66;
    }
}

int renewer_sprites(t_syn *p_syn)
{
    int x;
    double **new_sprites

    x=0;
    p_syn->num_of_sprite++;
    while (p_syn->sprites[x] != NULL)
        x++;
    if (NULL = (new_sprites = (double **)calloc(x+2, sizeof(double *))))
        return (-1):
    new_sprites[x+1] = NULL;
    new_sprites[x] = malloc(sizeof(int) * 2);
    new_sprites[x][0] = size;
    new_sprites[x][1] = idx;
    while (--x >= 0)
    {
        //new_sprites[x] = malloc(sizeof(int) * 2);
        new_sprites[x] = p_syn->sprites[x];
    }
    free(p_syn->sprites);
    p_syn->sprites = new_sprites;
    return (1);
}

void make_new_map(int **new_map, int **map, int *new_line, int size)
{
    new_map[size+1] = NULL;
    new_map[size] = new_line;
    while (--size >= 0)
        new_map[size] = map[size];
    free(map);
}
int **renewer_map(t_syn *p_syn, int **map, char *add_line)//생각보다 복잡하네....
{
    int **new_map;
    int size=0;
    int idx = -1;

    //part 1
    while (map[size] != NULL)
        size++;
    //free(&map[size]);//NULL이 존재하는 메모리 공간 프리...
    if (NULL == (new_map = (int **)calloc(1, sizeof(int *) * (size + 2))))
        return (NULL);
    int *temp = malloc(sizeof(int) * ft_strlen(add_line));
    while (add_line[++idx])
    {
        if (ft_strchr("NEWS", add_line[idx]) != 0)
        {
            get_dir(p_syn, idx);
            /*if (add_line[idx] == 'N')
            {
                p_syn->tri.dir[0] = -1;
                p_syn->tri.dir[1] = 0;
                p_syn->tri.plane[0] = 0;
                p_syn->tri.plane[1] = 0.66;
            }
            if (add_line[idx] == 'E')
            {
                p_syn->tri.dir[0] = 0;
                p_syn->tri.dir[1] = 1;
                p_syn->tri.plane[0] = 0.66;
                p_syn->tri.plane[1] = 0;
            }
            if (add_line[idx] == 'W')
            {
                p_syn->tri.dir[0] = 0;
                p_syn->tri.dir[1] = -1;
                 p_syn->tri.plane[0] = 0.66;
                p_syn->tri.plane[1] = 0;
            }
            if (add_line[idx] == 'S')
            {
                p_syn->tri.dir[0] = 1;
                p_syn->tri.dir[1] = 0;
                p_syn->tri.plane[0] = 0;
                p_syn->tri.plane[1] = 0.66;
            }*/
            //add_line[idx] = '0';
            p_syn->tri.pos[0] = size;
            temp[idx] = 0;
            continue;
        }
        else if (add_line[idx] == '2')
        {
            renewer_sprites(p_syn);
            /*p_syn->num_of_sprite++;
            int x=0;
            while (p_syn->sprites[x] != NULL)
                x++;
            double **new_sprites = calloc(x+2, sizeof(double *));
            new_sprites[x+1] = NULL;
            new_sprites[x] = malloc(sizeof(int) * 2);
            new_sprites[x][0] = size;
            new_sprites[x][1] = idx;
            while (--x >= 0)
            {
                //new_sprites[x] = malloc(sizeof(int) * 2);
                new_sprites[x] = p_syn->sprites[x];
            }
            free(p_syn->sprites);
            p_syn->sprites = new_sprites;*/
        }
        temp[idx] = add_line[idx]- '0';
    }
    make_new_map(new_map, map, temp, size);
    return (new_map);
}

get_first(int fd, char *cur_buf)
{
    while (strcmp(cur_buf, "") == 0)
        get_next_line(fd, &cur_buf);
    while (ft_strchr(cur_buf, ' '))
        *(ft_strchr(cur_buf, ' ')) = '1';
}

int valid_check(t_syn *p_syn, char *cur_buf, char *before_buf, int flag)
{
    while (ft_strchr(cur_buf, ' '))
        *(ft_strchr(cur_buf, ' ')) = '1';
    if (is_only_zero_blank_one(cur_buf) != 1 && flag != -1)
        return (-1);
    if ((cur_buf[0] != '1') || (cur_buf[ft_strlen(cur_buf) - 1] != '1') \
        && flag != -1)
        return (-1);
    free(before_buf);
    p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf);
    before_buf = cur_buf;
    return (1);
}

int get_last(t_syn *p_syn, char *cur_buf, char *before_buf, int ret)
{
    free(before_buf);
    while (ft_strchr(cur_buf, ' '))
        *(ft_strchr(cur_buf, ' ')) = '1';
    if (-1 == (check_last(cur_buf)))
        return (-1);
    p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf);
    free(cur_buf);
    if (ret == -1)//important point!!!!!
        return (-1);
    else
        return (1);
}

int is_valid_map(int fd, t_syn *p_syn)
{
    int ret;
    int idx=0;
    int *temp;
    char *cur_buf;
    char *before_buf;

    p_syn->sprites = (double **)calloc(1, sizeof(double *));
    //*(p_syn->sprites) = NULL;
    p_syn->num_of_sprite = 0;
    p_syn->dir_alpha_is_exist = 0;//매 (숫자부 체크)(<- no) 숫자부 범위 결정 부분과 빈칸부 체크부분 문자 각각에 대해 검사해야겠다.... 빈칸부에 존재하면 유호하지 않은 맵일것.

    //맵에서 빈칸부분이나 방향지시 문자를 0으로 바꾸어 줄껀데, 문자상태로 저장해 놓은건 절대 변경 안하고, 숫자로 저장해놓는 곳에서만 공백이나 방향지시문자를 숫자0으로 변경하자
    get_next_line(fd, &cur_buf);
    p_syn->tri.test_map = (int **)calloc(1, sizeof(int *));
    /*while (strcmp(cur_buf, "") == 0)
        get_next_line(fd, &cur_buf);
    while (ft_strchr(cur_buf, ' '))
        *(ft_strchr(cur_buf, ' ')) = '1';*/
    get_first(fd, cur_buf);
    if (-1 == (check_first(cur_buf, &(p_syn->dir_alpha_is_exist))))
        return (-1);
    if (NULL == p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf))
        ret = -1;
    before_buf = cur_buf;
    while(get_next_line(fd, &(cur_buf)))//ret = -1 저장한다고 치자. break가 안걸리면 ret의 값이 계속 변하게 됨... 해결함
    {    ret = valid_check(p_syn, cur_buf, before_buf, ret);
        /*while (ft_strchr(cur_buf, ' '))
            *(ft_strchr(cur_buf, ' ')) = '1';
        if (is_only_zero_blank_one(cur_buf) != 1)
            return (-1);
        if ((cur_buf[0] != '1') || (cur_buf[ft_strlen(cur_buf) - 1] != '1'))
            return (-1);
        free(before_buf);
        p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf);
        before_buf = cur_buf;*/
    }
    if (-1 == (p_syn->spriteDistance = (double *)malloc(sizeof(double) * p_syn->num_of_sprite)))
        ret = -1;
    /*free(before_buf);
    while (ft_strchr(cur_buf, ' '))
        *(ft_strchr(cur_buf, ' ')) = '1';
    if (-1 == (check_last(cur_buf)))
        return (-1);
    p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf);
    free(cur_buf);*/
    if (p_syn->dir_alpha_is_exist == 0)
        ret = -1;
    return (ret);// if reach this line the map is valid map
}