#include <iostream>

void    print(std::string   str)
{
    int i = 0;
    while (str[i])
    {
        std::cout<< (char)toupper(str[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    else
    {
        for (int i = 1; i < ac; i++)
        {
            std::string str = av[i];
            print(str);
        }
    }
    return 0;
}