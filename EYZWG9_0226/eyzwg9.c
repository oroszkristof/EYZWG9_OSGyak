#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char filename[100];
    char line[256];

    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        printf("Hiba a fajlnev beolvasasakor.\n");
        return 1;
    }
    filename[strcspn(filename, "\n")] = '\0';

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("A fajl megnyitasa sikertelen.");
        return 1;
    }

    while (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "#") == 0) {
            break;
        }
        printf(fp, "%s\n", line);
    }
    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("A fajl megnyitása olvasasra sikertelen!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            line[i] = toupper((unsigned char)line[i]);
        }
        printf("%s", line);
    }
    fclose(fp);

    system("pause");
    return 0;
}
