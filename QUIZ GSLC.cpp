#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

FILE *fp;
int count=0;

struct Karyawan{
	char nama[100];
	char notelp[13];
	int tldd, tlmm, tlyyyy;
	char nosim[14];
}SKB[1000];

void menu(){
	for(int i=0;i<25;i++)printf("\n");
	printf(" _  ___     _   _       _         _            _   _       _    _   _        _   _   _   \n");
	printf("|_|  |     |_  |_ |\\/| |_] | |   |_| |\\ |  |/ |_| |_| \\ / |_|  |_] |_| |\\ | | _ |_  |_| \n");
	printf("|    | []   _| |_ |  | |_] | |__ | | | \\|  |\\ | | | \\  |  | |  |_] | | | \\| |_|  _| | | \n\n");
	printf("Menu :\n");
	printf("1. Registrasi\n");
	printf("2. Update Data\n");
	printf("3. Delete Data\n");
	printf("4. View Data\n");
	printf("5. Exit\n");
	printf("Masukkan Pilihan Anda: ");
}

void reg(){
	int cek = 0;
	char nama[100];
	char notelp[13];
	int tldd, tlmm, tlyyyy;
	char nosim[14];
	
	do{
		printf("Input Nama [Alphabet >5]\t\t\t\t: ");
		scanf("%[^\n]",&nama);
		fflush(stdin);
		if(strlen(nama) < 5){
			cek = 0;
		}
		else {
			for(int i = 0; i < strlen(nama);i++){
				if(nama[i] >= 'A' && nama[i] <= 'Z' || nama[i] == ' ' || nama[i] >= 'a' && nama[i] <= 'z'){   
					cek = 1;
				}
				else{
					cek=0;
					break;
				}
			}
		}
	}while(cek == 0);
	cek = 0;
	
	do{
		printf("Input Nomor Telepon [10...12 Digit]\t\t\t: ");
		scanf("%s",&notelp);
		fflush(stdin);
		if(strlen(notelp) < 10 || strlen(notelp) > 12){
			cek = 0;
		}
		else if(strlen(notelp) >= 10 && strlen(notelp) <= 12){
			for(int i = 0; i < strlen(notelp);i++){
				if(notelp[i] >= '0' && notelp[i] <= '9'){
					cek = 1;
				}
				else{
					cek = 0; break;
				}
			}
		}
	}while(cek == 0);
	cek = 0;
	
	do{
		printf("Input Tanggal Lahir [dd-mm-yyyy]\t\t\t: ");
		scanf("%d-%d-%d",&tldd, &tlmm, &tlyyyy);
		fflush(stdin);
		if(tlyyyy % 100 == 0 || tlyyyy % 4 != 0 || tlyyyy % 400 != 0)
			//bukan tahun kabisat
			if(tlmm == 1 || tlmm == 3 || tlmm == 5 || tlmm == 7 || tlmm == 8 || tlmm == 10 || tlmm == 12){
				if(tldd >=1 && tldd<=31){
					cek=1;
				}
				else{
					cek=0;
				}
			}
			else if(tlmm == 2){
				if(tldd >=1 && tldd<=28){
					cek=1;
				}
				else{
					cek=0;
				}
			}
			else if(tlmm == 4 || tlmm == 6 || tlmm == 9 || tlmm ==11){
				if(tldd >=1 && tldd<=30){
					cek=1;
				}
				else{
					cek=0;
				}
			}
		else if(tlyyyy%4==0 || tlyyyy%400==0){
			//tahun kabisat
			if(tlmm == 1 || tlmm == 3 || tlmm == 5 || tlmm == 7 || tlmm == 8 || tlmm == 10 || tlmm == 12){
				if(tldd >=1 && tldd<=31){
					cek=1;
				}
				else{
					cek=0;
				}
			}
			else if(tlmm == 2){
				if(tldd >=1 && tldd<=29){
					cek=1;
				}
				else{
					cek=0;
				}
			}
			else if(tlmm == 4 || tlmm == 6 || tlmm == 9 || tlmm ==11){
				if(tldd >=1 && tldd<=30){
					cek=1;
				}
				else{
					cek=0;
				}
			}
		}
	}while(cek == 0);
	cek=0;
	
	do{
		printf("Input Nomor SIM(Surat Izin Mengemudi) [12...13 Digit]\t: ");
		scanf("%s",&nosim);
		fflush(stdin);
		if(strlen(nosim) < 12 || strlen(notelp) > 13){
			cek = 0;
		}
		else if(strlen(notelp) >= 10 && strlen(notelp) <= 12){
			for(int i = 0; i < strlen(notelp);i++){
				if(notelp[i] >= '0' && notelp[i] <= '9'){
					cek = 1;
				}
				else{
					cek = 0; break;
				}
			}
		}
	}while(cek == 0);
	cek = 0;
	
	strcpy(SKB[count].nama,nama);
	strcpy(SKB[count].notelp,notelp);
	SKB[count].tldd = tldd;
	SKB[count].tlmm = tlmm;
	SKB[count].tlyyyy = tlyyyy;
	strcpy(SKB[count].nosim,nosim);
	count++;
	printf("Data Berhasil Dimasukan\n");
	getchar();
}

