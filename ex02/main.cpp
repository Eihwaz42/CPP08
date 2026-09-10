#include <iostream>
#include <stack>
#include <list>
#include <string>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== BASIC STACK TESTS ===" << std::endl;

    MutantStack<int> mstack;

    std::cout << std::boolalpha;
    std::cout << "Empty: " << mstack.empty() << std::endl;
    std::cout << std::noboolalpha;
    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(5);
    mstack.push(17);

    std::cout << "After pushing 5 and 17" << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.pop();

    std::cout << "After pop" << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;


    std::cout << std::endl;
    std::cout << "=== SUBJECT ITERATION TEST ===" << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Content:" << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }


    std::cout << std::endl;
    std::cout << "=== ITERATOR MOVEMENT TEST ===" << std::endl;

    it = mstack.begin();

    std::cout << "First value: " << *it << std::endl;

    ++it;
    std::cout << "After ++it: " << *it << std::endl;

    --it;
    std::cout << "After --it: " << *it << std::endl;


    std::cout << std::endl;
    std::cout << "=== MODIFY THROUGH ITERATOR ===" << std::endl;

    it = mstack.begin();

    std::cout << "Before modification: " << *it << std::endl;

    *it = 42;

    std::cout << "After modification: " << *it << std::endl;

    std::cout << "Full content:" << std::endl;

    for (it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;


    std::cout << std::endl;
    std::cout << "=== CONST ITERATOR TEST ===" << std::endl;

    const MutantStack<int> constStack(mstack);

    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();

    std::cout << "Const content:" << std::endl;

    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << std::endl;
    
    std::cout << "=== STD::STACK CONVERSION TEST ===" << std::endl;

    std::stack<int> normalStack(mstack);

    std::cout << "Normal stack size: " << normalStack.size() << std::endl;

    std::cout << "Normal stack top: " << normalStack.top() << std::endl;


    std::cout << std::endl;
    std::cout << "=== LIST COMPARISON TEST ===" << std::endl;

    std::list<int> lst;

    lst.push_back(42);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "MutantStack content:" << std::endl;

    for (it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "List content:" << std::endl;

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }


    std::cout << std::endl;
    std::cout << "=== STRING MUTANTSTACK TEST ===" << std::endl;

    MutantStack<std::string> strings;

    strings.push("hello");
    strings.push("from");
    strings.push("MutantStack");

    MutantStack<std::string>::iterator sit = strings.begin();
    MutantStack<std::string>::iterator site = strings.end();

    while (sit != site)
    {
        std::cout << *sit << std::endl;
        ++sit;
    }

    return 0;
}