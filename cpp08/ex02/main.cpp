#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    MutantStack<int> s(mstack);
    s.push(45);
    s.push(220);
    s.push(10);
    std::cout<<s.top()<<std::endl;
    s.pop();
    std::cout<<"--------------------------------\n";
    std::list<int> p;
    p.push_back(5);
    p.push_back(17);
    p.push_back(3);
    p.push_back(5);
    p.push_back(737);
    p.push_back(0);
    std::list<int>::iterator i = p.begin();
    std::list<int>::iterator ie = p.end();
    while (i != ie)
    {
        std::cout << *i << std::endl;
        ++i;
    }
    return 0;
}