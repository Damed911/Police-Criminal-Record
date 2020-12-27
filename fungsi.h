#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct catatan{	//Data Structures in C
	char id[30];
	char nama[50];
	char usia[5];
	char jenis_kelamin[20];
	char berat[20];
	char tinggi[20];
	char rambut[20];
	char mata[20];
	char kejahatan[40];
	char wajah[100];
	char hukuman[50];
	char faddress[50];
	char emergencyc[50];
	char emergencyr[50];
	char datearr[50];
	int data;
	struct catatan *next;
}a;

void tambah(){
	/*Fungsi ini digunakan untuk menambah catatan yang ada pada database. Fungsi bekerja dengan memasukkan nama dan ID.
Apabila nama atau ID sudah ada, user tidak bisa memasukkan data baru.*/	

	system("cls");
	FILE *fp ;//Pointer
    char another = 'Y' ,id[10];
    char filename[30];
    int choice;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t  - MENAMBAH CATATAN -");
    printf("\n\t\t====================================\n");

    fp = fopen ("Catatan Napi.txt", "ab+" ) ;

    if ( fp == NULL ){

        fp=fopen("filename","wb+");
        if(fp==NULL)
        {

            printf("\nSISTEM ERROR...");
            printf("\nKLIK APAPUN UNTUK KELUAR");
            getch();
            return ;

        }
    }
    
    while ( another == 'Y'|| another=='y' ){
        choice=0;
        fflush(stdin);
        
		printf ( "\n\n\tMASUKKAN ID NARAPIDANA(Untuk pengecekan apakah sama atau tidak): ");
        scanf("%s",id);
        
		rewind(fp);
		/*Apabila ID yang dimasukkan sama, program tidak akan dilanjutkan*/
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.id,id)==0)
            {

                printf("\nCATATAN SUDAH ADA.\n");
                choice=1;

            }

        }
        
        if(choice==0){
		/*Program untuk memasukkan data-data yang dibutuhkan dalam catatan*/
            strcpy(a.id,id);

            printf("\n\tMASUKKAN NAMA NARAPIDANA: ");
            fflush(stdin);
			gets(a.nama);	
            
			printf("\tMASUKKAN JENIS KELAMIN: ");
            gets(a.jenis_kelamin);
            fflush(stdin);

            printf("\tMASUKKAN USIA: ");
            gets(a.usia);
            fflush(stdin);

            printf("\tMASUKKAN BERAT: ");
            gets(a.berat);
            fflush(stdin);
            
            printf("\tMASUKKAN TINGGI (CM): ");
            gets(a.tinggi);
 			fflush(stdin);
           
            printf("\tMASUKKAN WARNA RAMBUT: ");
            gets(a.rambut);
            fflush(stdin);
            
            printf("\tMASUKKAN WARNA MATA: ");
            gets(a.mata);
            fflush(stdin);
            
            printf("\tMASUKKAN CIRI-CIRI WAJAH: ");
            gets(a.wajah);
            fflush(stdin);
			
			printf("\tMASUKKAN KEJAHATAN: ");
            gets(a.kejahatan);
            fflush(stdin);
            
            printf("\tMASUKKAN HUKUMAN: ");
            gets(a.hukuman);
            fflush(stdin);
            
            printf("\tALAMAT LENGKAP KANTOR POLISI: ");
            gets(a.faddress);
            fflush(stdin);
            
            printf("\tMASUKKAN NOMOR ID: ");
            gets(a.id);
            fflush(stdin);
            
            printf("\tMASUKKAN KONTAK DARURAT: ");
            gets(a.emergencyc);
            fflush(stdin);
            
            printf("\tMASUKKAN HUBUNGAN KONTAK DARURAT: ");
            gets(a.emergencyr);
            fflush(stdin);
            
            printf("\tMASUKKAN TANGGAL PENANGKAPAN: ");
            gets(a.datearr);
            
            fwrite ( &a, sizeof ( a ), 1, fp ) ;
            printf("\nCATATAN BERHASIL DITAMBAH...\n");
        }
        
		printf ( "\n\tAPAKAH INGIN MENAMBAH CATATAN KEMBALI...(Y/N) \t" ) ;
        fflush ( stdin ) ;
        another = getch( ) ;
	}
	fclose ( fp ) ;
    printf("\n\n\tKLIK APAPUN UNTUK KELUAR...");
    getch();
    
}

