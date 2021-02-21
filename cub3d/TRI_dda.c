#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int get_x_rotate(int *vec, double theta);
int get_y_rotate(int *vec, double theta);

void renewer_tri(t_tri *test, int *new_pos, int *new_dir)///&********&
{
    if (new_pos != NULL)
    {
        test->pos[0] = new_pos[0];
        test->pos[1] = new_pos[1];
    }
    if (new_dir != NULL)
    {
        test->dir[0] = new_dir[0];
        test->dir[1] = new_dir[1];                  
    }
}
//************************************************************************************/
void get_tri(t_tri *p_tria)
{
    int pos_x;
    int pos_y;
    int dir_x;
    int dir_y;

    pos_x = p_tria->pos[0];
    pos_y = p_tria->pos[1];

    dir_x = p_tria->dir[0];
    dir_y = p_tria->dir[1];

    //p_tria->left[0] = pos_x + (get_x_rotate(p_tria->dir, p_tria->theta)* fabs((1.0 / cos(p_tria->theta));
    //p_tria->left[1] = pos_y + (get_y_rotate(p_tria->dir, p_tria->theta)* fabs((1.0 / cos(p_tria->theta));

    //p_tria->right[0] = pos_x + get_x_rotate(p_tria->dir, -(p_tria->theta));
    //p_tria->right[1] = pos_y + get_y_rotate(p_tria->dir, -(p_tria->theta)); 
}

/*int get_x_rotate(int *vec, double theta)
{
    int y;
    int x;

    x = vec[0];
    y = vec[1];
    return (x * cos(theta) - y * sin(theta));
}

int get_y_rotate(int *vec, double theta)
{
    int x;
    int y;

    x = vec[0];
    y = vec[1];
    return (x * sin(theta) + y * cos(theta));
} */  

void abs_must_equal_one(t_tri *p_tri)
{
    double weight;
    weight = sqrt(pow(p_tri->dir_x, 2) + pow(p_tri->dir_y, 2));
    if (weight != 1)
    {
        p_tri->dir_x /= weight; 
        p_tri->dir_y /= weight;
    }
}

int main(void)
{
    t_tri test;
    init_tria(&test);
    get_tri(&test);
    printf("pos : %d %d\ndir : %d %d\nleft: %lf %lf right: %lf %lf", test.pos[0], \
    test.pos[1], test.dir[0], test.dir[1], test.left[0], test.left[1], test.right[0], test.right[1]);

    int new_pos[2] = {10,10};
    renewer_tri(&test, new_pos, NULL);
    printf("pos : %d %d\ndir : %d %d\nleft: %lf %lf right: %lf %lf", test.pos[0], \
    test.pos[1], test.dir[0], test.dir[1], test.left[0], test.left[1], test.right[0], test.right[1]);
}