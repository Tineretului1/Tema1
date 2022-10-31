//
// Created by Rares on 10/26/2022.
//

#ifndef TEMA1_SALES_H
#define TEMA1_SALES_H
#include <ostream>
#include "date.h"

class sales
{
    int invoice_id;
    int member_id;
    int product_id;
    int qty;
    int amount;
    date date_s;
public:
    sales(int invoiceId, int memberId, int productId, int qty, int amount, const date &dateS) : invoice_id(invoiceId),
                                                                                                member_id(memberId),
                                                                                                product_id(productId),
                                                                                                qty(qty),
                                                                                                amount(amount),
                                                                                                date_s(dateS) {}

    virtual ~sales() {


    }


    friend std::ostream &operator<<(std::ostream &os, const sales &sales) {
        os << "invoice_id: " << sales.invoice_id << " member_id: " << sales.member_id << " product_id: "
           << sales.product_id << " qty: " << sales.qty << " amount: " << sales.amount << " date_s: " << sales.date_s.day
           <<"."<< sales.date_s.month <<"."<< sales.date_s.year;
        return os;
    }
    void add();
    void find_total_sales();
};


#endif //TEMA1_SALES_H
