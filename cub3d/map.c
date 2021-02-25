#include "cub3d.h"
#include "get_next_line.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
int get_end(char *buf, int start, int *p_flag);
int check_first(char *buf, int *p_flag)
{
    if (strchr(buf, '0') != 0)
        return (-1);
    return (1);
}

int get_end(char *buf, int start, int *p_flag)
{
    int i;
    i = start;
    while (buf[i] != '\0')
    {
        if (ft_strchr("NEWS", buf[i]) != 0 )
        {
            if (*p_flag == 1)
                return (-1);
            else//해당 방향정보 저장하고 해당문자를 0으로 바꾸어주는 작업이 필요할듯
            {// 후자부분은 매우 간단..
            // 전자 부분은.. 방법이 매우 다양할수있다. 
                *p_flag = 1;
            }
            i++;
            continue;
        }
        if (ft_strchr("012 ", buf[i]) == 0)//만약 buf[i]가 이 라인을 넘어갈수있다면 그때 buf[i] = '0' ' ' '1' '2' 중 하나이다.
            return (-1);
        if (buf[i] == ' ')
            return (i - 1);
        i++;
    }//if break this loop buf[i] is NULL character// so end idx is (i-1);
    return (i - 1);
}

int check_num_part(char *cur,char *before, int start, int end)// is the flag is need...?   this function not will be in get_end_fuction
{
    int idx = start;
    if (cur[start] != '1')//part 1
        return (-1);
    if (cur[end] != '1')
        return (-1);
    while (idx <= end)//part2
    {
        if (cur[idx] == '0')
        {
            if (strlen(before) < idx)
                return (-1);
            if (before[idx] == ' ')
                return (-1);
            else
                idx++;
        }
        else
            idx++;
    }
    return (1);
}

/*int sub_get_start_func(char cur, char before)//this fuction will be incldued in get_start function..!!
{//this function is error check funcion // this function is compare just one character
    if ()
}*/
int get_start(char *buf,char *before, int end)
{
    int i;
    i = end + 1;

    while(buf[i] != '\0')
    {
        printf("\nidx : %d buf[i] = %c\n", i, buf[i]);
        if (ft_strchr("NEWS", buf[i]) != 0)//in the part of blank, this is the error...
            return (-1);
        if (buf[i] == ' ')
        {
            if (strlen(buf) < i)
                return (-1);
            else if (strchr("02", before[i]) != 0)
                return (-1);
        }
        /*else if (buf[i] == '0' || buf[i] == '1' || buf[i] == '2')
            return (i);*/
        else if (buf[i] == '1')
            return (i);
        else
            return (-1);
        i++;
        
    }//if break this loop buf[i] is NULL character// so end_idx is (i-1);
    if (buf[i] == '\0')
        return (i);
    else
        return (i);
}

int check_last(char *buf)
{
    printf("\n%s\n", buf);
    if (strchr(buf, '0') != 0)
        return (-1);
    return (1);
}

int is_only_zero_blank_one(char *arr)
{
    int idx=0;
    while (arr[idx])
    {
        if (strchr("012 NEWS", arr[idx++]) == 0)
            return (-1);
    }
    return (1);
}

int is_valid_map(void)
{
    int ret = 1;
    char *cur_buf;
    char *before_buf;
    int start_idx;
    int end_idx;
    int dir_alpha_is_exist = 0;//매 (숫자부 체크)(<- no) 숫자부 범위 결정 부분과 빈칸부 체크부분 문자 각각에 대해 검사해야겠다.... 빈칸부에 존재하면 유호하지 않은 맵일것.
    int **map_used_in_dda;//매우 중요한 부분...! 이 부분 나중에 구현.. 일단 이렇게 저장해놓기로 결정
    //맵에서 빈칸부분이나 방향지시 문자를 0으로 바꾸어 줄껀데, 문자상태로 저장해 놓은건 절대 변경 안하고, 숫자로 저장해놓는 곳에서만 공백이나 방향지시문자를 숫자0으로 변경하자
    /*
        if ()

        elss if ()

        else
            return (invalid map)//macro will be used and the num will be -1
    */
    int fd = open("test.txt",  O_RDONLY);//일단 test.cub에 맵정보만 담겨있다고 생각하고 작성...
    get_next_line(fd, &cur_buf);
    if (-1 == (check_first(cur_buf, &dir_alpha_is_exist)))
        return (-1);
    before_buf = cur_buf;
    while(get_next_line(fd, &(cur_buf)))
    {
        printf("!!!!\n");
        if (is_only_zero_blank_one(cur_buf) != 1)
            return (-1);
        printf("here? %s\n", cur_buf);
        start_idx = 0;
        while(cur_buf[start_idx] == ' ')
            start_idx++;
        while(cur_buf[start_idx] != '\0')
        {
            printf(">???");
            if (-1 == (end_idx = get_end(cur_buf, start_idx, &dir_alpha_is_exist)))
                return (-1);
            printf("2 here? %s\n", cur_buf);
            if ( -1 == (check_num_part(cur_buf, before_buf, start_idx, end_idx)))
                return (-1);
            printf("3 here? %s\n", cur_buf);
            if (-1 == (start_idx = get_start(cur_buf, before_buf, end_idx)))
                return (-1);
            //printf("strar_idx = %d\n", start_idx);
        }
        printf("test : %s\n", cur_buf);
        free(before_buf);
        before_buf = cur_buf;
    }
    close(fd);
    free(before_buf);
    if (-1 == (check_last(cur_buf)))
        return (-1);
    printf("reach\n");
    free(cur_buf);
    if (dir_alpha_is_exist == 0)
        return (-1);
    return (ret);// if reach this line the map is valid map
}

int main(void)
{
    printf("%d", is_valid_map());
    return (0);
}