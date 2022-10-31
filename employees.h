//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_EMPLOYEES_H
#define TEMA1_EMPLOYEES_H
#include <ostream>
#include "date.h"

class employees
{
    int id;				//Primary Key
    std::string name;    //nume agajat
    std::string addr_line; //adresa angajat
    std::string city; //oras angajat
    long int phn; //numar telefon
    date date_of_joining; //data angajare
    long int salary; //salariu
    std::string mgr_status;	//manager magazin (A sau F)
public:
    employees(int id, const std::string &name, const std::string &addrLine, const std::string &city, long phn,
              const date &dateOfJoining, long salary, const std::string &mgrStatus) : id(id), name(name),
                                                                                 addr_line(addrLine), city(city),
                                                                                 phn(phn),
                                                                                 date_of_joining(dateOfJoining),
                                                                                 salary(salary),
                                                                                 mgr_status(mgrStatus) {}

    virtual ~employees() {

    }
    

    friend std::ostream &operator<<(std::ostream &os, const employees &employees) {
        os << "id: " << employees.id << " name: " << employees.name << " addr_line: " << employees.addr_line
           << " city: " << employees.city << " phn: " << employees.phn << " date_of_joining: "
           << employees.date_of_joining.day<< employees.date_of_joining.month <<"."<< employees.date_of_joining.year
           << " salary: " << employees.salary << " mgr_status: " << employees.mgr_status;
        return os;
    }

    void add_emp(); //adauga angajat
    void search_emp(); //cauta angajat
    void assign_mgr_stat(); //rol manager
    void display(); //afiseaza angajat
    void update_sal(); //modifica salariu
};


#endif //TEMA1_EMPLOYEES_H
