#include <iostream>

using namespace std;
//structura pt data calendaristica
typedef struct
{
	int date;
	int month;
	int year;
}date;

class products
{
	int id;	//Primary Key, in caz ca o sa implementez si un
	//db cu produse
	string name;
	string country; //chinez, vietnamez
	int qty; //cantitate
	int price; //pret
public:
	void add(); //adaugare produs
	void update_price(); //schimbare pret
	void search(); //cautam produs in DB
	void update(); //modificam produs
	void display(); //afisam produs
};

class suppliers
{
	int id;				//Primary Key
	string name; //nume producator
	long int phn; //nr telefon producator
	string addr_line1; //adresa
	string city; //oras produc.
	string country; //tara firma produc.
public:
	void add_sup(); //nou produc.
	void remove_supplier(); //sterge produc.
	void search_id(); //cauta produc.
};

class purchases
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
	void new_ord();
	void view();
	void mar_cancel();
	void mark_reciv();
};

class employees
{
	int id;				//Primary Key
	string name;    //nume agajat
	string addr_line; //adresa angajat
	string city; //oras angajat
	long int phn; //numar telefon
	date date_of_joining; //data angajare
	long int salary; //salariu
	string mgr_status;	//manager magazin (A sau F)
public:
	void add_emp(); //adauga angajat
	void search_emp(); //cauta angajat
	void assign_mgr_stat(); //rol manager
	void display(); //afiseaza angajat
	void update_sal(); //modifica salariu
};

class members //magazin membership-only ca la Metro
{
    int id;				//Primary Key
	string name;
	string addr_line;
	string city;
	string state;
	long int phn;
	date beg_date;
	date end_date;
public:
	void add_mem(); //adauga membru
	void update(); //modifica membru
	void search_mem(); //cauta membru
};

class sales
{
	int invoice_id;
 	int member_id;
	int product_id;
	int qty;
	int amount;
	date date_s;
public:
	void add();
	void find_total_sales();
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