void mencari(){
	/*Fungsi ini digunakan untuk mencari data pada file. Fungsi bekerja dengan menggunakan linked list .
User memasukkan nama dari narapidana dan catatannya akan timbul.*/
	system("cls");
    FILE *fp ;
	char nama[16],choice,filename[14];
    int ch, i, j, banyak, flag=0;
    struct catatan read1, read2, *current, *temp, *head, *memori;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- MENCARI CATATAN -");
    printf("\n\t\t====================================\n\n");

	do{
	fp = fopen ( "Catatan Napi.txt", "r" ) ;
	
	if(fp==NULL){
		printf("Error untuk membuka file");
	}
	
	banyak = 0;
	j = 0;
	while(fread(&read1, sizeof(a),1,fp) >0){
		j++;
		banyak++;
	}
	fclose(fp);
	
	memori = (struct catatan*)malloc(banyak * sizeof(struct catatan));
	fp = fopen("Catatan Napi.txt", "r");
	j = 0;
	while(fread(&read2, sizeof(a),1,fp) > 0 && j < banyak){
		strcpy((memori+j)->nama, read2.nama);
		strcpy((memori+j)->jenis_kelamin, read2.jenis_kelamin);
		strcpy((memori+j)->usia, read2.usia);
		strcpy((memori+j)->berat, read2.berat);
		strcpy((memori+j)->tinggi, read2.tinggi);
		strcpy((memori+j)->rambut, read2.rambut);
		strcpy((memori+j)->mata, read2.mata);
		strcpy((memori+j)->kejahatan, read2.kejahatan);
		strcpy((memori+j)->wajah, read2.wajah);
		strcpy((memori+j)->hukuman, read2.hukuman);
		strcpy((memori+j)->faddress, read2.faddress);
		strcpy((memori+j)->id, read2.id);
		strcpy((memori+j)->emergencyc, read2.emergencyc);
		strcpy((memori+j)->emergencyr, read2.emergencyr);
		strcpy((memori+j)->datearr, read2.datearr);
		j++;
	}
	fclose(fp);
	
	/*Program untuk linked list pada searching*/
	current = (struct catatan*) malloc(sizeof(struct catatan));//Linked List
	strcpy(current->nama, (memori+0)->nama);
	strcpy(current->jenis_kelamin, (memori+0)->jenis_kelamin);
	strcpy(current->usia, (memori+0)->usia);
	strcpy(current->berat, (memori+0)->berat);
	strcpy(current->tinggi, (memori+0)->tinggi);
	strcpy(current->rambut, (memori+0)->rambut);
	strcpy(current->mata, (memori+0)->mata);
	strcpy(current->kejahatan, (memori+0)->kejahatan);
	strcpy(current->wajah, (memori+0)->wajah);
	strcpy(current->hukuman, (memori+0)->hukuman);
	strcpy(current->faddress, (memori+0)->faddress);
	strcpy(current->id, (memori+0)->id);
	strcpy(current->emergencyc, (memori+0)->emergencyc);
	strcpy(current->emergencyr, (memori+0)->emergencyr);
	strcpy(current->datearr, (memori+0)->datearr);
	current->next = NULL;
	head = current;
	
	for(i=1;i<banyak;i++){
		temp = (struct catatan*) malloc(sizeof(struct catatan));
		current->next = temp;
		strcpy(temp->nama, (memori+i)->nama);
		strcpy(temp->jenis_kelamin, (memori+i)->jenis_kelamin);
		strcpy(temp->usia, (memori+i)->usia);
		strcpy(temp->berat, (memori+i)->berat);
		strcpy(temp->tinggi, (memori+i)->tinggi);
		strcpy(temp->rambut, (memori+i)->rambut);
		strcpy(temp->mata, (memori+i)->mata);
		strcpy(temp->kejahatan, (memori+i)->kejahatan);
		strcpy(temp->wajah, (memori+i)->wajah);
		strcpy(temp->hukuman, (memori+i)->hukuman);
		strcpy(temp->faddress, (memori+i)->faddress);
		strcpy(temp->id, (memori+i)->id);
		strcpy(temp->emergencyc, (memori+i)->emergencyc);
		strcpy(temp->emergencyr, (memori+i)->emergencyr);
		strcpy(temp->datearr, (memori+i)->datearr);
		temp->next = NULL;
		current = temp;
	}
	
	current = head;    
	

	printf("\n\tMASUKKAN NAMA NARAPIDANA YANG AKAN DICARI:");//Searching
    fflush(stdin);
    gets(nama);
    
    system("cls");
    printf("\nCATATAN NARAPIDANA:");
 
        while ( current != NULL ){
		/*Apabila nama narapidana sesuai dengan yang ada pada catatan,
			data akan menjadi current*/
          if(strcmpi(current->nama, nama)==0)
               { flag = 1;
                break;
            }
            current = current->next;
        }
        if(flag==1){
        		printf("\n");
                printf("\nNAMA: %s",current->nama);
                printf("\nJENIS KELAMIN: %s",current->jenis_kelamin);
                printf("\nUSIA: %s",current->usia);
                printf("\nBERAT: %s",current->berat);
                printf("\nTINGGI: %s",current->tinggi);
                printf("\nWARNA RAMBUT: %s",current->rambut);
				printf("\nWARNA MATA: %s",current->mata);
                printf("\nKEJAHATAN: %s",current->kejahatan);
                printf("\nCIRI-CIRI WAJAH: %s",current->wajah);
                printf("\nHUKUMAN: %s",current->hukuman);
                printf("\nALAMAT KANTOR POLISI: %s",current->faddress);
                printf("\nNOMOR ID: %s",current->id);
                printf("\nKONTAK DARURAT: %s",current->emergencyc);
                printf("\nHUBUNGAN KONTAK DARURAT: %s",current->emergencyr);
                printf("\nTANGGAL DITANGKAP: %s",current->datearr);
                printf("\n");
		}
		else{
			printf("Data tidak ditemukan");
		}
        printf("\n\nAPAKAH ANDA MASIH INGIN MENCARI...(Y/N):");
        fflush(stdin);
        scanf("%c",&choice);
}while(choice=='Y'||choice=='y');
	
    fclose (fp) ;
    printf("\nKLIK APAPUN UNTUK KEMBALI KE MENU...");
	getch();
    return ;
	getch();

}

