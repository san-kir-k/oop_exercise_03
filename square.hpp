#pragma once
#include "figure.hpp"
#include "dot.hpp"
#include <iostream>
#include <string>

class Square: public Figure {
    public:
        Square() = default;
        Square(const Dot& d1, const Dot& d2, const Dot& d3, const Dot& d4);
        Square(const Square& s);
        Square(std::istream& is);
        Dot getCenter() const override;
        void print(std::ostream& os) const override;
        double getArea() const override;
        std::string getType() const override;
        ~Square() = default;
    private:
        Dot _d1, _d2, _d3, _d4;
        std::string _type;
};

std::ostream& operator<<(std::ostream& os, const Square& s); 
