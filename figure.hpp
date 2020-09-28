// Киреев Александр Константинович 206
#pragma once
#include "dot.hpp"
#include <string>

class Figure {
    public: 
        virtual Dot getCenter() const = 0;
        virtual void print(std::ostream& os) const = 0;
        virtual double getArea() const = 0;
        // добавим метод getType(), чтобы при выводе видить, что за фигура перед нами
        virtual std::string getType() const { return _type; }
        // виртуальный деструктор, чтобы корректно вызывались деструкторы дочерних классов
        virtual ~Figure() = default;
    protected:
        std::string _type;
};
