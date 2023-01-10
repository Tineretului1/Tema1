//
// Created by Rares on 11/2/2022.
//

#ifndef TEMA1_TEA_H
#define TEMA1_TEA_H
#include "product.h"
#include <ostream>

class tea : public product{
    std::string type;//green black white
public:
    tea(int id, const std::string &name, const std::string &country, int qty, int price, const std::string &type)
            : product(id, name, country, qty, price), type(type) {}

    bool operator==(const tea &rhs) const {
        return static_cast<const product &>(*this) == static_cast<const product &>(rhs) &&
               type == rhs.type;
    }

    bool operator!=(const tea &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const tea &tea) {
        os << static_cast<const product &>(tea) << " type: " << tea.type;
        return os;
    }
};


#endif //TEMA1_TEA_H
