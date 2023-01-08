//
// Created by Rares on 11/2/2022.
//

#ifndef TEMA1_SRIRACHA_H
#define TEMA1_SRIRACHA_H
#include "product.h"
#include <ostream>

class sriracha: public product{

    std::string bottle;//glass or plastic
public:
    sriracha(int id, const std::string &name, const std::string &country, int qty, int price, const std::string &bottle)
            : product(id, name, country, qty, price), bottle(bottle) {}

    bool operator==(const sriracha &rhs) const {
        return dynamic_cast<const product &>(*this) == dynamic_cast<const product &>(rhs) &&
               bottle == rhs.bottle;
    }

    bool operator!=(const sriracha &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const sriracha &sriracha) {
        os << dynamic_cast<const product &>(sriracha) << " bottle: " << sriracha.bottle;
        return os;
    }
};


#endif //TEMA1_SRIRACHA_H
