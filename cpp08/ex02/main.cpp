#include "MutantStack.hpp"
#include <deque>
#include <iostream>

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(90);
        std::cout << "top value: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        int i = 0;
        while (it != ite)
        {
            std::cout << "stack[" << i << "]: " << *it << std::endl;
            ++it;
            i++;
        }

        std::stack<int> s(mstack);
    }

    {
        std::deque<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        mstack.push_back(90);
        std::cout << "top value: " << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << "size: " << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::deque<int>::iterator it = mstack.begin();
        std::deque<int>::iterator ite = mstack.end();

        ++it;
        --it;
        int i = 0;
        while (it != ite)
        {
            std::cout << "stack[" << i << "]: " << *it << std::endl;
            ++it;
            i++;
        }

        std::stack<int> s(mstack);
    }
    
    return 0;
}