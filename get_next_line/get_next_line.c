/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:43:14 by marvin            #+#    #+#             */
/*   Updated: 2021/01/12 10:43:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_next_line(int fd, char **line)
{
    char *buf;
    char *temp;
    char *str;
    int ret;

    str = malloc(sizeof(char) * (BUFFER_SIZE + 1);
    str[0] = '\0';
    buf = malloc(sizof(char) * BUFFER_SIZE);//buf don't need the null (strlcat will be used) you must know that null is just check point
    if (fd < 0 || buf = -1) 
        return (-1);
    while(1)
    {
        ret = read(fd, buf, BUFFER_SIZE);//the return nalue of read function is very useful value 
        if(0 == ret)//read dosen't prommis the null terminated, read return 0 if contact wih EOF
            return (0);//read 함수가 언제 0을 반환하는지가 애매하다... read는 읽은 만큼만 반환한다. 그걸 이용하면 된다.
        if(check_buffer(buf, ret) != ret)//enter is founded
        {
           get_new_str(&str, buf, ret);//add this string to the char **line
            if (-1 == add_new_str(line, str);
                return (-1);
            return (1);
        }
        else//just cat the stirng of buufer to the array str.
        {
            get_new_str(&str, buf, ret);
            if (-1 == add_new_str(line, str))
                return (-1);
            return (1);
        }
    }
}