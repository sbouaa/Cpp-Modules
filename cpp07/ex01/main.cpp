#include "iter.hpp"

template <typename X>
void    p(X const &i)
{
    std::cout<<i<<std::endl;
}

int main()
{
    int arr[5] = {1,2,2,2,2};
    iter(arr, 5, p);
    return 0;
}