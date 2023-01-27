//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_PRODUCT_H
#define TEMA1_PRODUCT_H
#include <ostream>
#include <vector>
#include <iostream>
#include <memory>

class myException : public std::runtime_error { using std::runtime_error::runtime_error; };
class eroare_discount_produs: public myException {using myException::myException;};
class product
{
    int id;	//Primary Key, in caz ca o sa implementez si un
    //db cu produse
    std::string name;
    std::string country; //chinez, vietnamez
    int qty; //cantitate
    //pret
    friend class ProductBuilder;
protected:
    float price;
public:

    int getPrice() const {
        return price;
    }

    const std::string &getName() const;

    product(int id, const std::string &name, const std::string &country, int qty, float price) : id(id), name(name), country(country), qty(qty),
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

    product();

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
    virtual void discount(int percent){
        if(percent>99)
            throw eroare_discount_produs("eroare discount produs");
        else {
            float oldPrice = getPrice();
            float newPrice = (oldPrice * 100 - oldPrice * percent) / 100;
            product::price = newPrice;
        }
    }

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
    }

    virtual void display(){
        std::cout<<id;
    } //afisam produs
};

class ProductBuilder {
private:
    product p;
public:
    ProductBuilder& setId(int id) {
        p.id = id;
        return *this;
    }
    ProductBuilder& setName(std::string name) {
        p.name = name;
        return *this;
    }
    ProductBuilder& setCountry(std::string country) {
        p.country = country;
        return *this;
    }
    ProductBuilder& setQty(int qty) {
        p.qty = qty;
        return *this;
    }
    ProductBuilder& setPrice(float price) {
        p.price = price;
        return *this;
    }
    product& build() {
        return p;
    }
};


class productDecorator : public product {
    std::shared_ptr<product> decoratedProduct;

public:
    productDecorator(std::shared_ptr<product> decoratedProduct) : decoratedProduct(decoratedProduct) {}

    int getPrice() const {
        return decoratedProduct->getPrice();
    }

    const std::string &getName() const {
        return decoratedProduct->getName();
    }

    friend std::ostream &operator<<(std::ostream &os, const productDecorator &decorator) {
        os << *decorator.decoratedProduct;
        return os;
    }

    bool operator==(const productDecorator &rhs) const {
        return *decoratedProduct == *rhs.decoratedProduct;
    }

    bool operator!=(const productDecorator &rhs) const {
        return !(rhs == *this);
    }

    void discount(int percent) {
        decoratedProduct->discount(percent);
    }

    void display() {
        decoratedProduct->display();
    }

    float vat(int percent) {
        return ((100 + percent * 1.0) / 100) * (decoratedProduct->getPrice());
    }
};

class asian_products_factory {
public:
    static product create_chinese_chair() { return product(1, "Chinese Chair", "China", 10, 20.0f); }
    static product create_vietnamese_chair() { return product(2, "Vietnamese Chair", "Vietnam", 5, 15.0f); }
    static product create_chinese_table() { return product(3, "Chinese Table", "China", 8, 25.0f); }
    static product create_vietnamese_table() { return product(4, "Vietnamese Table", "Vietnam", 12, 30.0f); }
    static product create_asian_lamp() { return product(5, "Asian Lamp", "Asia", 15, 35.0f); }
    static product create_japanese_chair() { return product(6, "Japanese Chair", "Japan", 7, 18.0f); }
    static product create_korean_chair() { return product(7, "Korean Chair", "Korea", 9, 22.0f); }
    static product create_japanese_table() { return product(8, "Japanese Table", "Japan", 11, 28.0f); }
    static product create_korean_table() { return product(9, "Korean Table", "Korea", 13, 32.0f); }
    static product create_asian_carpet() { return product(10, "Asian Carpet", "Asia", 20, 40.0f); }
};


#endif //TEMA1_PRODUCT_H
