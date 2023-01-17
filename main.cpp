#include <vector>
#include <memory>
#include "product.h"
#include "supplier.h"
#include "purchase.h"
#include "employee.h"
#include "date.h"
#include "member.h"
#include "sale.h"
#include "ramen.h"
#include "sriracha.h"
#include "matcha.h"
#include "tea.h"
#include "noodle.h"


int main() {
    date order{};
    order.day = 10;
    order.month = 10;
    order.year = 2010;

    std::vector <member> membrii;

    std::vector <std::shared_ptr<product>> produse1;
    int qty=100, price=5;
    std::string name="moji",country="china";
    produse1.emplace_back(std::make_shared<ramen>(1,name,country,qty,price,"gaina"));
    produse1.emplace_back(std::make_shared<matcha>(1,name,country,qty,price,'a'));
    produse1.emplace_back(std::make_shared<tea>(1,name,country,qty,price,"green"));
    produse1.emplace_back(std::make_shared<noodle>(1,name,country,qty,price,'y'));
    produse1.emplace_back(std::make_shared<sriracha>(1,name,country,100,10,"plastic"));
    produse1[2]->display();
    std::cout<<*std::dynamic_pointer_cast<noodle>(produse1[3])<<std::endl;

    purchase cumparaturi(produse1, 1, 1, 100, order, 20, 'Y', 3);
    supplier aprovizionare(*produse1[0], 1, "kaufland", 123456, "Strada Unirii", "Bucuresti", "Romania");
    employee angajat(1, "Rares", "Strada Unirii", "Bucuresti", 19293929, order, 3000, "A");
    std::cout<<angajat<<std::endl;
    angajat.display(angajat);
    member membru1(1, "Rares1", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    member aux = membru1;
    member membru2(1, "Rares2", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    member membru3(1, "Rares3", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    aux.add_mem(membrii, aux);
    membru1.add_mem(membrii, membru1);
    membru2.add_mem(membrii, membru2);
    membru3.add_mem(membrii, membru3);
    membru2.search_mem(membrii, membru2);
    try{
        produse1[1]->discount(30);
    }
    catch (...){
        std::cout<<"nu a mers";
    }

    return 0;
}
