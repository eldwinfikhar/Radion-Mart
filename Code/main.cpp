#include <iostream>
#include "shopping.h"

using namespace std;

int main()
{
    int choice, i, N=0, jum = 0;
    string id_cust, nama_item, show, lagi;
    adr_cust P_cust;
    adr_item P_item;
    list_cust LC;
    list_item LI;
    infotype_cust x;
    infotype_item y;

    createListCustomer(LC);
    createListItem(LI);
    menu(choice);
    while (choice!=0) {
        switch(choice) {
        case 1:
            cout << "=======================" << endl;
            cout << "Jumlah data customer : ";
            cin >> N;
            for (i=1; i<=N; i++) {
                cout << "Data customer ke-" << i << " :" << endl;
                cout << "Nama : "; cin >> x.nama;
                cout << "ID   : "; cin >> x.id;
                P_cust = createElmCustomer(x);
                insertCustomer(LC, P_cust);
            }
            cout << endl << "Input Data Customer BERHASIL!" << endl << endl;
            break;
        case 2:
            cout << "=======================" << endl;
            cout << "Jumlah data item : ";
            cin >> N;
            for (i=1; i<=N; i++) {
                cout << "Data item ke-" << i << " :" << endl;
                cout << "Nama  : "; cin >> y.nama;
                cout << "Jenis : "; cin >> y.jenis;
                cout << "Harga : "; cin >> y.harga;
                P_item = createElmItem(y);
                insertItem(LI, P_item);
            }
            cout << endl << "Input Data Item BERHASIL!" << endl << endl;
            break;
        case 3:
            buyItem(LC, LI);
            cout << "Ingin masukkan data lagi (Y/N)? ";
            cin >> lagi;
            while (lagi=="Y") {
                buyItem(LC, LI);
                cout << "Ingin masukkan data lagi (Y/N)? ";
                cin >> lagi;
            }
            cout << endl;
            break;
        case 4:
            cout << "Tampilkan Barang yang Dibeli (Y/N)? ";
            cin >> show;
            while (show!="Y" && show!="N") {
                cin >> show;
            }
            if (show=="Y") {
                showAllCustAndPurchase(LC);
            } else {
                showCustomerOnly(LC);
            }
            break;
        case 5:
            showAllItem(LI);
            break;
        case 6:
            cout << "=======================" << endl;
            cout << "ID customer yang dihapus : ";
            cin >> id_cust;
            deleteCustomer(LC, id_cust);
            cout << "=======================" << endl;
            showCustomerOnly(LC);
            cout << "Penghapusan Customer BERHASIL!" << endl << endl;
            break;
        case 7:
            cout << "=========================" << endl;
            cout << "DATA PURCHASE" << endl;
            cout << "ID customer : ";
            cin >> id_cust;
            cout << "Nama Item   : ";
            cin >> nama_item;
            cout << endl;
            deletePurchase(LC, id_cust, nama_item);
            break;
        case 8:
            cout << "=======================" << endl;
            cout << "Nama Item yang Dicari : ";
            cin >> nama_item;
            if (first(LC)!=NULL && first(LI)!=NULL) {
                searchItemPurchaser(LC, nama_item);
            } else {
                cout << "Data pembeli d/a barang KOSONG." << endl << endl;
            }
            break;
        case 9:
            cout << "=======================" << endl;
            cout << "ID customer yang dicari : ";
            cin >> id_cust;
            jum = countCustomerPurchase(LC, id_cust);
            cout << "Jumlah barang yang dibeli : " << jum << endl << endl;
            break;
        }
        menu(choice);
    }
    cout << "Anda keluar dari aplikasi." << endl;

    return 0;
}

