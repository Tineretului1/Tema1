//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_SUPPLIER_H
#define TEMA1_SUPPLIER_H
#include <ostream>
#include "product.h"
class supplier
{
    product produs;
    int id;				//Primary Key
    std::string name; //nume producator
    long int phn; //nr telefon producator
    std::string addr_line1; //adresa
    std::string city; //oras produc.
    std::string country; //tara firma produc.
public:
    supplier(product produs, int id, const std::string &name, long phn, const std::string &addrLine1,
             const std::string &city, const std::string &country)
            : produs(produs), id(id), name(name), phn(phn), addr_line1(addrLine1), city(city), country(country) {}

    virtual ~supplier() {

    }

    friend std::ostream &operator<<(std::ostream &os, const supplier &suppliers) {
        os <<"Nume produs: "<<suppliers.produs.getName() << "id: " << suppliers.id << " name: " << suppliers.name << " phone: " << suppliers.phn << " addr_line1: "
           << suppliers.addr_line1 << " city: " << suppliers.city << " country: " << suppliers.country;
        return os;
    }

    void add_sup(); //nou produc.
    void remove_supplier(); //sterge produs.
    void search_id(); //cauta produc.
};


#endif //TEMA1_SUPPLIER_H
