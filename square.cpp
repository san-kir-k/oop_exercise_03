#include "square.hpp"
#include "cmath"

Square::Square(const Dot& d1, const Dot& d2, const Dot& d3, const Dot& d4) :
_d1(d1), _d2(d2), _d3(d3), _d4(d4) {}
Square::Square(const Square& s) {
    this->_d1 = s._d1;
    this->_d2 = s._d2;
    this->_d3 = s._d3;
    this->_d4 = s._d4;
}
Square::Square(std::istream& is) {
    is >> this->_d1 >> this->_d2 >> this->_d3 >> this->_d4;
}
Dot Square::getCenter() const {
    double x = (_d1.X + _d2.X + _d3.X + _d4.X) / 4.0;
    double y = (_d1.Y + _d2.Y + _d3.Y + _d4.Y) / 4.0;
    return Dot(x, y);
}
void Square::print(std::ostream& os) const {
    os << "[ " << this->_d1 << ", " << this->_d2 << ", "  << this->_d3 << ", "  << this->_d4 << " ]";
}
double Square::getArea() const {
    return 0.5 * abs(_d1.X * _d2.Y + _d2.X * _d3.Y + _d3.X * _d4.Y + _d4.X * _d1.Y - 
    (_d1.Y * _d2.X + _d2.Y * _d3.X + _d3.Y * _d4.X + _d4.Y * _d1.X));
}
std::ostream& operator<<(std::ostream& os, const Square& s) {
    s.print(os);
    return os;
}