int search(char temp_nosim[]){
	int i;	
	for(i=0;i<count;i++)
	{
		if(strcmpi(temp_nosim, SKB[i].nosim)==0)
		{
			return i;
		}
	}
	return -1;
}

void upd(){
	char temp_nosim[14];
	int temp=0;
	printf("Masukan Nomor Surat Izin Mengemudi yang Ingin di Update [12...13 Digit]: ");
	gets(temp_nosim);
	temp = search(temp_nosim);
	
	if(temp==-1){ //not found
		printf("DATA NOT FOUND!\n");
	}
	else{ //found
	printf("DATA FOUND\n");
	int cek = 0;
	char nama[100];
	char notelp[13];
	int tldd, tlmm, tlyyyy;
	char nosim[14];
	
	do{
		printf("Input Nama [Alphabet >5]\t\t\t\t: ");
		scanf("%[^\n]",&nama);
		fflush(stdin);
		if(strlen(nama) < 5){
			cek = 0;
		}
		else {
			for(int i = 0; i < strlen(nama);i++){
				if(nama[i] >= 'A' && nama[i] <= 'Z' || nama[i] == ' ' || nama[i] >= 'a' && nama[i] <= 'z'){   
					cek = 1;
				}
				else{
					cek=0;
					break;
				}
			}
		}
	}while(cek == 0);
	cek = 0;
	
	do{
		printf("Input Nomor Telepon [10...12 Digit]\t\t\t: ");
		scanf("%s",&notelp);
		fflush(stdin);
		if(strlen(notelp) < 10 || strlen(notelp) > 12){
			cek = 0;
		}
		else if(strlen(notelp) >= 10 && strlen(notelp) <= 12){
			for(int i = 0; i < strlen(notelp);i++){
				if(notelp[i] >= '0' && notelp[i] <= '9'){
					cek = 1;
				}
				else{
					cek = 0; break;
				}
			}
		}
	}while(cek == 0);
	cek = 0;
	
	do{
		printf("Input Tanggal Lahir [dd-mm-yyyy]\t\t\t: ");
		scanf("%d-%d-%d",&tldd, &tlmm, &tlyyyy);
		fflush(stdin);
		if(tlyyyy % 100 == 0 || tlyyyy % 4 != 0 || tlyyyy % 400 != 0)
			//bukan tahun kabisat
			if(tlmm == 1 || tlmm == 3 || tlmm == 5 || tlmm == 7 || tlmm == 8 || tlmm == 10 || tlmm == 12){
				if(tldd >=1 && tldd<=31){
					cek=1;
				}
				else{
					cek=0;
				}
			}
			else if(tlmm == 2){
				if(tldd >=1 && tldd<=28){
					cek=1;
				}
				else{
					cek=0;
				}
			}
			else if(tlmm == 4 || tlmm == 6 || tlmm == 9 || tlmm ==11){
				if(tldd >=1 && tldd<=30){
					cek=1;
				}
				else{
					cek=0;
				}
			}
		else if(tlyyyy%4==0 || tlyyyy%400==0){
			//tahun kabisat
			if(tlmm == 1 || tlmm == 3 || tlmm == 5 || tlmm == 7 || tlmm == 8 || tlmm == 10 || tlmm == 12){
				if(tldd >=1 && tldd<=31){
					cek=1;
				}
				else{
					cek=0;
				}
			}
			else if(tlmm == 2){
				if(tldd >=1 && tldd<=29){
					cek=1;
				}
				else{
					cek=0;
				}
			}
			else if(tlmm == 4 || tlmm == 6 || tlmm == 9 || tlmm ==11){
				if(tldd >=1 && tldd<=30){
					cek=1;
				}
				else{
					cek=0;
				}
			}
		}
	}while(cek == 0);
	cek=0;
	
	do{
		printf("Input Nomor SIM(Surat Izin Mengemudi) [12...13 Digit]\t: ");
		scanf("%s",&nosim);
		fflush(stdin);
		if(strlen(nosim) < 12 || strlen(notelp) > 13){
			cek = 0;
		}
		else if(strlen(notelp) >= 10 && strlen(notelp) <= 12){
			for(int i = 0; i < strlen(notelp);i++){
				if(notelp[i] >= '0' && notelp[i] <= '9'){
					cek = 1;
				}
				else{
					cek = 0; break;
				}
			}
		}
	}while(cek == 0);
	cek = 0;
	
	strcpy(SKB[temp].nama,nama);
	strcpy(SKB[temp].notelp,notelp);
	SKB[temp].tldd = tldd;
	SKB[temp].tlmm = tlmm;
	SKB[temp].tlyyyy = tlyyyy;
	strcpy(SKB[temp].nosim,nosim);
	temp = 0;
	printf("Data Berhasil Diupdate\n");
	}
	getchar();
}

