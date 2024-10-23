#include <iostream>
#include "square.hpp"

double Square::get_side() const
{
    return this->side;
}
double Square::get_area() const
{
    return this->side * this->side;
}

double Square::get_perimeter() const
{
    return 4 * this->side;
}

void Square::print(std::ostream& out = std::cout) const
{
    out << "(square " << this->get_side() << ")";
}

bool Square::operator<(const Square& rhs) const
{
    return this->get_side() < rhs.get_side();
}

bool Square::operator==(const Square& rhs) const
{
    return this->get_side() == rhs.get_side();
}

std::ostream& operator<<(std::ostream& out, const Square& rhs)
{
    rhs.print(out);
    return out;
}