#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <dummy_class.hpp>
#include <compare_helper.hpp>


int main()
{
    std::vector<int> v1;
    std::vector<double> v2;
    std::vector<std::string> v3;
    std::vector<DummyClass> v4;

    std::uniform_int_distribution<int> int_unif(0, 100);
    std::uniform_real_distribution<double> double_unif(0, 100);
    std::default_random_engine re;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(int_unif(re));
        v2.push_back(double_unif(re));
        v3.push_back(std::to_string(int_unif(re)));
        v4.push_back(DummyClass());
    }
    tools::print_vector(v1);
    tools::print_vector(v2);
    tools::print_vector(v3);

    std::cout << tools::find_max(v1) << '\n';
    std::cout << tools::find_max(v2) << '\n';
    std::cout << tools::find_max(v3) << '\n';
    //std::cout << find_max(v4) << '\n'; Error: DummyClass doesn't implements operator< and operator=
}
