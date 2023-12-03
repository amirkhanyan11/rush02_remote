void for_two(char *str1, char *buffer, int strlen)
{
    char test[3];
    char test_partition[3];

    *test = *str1;
    *(test + 1) = *(str1 + 1);
    test[3] = '\0';
    if(test[0] == '0')
    {
        for_one(test[1], buffer);
    }
    else if(test[0] == '1')
        execute_printing(ft_strstr(buffer, test));
    else
    {
        *test_partition = *test;
        *(test_partition + 1) = '0';
        *(test_partition + 2) = '\0';
        execute_printing(ft_strstr(buffer, test_partition));
        *test_partition = *(test + 1);
        *(test_partition + 1) = '\0';
        execute_printing(ft_strstr(buffer, test_partition));
    }
    if (strlen >= 6)
        limon(buffer, strlen - 3);
}

void for_three(char *str1, char*buffer, int strlen)
{
    char *test = (char*)malloc(4);
    int i = 0;
    *(test + 3) = '\0';
    while (i < 3)
    {
        test[i] = str1[i];
        i++;
    }
    for_one(test[0], buffer);
    limon(buffer, 2);
    if(test[1] != '0')
        for_two(test + 1, buffer, strlen);
    else if (strlen >= 6)
        limon(buffer,strlen - 3);
    free(test);
}

void print_nume_name(char*str1, char*buffer, int strlen)
{
    
    if (strlen > 0)
    {
        if (strlen % 3 == 0)
        {
            if(check4end(str1))
                return;
            for_three(str1, buffer, strlen);
            print_nume_name(str1 + 3, buffer, strlen - 3);
        }
        else if (strlen % 3 == 2)
        {
            for_two(str1,buffer, strlen);
            print_nume_name(str1 + 2, buffer, strlen - 2);
        }
        else if (strlen % 3 == 1)
        {
            for_one(*str1,buffer);
            print_nume_name(str1 + 1, buffer, strlen - 1);
        }  
    }
}