void modifikasi(){
	/*Fungsi ini digunakan untuk memodifikasi data pada file. Fungsi bekerja dengan memasukkan nama dan ID dari narapidana.
Catatan narapidana akan muncul dapat dilihat terlebih dahulu sebelum melakukan perubahan.*/
	system("cls");
    FILE *fp ;
    char id[10],choice,filename[14];
    int num,count=0;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- MODIFIKASI CATATAN -");
    printf("\n\t\t====================================\n\n");

    do
    {
    	printf("\n\tMASUKKAN NAMA NARAPIDANA YANG AKAN DIUBAH:");
    	fflush(stdin);
    	gets(filename);
    
        printf("\n\tMASUKKAN ID:");
    	gets(id);
        fp = fopen ( "Catatan Napi.txt", "rb+" ) ;

        while ( fread ( &a, sizeof ( a ), 1, fp ) == 1 )
        {
		/*Program untuk menampilkan catatan sebelumnya, apabila
		nama dan ID yang dihapuskan sama*/
            if(strcmp(a.id,id)==0)
            {
                printf("\nCATATAN SEBELUMNYA:");
                printf("\nNAMA: %s",a.nama);
                printf("\nJENIS KELAMIN: %s",a.jenis_kelamin);
                printf("\nUSIA: %s",a.usia);
                printf("\nBERAT: %s",a.berat);
                printf("\nTINGGI: %s",a.tinggi);
                printf("\nWARNA RAMBUT: %s",a.rambut);
				printf("\nWARNA MATA: %s",a.mata);
                printf("\nKEJAHATAN: %s",a.kejahatan);
                printf("\nCIRI-CIRI WAJAH: %s",a.wajah);
                printf("\nHUKUMAN: %s",a.hukuman);
                printf("\nALAMAT KANTOR POLISI: %s",a.faddress);
                printf("\nNOMOR ID: %s",a.id);
                printf("\nKONTAK DARURAT: %s",a.emergencyc);
                printf("\nHUBUNGAN KONTAK DARURAT: %s",a.emergencyr);
                printf("\nTANGGAL DITANGKAP: %s",a.datearr);
                
                /*Program yang akan menentukan apa data yang akan dimodifikasi*/
				printf("\n\n\t\tAPA YANG ANDA INGIN UBAH..");
                
                printf("\n1.NAMA.");
                printf("\n2.JENIS KELAMIN.");
                printf("\n3.USIA.");
                printf("\n4.BERAT.");
                printf("\n5.TINGGI.");
                printf("\n6.WARNA RAMBUT.");
                printf("\n7.WARNA MATA.");
                printf("\n8.KEJAHATAN.");
                printf("\n9.CIRI-CIRI WAJAH.");
                printf("\n10.HUKUMAN.");
                printf("\n11.ALAMAT KANTOR POLISI.");
                printf("\n12.NOMOR ID.");
                printf("\n13.KONTAK DARURAT.");
                printf("\n14.HUBUNGAN KONTAK DARURAT.");
                printf("\n15.TANGGAL DITANGKAP.");
                printf("\n16.KESELURUHAN CATATAN.");
                printf("\n17.KEMBALI KE MENU UTAMA.");
                
                do
                {

                    printf("\n\tMASUKKAN PILIHAN ANDA:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);
                    
                    switch(num)
                    {

                    case 1:
                        printf("\nMASUKKAN DATA YANG BARU:");
                        printf("\nNAMA:");
                        gets(a.nama);
                        break;

                    case 2:
                        printf("\nMASUKKAN DATA YANG BARU:");
                        printf("\nJENIS KELAMIN:");
                        gets(a.jenis_kelamin);
                        break;

                    case 3:
                        printf("\nMASUKKAN DATA YANG BARU:");
                        printf("\nUSIA:");
                        gets(a.usia);
                        break;

                    case 4:
                        printf("\nMASUKKAN DATA YANG BARU:");
                        printf("\nBERAT:");
                        gets(a.berat);
                        break;

                    case 5:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nTINGGI:");
                        gets(a.tinggi);
                        break;

                    case 6:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nWARNA RAMBUT:");
                        gets(a.rambut);
                        break;

                    case 7:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nWARNA MATA:");
                        gets(a.mata);
                        break;

                    case 8:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nKEJAHATAN:");
                        gets(a.kejahatan);
                        break;

                    case 9:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nCIRI-CIRI WAJAH:");
                        gets(a.wajah);
                        break;

                    case 10:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nHUKUMAN:");
                        gets(a.hukuman);
                        break;

                    case 11:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nALAMAT KANTOR POLISI:");
                        gets(a.faddress);
                        break;

                    case 12:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nNOMOR ID:");
                        gets(a.id);
                        break;

                    case 13:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nKONTAK DARURAT:");
                        gets(a.emergencyc);
                        break;

                    case 14:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nHUBUNGAN KONTAK DARURAT:");
                        gets(a.emergencyr);
                        break;

                    case 15:
                        printf("MASUKKAN DATA YANG BARU:");
                        printf("\nTANGGAL DITANGKAP:");
                        gets(a.datearr);
                        break;

                    case 16:
                    	printf("MASUKKAN DATA YANG BARU:");
                        printf("\tNAMA:");
			            gets(a.nama);		
						printf("\tJENIS KELAMIN:");
			            gets(a.jenis_kelamin);			
			            printf("\tUSIA:");
			            gets(a.usia);
			            printf("\tBERAT:");
			            gets(a.berat);
			            printf("\tTINGGI:");
			            gets(a.tinggi);
			            printf("\tWARNA RAMBUT:");
			            gets(a.rambut);
			            printf("\tWARNA MATA:");
			            gets(a.mata);
			            printf("\tKEJAHATAN:");
			            gets(a.kejahatan);
			            printf("\tCIRI-CIRI WAJAH:");
			            gets(a.wajah);
			            printf("\tHUKUMAN:");
			            gets(a.hukuman);
			            printf("\tALAMAT KANTOR POLISI:");
			            gets(a.faddress);
			            printf("\tNOMOR ID:");
			            gets(a.id);
			            printf("\tKONTAK DARURAT:");
			            gets(a.emergencyc);
			            printf("\tHUBUNGAN KONTAK DARURAT:");
			            gets(a.emergencyr);
			            printf("\tTANGGAL DITANGKAP:");
			            gets(a.datearr);
                        break;

                    case 17:
                        printf("\nKLIK APAPUN UNTUK KEMBALI KE MENU...\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\nPILIHANMU TIDAK SESUAI...COBA LAGI\n");
                        break;

                    }

                }
                while(num<1||num>20);
                	fseek(fp,sizeof(a),SEEK_CUR);

                	fwrite(&a,sizeof(a),1,fp);

                	fseek(fp,sizeof(a),SEEK_CUR);

                	fread(&a,sizeof(a),1,fp);

                	choice=5;
                break;
            }
        }

        if(choice==5){

            system("cls");

            printf("\n\t\tMODIFIKASI SELESAI...\n");
            printf("--------------------\n");
            printf("CATATAN YANG BARU ADALAH:\n");
            printf("--------------------\n");
            printf("\nNAMA: %s",a.nama);
            printf("\nJENIS KELAMIN: %s",a.jenis_kelamin);
            printf("\nUSIA: %s",a.usia);
            printf("\nBERAT: %s",a.berat);
            printf("\nTINGGI: %s",a.tinggi);
            printf("\nWARNA RAMBUT: %s",a.rambut);
			printf("\nWARNA MATA: %s",a.mata);
            printf("\nKEJAHATAN: %s",a.kejahatan);
            printf("\nCIRI-CIRI WAJAH: %s",a.wajah);
            printf("\nHUKUMAN: %s",a.hukuman);
            printf("\nALAMAT KANTOR POLISI: %s",a.faddress);
            printf("\nNOMOR ID: %s",a.id);
            printf("\nKONTAK DARURAT: %s",a.emergencyc);
            printf("\nHUBUNGAN KONTAK DARURAT: %s",a.emergencyr);
            printf("\nTANGGAL DITANGKAP: %s",a.datearr);

            fclose(fp);

            printf("\n\n\tAPAKAH ANDA INGIN MEMODIFIKASI DATA KEMBALI.(Y/N)");
            scanf("%c",&choice);
            count++;
        }
        
        else{
            printf("\nCATATAN TIDAK ADA PADA DATA::\n");
            printf("\nAPAKAH ANDA INGIN MENCOBA KEMBALI...(Y/N)");
        	scanf("%c",&choice);
        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp ) ;
    printf("\tKLIK ENTER UNTUK KELUAR MENU MODIFIKASI.");
    getch();
}

void melihat(){
	/*Fungsi ini digunakan untuk melihat catatan pada file. User dapat melakukan sorting terlebih dahulu atau langsung melihat.
Sorting dapat dilakukan berdasarkan usia dan jenis kelamin.*/
	system("cls");
    FILE *fp;
    char filename[30];
    char temp[50], temp1[50], temp2[50], temp3[50], temp4[50], temp5[50], temp6[50], temp7[50], 
	temp8[50], temp9[50], temp10[50], temp11[50], temp12[50], temp13[50], temp14[50];
    int i, j, k, banyak, choice;
    struct catatan read1, read2, *memori;
    
    printf("\n\n\t\t====================================\n");
    printf("\t\t\t - MELIHAT CATATAN -");
    printf("\n\t\t====================================\n");
    
    fp = fopen("Catatan Napi.txt", "rb");
    
    printf("\nApakah anda ingin melakukan pengurutan data? (1. Yes, 2. No)\n>>>");
    scanf("%d", &choice);
    
    switch(choice){
    	int x;
		/*Program jika memilih sorting terlebih dahulu sebelum melihat data*/
		case 1:
			if(fp==NULL){
			printf("Error untuk membuka file");
		}
		
		banyak = 0;
		j = 0;
		while(fread(&read1, sizeof(a),1,fp) >0){
			j++;
			banyak++;
		}
		fclose(fp);
	
		memori = (struct catatan*)malloc(banyak * sizeof(struct catatan));//Dynamic Memory Allocation
		fp = fopen("Catatan Napi.txt", "r");
		j = 0;
		while(fread(&read2, sizeof(a),1,fp) > 0 && j < banyak){
			strcpy((memori+j)->nama, read2.nama);
			strcpy((memori+j)->jenis_kelamin, read2.jenis_kelamin);
			strcpy((memori+j)->usia, read2.usia);
			strcpy((memori+j)->berat, read2.berat);
			strcpy((memori+j)->tinggi, read2.tinggi);
			strcpy((memori+j)->rambut, read2.rambut);
			strcpy((memori+j)->mata, read2.mata);
			strcpy((memori+j)->kejahatan, read2.kejahatan);
			strcpy((memori+j)->wajah, read2.wajah);
			strcpy((memori+j)->hukuman, read2.hukuman);
			strcpy((memori+j)->faddress, read2.faddress);
			strcpy((memori+j)->id, read2.id);
			strcpy((memori+j)->emergencyc, read2.emergencyc);
			strcpy((memori+j)->emergencyr, read2.emergencyr);
			strcpy((memori+j)->datearr, read2.datearr);
			j++;
		}
	
    		printf("\nBerdasarkan aspek apa akan diurutkan?(1. Usia, 2. Jenis Kelamin)\n>>>");
    		scanf("%d", &x);
    		if(x==1){
    			int y;
				printf("\nApakah sorting akan dilakukan secara (1) Ascending atau (2) Descending?\n>>>");
    			scanf("%d", &y);
    			/* Proses melakukan sorting baik ascennding atau descending */
				if(y==1){
    				for(i = 0;i < banyak;i++){
    					for(k=i+1;k<banyak;k++){
    						if(strcmp((memori+i)->usia, (memori+k)->usia)> 0){
    						strcpy(temp, (memori+i)->nama);
    						strcpy((memori+i)->nama, (memori+k)->nama);
    						strcpy((memori+k)->nama, temp);
    						strcpy(temp1, (memori+i)->jenis_kelamin);
    						strcpy((memori+i)->jenis_kelamin, (memori+k)->jenis_kelamin);
    						strcpy((memori+k)->jenis_kelamin, temp1);
							strcpy(temp2, (memori+i)->usia);
    						strcpy((memori+i)->usia, (memori+k)->usia);
    						strcpy((memori+k)->usia, temp2);
    						strcpy(temp3, (memori+i)->berat);
    						strcpy((memori+i)->berat, (memori+k)->berat);
    						strcpy((memori+k)->berat, temp3);
    						strcpy(temp4, (memori+i)->tinggi);
    						strcpy((memori+i)->tinggi, (memori+k)->tinggi);
    						strcpy((memori+k)->tinggi, temp4);
    						strcpy(temp5, (memori+i)->rambut);
    						strcpy((memori+i)->rambut, (memori+k)->rambut);
    						strcpy((memori+k)->rambut, temp5);
    						strcpy(temp6, (memori+i)->mata);
    						strcpy((memori+i)->mata, (memori+k)->mata);
    						strcpy((memori+k)->mata, temp6);
    						strcpy(temp7, (memori+i)->kejahatan);
    						strcpy((memori+i)->kejahatan, (memori+k)->kejahatan);
    						strcpy((memori+k)->kejahatan, temp7);
    						strcpy(temp8, (memori+i)->wajah);
    						strcpy((memori+i)->wajah, (memori+k)->wajah);
    						strcpy((memori+k)->wajah, temp8);
    						strcpy(temp9, (memori+i)->hukuman);
    						strcpy((memori+i)->hukuman, (memori+k)->hukuman);
    						strcpy((memori+k)->hukuman, temp9);
    						strcpy(temp10, (memori+i)->faddress);
    						strcpy((memori+i)->faddress, (memori+k)->faddress);
    						strcpy((memori+k)->faddress, temp10);
    						strcpy(temp11, (memori+i)->id);
    						strcpy((memori+i)->id, (memori+k)->id);
    						strcpy((memori+k)->id, temp11);
    						strcpy(temp12, (memori+i)->emergencyc);
    						strcpy((memori+i)->emergencyc, (memori+k)->emergencyc);
    						strcpy((memori+k)->emergencyc, temp12);
    						strcpy(temp13, (memori+i)->emergencyr);
    						strcpy((memori+i)->emergencyr, (memori+k)->emergencyr);
    						strcpy((memori+k)->emergencyr, temp13);
    						strcpy(temp14, (memori+i)->datearr);
    						strcpy((memori+i)->datearr, (memori+k)->datearr);
    						strcpy((memori+k)->datearr, temp14);
						}
					}
				}
			}
				else if(y==2){
					for(i = 0;i < banyak;i++){
    					for(k=i+1;k<banyak;k++){
    						if(strcmp((memori+k)->usia, (memori+i)->usia)> 0){//Sorting
    						strcpy(temp, (memori+i)->nama);
    						strcpy((memori+i)->nama, (memori+k)->nama);
    						strcpy((memori+k)->nama, temp);
    						strcpy(temp1, (memori+i)->jenis_kelamin);
    						strcpy((memori+i)->jenis_kelamin, (memori+k)->jenis_kelamin);
    						strcpy((memori+k)->jenis_kelamin, temp1);
							strcpy(temp2, (memori+i)->usia);
    						strcpy((memori+i)->usia, (memori+k)->usia);
    						strcpy((memori+k)->usia, temp2);
    						strcpy(temp3, (memori+i)->berat);
    						strcpy((memori+i)->berat, (memori+k)->berat);
    						strcpy((memori+k)->berat, temp3);
    						strcpy(temp4, (memori+i)->tinggi);
    						strcpy((memori+i)->tinggi, (memori+k)->tinggi);
    						strcpy((memori+k)->tinggi, temp4);
    						strcpy(temp5, (memori+i)->rambut);
    						strcpy((memori+i)->rambut, (memori+k)->rambut);
    						strcpy((memori+k)->rambut, temp5);
    						strcpy(temp6, (memori+i)->mata);
    						strcpy((memori+i)->mata, (memori+k)->mata);
    						strcpy((memori+k)->mata, temp6);
    						strcpy(temp7, (memori+i)->kejahatan);
    						strcpy((memori+i)->kejahatan, (memori+k)->kejahatan);
    						strcpy((memori+k)->kejahatan, temp7);
    						strcpy(temp8, (memori+i)->wajah);
    						strcpy((memori+i)->wajah, (memori+k)->wajah);
    						strcpy((memori+k)->wajah, temp8);
    						strcpy(temp9, (memori+i)->hukuman);
    						strcpy((memori+i)->hukuman, (memori+k)->hukuman);
    						strcpy((memori+k)->hukuman, temp9);
    						strcpy(temp10, (memori+i)->faddress);
    						strcpy((memori+i)->faddress, (memori+k)->faddress);
    						strcpy((memori+k)->faddress, temp10);
    						strcpy(temp11, (memori+i)->id);
    						strcpy((memori+i)->id, (memori+k)->id);
    						strcpy((memori+k)->id, temp11);
    						strcpy(temp12, (memori+i)->emergencyc);
    						strcpy((memori+i)->emergencyc, (memori+k)->emergencyc);
    						strcpy((memori+k)->emergencyc, temp12);
    						strcpy(temp13, (memori+i)->emergencyr);
    						strcpy((memori+i)->emergencyr, (memori+k)->emergencyr);
    						strcpy((memori+k)->emergencyr, temp13);
    						strcpy(temp14, (memori+i)->datearr);
    						strcpy((memori+i)->datearr, (memori+k)->datearr);
    						strcpy((memori+k)->datearr, temp14);
						}
					}
				}	
				}
			}
			if(x==2){
				int y;
				printf("\nApakah sorting akan dilakukan secara (1) Ascending atau (2) Descending?\n>>>");
    			scanf("%d", &y);
    			if(y==1){
    				for(i = 0;i < banyak;i++){
    					for(k=i+1;k<banyak;k++){
    						if(strcmp((memori+i)->jenis_kelamin, (memori+k)->jenis_kelamin) > 0){
    						strcpy(temp, (memori+i)->nama);
    						strcpy((memori+i)->nama, (memori+k)->nama);
    						strcpy((memori+k)->nama, temp);
    						strcpy(temp1, (memori+i)->jenis_kelamin);
    						strcpy((memori+i)->jenis_kelamin, (memori+k)->jenis_kelamin);
    						strcpy((memori+k)->jenis_kelamin, temp1);
							strcpy(temp2, (memori+i)->usia);
    						strcpy((memori+i)->usia, (memori+k)->usia);
    						strcpy((memori+k)->usia, temp2);
    						strcpy(temp3, (memori+i)->berat);
    						strcpy((memori+i)->berat, (memori+k)->berat);
    						strcpy((memori+k)->berat, temp3);
    						strcpy(temp4, (memori+i)->tinggi);
    						strcpy((memori+i)->tinggi, (memori+k)->tinggi);
    						strcpy((memori+k)->tinggi, temp4);
    						strcpy(temp5, (memori+i)->rambut);
    						strcpy((memori+i)->rambut, (memori+k)->rambut);
    						strcpy((memori+k)->rambut, temp5);
    						strcpy(temp6, (memori+i)->mata);
    						strcpy((memori+i)->mata, (memori+k)->mata);
    						strcpy((memori+k)->mata, temp6);
    						strcpy(temp7, (memori+i)->kejahatan);
    						strcpy((memori+i)->kejahatan, (memori+k)->kejahatan);
    						strcpy((memori+k)->kejahatan, temp7);
    						strcpy(temp8, (memori+i)->wajah);
    						strcpy((memori+i)->wajah, (memori+k)->wajah);
    						strcpy((memori+k)->wajah, temp8);
    						strcpy(temp9, (memori+i)->hukuman);
    						strcpy((memori+i)->hukuman, (memori+k)->hukuman);
    						strcpy((memori+k)->hukuman, temp9);
    						strcpy(temp10, (memori+i)->faddress);
    						strcpy((memori+i)->faddress, (memori+k)->faddress);
    						strcpy((memori+k)->faddress, temp10);
    						strcpy(temp11, (memori+i)->id);
    						strcpy((memori+i)->id, (memori+k)->id);
    						strcpy((memori+k)->id, temp11);
    						strcpy(temp12, (memori+i)->emergencyc);
    						strcpy((memori+i)->emergencyc, (memori+k)->emergencyc);
    						strcpy((memori+k)->emergencyc, temp12);
    						strcpy(temp13, (memori+i)->emergencyr);
    						strcpy((memori+i)->emergencyr, (memori+k)->emergencyr);
    						strcpy((memori+k)->emergencyr, temp13);
    						strcpy(temp14, (memori+i)->datearr);
    						strcpy((memori+i)->datearr, (memori+k)->datearr);
    						strcpy((memori+k)->datearr, temp14);
						}
					}
				}	
			}
				else if(y==2){
					for(i = 0;i < banyak;i++){
    					for(k=i+1;k<banyak;k++){
    						if(strcmp((memori+k)->jenis_kelamin, (memori+i)->jenis_kelamin) > 0){
    						strcpy(temp, (memori+i)->nama);
    						strcpy((memori+i)->nama, (memori+k)->nama);
    						strcpy((memori+k)->nama, temp);
    						strcpy(temp1, (memori+i)->jenis_kelamin);
    						strcpy((memori+i)->jenis_kelamin, (memori+k)->jenis_kelamin);
    						strcpy((memori+k)->jenis_kelamin, temp1);
							strcpy(temp2, (memori+i)->usia);
    						strcpy((memori+i)->usia, (memori+k)->usia);
    						strcpy((memori+k)->usia, temp2);
    						strcpy(temp3, (memori+i)->berat);
    						strcpy((memori+i)->berat, (memori+k)->berat);
    						strcpy((memori+k)->berat, temp3);
    						strcpy(temp4, (memori+i)->tinggi);
    						strcpy((memori+i)->tinggi, (memori+k)->tinggi);
    						strcpy((memori+k)->tinggi, temp4);
    						strcpy(temp5, (memori+i)->rambut);
    						strcpy((memori+i)->rambut, (memori+k)->rambut);
    						strcpy((memori+k)->rambut, temp5);
    						strcpy(temp6, (memori+i)->mata);
    						strcpy((memori+i)->mata, (memori+k)->mata);
    						strcpy((memori+k)->mata, temp6);
    						strcpy(temp7, (memori+i)->kejahatan);
    						strcpy((memori+i)->kejahatan, (memori+k)->kejahatan);
    						strcpy((memori+k)->kejahatan, temp7);
    						strcpy(temp8, (memori+i)->wajah);
    						strcpy((memori+i)->wajah, (memori+k)->wajah);
    						strcpy((memori+k)->wajah, temp8);
    						strcpy(temp9, (memori+i)->hukuman);
    						strcpy((memori+i)->hukuman, (memori+k)->hukuman);
    						strcpy((memori+k)->hukuman, temp9);
    						strcpy(temp10, (memori+i)->faddress);
    						strcpy((memori+i)->faddress, (memori+k)->faddress);
    						strcpy((memori+k)->faddress, temp10);
    						strcpy(temp11, (memori+i)->id);
    						strcpy((memori+i)->id, (memori+k)->id);
    						strcpy((memori+k)->id, temp11);
    						strcpy(temp12, (memori+i)->emergencyc);
    						strcpy((memori+i)->emergencyc, (memori+k)->emergencyc);
    						strcpy((memori+k)->emergencyc, temp12);
    						strcpy(temp13, (memori+i)->emergencyr);
    						strcpy((memori+i)->emergencyr, (memori+k)->emergencyr);
    						strcpy((memori+k)->emergencyr, temp13);
    						strcpy(temp14, (memori+i)->datearr);
    						strcpy((memori+i)->datearr, (memori+k)->datearr);
    						strcpy((memori+k)->datearr, temp14);
						}
					}
				}	
			}
		
			}
				for(i=0;i<banyak;i++){
				printf("\n\n\t\t::KLIK ENTER UNTUK MELIHAT CATATAN LAIN!::\n");
        		printf("\nNAMA: %s",(memori+i)->nama);
        		printf("\nJENIS KELAMIN: %s",(memori+i)->jenis_kelamin);
       	 		printf("\nUSIA: %s",(memori+i)->usia);
        		printf("\nBERAT: %s",(memori+i)->berat);
        		printf("\nTINGGI: %s",(memori+i)->tinggi);
        		printf("\nWARNA RAMBUT: %s",(memori+i)->rambut);
				printf("\nWARNA MATA: %s",(memori+i)->mata);
        		printf("\nKEJAHATAN: %s",(memori+i)->kejahatan);
        		printf("\nCIRI-CIRI WAJAH: %s",(memori+i)->wajah);
        		printf("\nHUKUMAN: %s",(memori+i)->hukuman);
        		printf("\nALAMAT KANTOR POLISI: %s",(memori+i)->faddress);
        		printf("\nNOMOR ID: %s",(memori+i)->id);
        		printf("\nKONTAK DARURAT: %s",(memori+i)->emergencyc);
        		printf("\nHUBUNGAN KONTAK DARURAT: %s",(memori+i)->emergencyr);
        		printf("\nTANGGAL PENANGKAPAN: %s",(memori+i)->datearr);
        		getch();	
        	}
        	printf("\n\nDATA SUDAH TIDAK ADA LAGI");
    		printf("\n\nKLIK APAPUN UNTUK KELUAR...");
			break;
		case 2:
			/*Program jika tidak memilih untuk melakukan sorting*/
			while((fread(&a,sizeof(a),1,fp))==1){
        	printf("\n\n\t\t::KLIK ENTER UNTUK MELIHAT CATATAN LAIN!::\n");
        	printf("\nNAMA: %s",a.nama);
        	printf("\nJENIS KELAMIN: %s",a.jenis_kelamin);
       	 	printf("\nUSIA: %s",a.usia);
        	printf("\nBERAT: %s",a.berat);
        	printf("\nTINGGI: %s",a.tinggi);
        	printf("\nWARNA RAMBUT: %s",a.rambut);
			printf("\nWARNA MATA: %s",a.mata);
        	printf("\nKEJAHATAN: %s",a.kejahatan);
        	printf("\nCIRI-CIRI WAJAH: %s",a.wajah);
        	printf("\nHUKUMAN: %s",a.hukuman);
        	printf("\nALAMAT KANTOR POLISI: %s",a.faddress);
        	printf("\nNOMOR ID: %s",a.id);
        	printf("\nKONTAK DARURAT: %s",a.emergencyc);
        	printf("\nHUBUNGAN KONTAK DARURAT: %s",a.emergencyr);
        	printf("\nTANGGAL PENANGKAPAN: %s",a.datearr);
        	getch();
    	}
    	printf("\n\nDATA SUDAH TIDAK ADA LAGI");
    	printf("\n\nKLIK APAPUN UNTUK KELUAR...");
	}
	fclose(fp);
	getch();
}
void menghapus(){
	/*Fungsi ini digunakan untuk menghapus catatan pada file.
User memasukkan nama narapidana dan data akan terhapus dari file.*/
	system("cls");
    FILE *fp,*ft ;//Pointers
    struct catatan file;
    char filename[15],another = 'Y' ,nama[30];;
    int choice,check;
    int j=0;
    char pass[20];

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- MENGHAPUS CATATAN -");
    printf("\n\t\t====================================\n\n");
    
    printf("\nMASUKKAN PASSWORD\n");
    int i;
    for(  i=0;i<8;i++)
    {
    	pass[i]=getch();
    	printf("*");
	}
	if (strcmpi(pass,"tekkom19")==0)
	{
	
     printf("\n\t\t*AKSES DITERIMA*\n\n");
   while ( another == 'Y' || another == 'y' )

    {
        fp = fopen ("Catatan Napi.txt", "rb" ) ;
        if ( fp == NULL )
                {
                    printf("\nFILE TIDAK ADA");
                    printf("\nKLIK APAPUN UNTUK KEMBALI.");
                    getch();
                    return ;
				}
				ft=fopen("temp","wb");
				
				if(ft==NULL)
                {
                	printf("\nSISTEM ERROR");
                    printf("\nKLIK APAPUN UNTUK KEMBALI");
                    getch();
                    return ;
                }
                printf("\nMASUKKAN NAMA NARAPIDANA YANG AKAN DIHAPUS:");
                fflush(stdin);
                gets(nama);

        		while(fread(&file,sizeof(file),1,fp)==1)

                {
                    if(strcmp(file.nama,nama)!=0)

                        fwrite(&file,sizeof(file),1,ft);
                }
        fclose(ft);
        fclose(fp);
        remove("Catatan Napi.txt");
        rename("temp","Catatan Napi.txt");
        printf("\nSUKSES DIHAPUS...");
        getch();

        printf("\n\tAPAKAH ANDA INGIN MENGHAPUS CATATAN YANG LAIN... .(Y/N):");
        fflush(stdin);
        scanf("%c",&another);

    }
    
    printf("\n\n\tKLIK APAPUN UNTUK KELUAR...");
    getch();
}
	else
	{/*Apabila password salah, program akan langsung selesai dan keluar*/
		printf("\nMAAF!PASSWORD SALAH\n");
		exit(0);
	}

}

void login(){
	/*Fungsi ini digunakan sebagai awalan dari program berfungsi untuk mencegah terjadinya sabotase dari catatan.
User hanya bisa memasukkan username dan password sebanyak 3 kali. Lebih dari 3 kali, program akan keluar.*/
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="damed911";
    char pass[20]="tekkom19";
    do{
	/*User harus memasukkan username : damed911 dan password : tekkom19*/
    printf("\n  ======================  LOGIN FORM  ======================  \n");
    printf(" \n                       MASUKKAN USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       MASUKKAN PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0; 
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n    LOGIN BERHASIL! SELAMAT DATANG DI SISTEM CATATAN KRIMINAL KEPOLISIAN");
	printf("\n\n\n\t\t\tKLIK APAPUN UNTUK LANJUT...");
	getch();
	break;
	}
	else
	{
		printf("\n        MAAF !!!!  LOGIN TIDAK BERHASIL");
		a++;
		
		getch();
		system("cls");
		
	}
}
	while(a<=3);
	if (a>3)
	{	/*Apabila user memasukkan password yang salah sebanyak lebih dari 4x,
		maka program akan langsung keluar dan harus mengulangnya*/
		printf("\nMAAF ANDA MEMASUKKAN USERNAME ATAU PASSWORD YANG SALAH SEBANYAK 4 KALI!!!");
		
		exit(0);
		
		}
		system("cls");
}
