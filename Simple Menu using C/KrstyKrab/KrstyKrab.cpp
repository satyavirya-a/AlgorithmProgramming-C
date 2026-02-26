#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	
	char idStore[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#"};
	
	int cPesan = 0;
	while (true) {
		system("cls");
		printf("THE KRUSTY KRAB\n");
		printf("===================\n");
		printf("1. Add New Menu Item\n2. View Menu\n3. Remove Menu Item\n4. Exit\n>> ");
		
		int opsi;
		
		scanf("%d", &opsi); getchar();
		
		char nama[10][35];
		char tipe[10][35];
		
		
		int price[10];
		char id[10][35];
		char con;
		
		if (opsi == 1) {
			while (true) {
				
				system("cls");
				printf("Add Menu\n");
				printf("Menu Item Name [8-30]: ");
				scanf("%s", nama[cPesan] ); getchar();
				int len = strlen(nama[cPesan]);
				while (len < 8 || len >30) {
					printf("Harus 8-30 chara\n");
					printf("Menu Item Name [8-30]: ");
					scanf("%s", nama[cPesan] ); getchar();
					len = strlen(nama[cPesan]);
				}
				
				printf("Item Type [Food, Drinks, Merc]: ");
				scanf("%s", tipe[cPesan] ); getchar();
				while (!(strcmp(tipe[cPesan], "Food") == 0 
				|| strcmp(tipe[cPesan], "Drinks") == 0 
				|| strcmp(tipe[cPesan], "Merchandise") == 0)) {
					printf("Salah Tipe\n");
					printf("Item Type [Food, Drinks, Merc]: ");
					scanf("%s", tipe[cPesan] ); getchar();
				}
				
				printf("Item Price [10000 - 500000]: ");
				scanf("%d", &price[cPesan]); getchar();
				while (price[cPesan]< 10000 || price[cPesan] > 500000) {
					printf("Masih Belum Tepat\n");
					printf("Item Price [10000 - 500000]: ");
					scanf("%d", &price[cPesan]); getchar();
					
				}
				
				//anggap id kombinasi 10 karakter dan angka
				for (int i = 0; i < 10; i++) {
					id[cPesan][i] = idStore[rand() % 67];
				}
				id[cPesan][10] = '\0';
				
				system("cls");
				printf("Add Menu\n");
				printf("ID item: %s\n", id[cPesan]);
				printf("Menu Item Name: %s\n", nama[cPesan]);
				printf("Item Type: %s\n", tipe[cPesan]);
				printf("Item Price: %d\n", price[cPesan]);
				printf("----------------\n");
				printf("Confirm adding this item? [y/n]: ");
				scanf("%c", &con); getchar();
				
				if (con == 'y') {
					cPesan++;
//					printf("Data tersimpan!\n");
//					getchar();
					break;
				}
				else if (con == 'n') {
					break;
				}
				else {
					printf("Salah boy\n");
					getchar();
					continue;
				}
				
			}
			
		
			continue;
		}
		
		
		else if (opsi == 2) {
			system("cls");
			printf("View Menu\n");
			
			if (cPesan == 0) {
				printf("The menu is empty, please add more items!\n");
				getchar();
				continue;
			}
			
			else {
				
				for (int j = 0; j < cPesan; j++) {
					printf("Item #%d\n", j+1);
					printf("ID item: %s\n", id[j]);
					printf("Menu Item Name:\t%s\n", nama[j]);
					printf("Item Type:\t%s\n", tipe[j]);
					printf("Item Price:\t%d\n", price[j]);
					printf("---------------------------------\n");
				}
				
				
			}
			
			printf("Press Enter to Continue...");
			getchar();
			continue;
			
			
			
		}
		
		
		else if (opsi == 3) {
			while (true) {
				int index;
				system("cls");
				printf("Remove Menu\n");
				
				if (cPesan == 0) {
					printf("Menu Empty\n");
					getchar();
					break;
				}
				for (int j = 0; j < cPesan; j++) {
					printf("%d. %s\n", j+1, nama[j]);
				}
				
				printf("======================\n");
				printf("Enter item index to remove [1-%d]: ", cPesan);
				scanf("%d", &index); getchar();
				
				if (index < 1 || index > cPesan) {
					printf("index salah masukan lagin\n");
					getchar();
					continue;
				}
				
				for (int j = index-1; j < cPesan; j++) {
					strcpy(nama[j], nama[j+1]);
					strcpy(tipe[j], tipe[j+1]);
					price[j] = price[j+1];
				}
				
				cPesan--;
			}
			
			
			
			continue;
		}
		
		
		else if (opsi == 4) {
			system("cls");
			printf("Closing the Krusty Krab... Goodbye!\n");
			break;
		}
		else {
			printf("Salah opsi\nEnter to ulang\n");
			getchar();
			continue;
		}
	
	
	
	}
	
	
	
	
	
	return 0;
}