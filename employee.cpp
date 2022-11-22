//
// Created by Rares on 10/26/2022.
//

#include <iostream>
#include "employee.h"
void employee::setSalary(long x) {
    employee::salary = x;
}
//void employee::add_emp(std::vector<employee>& vector, employee angajat) {
//    vector.push_back(angajat);
//}

//void employee::update_sal(employee angajat, long int newSalary) {
//    angajat.setSalary(newSalary);
//}
void employee::display(const employee angajat) {
    std::cout << angajat << '\n';
}

bool employee::operator==(const employee &rhs) const {
    return id == rhs.id &&
           name == rhs.name &&
           addr_line == rhs.addr_line &&
           city == rhs.city &&
           phone == rhs.phone &&
           date_of_joining == rhs.date_of_joining &&
           salary == rhs.salary &&
           mgr_status == rhs.mgr_status;
}

bool employee::operator!=(const employee &rhs) const {
    return !(rhs == *this);
}
