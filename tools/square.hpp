#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>

class Square
{
public:
    explicit Square(double s = 0.0) : side{s}
    {}

    double get_side() const;
    double get_area() const;
    double get_perimeter() const;
    void print(std::ostream& out) const;
    bool operator<(const Square& rhs) const;
    bool operator==(const Square& rhs) const;

private:
    double side;
};

// Define an output operator for Square
std::ostream& operator<<(std::ostream& out, const Square& rhs);

#endif