// Киреев Александр Константинович 206
#include "dot.hpp"

Dot::Dot() {
    X = 0.0;
    Y = 0.0;
}
Dot::Dot(double x, double y) {
    X = x;
    Y = y;
}
Dot::Dot(const Dot& d) {
    this->X = d.X;
    this->Y = d.Y;
}

std::istream& operator>>(std::istream& is, Dot& d) {
    is >> d.X >> d.Y;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Dot& d) {
    std::cout.precision(3);
    os << "(" << std::fixed <<  d.X << ", " << std::fixed <<  d.Y << ")"; 
    return os;
}
