#pragma once
#include "figure.hpp"
#include "dot.hpp"
#include <iostream>

class Octagon: public Figure {
    public:
        Octagon(const Dot& d1, const Dot& d2, const Dot& d3, const Dot& d4,
            const Dot& d5, const Dot& d6, const Dot& d7, const Dot& d8);
        Octagon(const Octagon& o);
        Octagon(std::istream& is);
        Dot getCenter() const override;
        void print(std::ostream& os) const override;
        double getArea() const override;
        ~Octagon() {};
    private:
        Dot _d1, _d2, _d3, _d4, _d5, _d6, _d7, _d8;
};

std::ostream& operator<<(std::ostream& os, const Octagon& o); 
