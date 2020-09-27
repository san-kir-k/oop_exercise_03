#include "triangle.hpp"
#include "cmath"

Triangle::Triangle(const Dot& d1, const Dot& d2, const Dot& d3) : _d1(d1), _d2(d2), _d3(d3) {
    _type = "Triangle";
}
Triangle::Triangle(const Triangle& t) {
    this->_d1 = t._d1;
    this->_d2 = t._d2;
    this->_d3 = t._d3;
    this->_type = t._type;
}
Triangle::Triangle(std::istream& is) {
    is >> this->_d1 >> this->_d2 >> this->_d3;
    _type = "Triangle";
}
Dot Triangle::getCenter() const {
    double x = (_d1.X + _d2.X + _d3.X) / 3.0;
    double y = (_d1.Y + _d2.Y + _d3.Y) / 3.0;
    return Dot(x, y);
}
void Triangle::print(std::ostream& os) const {
    os << "[ " << this->_d1 << ", " << this->_d2 << ", "  << this->_d3 << " ]";
}
double Triangle::getArea() const {
    return 0.5 * abs(_d1.X * _d2.Y + _d2.X * _d3.Y + _d3.X * _d1.Y - 
    (_d1.Y * _d2.X + _d2.Y * _d3.X + _d3.Y * _d1.X));
}
std::string Triangle::getType() const {
    return _type;
}
std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    t.print(os);
    return os;
}
