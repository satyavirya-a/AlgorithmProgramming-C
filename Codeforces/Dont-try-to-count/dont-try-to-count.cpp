#include <stdio.h>
#include <string.h>

int main() {

    int T; 

    scanf("%d", &T); getchar();

    for (int i = 0; i < T; i++) {

        int n, m;

        scanf("%d %d", &n, &m);

        char str[n];
        char target[m];

        scanf("%s", str); getchar();
        scanf("%s", target); getchar();

        int j = 0;

        while (true) {
            if (strncmp(str+j, target, m) != 0) {
                strcat(str, str); //error segmented fault
                j++;
            }

            else if (strncmp(str+j, target, m) == 0) {
                break;
            }
            // printf("string setelah di tambah %s\n", str);

            //kalau imposible buat kondisinya gimana ya?
            
        }

        printf("Hasil : %d\n", j);

    }

    return 0; 
}