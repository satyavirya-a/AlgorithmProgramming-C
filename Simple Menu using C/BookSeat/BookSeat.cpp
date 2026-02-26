#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int ROWS = 10;
int COLS = 10;

int main () {
	
	char inputUsername[20];
	char dataUsername[10][20];
	
	int opsi1;
	int opsi2;
	
	
	int countData = 0;
	int isKetemu = 0;
	
	int inputRows;
	int inputCols;
	
	//deklarasi seat 10x10
	char seat[ROWS][COLS];
	for (int i = 0; i < ROWS; i++ ) {
		for (int j = 0; j < COLS; j++) {
			
			seat[i][j] = 'O';
			
		}
	}
	
	
	while (true) {
		system("cls");
		
		printf("BOOK SEAT\n");
		printf("1. Login\n");
		printf("2. Register\n");
		printf("3. Exit\n");
		printf(">> ");
		
		scanf("%d", &opsi1); getchar();
		
		
		if (opsi1 == 1) {
			while (true) {
				system("cls");
				
				printf("Menu Login\n");
				printf("Enter Your Username [length more than 3 | alphabet only | 0 to Exit]:");
				scanf("%[^\n]", inputUsername); getchar();
				
				if (strcmp(inputUsername, "0") == 0) {
					isKetemu = 0;
					break;
				}
				
				isKetemu = 0;
				
				for (int i = 0; i < countData; i++) {
					if (strcmp(inputUsername, dataUsername[i]) == 0) {
						printf("Data Valid\n");
						printf("ENTER TO GO TO THE NEXT menu\n");
						isKetemu = 1;
						getchar();
						break;
					}
				}
				
				if (isKetemu == 0) {
					printf("DATA GAK ADA, try again!\n");
					getchar();
					continue;
				}				
				
				if (isKetemu == 1) {
					break;
				}
				
			}
			
		}
		
		else if (opsi1 == 2) {
			
			while (true) {
				system("cls");
				printf("Menu Register\n");
				printf("Enter Your Username [length more than 3 | alphabet only | 0 to Exit]:");
				scanf("%[^\n]", inputUsername); getchar();
				
				int len = strlen(inputUsername);
				int isCorrect = 1;
				
				if (strcmp(inputUsername, "0") == 0) {
					isCorrect = 0;
					break;
				}
				
				if (len <= 3) {
					printf("Name too Short!\n");
					getchar();
					isCorrect = 0; 
					continue;
				}
				
				for (int i = 0; i < len; i++) {
					if (!(isalpha(inputUsername[i]))) {
						printf("Harus alphabet doang!\n");
						isCorrect = 0; 
						getchar();
						continue;
					}
				}
				
				if (isCorrect) {
					printf("Data Berhasil dibuat!\n");
					strcpy(dataUsername[countData], inputUsername);
					countData++;
					getchar();
					break;
				}
			}
			
		}
		
		
		
	
		else if (opsi1 == 3) {
			printf("Exiting...");
			return 0;
		}
		
		else if (opsi1 > 3 || opsi1 < 1) {
			printf("Invalid Choice\n");
			getchar();
			continue;
		}
		
	
		
		if (isKetemu == 1) {
			while (true) {
				system("cls");
				printf("BOOKING SEAT\n");
				printf("1. Show Seats\n2. Reserve a Seat\n3. Cancel Reservation\n4. Exit\n>> ");
				
				scanf("%d", &opsi2); getchar();

				
				if (opsi2 == 1) {
					system("cls");
					
					printf("Tempat Duduk yang Tersedia\n");
					
					for (int i = 0; i < ROWS; i++ ) {
						for (int j = 0; j < COLS; j++) {
							printf("| %c |", seat[i][j] );
						}
						printf("\n");
					}
					
					getchar();
					continue;
				}
				
				else if (opsi2 == 2) {
					while (true) {
						system("cls");
						printf("MENU PESAN TEMPAT DUDUK\n");
						
						for (int i = 0; i < ROWS; i++ ) {
							for (int j = 0; j < COLS; j++) {
								printf("| %c |", seat[i][j] );
							}
							printf("\n");
						}
						
						printf("ROW BERAPA [0-9]: ");
						scanf("%d", &inputRows ); getchar();
						
						if (inputRows < 0 || inputRows > 9) {
							printf("input salah, enter to ulang\n");
							getchar();
							continue;
						}
						
						printf("COL BERAPA [0-9]: ");
						scanf("%d", &inputCols ); getchar();
						
						if (inputCols < 0 || inputCols > 9) {
							printf("input salah, enter to ulang\n");
							getchar();
							continue;
						}
						
						seat[inputRows][inputCols] = 'X';
						
						system("cls");
						printf("MENU PESAN TEMPAT DUDUK\n");
						
						for (int i = 0; i < ROWS; i++ ) {
							for (int j = 0; j < COLS; j++) {
								printf("| %c |", seat[i][j] );
							}
							printf("\n");
						}
						
						printf("Data Berhasil Masuk! Enter to back to menu\n");
						
						getchar();
						break;
						
						
					}
					
					
				}
				
				else if (opsi2 == 3) {
					while (true) {
						system("cls");
						printf("MENU REMOVE TEMPAT DUDUK\n");
						
						for (int i = 0; i < ROWS; i++ ) {
							for (int j = 0; j < COLS; j++) {
								printf("| %c |", seat[i][j] );
							}
							printf("\n");
						}
						
						printf("ROW BERAPA [0-9]: ");
						scanf("%d", &inputRows ); getchar();
						
						if (inputRows < 0 || inputRows > 9) {
							printf("input salah, enter to ulang\n");
							getchar();
							continue;
						}
						
						printf("COL BERAPA [0-9]: ");
						scanf("%d", &inputCols ); getchar();
						
						if (inputCols < 0 || inputCols > 9) {
							printf("input salah, enter to ulang\n");
							getchar();
							continue;
						}
						
						seat[inputRows][inputCols] = 'O';
						
						system("cls");
						printf("MENU REMOVE TEMPAT DUDUK\n");

						
						for (int i = 0; i < ROWS; i++ ) {
							for (int j = 0; j < COLS; j++) {
								printf("| %c |", seat[i][j] );
							}
							printf("\n");
						}
						
						printf("Data Berhasil Dihapus! Enter to back to menu\n");
						
						getchar();
						break;
						
						
					}
					
					
				}
				
				else if (opsi2 == 4) {
					isKetemu = 0; 
					break;
				}
				
			
			
			
			}
		}
	
	
		
	}
		
		
		
		
	
	
	
	
	
	return 0; 
}
