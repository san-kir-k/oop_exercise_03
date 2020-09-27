#pragma once

class Figure {
    public: 
        virtual double getCenter() const = 0;
        virtual void print() const = 0;
        virtual double getArea() const = 0;
        virtual ~Figure() {};
};
