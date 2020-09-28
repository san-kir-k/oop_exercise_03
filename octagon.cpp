// Киреев Александр Константинович 206
#include "octagon.hpp"
#include "cmath"

Octagon::Octagon(const Dot& d1, const Dot& d2, const Dot& d3,
const Dot& d4, const Dot& d5, const Dot& d6, const Dot& d7, const Dot& d8) :
_d1(d1), _d2(d2), _d3(d3), _d4(d4), _d5(d5), _d6(d6), _d7(d7), _d8(d8) {
    _type = "Octagon";
}
Octagon::Octagon(const Octagon& o) {
    this->_d1 = o._d1;
    this->_d2 = o._d2;
    this->_d3 = o._d3;
    this->_d4 = o._d4;
    this->_d5 = o._d5;
    this->_d6 = o._d6;
    this->_d7 = o._d7;
    this->_d8 = o._d8;
    this->_type = o._type;
}
Octagon::Octagon(std::istream& is) {
    is >> this->_d1 >> this->_d2 >> this->_d3 >> this->_d4 >>
    this->_d5 >> this->_d6 >> this->_d7 >> this->_d8;
    _type = "Octagon";
}
Dot Octagon::getCenter() const {
    double x = (_d1.X + _d2.X + _d3.X + _d4.X + _d5.X + _d6.X + _d7.X + _d8.X) / 8.0;
    double y = (_d1.Y + _d2.Y + _d3.Y + _d4.Y + _d5.Y + _d6.Y + _d7.Y + _d8.Y) / 8.0;
    return Dot(x, y);
}
void Octagon::print(std::ostream& os) const {
    os << "[ " << this->_d1 << ", " << this->_d2 << ", "  << this->_d3 << ", "  << this->_d4 <<
    ", "  << this->_d5 << ", "  << this->_d6 << ", "  << this->_d7 << ", "  << this->_d8 << " ]";
}
// будем считать площадь через описанную окружность, тк порядок точек фигуры не влияет на ее результат
double Octagon::getArea() const {
    Dot c = this->getCenter();
    double r = sqrt((this->_d1.X - c.X) * (this->_d1.X - c.X) + (this->_d1.Y - c.Y) * (this->_d1.Y - c.Y));
    return 2.0 * sqrt(2.0) * r * r;
}
std::string Octagon::getType() const {
    return _type;
}
std::ostream& operator<<(std::ostream& os, const Octagon& o) {
    o.print(os);
    return os;
}
