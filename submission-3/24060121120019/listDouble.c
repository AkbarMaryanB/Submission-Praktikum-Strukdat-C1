/****************************************************/
/* Program   : listDouble.c                              */
/* Deskripsi : file body modul list Double              */
/* NIM/Nama  : 24060121120019/Akbar Maryan Bagaskara*/
/* Tanggal   : 27 November 2022*/                   
/*************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "listDouble.h"


bool ListEmpty(List L){
	/* Mengirim true jika list kosong */
	
	//Kamus Lokal
	
	//Algoritma
    return First(L) == Nil && Last(L) == Nil;
    //return First(L) == Nil;
}

void CreateList(List *L){
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */

//Kamus Lokal
	
//Algoritma
    First((*L)) = Nil;
    Last((*L)) = Nil;
    //First((*L)) = Nil;
}

address Alokasi(infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

//Kamus Lokal
	
//Algoritma
    address P = (address)malloc(sizeof(ElmtList));
    if(P!=Nil){
        info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

//Kamus Lokal
	
//Algoritma
    free(*P);
}

address Search(List L, infotype X){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

//Kamus Lokal
	
//Algoritma
    address P = First(L);
    while(P!=Nil){
        if(X == info(P)){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}

bool FSearch(List L, address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

//Kamus Lokal
	
//Algoritma
    address Q = First(L);
    while(Q!=Nil){
        if(Q==P){
            return true;
        }else{
            Q = next(Q);
        }
    }
    return false;
}

address SearchPrec(List L, infotype X, address *Prec){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/

//Kamus Lokal
	
//Algoritma
    address P = First(L);
    while(next(P)!=Nil){
        if(info(next(P))==X){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}

void InsVFirst(List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

//Kamus Lokal
	
//Algoritma
    address P = Alokasi(X);
    InsertFirst(&(*L),P);
}

void InsVLast(List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

//Kamus Lokal
	
//Algoritma
    address P = Alokasi(X);
    InsertLast(&(*L),P);
}

void InsVAfter(List *L, infotype Prec, infotype X){
/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */

//Kamus Lokal
	
//Algoritma
    address P = Alokasi(X);
    address Q = First((*L));
    if(ListEmpty((*L))){
        InsVFirst(&(*L),X);
    }else{
        while(info(Q)!=Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}

void DelVFirst(List *L, infotype *X){
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */

//Kamus Lokal
	
//Algoritma
    address P;
    DelFirst(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}
void DelVLast(List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */

//Kamus Lokal
	
//Algoritma
    address P;
    DelLast(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}

void DelVAfter(List *L, infotype *X, infotype Y){
/* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
/*      dan alamat elemen nilsi info Y tersebut di-dealokasi */

//Kamus Lokal
	
//Algoritma
    address P = First(*L);
    address Q;
    if(info(First(*L))==Y){
        Q = next(P);
        (*X) = info(P);
        
    }else{
        while(info(P)!=Y){
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
    }
    next(P) = next(Q);
    next(Q) = Nil;
    //prev(next(Q)) = P;
    Dealokasi(&Q);
}

void InsertFirst(List *L, address P){
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

//Kamus Lokal
	
//Algoritma
    if(!ListEmpty(*L)){
        next(P) = First(*L);
        prev(First(*L)) = P;
    }else{
        Last(*L) = P;
    }
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

//Kamus Lokal
	
//Algoritma
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}

void InsertLast(List *L, address P){
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/*** PENGHAPUSAN SEBUAH ELEMEN ***/

//Kamus Lokal
	
//Algoritma
    if(!ListEmpty(*L)){
        prev(P) = Last(*L);
        next(Last(*L)) = P;
    }else{
        First(*L) = P;
    }
    Last(*L) = P;

    // address Last;
    // if (ListEmpty(*L)){
    //     InsertFirst(L, P);
    // }
    // else{
    //     Last = First(*L);
    //     while (next(Last) != Nil)
    //     {
    //         Last = next(Last);
    //     }
    //     next(Last) = P;
    //     prev(P) = Last;
    //     next(P) = Nil;
    // }
}

void DelFirst(List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

//Kamus Lokal
	
//Algoritma
    (*P) = First(*L);
    First(*L) = next(First(*L));
    prev(First(*L)) =Nil;
}

void DelLast(List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */

//Kamus Lokal
	
//Algoritma
    *P = Last(*L);
    Last(*L) = prev(*P);
    if(Last(*L) != Nil){
        next(Last(*L)) = Nil;
    }else{
        First(*L) = Nil;
    }
    prev(*P) = Nil;

    // address Last;
    // if (!(ListEmpty(*L))){
    //     Last = First(*L);
    //     while (next(Last) != Nil)
    //     {
    //         Last = next(Last);
    //     }
    //     (*P) = Last;
    //     if (prev(*P) == Nil)
    //     {
    //         First(*L) = Nil;
    //     }
    //     else
    //     {
    //         Last = prev(*P);
    //         next(Last) = Nil;
    //     }
    // }
    
}
void DelAfter(List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */

//Kamus Lokal
	
//Algoritma
    address P = next(Prec);
    (*Pdel) = P;
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    Dealokasi(&P);
}

void DelP(List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

//Kamus Lokal
	
//Algoritma
    address P = First(*L);
    address Q;
    if(info(P)==X && next(P) == Nil){
        DelFirst(&(*L),&P);
    }else{
        while(info(next(P)) != X){
            P = next(P);
        }
        DelAfter(&(*L),&Q,P);
    }
}

void Printinfo(List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */

//Kamus Lokal
	
//Algoritma
    address P= First(L);
    if (!ListEmpty(L))
    {
        while (next(P) != Nil)
        {
            printf("%d,", info(P));
            P = next(P);
        }
        printf("%d\n", info(P));
    }
}

int NbElmt(List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/

//Kamus Lokal
	
//Algoritma
    int counter = 0;
    address P = First(L);
    while(P!=Nil){
        counter++;
        P=next(P);
    }
    return counter;
}

void AdrLast (List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/

	//Kamus Lokal
	
	//Algoritma
	*Prec = Nil; // Mencari last dan preclast
	*Last = First(*L);
	while(next(*Last)!=Nil){
		*Prec = *Last;
		*Last = next(*Last);
	}
}

void DelAll(List *L){
/* Delete semua elemen list dan alamat elemen di-dealokasi */
//Kamus Lokal
    address P;
    
//Algoritma
    P = First(*L);
    while(next(P) != Nil){
        P = next(P);
        Dealokasi(&prev(P));
    }
    Dealokasi(&P);
    First(*L) = Nil;
    Last(*L) = Nil;
}

void InversList (List *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

//Kamus Lokal
	address P,Q,N;
	
//Algoritma
	P = next(First(*L));
	Q = Nil;
	N = First(*L);
	while(next(P)!=Nil){
        Q = prev(P);
        N = next(P);
        next(P) = Q;
        prev(Q) = P;
        P = N;
	}
    Q = prev(P);
    next(P) = Q;
    prev(Q) = P;
	Last(*L) = First(*L);
	First(*L) = P;
	next(Last(*L)) = Nil;
	prev(P) = Nil;
}

List FInversList(List L){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

    //Kamus Lokal
    List newL;
    address P, newP;
    
    //Algoritma
    CreateList(&newL);
    P = First(L);
    newP = Alokasi(info(P));

    if (newP != Nil)
    {
        InsertFirst(&newL, newP);
    }
    else
    {
        return newL;
    }

    P = next(P);

    while (P != Nil)
    {
        newP = Alokasi(info(P));
        if (newP != Nil)
        {
            InsertFirst(&newL, newP);
        }
        else
        {
            DelAll(&newL);
            break;
        }
        P = next(P);
    }
    return newL;
}

void CopyList(List *L1, List *L2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

    //Kamus Lokal

    //Algoritma
    First(*L2) = First(*L1);
}

List FCopyList(List L){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */	

    //Kamus Lokal
    List newC;
    address P,newP;
    
    //Algoritma
    CreateList(&newC);
    P = First(L);

    newP = Alokasi(info(P));

    if (newP != Nil)
    {
        InsertFirst(&newC, newP);
    }
    else
    {
        return newC;
    }

    P = next(P);

    while (P != Nil)
    {
        newP = Alokasi(info(P));
        if (newP != Nil)
        {
            InsertLast(&newC, newP);
        }
        else
        {
            DelAll(&newC);
            break;
        }
        P = next(P);
    }
    return newC;
}

void CpAlokList(List Lin, List *Lout){
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

    //Kamus Lokal
    List L;
    //Algoritma
    L = FCopyList(Lin);
    (*Lout) = L;
}

void Konkat(List L1, List L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang baru */
/* Elemen L3 adalah hasil alokasi elemen yang baru */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */

	/* Kamus Lokal */
	address P, Q;
	
	/* Algoritma */
	CreateList(L3);
	P = First(L1);
	while (P!=Nil){
		Q = Alokasi(info(P));
		if (Q!=Nil){
			InsertLast(L3,Q);
			P = next(P);
		}else{
			DelAll(L3);
			P = Nil;
		}
	}
	P = First(L2);
	while (P!=Nil){
		Q = Alokasi(info(P));
		if (Q!=Nil){
			InsertLast(L3,Q);
			P = next(P);
		}else{
			DelAll(L3);
			P = Nil;
		}
	}
}

void Konkat1(List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

	/* Kamus Lokal */
	address Prec, Last;
	
	/* Algoritma */
	CreateList(L3);
	if (First(*L1)==Nil){
		First(*L3) = First(*L2);
		First(*L2) = Nil;
	}
	else{
		First(*L3) = First(*L1);
		AdrLast(L1, &Prec, &Last);
		next(Last) = First(*L2);
		First(*L1) = Nil;
		First(*L2) = Nil;
	}
}

void PecahList (List *L1, List *L2, List L){
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */

	/* Kamus Lokal */
	address P,E,Prec1,Last1;
	int i, batas;
	
	/* Algoritma */
	CreateList(L1);
	CreateList(L2);
	P = First(L);
	i = 1;
	batas = NbElmt(L)/2;
	if(!ListEmpty(L)){
        while(P != Nil){
            E = Alokasi(info(P));
			if (i<=batas){
				if (E!=Nil){
					InsertLast(L1,E);
				}else{
					DelAll(L1);
				}
			}
			else{
				if (E!=Nil){
					InsertLast(L2,E);
				}else{
					DelAll(L2);
				}
			}
			P = next(P);
			i++;
        }
	}
}
