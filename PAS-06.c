#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "fungsi.h"

/*Mohon untuk membaca readme.txt terlebih dahulu 
untuk mengatahui username dan password program*/
int main(){
	system("color 6");
	
	login();
	
	int x;
    
    while(1){
    
	printf("\n\n\t=================================\n");
    printf("\t   -CATATAN KRIMINAL KEPOLISIAN-\n");
    printf("\t=================================");
	
    printf("\n\n\t\t::MENU UTAMA::");
    printf("\n\n\t\tMENAMBAH CATATAN\t[1]");
    printf("\n\t\tMENCARI CATATAN\t\t[2]");
    printf("\n\t\tMODIFIKASI CATATAN\t[3]");
    printf("\n\t\tDAFTAR CATATAN\t\t[4]");
	printf("\n\t\tMENGHAPUS CATATAN\t[5]");
    printf("\n\t\tKELUAR\t\t\t[6]");
	printf("\n\n\t=> MASUKAN PILIHAN ANDA:");
	
	scanf("%d", &x);
	
	/*Program untuk memilih menu apa yang akan dipilih*/
	switch(x){
		case 1:
            tambah();
            break;

        case 2:
            mencari();
            break;

        case 3:
            modifikasi();
            break;

        case 4:
            melihat();
            break;
            
        case 5:
            menghapus();
            break;

        case 6:
        	system("cls");
            printf("\n\n\t\tSAMPAI BERTEMU DI LAIN HARI :)");
            exit(0);

        default:
            printf("\nPILIHAN TIDAK ADA.");
            printf("\nKLIK APAPUN UNTUK MENCOBA KEMBALI!");
            getch();
            break;

        }
        system("cls");
    }
    return 0;
}
