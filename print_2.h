void fill_test(char *test, int len)
{
    int i;

    i = 1;
    while(i <= len)
    {
        test[i] = '0';
        i++;
    }
}

void execute_printing(char* print_)
{
    while(is_alpha(*print_))
    {
        write(1, print_, 1);
        print_++;
    }
    write(1, " ", 1);
}

void limon(char*str, int len)
{
    int i = 0;
    int count = 0;
    char *test = (char*) malloc(len + 2);
    char *print_;
    
    test[0] = '1';
    test[len + 1] = '\0';
    fill_test(test, len);
    print_ = ft_strstr(str, test);
    execute_printing(print_);
    free(test);
    test = NULL;
}

int check4end(char *str)
{
    while (*str)
    {
        if(*str != '0')
            return (0);
        str++;
    }
    return 1;
}

void for_one(char dg, char*buffer)
{
    char test[2];
    char *print_;

    test[0] = dg;
    test[1] = '\0';
    
    print_ = ft_strstr(buffer, test);
    execute_printing(print_);
}