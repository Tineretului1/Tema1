//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_MEMBER_H
#define TEMA1_MEMBER_H
#include <ostream>
#include <vector>
#include <iostream>
#include "date.h"
class member //magazin membership-only ca la Metro
{
    int id;				//Primary Key
    std::string name;
    std::string addr_line;
    std::string city;
    std::string state;
    long int phone;
    date beg_date;
    date end_date;
public:
    member(int id, const std::string &name, const std::string &addrLine, const std::string &city, const std::string &state, long phn,
           const date &begDate, const date &endDate) : id(id), name(name), addr_line(addrLine), city(city),
                                                       state(state), phone(phn), beg_date(begDate), end_date(endDate) {}

    virtual ~member() {

    }

    void setName(const std::string &name) {
        member::name = name;
    }

    void setAddrLine(const std::string &addrLine) {
        addr_line = addrLine;
    }

    void setCity(const std::string &city) {
        member::city = city;
    }

    void setState(const std::string &state) {
        member::state = state;
    }

    void setPhone(long phone) {
        member::phone = phone;
    }

    friend std::ostream &operator<<(std::ostream &os, const member &members) {
        os << "id: " << members.id << " name: " << members.name << " addr_line: " << members.addr_line << " city: "
           << members.city << " state: " << members.state << " phone: " << members.phone << " beg_date: "
           << members.beg_date.day << "." << members.beg_date.month << "." << members.beg_date.year
           << " end_date: " << members.end_date.day << "." << members.end_date.month << "." << members.end_date.year;
        return os;
    }

    bool operator==(const member &rhs) const;

    bool operator!=(const member &rhs) const;

    static void add_mem(std::vector <member>& vector, member membru); //adauga membru
    static void search_mem(std::vector <member>& vector, member membru){
        for(long unsigned int i = 0; i<vector.size(); i++)
            if(membru == vector[i])
                std::cout<<"exista"<<'\n';
    }; //cauta membru

    void update(member membru, std::string newName, std::string newAddr, std::string newCit, long newPhn);
};


#endif //TEMA1_MEMBER_H