void del(){
	char temp_nosim[14];
	int temp=0, i;
	printf("Masukan Nomor Surat Izin Mengemudi yang Ingin di Delete [12...13 Digit]: ");
	gets(temp_nosim);
	temp = search(temp_nosim);
	if(temp==-1){
		printf("DATA NOT FOUND");
	}else{
		for(i=temp;i<count;i++){
				SKB[i] = SKB[i+1];
			}
		count--;
		printf("Data Berhasil Didelete\n");
	}
	getchar();
}

void viw(){
	if(!count){
		printf("PLEASE INSERT MORE DATA !");
		getchar();
		return;
	}
	printf("================================================================================================\n");
	printf("||No.|          Nama           |     No.Telp     |  Tanggal Lahir  |Nomor Surat Izin Mengemudi||\n");
	printf("||---|-------------------------|-----------------|-----------------|--------------------------||\n");
	for(int i=0;i<count;i++){
		printf("||%-3d|%-25s|%-16s |%.2d-%.2d-%-10d |%-26s||\n",i+1,SKB[i].nama, SKB[i].notelp, SKB[i].tldd, SKB[i].tlmm, SKB[i].tlyyyy, SKB[i].nosim);
	}
	printf("================================================================================================\n");
	getchar();
}

void read_file(){
	fp = fopen("PT_SKB.txt","r");
	if(!fp){
		perror("File not found PT_SKB.txt\n");
		getchar();
		return;
	}else{
		while(!feof(fp)){
			fscanf(fp,"%[^#]#%[^#]#%d-%d-%d#%[^\n]\n",SKB[count].nama, SKB[count].notelp, &SKB[count].tldd, &SKB[count].tlmm, &SKB[count].tlyyyy, SKB[count].nosim);
			count++;
		}
	}
	fclose(fp);
}

void write_file(){
	if(!count){
		return;
	}
	fp = fopen("PT_SKB.txt","w");
	for(int i=0;i<count;i++){
		fprintf(fp,"%s#%s#%d-%d-%d#%s\n",SKB[i].nama, SKB[i].notelp, SKB[i].tldd, SKB[i].tlmm, SKB[i].tlyyyy, SKB[i].nosim);
	}
	fclose(fp);
}

int main(){
	int chosen;
	read_file();
	count=0;
	do{
		menu();
		scanf("%d", &chosen); getchar();
		switch(chosen){
			case 1: 
				reg(); break;
			case 2:
				upd(); break;
			case 3:
				del(); break;
			case 4:
				viw(); break;
		}
	}while(chosen != 5);	
	write_file();
	return 0;
}
