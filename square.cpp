// Киреев Александр Константинович 206
#include "square.hpp"
#include "cmath"
#define _USE_MATH_DEFINES

Square::Square(const Dot& center, const Dot& d) :
_center(center), _d(d) {
    _type = "Square";
}
Square::Square(const Square& s) {
    this->_center = s._center;
    this->_d = s._d;
    this->_type = s._type;
}
Square::Square(std::istream& is) {
    is >> this->_center >> this->_d;
    _type = "Square";
}
Dot Square::getCenter() const {
    return this->_center;
}
void Square::print(std::ostream& os) const {
    std::vector<Dot> dots;
    this->getCoords(dots);
    os << "[ " << dots[0];
    for (int i = 1; i < dots.size(); ++i) {
        os << ", " << dots[i];
    }
    os << " ]";
}
// будем считать площадь через описанную окружность, тк порядок точек фигуры не влияет на ее результат
double Square::getArea() const {
    double r = sqrt((this->_d.X - this->_center.X) * (this->_d.X - this->_center.X) +
    (this->_d.Y - this->_center.Y) * (this->_d.Y - this->_center.Y));
    return 2.0 * r * r;
}
std::string Square::getType() const {
    return _type;
}
void Square::getCoords(std::vector<Dot>& dots) const {
    double r = sqrt((this->_d.X - this->_center.X) * (this->_d.X - this->_center.X) +
    (this->_d.Y - this->_center.Y) * (this->_d.Y - this->_center.Y));
    double lenX = this->_d.X - this->_center.X;
    double lenY = this->_d.Y - this->_center.Y;
    double phi = acos(lenX / r);
    if (lenX < 0) {
        if (lenY < 0)
            phi = -M_PI + phi;
    } else {
        if (lenY < 0)
            phi = -phi;
    }
    for (int i = 0; i < 4; ++i) {
        double angle = 2.0 * M_PI * i / 4.0;
        dots.push_back(Dot(r * cos(angle + phi) + this->_center.X, r * sin(angle + phi) + this->_center.Y));
    }
}
std::ostream& operator<<(std::ostream& os, const Square& s) {
    s.print(os);
    return os;
}
