#include "cub3d.h"
#include "get_next_line.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#define TT  printf("test!!\n")

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
            p_syn->tri.pos[1] = idx;
            printf("\n\n\np_syn->tri.pos[1] = %f\n\n\n\n", p_syn->tri.pos[1]);
            printf(" idx = %d", idx);
            if (add_line[idx] == 'N')
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
            }
            //add_line[idx] = '0';
            p_syn->tri.pos[0] = size;
            printf("진입\n");
            printf("\n\n\n\nsize = %d\n\n\n",size);
            temp[idx] = 0;
            continue;
        }
        else if (add_line[idx] == '2')
        {
            p_syn->num_of_sprite++;
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
            p_syn->sprites = new_sprites;
        }
        temp[idx] = add_line[idx]- '0';
    }
    //temp[idx] = '\0';
    //new_map[size+1] = *(int **)calloc(1, sizeof(int *));
    new_map[size+1] = NULL;
    new_map[size] = temp;
    //printf("\n\n\n\n size = %d\n\n\n", size);
    //part 2
    while (--size >= 0)
    {
        new_map[size] = map[size];
    }
    free(map);
    //TT;
    return (new_map);
}

int is_valid_map(int fd, t_syn *p_syn)
{
    //printf("why..???\n");
    int ret = 1;
    int idx=0;
    int *temp;
    char *cur_buf;
    char *before_buf;
    int start_idx;
    int end_idx;
    p_syn->sprites = (double **)calloc(1, sizeof(double *));
    *(p_syn->sprites) = NULL;
    p_syn->num_of_sprite = 0;
    int dir_alpha_is_exist = 0;//매 (숫자부 체크)(<- no) 숫자부 범위 결정 부분과 빈칸부 체크부분 문자 각각에 대해 검사해야겠다.... 빈칸부에 존재하면 유호하지 않은 맵일것.
    int **map_used_in_dda;//매우 중요한 부분...! 이 부분 나중에 구현.. 일단 이렇게 저장해놓기로 결정
    //맵에서 빈칸부분이나 방향지시 문자를 0으로 바꾸어 줄껀데, 문자상태로 저장해 놓은건 절대 변경 안하고, 숫자로 저장해놓는 곳에서만 공백이나 방향지시문자를 숫자0으로 변경하자
    /*
        if ()

        elss if ()

        else
            return (invalid map)//macro will be used and the num will be -1
    */
    //int fd = open("test.txt",  O_RDONLY);//일단 test.cub에 맵정보만 담겨있다고 생각하고 작성...
    get_next_line(fd, &cur_buf);
    p_syn->tri.test_map = (int **)calloc(1, sizeof(int *));
    //p_syn->tri.test_map[0] = NULL
    while (strcmp(cur_buf, "") == 0)
        get_next_line(fd, &cur_buf);
    while (ft_strchr(cur_buf, ' '))
        *(ft_strchr(cur_buf, ' ')) = '1';
    if (-1 == (check_first(cur_buf, &dir_alpha_is_exist)))
        return (-1);
    /*while (cur_buf[idx])
    {
        if (cur_buf[idx] == '0')
            return (-1);//free is needed...!!! free_ret_zero will be used 
        idx++;
    }*/
    p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf);
    //printf("what?       %s\n", cur_buf);
    int i = 0;
    while (i < 3)
    {
        i = i + 0;
        printf("%d\n",p_syn->tri.test_map[0][i]);
        i++;
    }
    before_buf = cur_buf;
    while(get_next_line(fd, &(cur_buf)))
    {
        //printf("in here!!!!\n");
        while (ft_strchr(cur_buf, ' '))
            *(ft_strchr(cur_buf, ' ')) = '1';
        //printf("cur_buf = %s\n", cur_buf);
        if (is_only_zero_blank_one(cur_buf) != 1)
            return (-1);
        //printf("here? %s\n", cur_buf);
        /*start_idx = 0;
        while(cur_buf[start_idx] == ' ')
            start_idx++;*/
        if ((cur_buf[0] != '1') || (cur_buf[ft_strlen(cur_buf) - 1] != '1'))
            return (-1);
        //printf("here\n");
        free(before_buf);
        p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf);
        before_buf = cur_buf;
    }
    //printf("is this?\n");
    p_syn->spriteDistance = (double *)malloc(sizeof(double) * p_syn->num_of_sprite);
    close(fd);
    free(before_buf);
    while (ft_strchr(cur_buf, ' '))
        *(ft_strchr(cur_buf, ' ')) = '1';
    if (-1 == (check_last(cur_buf)))
        return (-1);
    //printf("reach\n");
    p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf);
    free(cur_buf);
    if (dir_alpha_is_exist == 0)
        return (-1);
    printf("is this?\n");
    return (ret);// if reach this line the map is valid map
}