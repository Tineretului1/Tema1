//
// Created by Rares on 11/2/2022.
//

#ifndef TEMA1_NOODLE_H
#define TEMA1_NOODLE_H
#include "product.h"
#include <ostream>

class noodle:product{
    char cooked;
public:
    noodle(int id, const std::string &name, const std::string &country, int qty, int price, char cooked) : product(id,
                                                                                                                    name,
                                                                                                                    country,
                                                                                                                    qty,
                                                                                                                    price),
                                                                                                            cooked(cooked) {}

    noodle& operator=(const noodle& other);

    bool operator==(const noodle &rhs) const {
        return static_cast<const product &>(*this) == static_cast<const product &>(rhs) &&
               cooked == rhs.cooked;
    }

    bool operator!=(const noodle &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const noodle &noodles) {
        os << static_cast<const product &>(noodles) << " cooked: " << noodles.cooked;
        return os;
    }
};


#endif //TEMA1_NOODLE_H
