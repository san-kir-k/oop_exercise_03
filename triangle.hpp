#pragma once
#include "figure.hpp"
#include "dot.hpp"
#include <iostream>
#include <string>

class Triangle: public Figure {
    public:
        Triangle(const Dot& d1, const Dot& d2, const Dot& d3);
        Triangle(const Triangle& t);
        Triangle(std::istream& is);
        Dot getCenter() const override;
        void print(std::ostream& os) const override;
        double getArea() const override;
        std::string getType() const override;
        ~Triangle() {};
    private:
        Dot _d1, _d2, _d3;
        std::string _type;
};

std::ostream& operator<<(std::ostream& os, const Triangle& t); 
