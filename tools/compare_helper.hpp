#ifndef COMPARE_HELPER_HPP
#define COMPARE_HELPER_HPP

#include <iostream>
#include <vector>


namespace tools{

/**
 * Prints the vector in a style "v = [ a1, a2, a3, a4, ..., an ]".
 * Supports displayable types.
 */
template <typename T>
void print_vector(std::vector<T>& vec)
{
    std::cout << "v = [ ";
    for (T& val : vec)
    {
        std::cout << val << ' ';
    }
    std::cout << "]" << '\n';
}

/**
 * Return the maximum item in array a.
 * Assumes a.size() > 0.
 * Comparable objects must provide operator< and operator=.
 */
template <typename Comparable>
const Comparable& find_max(const std::vector<Comparable>& a)
{
    int max_index = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[max_index] < a[i]) max_index = i;
    }
    return a[max_index];
}
}

#endif