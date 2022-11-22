//
// Created by Rares on 10/26/2022.
//

#include "product.h"
product &product::operator=(const product &other) {
    id = other.id;
    name = other.name;
    country = other.country;
    qty = other.qty;
    price = other.price;
    return *this;
}
product::product(const product& other) : id{other.id}, name{other.name}, country{other.country}, qty{other.qty}, price{other.price} {
    std::cout << "Constr de copiere Student\n";
}