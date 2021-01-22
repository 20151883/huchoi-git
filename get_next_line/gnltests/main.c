int main(void)
{
    int fd = open("test.txt", ONREAD_);
    char * line;

    while(get_next_line(fd, &&line))
    {
        
    }
}