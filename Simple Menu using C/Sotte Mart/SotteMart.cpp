#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

const int MAX_SIZE = 100;

typedef struct{
	char code[MAX_SIZE];
	char name[16];
	char type[20];
	int amount;
	int price;
	
}Data;

Data d[MAX_SIZE];
int cData = 0;

void swap(Data *a, Data *b) {
	Data temp = *a;
	*a = *b;
	*b = temp;
}

void qiSort(Data d[], int low, int high) {
	
	if (low >= high) return;
	
	int pIdx = low + rand() % (high - low + 1);
	Data pivot = d[pIdx];
	swap(&d[pIdx], &d[low]);
	
	int bh = high, bl = low, i = low + 1;
	
	while (i <= bh) {
		if (d[i].price < pivot.price) {
			swap(&d[i], &d[bl]);
			i++;
			bl++;
		}
		else if (d[i].price > pivot.price) {
			swap(&d[i], &d[bh]);
			bh--;
		}
		else {
			i++;
		}
	}
	
	qiSort(d, low, bl - 1);
	qiSort(d, bh+1, high);
	
}

void initialize() {
	//load data dari file
	FILE* fp = NULL;
	
	fp = fopen("data.txt", "r");
	
	Data temp;
	
	if (fp == NULL) {
		printf("File tidak ditemukan\n");
	}
	
	else {
		while (fscanf(fp, "%[^#]#%[^#]#%[^#]#%d#%d\n", d[cData].code, d[cData].name, d[cData].type, &d[cData].price, &d[cData].amount ) == 5) {
			cData++;
		}
			
	}	
	
	fclose(fp);
	
}

void WriteToFile() {
	FILE* fp = NULL;
	
	fp = fopen("data.txt", "w");
	
	if (!fp) printf("File tidak ada\n");
	
	for (int i = 0; i < cData; i++) {
		fprintf(fp, "%s#%s#%s#%d#%d\n", d[i].code, d[i].name, d[i].type, d[i].price, d[i].amount  );
	}
	
	fclose(fp);
}



void printData() {
	qiSort(d, 0, cData - 1);
	system("cls");
	printf("VIEW ITEM\n");
	printf("Total data = %d\n", cData);
	printf("| No  | %-10s | %-30s | %-10s | %-6s | %-10s |\n", "Item ID", "Item Name", "Type", "Price", "Quantity");
	printf("========================================================================================\n");
	for (int i =0 ; i < cData; i++) {
		printf("| %-3d | %-10s | %-30s | %-10s | %-6d | %-10d |\n", i+1, d[i].code, d[i].name, d[i].type, d[i].price, d[i].amount);
		
	}
	
	printf("Enter untuk kembali ke menu\n");
	getchar();
}

char* generateID(char str[]) {
	
	//buat code nya
	static char id[7];
	strncpy(id, str, 3);
	strupr(id);
	
	for (int i = 3; i < 6; i++) {
		id[i] = rand() % 10 + '0';
	}
	
	id[7] = '\0';
	
	return id;
}

void addItem() {
	system("cls");
	
	printf("ADD ITEM\n\n");
	
	Data temp;
	
	do {
		printf("Input Item Name [10 - 15]: ");
		scanf("%[^\n]", temp.name); getchar();
		if (strlen(temp.name) < 10 || strlen(temp.name) > 15) {
			printf("Nama Tidak sesuai Format! ulangi lagi\n");
		}
	} while (strlen(temp.name) < 10 || strlen(temp.name) > 15);
	
	do {
		printf("Input Item Quantity [50 - 1500]: ");
		scanf("%d", &temp.amount); getchar();
		if (temp.amount < 50 || temp.amount > 1500) {
			printf("Quantity Tidak sesuai Format! ulangi lagi\n");
		}
	} while (temp.amount < 50 || temp.amount > 1500);
	
	do {
		printf("Input Item Price [> 100]: ");
		scanf("%d", &temp.price); getchar();
		if (temp.price <= 100) {
			printf("Price Tidak sesuai Format! ulangi lagi\n");
		}
	} while (temp.price <= 100);
	
	do {
		printf("Input Item Type [Grocery | Electronic | Clothing]: ");
		scanf("%s", temp.type); getchar();
		if (strcmp(temp.type, "Grocery") != 0 && strcmp(temp.type, "Electronic") != 0 && strcmp(temp.type, "Clothing") != 0) {
			printf("Type Tidak sesuai Format! ulangi lagi\n");
		}
	} while (strcmp(temp.type, "Grocery") != 0 && strcmp(temp.type, "Electronic") != 0 && strcmp(temp.type, "Clothing") != 0);
	//bisa gak pake != 0 -> strcmp(temp.type, "Grocery") && strcmp(temp.type, "Electronic") &&
	
	
	strcpy(temp.code, generateID(temp.name));
	
	
	d[cData++] = temp;
	
	printf("Data berhasil dimasukan\n");
	
	WriteToFile();
	
}


void menu() {
	
	int input;
	
	while(true) {
		system("cls");
		printf("SOTTE MART\n");
		printf("1. Create Item\n"); //atau puts("1. Create Item");
		printf("2. View Item\n");
		printf("3. Buy Item\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &input); getchar();
		
		switch(input) {
			case 1: addItem();
				break;
			case 2: printData();
				break;
			case 3:
				break;
			case 4:
				return;
			default: printf("Opsi salah, masukan lagi\n");
		}
	
	}
}

int main() {
	
	srand(time(NULL));
	
	initialize();
	
	
	menu();
	
	
	
	
	return 0;
}
