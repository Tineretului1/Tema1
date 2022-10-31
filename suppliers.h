//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_SUPPLIERS_H
#define TEMA1_SUPPLIERS_H
#include <ostream>

class suppliers
{
    int id;				//Primary Key
    std::string name; //nume producator
    long int phn; //nr telefon producator
    std::string addr_line1; //adresa
    std::string city; //oras produc.
    std::string country; //tara firma produc.
public:
    suppliers(int id, const std::string &name, long phn, const std::string &addrLine1, const std::string &city, const std::string &country)
            : id(id), name(name), phn(phn), addr_line1(addrLine1), city(city), country(country) {}

    virtual ~suppliers() {

    }

    friend std::ostream &operator<<(std::ostream &os, const suppliers &suppliers) {
        os << "id: " << suppliers.id << " name: " << suppliers.name << " phn: " << suppliers.phn << " addr_line1: "
           << suppliers.addr_line1 << " city: " << suppliers.city << " country: " << suppliers.country;
        return os;
    }

    void add_sup(); //nou produc.
    void remove_supplier(); //sterge produs.
    void search_id(); //cauta produc.
};


#endif //TEMA1_SUPPLIERS_H
