int is_numeric(char sym)
{
    return (sym >= '0' && sym <= '9');
}

int stlen(char* str)
{
    if (!(*str))
        return 0;
    return 1 + stlen(str + 1);
}

int check_num_arg(char* arg)
{
    while (*arg)
    {
        if (!(is_numeric(*arg)))
            return 1;
        ++arg;
    }
    return 0;
}

void check_and_swap_args(char**args)
{
    int i;

    i = 0;
    while (args[1][i])
    {
        if (!is_numeric(args[1][i]))
        {
            char* tmp = args[1];
            args[1] = args[2];
            args[2] = tmp;
            break;
        }
        ++i;
    }
}