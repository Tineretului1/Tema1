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
    matcha(int id, const std::string &name, const std::string &country, int qty, int price, char milk) : product(id,
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
};


#endif //TEMA1_MATCHA_H
