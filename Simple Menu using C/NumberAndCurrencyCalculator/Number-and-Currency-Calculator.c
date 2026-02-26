#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main() {
	
//	Calculate Numbers
//	Currency Calculate
//	EXIT
	
	while (true) {
		system("cls");
		
		int choice;
		printf("Calculator\n");
		printf("1. Calculate Numbers\n");
		printf("2. Currency Calculator\n");
		printf("3. Exit\n");
		printf("Enter choice: ");
		
		scanf("%d", &choice); getchar();
		
		while (choice == 1) {
			system("cls");
			int num1 = 0;
			int num2 = 0;
			double hasil = 0;
			char op;
			printf("Enter number 1: ");
			scanf("%d", &num1); getchar();
			printf("Enter operator [+,-,*,/]: ");
			scanf("%c", &op); getchar();
			printf("Enter number 2: ");
			scanf("%d", &num2); getchar();
			
			if (op == '+') {
				hasil = num1 + num2;
			}
			else if (op == '-') {
				hasil = num1 - num2;
			}		
			else if (op == '*') {
				hasil = num1 * num2;
			}		
			else if (op == '/') {
				if (num2 == 0) {
					printf("MANA BISA, enter untuk masukan lagi\n");
					getchar();
					continue;
				}
				hasil = (double) num1 / num2;
			}	
			else {
				printf("Salah operator atau input, enter untuk masukan lagi\n");
				getchar();
				continue;
			}
			
			printf("Result: %.2lf\n", hasil);
			
			printf("Klik enter untuk kembali ke menu\n");
			getchar();
			break;
		}
		
		while (choice == 2) {
			system("cls");
			int pil;
			double idr, usd;
			printf("Currency Calculator\n");
			printf("1. Convert IDR to USD [RP16000/USD]\n");
			printf("2. Convert USD to IDR\n");
			printf("3. Back\n");
			printf("Enter choice: ");
			scanf("%d", &pil ); getchar();
			
			while (pil == 1) {
				system("cls");
				printf("Enter IDR: ");
				scanf("%lf", &idr); getchar();
				printf("USD: %lf\n", idr/16000);
				getchar();
				break;
			}
			
			while (pil == 2) {
				system("cls");
				printf("Enter USD: ");
				scanf("%lf", &usd); getchar();
				printf("IDR: %lf\n", usd*16000);
				getchar();
				break;
			}
			
			if (pil == 3) {
				break;
			}
			
			
		}
		
		if (choice == 3) {
			system("cls");
			printf("Exiting...\n");
			break;
		}
		
		
	}
	

	return 0;
}


//bisa pake switch case
//		switch (op) {
//			case '+': 
//				hasil = 
//				break;
//			case '-':
//				hasil = 
//				break;
//			case '*':
//				hasil = 
//				break;
//			case '/':
//				hasil = 
//				break;
//			default: 
//				printf("Rusak\n");
//				break;
//			
//			
//		}

