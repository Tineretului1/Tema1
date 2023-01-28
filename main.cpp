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

void applyDiscount(std::vector<std::shared_ptr<product>>& produse, int index, int discount) {
    std::shared_ptr<ramen> trial = std::dynamic_pointer_cast<ramen>(produse[index]);
    if(trial){
        trial->discount(discount);
        std::cout<<*trial<<std::endl;
    }
    else
        std::cout<<"Invalid cast, cannot apply discount"<<std::endl;
}
int member::id_auto = 0;

template <typename Iter, typename T, typename Compare = std::equal_to<T>>
Iter search2(Iter first, Iter last, const T &find, Compare comp = Compare()) {
    auto it = std::find_if(first, last, [&](const T &m) { return comp(m, find); });
    if (it != last) {
        return it;
    } else {
        return last;
    }
}

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
    //produse1[2]->display();
    try {
        applyDiscount(produse1, 0, 20);
        applyDiscount(produse1, 1, 20);
    }
    catch (const myException &e){
        std::cout<<e.what()<<std::endl;
    }
    //std::cout<<*produse1[1]<<std::endl;

    productDecorator a = productDecorator(produse1[1]);
    std::cout<<a.vat(19)<<std::endl;
    std::cout<<a.pretTotal()<<std::endl;

    product vietnamese_chair = asian_products_factory::create_vietnamese_chair();
    product chinese_table = asian_products_factory::create_chinese_table();
    product japanese_table = asian_products_factory::create_japanese_table();
    product korean_chair = asian_products_factory::create_korean_chair();
    product asian_carpet = asian_products_factory::create_asian_carpet();

    std::cout << vietnamese_chair.getName() << std::endl;
    std::cout << chinese_table.getName() << std::endl;
    std::cout << japanese_table.getName() << std::endl;
    std::cout << korean_chair.getName() << std::endl;
    std::cout << asian_carpet.getName() << std::endl;

    ProductBuilder builder;
    product product2 = builder.setId(1).setName("Product 1").setCountry("USA").setQty(10).setPrice(100.0).build();
    product product3 = builder.setPrice(102.0).setQty(19).setName("Product 3").setId(5).setCountry("USA").build();
    std::cout<<product2<<std::endl;
    std::cout<<product3<<std::endl;
    purchase cumparaturi(produse1, 1, 1, 100, order, 20, 'Y', 3);
    supplier aprovizionare(*produse1[0], 1, "kaufland", 123456, "Strada Unirii", "Bucuresti", "Romania");
    employee angajat(1, "Rares", "Strada Unirii", "Bucuresti", 19293929, order, 3000, "A");
    std::cout<<angajat<<std::endl;
    angajat.setSalary(10);
    angajat.display(angajat);
    member membru1( "Rares1", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    member aux = membru1;
    member membru2( "Rares2", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    member membru3( "Rares3", "Strada Unirii", "Bucuresti", "Romania", 1234567, order, order);
    aux.add_mem(membrii, aux);
    membru1.add_mem(membrii, membru1);
    membru2.add_mem(membrii, membru2);
    membru3.add_mem(membrii, membru3);

    //membru2.search_mem(membrii, membru2);
    auto it = search2(membrii.begin(), membrii.end(), membru2);
    if (it != membrii.end()) {
        std::cout << "exista" << '\n';
    }
        std::cout<<"nu exista" << '\n';
    auto ec = search2(produse1.begin(), produse1.end(), produse1[2]);
    if (ec != produse1.end()) {
        std::cout << "exista" << '\n';
    }
    else
        std::cout<<"nu exista" << '\n';
    return 0;
}
