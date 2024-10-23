#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}
    {}

    /**
     * Copy constructor.
     */
    BinarySearchTree(const BinarySearchTree& rhs) : root{nullptr}
    {
        this->root = this->clone(rhs.root);
    }

    BinarySearchTree(const BinarySearchTree&& rhs) : root{std::move(rhs)}
    {}

    ~BinarySearchTree()
    {
        this->make_empty();
    }

    /**
     * Find mininum element in the tree.
     */
    Comparable& find_min() const
    {
        return this->_find_min(this->root)->key;
    }

    /**
     * Find maximum element in the tree.
     */
    Comparable& find_max() const
    {
        return this->_find_max(this->root)->key;
    }

    /**
     * Returns if x is found in the tree.
     */
    bool contains(const Comparable& x) const
    {
        return this->_contains(x, this->root);
    }

    bool is_empty() const
    {
        return this->root == nullptr;
    }
    void inorder_walk(std::ostream& out) const
    {
        out << "Inorder walk: ";
        this->_inorder_walk(this->root, out);
    }

    /**
     * Internal method to make the subtree empty.
     */
    void make_empty()
    {
        this->_make_empty(this->root);
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert(const Comparable& x)
    {
        return this->_insert(x, this->root);
    }

    void insert(Comparable&& x)
    {
        return this->_insert(std::move(x), this->root);
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove(Comparable& x)
    {
        return this->_remove(x, this->root);
    }

    BinarySearchTree& operator=(const BinarySearchTree& rhs);
    BinarySearchTree& operator=(BinarySearchTree&& rhs);

private:
    struct BinaryNode
    {
        Comparable key;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable& key, BinaryNode *lt, BinaryNode *rt)
            : key{key}, left{lt}, right{rt}
        {}

        BinaryNode(Comparable&& key, BinaryNode *lt, BinaryNode *rt)
            : key{std::move(key)}, left{lt}, right{rt}
        {}
    };

    BinaryNode *root;

    /**
     * Internal method to insert a into a subtree. 
     * x: item to insert;
     * t: the node that roots the subtree;
     * 
     * Set the new root of the subtree.
     */
    void _insert(const Comparable& x, BinaryNode*& t)
    {
        if (t == nullptr)
            t = new BinaryNode{x, nullptr, nullptr};
        else if (x < t->key)
            this->_insert(x, t->left);
        else if (t->key < x)
            this->_insert(x, t->right);
        else
            return ;
    } 

    /**
     * Internal method to insert into a subtree by moving. 
     * x: item to insert;
     * t: the node that roots the subtree;
     * 
     * Set the new root of the subtree.
     */
    void _insert(Comparable&& x, BinaryNode*& t)
    {
        if (t == nullptr)
            t = new BinaryNode{std::move(x), nullptr, nullptr};
        else if (x < t->key)
            this->_insert(std::move(x), t->left);
        else if (t->key < x)
            this->_insert(std::move(x), t->right);
        else
            return ;
    } 

    /**
     * Internal method to remove from a subtree.
     * x: item to be removed.
     * t: subtree's root.
     */
    void _remove(const Comparable& x, BinaryNode*& t)
    {
        if (t == nullptr)
            return; // do nothing. Item not found.

        if (x < t->key)
            this->_remove(x, t->left);

        else if (t->key < x)
            this->_remove(x, t->right);

        else if (t->left != nullptr && t->right != nullptr) // 2 children
        {
            t->key = this->_find_min(t->right)->key;
            this->_remove(t->key, t->right);
        }
        else
        {
            BinaryNode* old_node = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete old_node;
        }
    }
    
    /**
     * Internal method that searches recursively to find mininum element in the tree.
     */
    BinaryNode* _find_min(BinaryNode* t) const
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return this->_find_min(t->left);
    }

    /**
     * Internal method that searches through the right side of the three
     * to find maximum element.
     */
    BinaryNode* _find_max(BinaryNode* t) const
    {
        if (t != nullptr)
            while (t->right != nullptr)
                t = t->right;
        return t;
    }

    /**
     * Internal method to recursively search for the element x.
     * Returns true if it is found, otherwise returns false.
     */
    bool _contains(const Comparable& x, BinaryNode *t) const
    {
        if (t == nullptr)
            return false;
        else if (x < t->key)
            return this->_contains(x, t->left);
        else if (t->key < x)
            return this->_contains(x, t->right);
        else
            return true;
    }

    void _make_empty(BinaryNode*& t)
    {
        if (t != nullptr)
        {
            this->_make_empty(t->left);
            this->_make_empty(t->right);
            delete t;
        }
        t = nullptr;
    }
    
    void _inorder_walk(BinaryNode *t, std::ostream& out) const
    {
        if (t != nullptr)
        {
            this->_inorder_walk(t->left, out);
            out << t->key << ' ';
            this->_inorder_walk(t->right, out);
        }
    }

    BinaryNode* clone(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else
            return new BinaryNode{t->key, clone(t->left), clone(t->right)};
    }
};

#endif