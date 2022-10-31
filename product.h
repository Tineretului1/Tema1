//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_PRODUCT_H
#define TEMA1_PRODUCT_H
#include <ostream>

class product
{
    int id;	//Primary Key, in caz ca o sa implementez si un
    //db cu produse
    std::string name;
    std::string country; //chinez, vietnamez
    int qty; //cantitate
    int price; //pret
public:
    product(int id, const std::string &name, const std::string &country, int qty, int price) : id(id), name(name), country(country), qty(qty),
                                                                                     price(price) {}

    virtual ~product() {

    }

    friend std::ostream &operator<<(std::ostream &os, const product &products) {
        os << "id: " << products.id << " name: " << products.name << " country: " << products.country << " qty: "
           << products.qty << " price: " << products.price;
        return os;
    }

    bool operator==(const product &rhs) const {
        return id == rhs.id &&
               name == rhs.name &&
               country == rhs.country &&
               qty == rhs.qty &&
               price == rhs.price;
    }

    bool operator!=(const product &rhs) const {
        return !(rhs == *this);
    }

    void add(); //adaugare produs
    void update_price(); //schimbare pret
    void search(); //cautam produs in DB
    void update(); //modificam produs
    void display(); //afisam produs
};


#endif //TEMA1_PRODUCT_H
