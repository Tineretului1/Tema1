//
// Created by Rares on 11/2/2022.
//

#ifndef TEMA1_RAMEN_H
#define TEMA1_RAMEN_H
#include "product.h"
#include <ostream>

class ramen: public product{
    std::string flavour;//spicy
public:
    ramen(int id, const std::string &name, const std::string &country, int qty, int price, const std::string &flavour)
            : product(id, name, country, qty, price), flavour(flavour) {}

    ~ramen() override {

    }

    friend std::ostream &operator<<(std::ostream &os, const ramen &ramen) {
        os << static_cast<const product &>(ramen) << " flavour: " << ramen.flavour;
        return os;
    }

    bool operator==(const ramen &rhs) const {
        return static_cast<const product &>(*this) == static_cast<const product &>(rhs) &&
               flavour == rhs.flavour;
    }

    bool operator!=(const ramen &rhs) const {
        return !(rhs == *this);
    }

    void display() override{
        std::cout<<"Id ramen: ";
        product::display();
        std::cout<<std::endl;
    }
};


#endif //TEMA1_RAMEN_H
