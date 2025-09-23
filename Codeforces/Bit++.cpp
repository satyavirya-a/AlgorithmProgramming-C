#include <stdio.h>
#include <string.h>

int main() {

    int n;

    scanf("%d", &n);
    int angka = 0; 
    for (int i = 0; i < n;i++) {
        char command[3];
        scanf("%s", command);
        if (strcmp(command, "++X") == 0) {
            ++angka;
        }
        else if (strcmp(command, "X++") == 0) {
            angka++;
        }
        else if (strcmp(command, "--X") == 0) {
            --angka;
        }
        else if (strcmp(command, "X--") == 0) {
            angka--;
        }

    }

    printf("%d\n", angka);




    return 0;
}