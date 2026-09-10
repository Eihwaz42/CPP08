#include <iostream>
#include <vector>
#include <climits>
#include "Span.hpp"

int main()
{
    std::cout << "=== SUBJECT TEST ===" << std::endl;

    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;


    std::cout << std::endl;
    std::cout << "=== FULL SPAN TEST ===" << std::endl;

    try
    {
        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << std::endl;
    std::cout << "=== NOT ENOUGH NUMBERS ===" << std::endl;

    Span small(5);
    small.addNumber(42);

    try
    {
        std::cout << small.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Shortest span: " << e.what() << std::endl;
    }

    try
    {
        std::cout << small.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Longest span: " << e.what() << std::endl;
    }


    std::cout << std::endl;
    std::cout << "=== DUPLICATE TEST ===" << std::endl;

    Span duplicate(4);

    duplicate.addNumber(10);
    duplicate.addNumber(42);
    duplicate.addNumber(10);
    duplicate.addNumber(100);

    std::cout << "Shortest span: " << duplicate.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << duplicate.longestSpan() << std::endl;


    std::cout << std::endl;
    std::cout << "=== RANGE OF ITERATORS ===" << std::endl;

    std::vector<int> values;

    values.push_back(10);
    values.push_back(20);
    values.push_back(30);
    values.push_back(40);
    values.push_back(50);

    Span range(5);
    range.addNumbers(values.begin(), values.end());

    std::cout << "Shortest span: " << range.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << range.longestSpan() << std::endl;


    std::cout << std::endl;
    std::cout << "=== 10000 NUMBERS ===" << std::endl;

    std::vector<int> bigValues;

    for (int i = 0; i < 10000; ++i)
        bigValues.push_back(i * 2);

    Span big(10000);
    big.addNumbers(bigValues.begin(), bigValues.end());

    std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << big.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << "=== INT LIMITS ===" << std::endl;

    Span limits(2);

    limits.addNumber(INT_MIN);
    limits.addNumber(INT_MAX);

    std::cout << "Shortest span: " << limits.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << limits.longestSpan() << std::endl;

    return 0;
}