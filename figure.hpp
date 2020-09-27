#pragma once
#include "dot.hpp"
#include <string>

class Figure {
    public: 
        virtual Dot getCenter() const = 0;
        virtual void print(std::ostream& os) const = 0;
        virtual double getArea() const = 0;
        virtual std::string getType() const;
        virtual ~Figure() {};
};
