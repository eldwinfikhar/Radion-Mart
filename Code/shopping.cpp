//#include <iostream>
#include "shopping.h"

void createListCustomer(list_cust &LC) {
    first(LC) = NULL;
}
void createListItem(list_item &LI) {
    first(LI) = NULL;
}
adr_cust createElmCustomer(infotype_cust x) {
    adr_cust P = new elm_cust;
    info(P) = x;
    info(P).pembelian = 0;
    item(P).first = NULL;
    next(P) = NULL;
    return P;
}
adr_item createElmItem(infotype_item x) {
    adr_item P = new elm_item;
    info(P) = x;
    nextItem(P) = NULL;
    return P;
}
adr_relation createElmRelation() {
    adr_relation P = new elm_relation;
    P->purchase = NULL;
    nextRelation(P) = NULL;
    return P;
}


//NOMOR 1
void insertCustomer(list_cust &LC, adr_cust P) {
/* I.S. Terdefinisi sebuah list LC yang mungkin kosong dan adr_cust P yang tidak kosong.
F.S. isi pointer P sudah berada di akhir list LC */
    if (first(LC) == NULL){
        first(LC) = P;
    } else {
        adr_cust Q = first(LC);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

//NOMOR 2
void showCustomerOnly(list_cust LC) {
/* I.S. Terdefinisi sebuah list LC yang mungkin kosong.
F.S. Jika list LC kosong, akan ditampilkan string “Data pembeli KOSONG.” Jika LC
     tidak kosong, akan ditampilkan semua data pembelian yang ada di list. */
    int i=1;
    if (first(LC)==NULL) {
        cout << "Data pembeli KOSONG." << endl;
    } else {
        adr_cust P = first(LC);
        cout << "=== Data Pembelian ===" << endl;
        while (P != NULL) {
            cout << "Pembelian ke-" << i << endl;
            cout << "ID    : " << info(P).id << endl;
            cout << "Nama  : " << info(P).nama << endl;
            cout << "=======================" << endl;
            i++;
            P = next(P);
        }
    }
    cout << endl;
}
void showAllItem(list_item LI) {
/* I.S. Terdefinisi sebuah list LI yang mungkin kosong.
F.S. Jika list LI kosong, akan ditampilkan string “Data barang KOSONG.” Jika LI
     tidak kosong, akan ditampilkan semua data barang yang ada di list. */
    if (first(LI) == NULL) {
        cout << "Data barang KOSONG." << endl;
    } else {
        adr_item P = first(LI);
        cout << "===== Data Barang =====" << endl;
        int i = 1;
        while (P != NULL) {
            cout << "Barang ke-" << i << endl;
            cout << "Nama  : " << info(P).nama << endl;
            cout << "Jenis : " << info(P).jenis << endl;
            cout << "Harga : " << info(P).harga << endl;
            cout << "=======================" << endl;
            i++;
            P = nextItem(P);
        }
    }
    cout << endl;
}

//NOMOR 3
void deleteFirstCustomer(list_cust &LC, adr_cust &P) {
/* I.S. Terdefinisi sebuah list LC yang mungkin kosong.
F.S. Jika list LC memiliki satu elemen, maka LC menjadi list kosong. Jika LC
     memiliki lebih dari satu elemen, maka elemen pertama dihapus dari LC. */
    P = first(LC);
    if (next(P)==NULL) {
        first(LC) = NULL;
    } else {
        first(LC) = next(P);
        next(P) = NULL;
    }
}
void deleteLastCustomer(list_cust &LC, adr_cust &P) {
/* I.S. Terdefinisi sebuah list LC yang mungkin kosong.
F.S. Jika list LC memiliki satu elemen, maka LC menjadi list kosong. Jika LC
     memiliki lebih dari satu elemen, maka elemen terakhir dihapus dari LC. */
    if (next(first(LC)) == NULL) {
        P = first(LC);
        first(LC) = NULL;
    } else {
        adr_cust Q = first(LC);
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}
void deleteAfterCustomer(list_cust &LC, adr_cust prec, adr_cust &P) {
/* I.S. Terdefinisi sebuah list LC yang berisi lebih dari 1 elemen kosong.
F.S. Elemen setelah prec akan dihapus dari LC. */
    P = next(prec);
    next(prec) = next(P);
    next(P) = NULL;
}
void deleteCustomer(list_cust &LC, string ID) {
/* I.S. Terdefinisi sebuah list LC yang mungkin kosong dan string ID.
F.S. Jika elemen ID yang diberikan ditemukan pada LC, maka elemen tersebut
     dihapus dari LC. Sebaliknya, tidak akan ada perubahan pada LC*/
    if (first(LC)==NULL) {
        cout << "Penghapusan GAGAL." << endl << endl;
    } else {
        adr_cust Q = searchCustomer(LC, ID);
        adr_cust P, prec;
        adr_relation R = item(Q).first;
        while (R!=NULL) {
            deleteFirstPurchase(Q);
            R = item(Q).first;
        }
        if (Q!=NULL) {
            if (Q == first(LC)) {
                deleteFirstCustomer(LC, P);
            } else if (next(Q) ==  NULL) {
                deleteLastCustomer(LC, P);
            } else {
                prec = first(LC);
                while (next(prec)!=Q) {
                    prec = next(prec);
                }
                deleteAfterCustomer(LC, prec, Q);
            }
        }
    }
}

//NOMOR 4
adr_cust searchCustomer(list_cust LC, string ID) {
/* I.S. Terdefinisi sebuah list LC yang mungkin kosong dan string ID.
F.S. Mengembalikan adr_cust yang menunjuk ke elemen pertama pada LC yang memiliki
     info(P).id sama dengan ID. Jika tidak ditemukan, mengembalikan NULL.*/
    adr_cust P = first(LC);
    while (P != NULL && info(P).id != ID) {
        P = next(P);
    }
    return P;
}
adr_item searchItem(list_item LI, string namaItem) {
/* I.S. Terdefinisi sebuah list LI yang mungkin kosong dan string namaItem.
F.S. Mengembalikan adr_item yang menunjuk ke elemen pertama pada LI yang memiliki
     info(P).nama sama dengan namaItem. Jika tidak ditemukan, mengembalikan NULL.*/
    adr_item P = first(LI);
    while (P != NULL && info(P).nama != namaItem) {
        P = nextItem(P);
    }
    return P;
}

//NOMOR 5
adr_relation searchRelation(adr_cust P, string namaItem) {
    adr_relation R = item(P).first;
    while (R != NULL && R->purchase->info.nama != namaItem) {
        R = nextRelation(R);
    }
    return R;
}

//NOMOR 6
void insertItem(list_item &LI, adr_item P){
    if (first(LI) == NULL){
        first(LI) = P;
    } else {
        adr_item Q = first(LI);
        while (nextItem(Q) != NULL) {
            Q = nextItem(Q);
        }
        nextItem(Q) = P;
    }
}

//NOMOR 7
void buyItem(list_cust &LC, list_item LI) {
    int N, i;
    string id;
    adr_cust P;
    adr_item Q;
    adr_relation R;
    infotype_item x;
    cout << "=======================" << endl;
    cout << "ID customer : "; cin >> id;
    cout << "=======================" << endl;
    P = searchCustomer(LC, id);
    cout << "Jumlah pembelian : "; cin >> N;
    for (i=1; i<=N; i++) {
        cout << "Pembelian ke-" << i << endl;
        cout << "Nama  : "; cin >> x.nama;
        Q = searchItem(LI, x.nama);
        if (Q!=NULL) {
            R = createElmRelation();
            insertPurchase(P, R);
            R->purchase = Q;
            info(P).pembelian += info(Q).harga;
        }
    }
    cout << endl;
}
void insertPurchase(adr_cust P, adr_relation R) {
    if ((item(P).first) == NULL){
        item(P).first = R;
    } else {
        adr_relation temp = item(P).first;
        while (nextRelation(temp) != NULL) {
            temp = nextRelation(temp);
        }
        nextRelation(temp) = R;
    }
}

//NOMOR 8
void showAllCustAndPurchase(list_cust LC) {
    int i=1;
    adr_cust P;
    adr_relation R;
    P = first(LC);
    while (P!=NULL) {
        cout << "==== Pembelian Ke-" << i << " ====" << endl;
        cout << "ID    : " << info(P).id << endl;
        cout << "Nama  : " << info(P).nama << endl;
        cout << "Total : " << info(P).pembelian << endl;
        i++;
        R = item(P).first;
        cout << "== Barang yang Dibeli ==" << endl;
        if (R==NULL) {
            cout << "     [DATA KOSONG]" << endl;
        }
        int j = 1;
        while (R!=NULL) {
            cout << "[" << j << "] ";
            cout << R->purchase->info.nama << " ";
            cout << R->purchase->info.jenis << " ";
            cout << R->purchase->info.harga << endl;
            R = nextRelation(R);
            j++;
        }
        cout << endl;
        P = next(P);
    }
    cout << endl;
}

//NOMOR 9
void searchItemPurchaser(list_cust LC, string namaItem) {
    int i=1;
    adr_cust P = first(LC);
    adr_relation R = NULL;
    cout << "=======================" << endl;
    cout << "Data Pembeli '" << namaItem << "'" <<  endl;

    while (P!=NULL) {
        R = searchRelation(P, namaItem);
        if (R!=NULL) {
            cout << "[" << i << "] (ID: " << info(P).id;
            cout << ") " << info(P).nama << endl;
            i++;
        }
        P = next(P);
    }

    cout << "=======================" << endl << endl;
}


//NOMOR 10
void deleteFirstPurchase(adr_cust &P1) {
    adr_relation P2;
    P2 = item(P1).first;
    if (P2!=NULL) {
        P2->purchase = NULL;
        if (nextRelation(P2)==NULL) {
            item(P1).first = NULL;
        } else {
            item(P1).first = nextRelation(P2);
            nextRelation(P2) = NULL;
        }
    }
}
void deleteLastPurchase(adr_cust &P1) {
    adr_relation P2;
    P2 = item(P1).first;
    if (P2!=NULL) {
        if (nextRelation(P2)==NULL) {
            P2->purchase = NULL;
            item(P1).first = NULL;
        } else {
            while (nextRelation(nextRelation(P2))!=NULL) {
                P2 = nextRelation(P2);
            }
            nextRelation(P2)->purchase = NULL;
            nextRelation(P2) = NULL;
        }
    }
}
void deleteAfterPurchase(adr_cust &P1, adr_relation R) {
    adr_relation prec;
    prec = item(P1).first;
    while (nextRelation(prec)!=R) {
        prec = nextRelation(prec);
    }
    R->purchase = NULL;
    nextRelation(prec) = nextRelation(R);
    nextRelation(R) = NULL;
}
void deletePurchase(list_cust &LC, string ID, string namaItem) {
    adr_cust P = searchCustomer(LC, ID);
    adr_relation R = searchRelation(P, namaItem);
    if (P!=NULL && R!=NULL) {
        info(P).pembelian -= R->purchase->info.harga;
        if (R==item(P).first) {
            deleteFirstPurchase(P);
        } else if (nextRelation(R)==NULL) {
            deleteLastPurchase(P);
        } else {
            deleteAfterPurchase(P, R);
        }
        cout << "===== Data Terbaru =====" << endl;
        cout << "ID    : " << info(P).id << endl;
        cout << "Nama  : " << info(P).nama << endl;
        cout << "Total : " << info(P).pembelian << endl << endl;
        cout << "=== Barang yg Dibeli ===" << endl;
        R = item(P).first;
        int j=1;
        while (R!=NULL) {
            cout << "[" << j << "] ";
            cout << R->purchase->info.nama << endl;
            R = nextRelation(R);
            j++;
        }
        cout << "=======================" << endl;
        cout << "Penghapusan Purchase BERHASIL!" << endl << endl;
    } else {
        cout << "Penghapusan Purchase GAGAL!" << endl << endl;
    }
}

//NOMOR 11
int countCustomerPurchase(list_cust LC, string ID) {
    adr_cust P = searchCustomer(LC, ID);
    adr_relation R = item(P).first;
    int jum = 0;
    if (P!=NULL) {
        while (R != NULL) {
            jum++;
            R = nextRelation(R);
        }
        return jum;
    }
}

void menu(int &choice) {
    cout << "===== RADION MART =====" << endl;
    cout << "1. Insert Customer" << endl;
    cout << "2. Insert Item" << endl;
    cout << "3. Insert Purchase" << endl;
    cout << "4. Show All Customer" << endl;
    cout << "5. Show All Item" << endl;
    cout << "6. Delete Customer" << endl;
    cout << "7. Delete 1 Purchase" << endl;
    cout << "8. Search Item Buyer" << endl;
    cout << "9. Count Purchase" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan (0-9) : ";
    cin >> choice;
    while (choice<=0 && choice >=9) {
        cin >> choice;
    }
    cout << endl;
}
