//
// Created by Rares on 11/2/2022.
//

#ifndef TEMA1_MATCHA_H
#define TEMA1_MATCHA_H
#include "product.h"
#include <ostream>

class matcha:public product{
    char milk;//A-yes F-no
public:
    matcha(int id, const std::string &name, const std::string &country, int qty, float price, char milk) : product(id,
                                                                                                                 name,
                                                                                                                 country,
                                                                                                                 qty,
                                                                                                                 price),
                                                                                                         milk(milk) {}

    bool operator==(const matcha &rhs) const {
        return static_cast<const product &>(*this) == static_cast<const product &>(rhs) &&
               milk == rhs.milk;
    }

    bool operator!=(const matcha &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const matcha &matcha) {
        os << static_cast<const product &>(matcha) << " milk: " << matcha.milk;
        return os;
    }
    void discount(int percent) override{
        if(percent>20)
            throw "Discount peste 20";
        else {
            float oldPrice = getPrice();
            float newPrice = (oldPrice * 100 - oldPrice * percent) / 100;
            matcha::price = newPrice;
        }
    }
};


#endif //TEMA1_MATCHA_H
