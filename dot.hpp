#pragma once
#include <iostream>

struct Dot {
    public:
        double X, Y;
        Dot(double x = 0.0, double y = 0.0);
        Dot(const Dot& d);
        ~Dot() {}; 
};

std::istream& operator>>(std::istream& is, Dot& d);
std::ostream& operator<<(std::ostream& os, const Dot& d);
