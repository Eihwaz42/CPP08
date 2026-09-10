#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include "easyfind.hpp"

int main()
{
    std::cout << "=== VECTOR TESTS ===" << std::endl;

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(20);
    vec.push_back(40);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 30);

        std::cout << "Searching for 30" << std::endl;
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Position: "
                  << std::distance(vec.begin(), it)
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);

        std::cout << "Searching for duplicated value 20" << std::endl;
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "First occurrence position: "
                  << std::distance(vec.begin(), it)
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Searching for 99" << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 99);

        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== LIST TESTS ===" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 15);

        std::cout << "Searching for 15" << std::endl;
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Position: "
                  << std::distance(lst.begin(), it)
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Searching for -1" << std::endl;
        std::list<int>::iterator it = easyfind(lst, -1);

        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== DEQUE TESTS ===" << std::endl;

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_front(50);

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 50);

        std::cout << "Searching for 50" << std::endl;
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Position: "
                  << std::distance(deq.begin(), it)
                  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Searching for 500" << std::endl;
        std::deque<int>::iterator it = easyfind(deq, 500);

        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}