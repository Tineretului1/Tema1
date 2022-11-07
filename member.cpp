//
// Created by Rares on 10/26/2022.
//

#include "member.h"
void member::add_mem(std::vector <member>& vector, member membru) {
    vector.push_back(membru);
}
void member::update(member membru,std::string newName,std::string newAddr, std::string newCit, long newPhn) {
    membru.setAddrLine(newAddr);
    membru.setCity(newCit);
    membru.setPhone(newPhn);
    membru.setName(newName);
}

bool member::operator==(const member &rhs) const {
    return id == rhs.id &&
           name == rhs.name &&
           addr_line == rhs.addr_line &&
           city == rhs.city &&
           state == rhs.state &&
           phone == rhs.phone &&
           beg_date == rhs.beg_date &&
           end_date == rhs.end_date;
}

bool member::operator!=(const member &rhs) const {
    return !(rhs == *this);
}
