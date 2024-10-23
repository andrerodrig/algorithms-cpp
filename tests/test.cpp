#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <cassert>
#include <dummy_class.hpp>
#include <compare_helper.hpp>
#include <memory_cell.hpp>
#include <algorithm>
#include <square.hpp>
#include <tree.hpp>


void test_find_max()
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

    int exp_v1_max = *std::max_element(v1.begin(), v1.end());
    double exp_v2_max = *std::max_element(v2.begin(), v2.end());
    std::string exp_v3_max = *std::max_element(v3.begin(), v3.end());

    assert(tools::find_max(v1) == exp_v1_max);
    assert(tools::find_max(v2) == exp_v2_max);
    assert(tools::find_max(v3) == exp_v3_max);

    // tools::find_max(v4);
}

void test_memory_cell()
{
    MemoryCell<int> m1;
    MemoryCell<std::string> m2{"hello"};

    m1.write(37);
    m2.write(m2.read() + " world");
    std::cout << m1.read() << std::endl << m2.read() << std::endl;
    assert(m1.read() == 37);
    assert(m2.read() == "hello world");
}

void test_square()
{
    std::vector<Square> v = {Square{3.0}, Square{4.0}, Square{5.3}};
    Square exp_max = *std::max_element(v.begin(), v.end());

    std::cout << "Largest Square: " << tools::find_max(v) << std::endl;

    assert(tools::find_max(v) == exp_max);
}

void test_insert_node()
{
    auto tree = new BinarySearchTree<int>();
    tree->insert(5);
    tree->insert(2);
    tree->insert(10);
    tree->insert(7);

    int min = tree->find_min();
    int max = tree->find_max();

    assert(min == 2);
    assert(max == 10);
}

void test_remove_node()
{
    auto tree = new BinarySearchTree<int>();
    tree->insert(6);
    tree->insert(2);
    tree->insert(8);
    tree->insert(1);
    tree->insert(3);
    tree->insert(4);

    assert(tree->find_min() == 1);
    assert(tree->find_max() == 8);
    assert(tree->contains(2));

    tree->inorder_walk(std::cout);

    int key = 2;
    tree->remove(key);

    assert(!tree->contains(2));
    assert(tree->find_min() == 1);
    assert(tree->find_max() == 8);
}

void test_delete_tree()
{
    auto tree = BinarySearchTree<int>();
    tree.insert(6);
    tree.insert(2);
    tree.insert(8);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(4);

    assert(tree.find_min() == 1);
    assert(tree.find_max() == 8);

    tree.make_empty();

    assert(tree.is_empty());
}


int main()
{
    test_find_max();
    test_memory_cell();
    test_square();
    test_insert_node();
    test_remove_node();
    return 0;
}
