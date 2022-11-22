//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_PRODUCT_H
#define TEMA1_PRODUCT_H
#include <ostream>
#include <vector>
#include <iostream>

class product
{
    int id;	//Primary Key, in caz ca o sa implementez si un
    //db cu produse
    std::string name;
    std::string country; //chinez, vietnamez
    int qty; //cantitate
    int price; //pret
public:

    int getPrice() const {
        return price;
    }

    product(int id, const std::string &name, const std::string &country, int qty, int price) : id(id), name(name), country(country), qty(qty),
                                                                                     price(price) {}

    virtual ~product() {

    }

    friend std::ostream &operator<<(std::ostream &os, const product &products) {
        os << "id: " << products.id << " name: " << products.name << " country: " << products.country << " qty: "
           << products.qty << " price: " << products.price;
        return os;
    }

    product& operator=(const product& other);
    product(const product& p1);
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
    void discount(int percent){
        int oldPrice = getPrice();
        int newPrice = (oldPrice*100 - oldPrice*percent)/100;
        product::price = newPrice;
    };
    void add(std::vector <product>& vector, product produs) {
        vector.push_back(produs);
    } //adaugare produs
    void update_price(int x){
        product::price = x;
    } //schimbare pret
    static void search(const std::vector <product>& vector, const product &angajat){
        for(long unsigned int i = 0; i<vector.size(); i++)
            if(angajat == vector[i])
                std::cout<<"exista"<<'\n';
    };
    void display(){
        std::cout<<id;
    } //afisam produs
};

#endif //TEMA1_PRODUCT_H
