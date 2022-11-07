//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_EMPLOYEE_H
#define TEMA1_EMPLOYEE_H
#include <ostream>
#include <vector>
#include "date.h"

class employee
{
    int id;				//Primary Key
    std::string name;    //nume agajat
    std::string addr_line; //adresa angajat
    std::string city; //oras angajat
    long int phone; //numar telefon
    date date_of_joining; //data angajare
    long int salary; //salariu
    std::string mgr_status;	//manager magazin (A sau F)
public:
    employee(int id, const std::string &name, const std::string &addrLine, const std::string &city, long phn,
             const date &dateOfJoining, long salary, const std::string &mgrStatus) : id(id), name(name),
                                                                                     addr_line(addrLine), city(city),
                                                                                     phone(phn),
                                                                                     date_of_joining(dateOfJoining),
                                                                                     salary(salary),
                                                                                     mgr_status(mgrStatus) {}

    void setMgrStatus(const std::string &mgrStatus) {
        mgr_status = mgrStatus;
    }

    void setSalary(long salary);

    virtual ~employee() {

    }
    

    friend std::ostream &operator<<(std::ostream &os, const employee &employees) {
        os << "id: " << employees.id << " name: " << employees.name << " addr_line: " << employees.addr_line
           << " city: " << employees.city << " phone: " << employees.phone << " date_of_joining: "
           << employees.date_of_joining.day<< employees.date_of_joining.month <<"."<< employees.date_of_joining.year
           << " salary: " << employees.salary << " mgr_status: " << employees.mgr_status;
        return os;
    }

    bool operator==(const employee &rhs) const;

    bool operator!=(const employee &rhs) const;

    static void search_mem(std::vector <employee>& vector, employee angajat){
        for(long unsigned int i = 0; i<vector.size(); i++)
            if(angajat == vector[i])
                std::cout<<"exista"<<'\n';
    };    //cauta angajat
    void assign_mgr_stat(std::string status){
        setMgrStatus(status);
    }; //rol manager
    static void display(employee angajat);//afiseaza angajat
    static void add_emp(std::vector<employee> &vector, employee angajat);

    static void update_sal(employee angajat, long newSalary);


};


#endif //TEMA1_EMPLOYEE_H
