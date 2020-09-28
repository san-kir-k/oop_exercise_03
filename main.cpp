// Киреев Александр Константинович 206
#include <iostream>
#include <vector>
#include "octagon.hpp"
#include "square.hpp"
#include "triangle.hpp"

// функция, которая вызывает для каждого элемента массива его 3 базовых метода
void applyToVec(const std::vector<Figure*>& vec) {
    for (auto v : vec) {
        std::cout << ">>Next figure is " << v->getType() << ": " << std::endl;
        std::cout << "Center: " << v->getCenter() << std::endl;
        std::cout << "Figure coords: ";
        v->print(std::cout);
        std::cout << std::endl;
        std::cout << "Area: " << v->getArea() << std::endl;
    }
}

// считает суммарную площадь всех фигур в векторе
double totalArea(const std::vector<Figure*>& vec) {
    double result = 0.0;
    for (auto v : vec) {
        result += v->getArea();
    }
    return result;
}

// мануал
void help() {
    std::cout << "Command -- Description\n" <<
                "1 [idx] -- Display figure by index in vector\n" <<
                "2 [1..3] -- Add figure (type 1 - oct, 2 - sq, 3 - tri)\n" <<
                "3 -- Apply base methods to the entire vector\n" <<
                "4 -- Calculate total area of figures in vector\n" << 
                "5 [idx] -- Delete figure by index from vector\n" <<
                "6 -- Display vector\n" << 
                "7 -- Display help\n" <<
                "8 -- End program" << std::endl;
}

void mainLoop() {
    int command = 0, idx = 0, type = 0;
    std::vector<Figure*> vec;
    Figure* f;
    while (std::cout << "Cmd: " && std::cin >> command && command != 8) {
        switch (command) {
            case 1:
                std::cin >> idx;
                if (idx < 0 || idx >= vec.size()) {
                    std::cout << "Invalid index." << std::endl;
                    break;
                }
                vec[idx]->print(std::cout);
                std::cout << std::endl;
                break;
            case 2:
                std::cin >> type;
                switch (type) {
                    case 1:
                        f = new Octagon(std::cin);
                        vec.push_back(f);
                        break;
                    case 2:
                        f = new Square(std::cin);
                        vec.push_back(f);
                        break;
                    case 3:
                        f = new Triangle(std::cin);
                        vec.push_back(f);
                        break;
                    default:
                        std::cout << "Invalid type." << std::endl;
                        break;
                }
                break;
            case 3:
                applyToVec(vec);
                break;
            case 4:
                std::cout << totalArea(vec) << std::endl;
                break;
            case 5:
                std::cin >> idx;
                if (idx < 0 || idx >= vec.size()) {
                    std::cout << "Invalid index." << std::endl;
                    break;
                }
                f = vec[idx];
                vec.erase(vec.begin() + idx);
                // освобождаем память, чтоб не утеклало по памяти
                delete f;
                break;
            case 6:
                std::cout << "=========START OF VECTOR=========" << std::endl;
                for (auto v : vec) {
                    v->print(std::cout);
                    std::cout << std::endl;
                }
                std::cout << "==========END OF VECTOR==========" << std::endl;
                break;
            case 7:
                help();
                break;
            default:
                std::cout << "Invalid command!" << std::endl; 
                break;
        }
    }
    // освобождаем память в векторе, чтобы не утекало
    for (auto v : vec) {
        delete v;
    }
}

int main() {
    help();
    mainLoop();
    return 0;
}
