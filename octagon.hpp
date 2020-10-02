// Киреев Александр Константинович 206
#pragma once
#include "figure.hpp"
#include "dot.hpp"
#include <iostream>
#include <string>
#include <vector>

class Octagon: public Figure {
    public:
        Octagon() = default;
        Octagon(const Dot& center, const Dot& d);
        Octagon(const Octagon& o);
        Octagon(std::istream& is);
        Dot getCenter() const override;
        void print(std::ostream& os) const override;
        double getArea() const override;
        std::string getType() const override;
        void getCoords(std::vector<Dot>& dots) const;
        ~Octagon() = default;
    private:
        Dot _center, _d;
};

std::ostream& operator<<(std::ostream& os, const Octagon& o); 
