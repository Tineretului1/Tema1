//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_PURCHASE_H
#define TEMA1_PURCHASE_H
#include <ostream>
#include "date.h"
class purchase
{
    int ord_id;			//Primary Key
    int product_id;		//produs
    int sup_id;			//firma producatoare
    int qty;
    date dt_ordered;
    int eta;
    char received;
    int inv;
public:
    purchase(int ordId, int productId, int supId, int qty, const date &dtOrdered, int eta, char received, int inv)
            : ord_id(ordId), product_id(productId), sup_id(supId), qty(qty), dt_ordered(dtOrdered), eta(eta),
              received(received), inv(inv) {}

    virtual ~purchase() {

    }

    friend std::ostream &operator<<(std::ostream &os, const purchase &purchases) {
        os << "ord_id: " << purchases.ord_id << " product_id: " << purchases.product_id << " sup_id: "
           << purchases.sup_id << " qty: " << purchases.qty << " dt_ordered: " << purchases.dt_ordered.day<<"."
           << purchases.dt_ordered.month <<"."<< purchases.dt_ordered.year << " eta: "
           << purchases.eta << " received: " << purchases.received << " inv: " << purchases.inv;
        return os;
    }

    void new_ord();
    void view();
    void mar_cancel();
    void mark_reciv();
};


#endif //TEMA1_PURCHASE_H
