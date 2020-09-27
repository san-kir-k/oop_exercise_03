#include <iostream>
#include <vector>
#include "octagon.hpp"
#include "square.hpp"
#include "triangle.hpp"

void applyToVec(const std::vector<Figure*>& vec) {
    for (auto v : vec) {
        std::cout << "Next figure is " << v->getType() << ": " << std::endl;
        std::cout << "Center: " << v->getCenter() << std::endl;
        std::cout << "Figure coords: ";
        v->print(std::cout);
        std::cout << std::endl;
        std::cout << "Area: " << v->getArea() << std::endl << std::endl;
    }
}

double totalArea(const std::vector<Figure*>& vec) {
    double result = 0.0;
    for (auto v : vec) {
        result += v->getArea();
    }
    return result;
}

int main() {
    return 0;
}