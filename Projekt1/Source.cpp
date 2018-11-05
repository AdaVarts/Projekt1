#include <stdio.h>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

FILE* f;
int count = 0;

typedef struct {
	char name[50];
	char sex;
	int birthday;
	char plate[9];
	bool offence;
	int sumOfFine;
	char dateOfFine[10];
} driver_t;

driver_t* drivers = NULL;

void o() {
	f = fopen("priestupky.txt", "r");
	count = 0;
	char str[265];
	while (fgets(str, 265, f)>0) {
		count++;
	}
	fclose(f);
	f = fopen("priestupky.txt", "r");
	
	
	if (drivers!=NULL)
		free(drivers);
	if (drivers = (driver_t*)malloc(sizeof(driver_t) * ((count+1)/8))) {
		int i = 0;
		for (int j = 0; j < (count+1)/8; j++)
		{
			while (fgets(str, 265, f)>0) {
				i++;
				char *pos = strrchr(str, '\n');
				if (pos)
					str[pos - str] = 0;
				switch (i % 8) {
				case 1:
					strcpy(drivers[j].name, str);
					break;
				case 2:
					drivers[j].sex = str[0];
					break;
				case 3:
					drivers[j].birthday = atoi(str);
					break;
				case 4:
					strcpy(drivers[j].plate, str);
					break;
				case 5:
					drivers[j].offence = str[0];
					break;
				case 6:
					drivers[j].sumOfFine = atoi(str);
					break;
				case 7:
					strcpy(drivers[j].dateOfFine, str);
					break;
				default:
					break;
				}
			}
		}
		
	}
	else {
		printf("Pole nie je naplnene");
	}
}

void v() {
	if (drivers != NULL) {
		for (int i = 0; i < (count + 1) / 8; i++) {
			printf("meno priezvisko: %s\n", drivers[i].name);
			printf("pohlavie: %c\n", drivers[i].sex);
			printf("rok narodenia: %d\n", drivers[i].birthday);
			printf("SPZ: %s", drivers[i].plate);
			printf("typ priestupku: %d\n", drivers[i].offence);
			printf("vyska pokuty: %d\n", drivers[i].sumOfFine);
			printf("datum priestupku: %s\n\n", drivers[i].dateOfFine);
		}
	}
}

void x() {
	struct tm *ptr;
	time_t lt;

	lt = time(NULL);
	ptr = localtime(&lt);
	
	int year = ptr->tm_year + 1900;

	for (int i = 0; i < (count+1)/8; i++)
	{
		char str[5];
		strncpy(str, drivers[i].dateOfFine, 4);
		if (atoi(str) == year) {
			printf("%s\n", drivers[i].name);
			printf("%s\n", drivers[i].plate);
			printf("%s\n", drivers[i].dateOfFine);
		}
	}
}

void p() {
	if (drivers != NULL) {
		for (int i = 0; i < (count + 1) / 8; i++)
		{
			char str[8];
			for (int j = 0; j < 7; j++)
				str[j] = drivers[i].plate[6 - j];
			str[7] = '\0';
			if (strcmp(str, drivers[i].plate) == 0) {
				printf("%s %s\n", drivers[i].name, drivers[i].plate);
			}
		}
	}
}

void r() {
	if (drivers != NULL) {
		struct tm *ptr;
		time_t lt;

		lt = time(NULL);
		ptr = localtime(&lt);

		int month = ptr->tm_mon + 1;
		int year = ptr->tm_year + 1900;
		double odmena = 0;
		for (int i = 0; i < (count + 1) / 8; i++)
		{
			char str[5];
			char str2[3];
			strncpy(str, drivers[i].dateOfFine, 4);
			str2[0] = drivers[i].dateOfFine[4];
			str2[1] = drivers[i].dateOfFine[5];
			str2[2] = '\0';
			if (atoi(str) == year && atoi(str2) == month) {
				if (drivers[i].offence == 1)
					odmena += drivers[i].sumOfFine*0.052;
				else if (drivers[i].offence == 0)
					odmena += drivers[i].sumOfFine*0.038;
			}
		}
		if (odmena != 0)
			printf("%.2lf\n", odmena);
	}
}

void k() {
	if (fclose(f) != 0) {  }
	if (drivers != NULL)
		free(drivers);
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
		default:
			break;
		}
	}

	system("pause");
	return 0;
}