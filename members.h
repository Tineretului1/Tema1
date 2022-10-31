//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_MEMBERS_H
#define TEMA1_MEMBERS_H
#include <ostream>
#include "date.h"
class members //magazin membership-only ca la Metro
{
    int id;				//Primary Key
    std::string name;
    std::string addr_line;
    std::string city;
    std::string state;
    long int phn;
    date beg_date;
    date end_date;
public:
    members(int id, const std::string &name, const std::string &addrLine, const std::string &city, const std::string &state, long phn,
            const date &begDate, const date &endDate) : id(id), name(name), addr_line(addrLine), city(city),
                                                        state(state), phn(phn), beg_date(begDate), end_date(endDate) {}

    virtual ~members() {

    }


    friend std::ostream &operator<<(std::ostream &os, const members &members) {
        os << "id: " << members.id << " name: " << members.name << " addr_line: " << members.addr_line << " city: "
           << members.city << " state: " << members.state << " phn: " << members.phn << " beg_date: "
           << members.beg_date.day << "." << members.beg_date.month << "." << members.beg_date.year
           << " end_date: " << members.end_date.day << "." << members.end_date.month << "." << members.end_date.year;
        return os;
    }

    void add_mem(); //adauga membru
    void update(); //modifica membru
    void search_mem(); //cauta membru
};


#endif //TEMA1_MEMBERS_H
