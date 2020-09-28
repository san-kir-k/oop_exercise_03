#pragma once
#include <iostream>

struct Dot {
    public:
        double X, Y;
        Dot();
        Dot(double x, double y);
        Dot(const Dot& d);
        ~Dot() = default; 
};

std::istream& operator>>(std::istream& is, Dot& d);
std::ostream& operator<<(std::ostream& os, const Dot& d);
