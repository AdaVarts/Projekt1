#include <stdio.h>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

FILE* f;
int count = 0;

typedef struct driver_t {
	char name[50];
	char sex;
	int birthday;
	char plate[9];
	bool offence;
	int sumOfFine;
	char dateOfFine[10];
} driver_t;

driver_t** drivers = NULL;

void o() {
	f = fopen("priestupky.txt", "r");
	int j = 0;
	char str[265];
	while (fgets(str, 265, f)>0) {
		j++;
	}
	count = (j + 1) / 8;
	fclose(f);
	f = fopen("priestupky.txt", "r");
	
	
	if (drivers != NULL) {
		for (int i = 0; i < count; i++)
			free(drivers[i]);
	}
	drivers = (driver_t**)malloc(sizeof(driver_t*));
	for (int j = 0; j < count; j++)
		drivers[j] = (driver_t*)malloc(sizeof(driver_t));
	if (drivers != NULL) {
		int i = 0;
		int j = 0;
		while (fgets(str, 265, f) > 0) {
			i++;
			if (i % 8 == 0)
				j++;
			char *pos = strrchr(str, '\n');
			if (pos)
				str[pos - str] = 0;
			switch (i % 8) {
			case 1:
				strcpy(drivers[j]->name, str);
				break;
			case 2:
				drivers[j]->sex = str[0];
				break;
			case 3:
				drivers[j]->birthday = atoi(str);
				break;
			case 4:
				strcpy(drivers[j]->plate, str);
				break;
			case 5:
				drivers[j]->offence = str[0];
				break;
			case 6:
				drivers[j]->sumOfFine = atoi(str);
				break;
			case 7:
				strcpy(drivers[j]->dateOfFine, str);
				break;
			default:
				break;
			}
		}
		
	}
	else {
		printf("Pole nie je naplnene");
	}
}

void v() {
	if (drivers != NULL) {
		for (int i = 0; i < count; i++) {
			printf("meno priezvisko: %s\n", drivers[i]->name);
			printf("pohlavie: %c\n", drivers[i]->sex);
			printf("rok narodenia: %d\n", drivers[i]->birthday);
			printf("SPZ: %s", drivers[i]->plate);
			printf("typ priestupku: %d\n", drivers[i]->offence);
			printf("vyska pokuty: %d\n", drivers[i]->sumOfFine);
			printf("datum priestupku: %s\n\n", drivers[i]->dateOfFine);
		}
	}
}

void x() {
	char *str = (char*)malloc(9);
	scanf("%8s", str);
	char year[5];
	strncpy(year, str, 4);
	year[4] = '\0';

	for (int i = 0; i < count; i++)
	{
		char str1[5];
		strncpy(str1, drivers[i]->dateOfFine, 4);
		str1[4] = '\0';
		if (strcmp(str1, year) == 0) {
			printf("%s\n", drivers[i]->name);
			printf("%s\n", drivers[i]->plate);
			printf("%s\n", drivers[i]->dateOfFine);
		}
	}
	printf("\n");
}

void p() {
	if (drivers != NULL) {
		for (int i = 0; i < count; i++)
		{
			char str[8];
			for (int j = 0; j < 7; j++)
				str[j] = drivers[i]->plate[6 - j];
			str[7] = '\0';
			if (strcmp(str, drivers[i]->plate) == 0) {
				printf("%s %s\n", drivers[i]->name, drivers[i]->plate);
			}
		}
	}
}

void r() {
	if (drivers != NULL) {
		
		char *str;
		str = (char*)malloc(9);
		scanf("%8s", str);
		char year[5];
		strncpy(year, str, 4);
		year[4] = '\0';
		char month[3];
		month[0] = str[4];
		month[1] = str[5];
		month[2] = '\0';

		double odmena = 0;
		for (int i = 0; i < count; i++)
		{
			char str1[5];
			char str2[3];
			strncpy(str1, drivers[i]->dateOfFine, 4);
			str1[4] = '\0';
			str2[0] = drivers[i]->dateOfFine[4];
			str2[1] = drivers[i]->dateOfFine[5];
			str2[2] = '\0';
			if (strcmp(str1, year) == 0 && strcmp(str2, month) == 0) {
				if (drivers[i]->offence == 1)
					odmena += drivers[i]->sumOfFine*0.052;
				else if (drivers[i]->offence == 0)
					odmena += drivers[i]->sumOfFine*0.038;
			}
		}
		if (odmena != 0)
			printf("%.2lf\n", odmena);
	}
}

/*void a() {
	if (drivers == NULL) {
		drivers = (driver_t**)malloc(sizeof(driver_t*));
		drivers[0] = (driver_t*)malloc(sizeof(driver_t));
		count++;
	}
	else {
		driver_t** drivers1 = (driver_t**)malloc(sizeof(driver_t*));
		for (int i = 0; i < count + 1; i++) {
			drivers1[i] = (driver_t*)malloc(sizeof(driver_t));
			if (i != count) {
				strcpy(drivers1[i]->name, drivers[i]->name);
				drivers1[i]->sex = drivers[i]->sex;
				drivers1[i]->birthday = drivers[i]->birthday;
				strcpy(drivers1[i]->plate, drivers[i]->plate);
				drivers1[i]->offence = drivers[i]->offence;
				drivers1[i]->sumOfFine = drivers[i]->sumOfFine;
				strcpy(drivers1[i]->dateOfFine, drivers[i]->dateOfFine);

				free(drivers[i]);
			}
		}
		count++;
	}
	scanf_s("%s", drivers[count - 1]->name);
	scanf_s("%c", drivers[count - 1]->sex);
	scanf_s("%d", drivers[count - 1]->birthday);
	scanf_s("%s", drivers[count - 1]->plate);
	scanf_s("%d", drivers[count - 1]->offence);
	scanf_s("%d", drivers[count - 1]->sumOfFine);
	scanf_s("%s", drivers[count - 1]->dateOfFine);
}*/

void k() {
	if (f != NULL)
		fclose(f);
	if (drivers != NULL)
		for (int i = 0; i < (count + 1) / 8; i++)
			free(drivers[i]);
	system("pause");
	exit(0);
}

int main() {
	char c;
	while (true) {
		scanf_s("%c", &c);
		switch (c) {
		case 'o':
			o();
			break;
		case 'r':
			r();
			break;
		case 'k':
			k();
			break;
		case 'x':
			x();
			break;
		case 'p':
			p();
			break;
		case 'v':
			v();
			break;
		case 'a':
			//a();
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}