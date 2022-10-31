#include <iostream>
#include "product.h"
#include "suppliers.h"
#include "purchases.h"
#include "employees.h"
#include "date.h"
#include "members.h"
#include "sales.h"

int main() {
    date order;
    order.day = 10;
    order.month = 10;
    order.year = 2010;

    product produs(1,"rares","romania",10,100);
    purchases cumparaturi(1, 1, 1, 100, order, 20, 'Y', 3);
    suppliers aprovizionare(1, "kaufland", 123456, "Strada Unirii", "Bucuresti", "Romania");
    employees angajat(1, "Rares","Strada Unirii", "Bucuresti", 19293929, order, 3000, "A");
    members membrii(1, "Rares", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    sales vanzari(1, 2, 3, 4, 5, order);

    std::cout << produs << std::endl;
    std::cout << cumparaturi << std::endl;
    std::cout << aprovizionare << std::endl;
    std::cout << angajat << std::endl;
    std::cout << membrii << std::endl;

    return 0;
}
