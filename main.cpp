
#include <vector>
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
    product produs(1,"rares","romania",10,100);
    purchase cumparaturi(1, 1, 1, 100, order, 20, 'Y', 3);
    supplier aprovizionare(1, "kaufland", 123456, "Strada Unirii", "Bucuresti", "Romania");
    employee angajat(1, "Rares", "Strada Unirii", "Bucuresti", 19293929, order, 3000, "A");
    angajat.display(angajat);
    member membru1(1, "Rares1", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    member membru2(1, "Rares2", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    member membru3(1, "Rares3", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    membru1.add_mem(membrii, membru1);
    membru2.add_mem(membrii, membru2);
    membru3.add_mem(membrii, membru3);
    membru2.search_mem(membrii, membru2);
    sale vanzari(1, 2, 3, 4, 5, order);
    ramen udon(1,"cico","south korea",5,300,"spicy chicken");
    udon.discount(20);
    produs.display();
    //std::cout<<udon;
    sriracha goose(2,"flying goose","thailand", 5, 15, "glass");
    matcha green(5,"aloe china","china",5,5,'A');
    tea earl(6,"earl gray","china",3,100,"black");
    noodle riced(3,"blackNOOdle","vietnam",4,15,'A');

    //std::cout << produs << std::endl;
    //std::cout << cumparaturi << std::endl;
    //std::cout << aprovizionare << std::endl;
    //std::cout << angajat << std::endl;
    //std::cout << membrii[1] << std::endl;

    return 0;
}
