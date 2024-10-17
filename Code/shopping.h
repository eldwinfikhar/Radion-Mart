#ifndef SHOPPING_H_INCLUDED
#define SHOPPING_H_INCLUDED
#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define nextItem(P) P->nextItem
#define nextRelation(P) P->nextRelation
#define item(P) P->item
#define first(L) L.first
using namespace std;

struct infotype_item {
    string nama, jenis;
    int harga;
};

struct infotype_cust {
    string nama, id;
    int pembelian;
};

typedef struct elm_item *adr_item;
typedef struct elm_relation *adr_relation;
typedef struct elm_cust *adr_cust;

struct elm_item {
    infotype_item info;
    adr_item nextItem;
};
struct list_item {
    adr_item first;
};

struct elm_relation {
    adr_item purchase;
    adr_relation nextRelation;
};
struct relation_list {
    adr_relation first;
};

struct elm_cust {
    infotype_cust info;
    adr_cust next;
    relation_list item;
};
struct list_cust {
    adr_cust first;
};

void createListCustomer(list_cust &LC);
void createListItem(list_item &LI);
adr_cust createElmCustomer(infotype_cust x);
adr_item createElmItem(infotype_item x);
adr_relation createElmRelation();

//NOMOR 1
void insertCustomer(list_cust &LC, adr_cust P);

//NOMOR 2
void showCustomerOnly(list_cust LC);
void showAllItem(list_item LI);

//NOMOR 3
void deleteFirstCustomer(list_cust &LC, adr_cust &P);
void deleteLastCustomer(list_cust &LC, adr_cust &P);
void deleteAfterCustomer(list_cust &LC, adr_cust prec, adr_cust &P);
void deleteCustomer(list_cust &LC, string ID);

//NOMOR 4 dan 5
adr_cust searchCustomer(list_cust LC, string ID);
adr_item searchItem(list_item LI, string namaItem);
adr_relation searchRelation(adr_cust P, string namaItem);

//NOMOR 6
void insertItem(list_item &LI, adr_item P);

//NOMOR 7
void buyItem(list_cust &LC, list_item LI);  //belum
void insertPurchase(adr_cust P, adr_relation R);

//NOMOR 8
void showAllCustAndPurchase(list_cust LC);

//NOMOR 9
void searchItemPurchaser(list_cust LC, string namaItem);

//NOMOR 10
void deleteFirstPurchase(adr_cust &P1);
void deleteLastPurchase(adr_cust &P1);
void deleteAfterPurchase(adr_cust &P1, adr_relation R);
void deletePurchase(list_cust &LC, string ID, string namaItem);

//NOMOR 11
int countCustomerPurchase(list_cust LC, string ID);

void menu(int &choice);

#endif // SHOPPING_H_INCLUDED
