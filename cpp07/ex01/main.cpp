#include "iter.hpp"

void    inc(int &x)
{ 
    x++;
}

void    print_s(const std::string &s)
{
    std::cout<<s<<std::endl;
}

void    to_up(std::string &s)
{
    for (size_t i = 0; i < s.length(); i++)
        s[i] = std::toupper(s[i]);
}

void    print_i(const int &x)
{
    std::cout<<x<<std::endl;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    const int a[5] = {5,4,3,2,1};
    std::string s[5] = {"sss", "www", "ssas", "poil", "qwerty"};
    const std::string x[5] = {"sss", "www", "ssas", "poil", "azerty"};

    ::iter(arr, 5, inc);
    ::iter(s, 5, to_up);
    ::iter(x, 5, print_s);
    ::iter(a, 5, print_i);
    return 0;
}