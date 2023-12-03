#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "__strstr__.h"
#include "checking.h"
#include "print_2.h"
#include "print.h"

int main(int argc, char** argv)  
{
    if (argc == 1 || argc > 3)
    {
        write(1,"Error", 5);
        return 1;
    }
    if (argc == 2)
    {
        if (check_num_arg(argv[1]))
        {
            return 1;
        }
    }
    check_and_swap_args(argv);
    if (argv[1][0] == '0')
    {
        write(1,"Error", 5);
        return 1;
    }
    int fd;
    char buffer[1000];
    fd = open(argv[2], O_RDONLY);
    read(fd, buffer, 1000);    
    print_nume_name(argv[1], buffer, stlen(argv[1]));
    close(fd);
    return 0;
}