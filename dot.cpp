#include "dot.hpp"

Dot::Dot(double x = 0.0, double y = 0.0) {
    X = x;
    Y = y;
}
Dot::Dot(const Dot& d) {
    this->X = d.X;
    this->Y = d.Y;
}

std::istream& operator>>(std::istream& is, Dot& d) {
    is >> d.X >> d.Y;
}
std::ostream& operator<<(std::ostream& os, const Dot& d) {
    os << "(" << d.X << ", " << d.Y << ")"; 
}
