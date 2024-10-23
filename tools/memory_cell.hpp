#ifndef MEMORY_CELL_HPP
#define MEMORY_CELL_HPP

/**
 * A class for simulating a memory cell.
 */
template <typename Object>
class MemoryCell
{
public:
    explicit MemoryCell(const Object& initial_value = Object{})
        : stored_value{initial_value}
    {}

    const Object& read() const
    {
        return this->stored_value;
    }

    void write(const Object& x)
    {
        this->stored_value = x;
    }
private:
    Object stored_value;
};

#endif