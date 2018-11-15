//Yelyzaveta Klysa 99411
#include "Header.h"

//structure
typedef struct driver_t {
	char name[50];
	char sex;
	int birthday;
	char plate[9];
	bool offence;
	int sumOfFine;
	char dateOfFine[10];
} driver_t;

driver_t** o(driver_t** drivers, FILE** f, int* countDrivers) {
	//cleaning array if it exists
	if (drivers != NULL) {
		for (int i = 0; i < *countDrivers; i++)
			free(drivers[i]);
	}
	//creating a new pointer on array
	drivers = (driver_t**)malloc(sizeof(driver_t*));

	char str[265];
	//getting amount of drivers
	if ((*f = fopen("priestupky.txt", "r")) != NULL) {
		int j = 0;
		while (fgets(str, 265, *f) > 0) {
			j++;
		}
		*countDrivers = j / 8;
		fclose(*f);
	}
	
	if ((*f = fopen("priestupky.txt", "r")) != NULL) {
		//creating a new array
		for (int j = 0; j < *countDrivers; j++)
			drivers[j] = (driver_t*)malloc(sizeof(driver_t));
		//getting values from file
		if (drivers != NULL) {
			int i = 0;
			int j = 0;
			while (fgets(str, 265, *f) > 0) {
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
					if (str[0] == 48)
						drivers[j]->offence = false;
					else
						drivers[j]->offence = true;
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
	return drivers;
}

void v(driver_t** drivers, int* countDrivers) {
	if (drivers != NULL) {
		//printing all drivers
		for (int i = 0; i < *countDrivers; i++) {
			printf("meno priezvisko: %s\n", drivers[i]->name);
			printf("pohlavie: %c\n", drivers[i]->sex);
			printf("rok narodenia: %d\n", drivers[i]->birthday);
			printf("SPZ: %s\n", drivers[i]->plate);
			printf("typ priestupku: %d\n", drivers[i]->offence);
			printf("vyska pokuty: %d\n", drivers[i]->sumOfFine);
			printf("datum priestupku: %s\n\n", drivers[i]->dateOfFine);
		}
	}
}

void x(driver_t** drivers, int* countDrivers) {
	//getting year
	char *str = (char*)malloc(9);
	scanf("%8s", str);
	char year[5];
	strncpy(year, str, 4);
	year[4] = '\0';

	for (int i = 0; i < *countDrivers; i++)
	{
		char str1[5];
		strncpy(str1, drivers[i]->dateOfFine, 4);
		str1[4] = '\0';
		if (strcmp(str1, year) == 0 && drivers[i]->offence == false) {
			printf("meno priezvisko: %s\n", drivers[i]->name);
			printf("SPZ: %s\n", drivers[i]->plate);
			printf("datum priestupku: %s\n", drivers[i]->dateOfFine);
			printf("\n");
		}
	}
}

void p(driver_t** drivers, int* countDrivers) {
	if (drivers != NULL) {
		for (int i = 0; i < *countDrivers; i++)
		{
			//getting reverse string of 'plate license'
			char str[8];
			for (int j = 0; j < 7; j++)
				str[j] = drivers[i]->plate[6 - j];
			str[7] = '\0';
			//comparing reverse and initial strings
			if (strcmp(str, drivers[i]->plate) == 0) {
				printf("%s %s\n", drivers[i]->name, drivers[i]->plate);
			}
		}
	}
}

void r(driver_t** drivers, int* countDrivers) {
	if (drivers != NULL) {
		//getting year and month
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
		for (int i = 0; i < *countDrivers; i++)
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

driver_t** a(driver_t** drivers, int* countDrivers) {
	//creating new array if there is no previous
	if (drivers == NULL) {
		drivers = (driver_t**)malloc(sizeof(driver_t*));
		drivers[0] = (driver_t*)malloc(sizeof(driver_t));
	}
	//incremening previous if it exists
	else {
		drivers[*countDrivers] = (driver_t*)malloc(sizeof(driver_t));
	}
	char *str = (char*)malloc(50);
	getchar();
	char c;
	int i = 0;
	while ((c = getchar()) != '\n') str[i++] = c;
	str[i] = '\0';
	strncpy(drivers[*countDrivers]->name, str, 50);
	scanf("%s", str);
	drivers[*countDrivers]->sex = str[0];
	scanf("%s", str);
	drivers[*countDrivers]->birthday = atoi(str);
	scanf("%s", str);
	strcpy(drivers[*countDrivers]->plate, str);
	scanf("%s", str);
	drivers[*countDrivers]->offence = str[0];
	scanf("%s", str);
	drivers[*countDrivers]->sumOfFine = atoi(str);
	scanf("%s", str);
	strcpy(drivers[*countDrivers]->dateOfFine, str);
	(*countDrivers)++;

	//bubble sorting by alphabet
	for (int k = 1; k < *countDrivers; k++) 
		for (int j = 0; j < *countDrivers - k; j++)
			if (strcmp(drivers[j]->name, drivers[j + 1]->name) > 0) {
				driver_t *driverTemp = (driver_t*)malloc(sizeof(driver_t));
				driverTemp = drivers[j];
				drivers[j] = drivers[j + 1];
				drivers[j + 1] = driverTemp;
			}

	return drivers;
}

//function for Test2 c(n)
driver_t** n(driver_t** drivers, int* countDrivers) {
	if (drivers != NULL) {
		int n = 0;
		char strn[5];
		scanf("%s", strn);
		n = atoi(strn);
		char str[9];
		scanf("%s", str);
		char spz1[3] = { str[0], str[1], '\0' };
		for (int i = 0; i < *countDrivers; i++)
		{
			char spz[3] = { drivers[i]->plate[0], drivers[i]->plate[1], '\0' };
			if (drivers[i]->sumOfFine < n && strcmp(spz1, spz) == 0) {
				for (int j = i; j < *countDrivers - 1; j++)
				{
					strcpy(drivers[j]->name, drivers[j + 1]->name);
					drivers[j]->sex = drivers[j + 1]->sex;
					drivers[j]->birthday = drivers[j + 1]->birthday;
					strcpy(drivers[j]->plate, drivers[j + 1]->plate);
					drivers[j]->offence = drivers[j + 1]->offence;
					drivers[j]->sumOfFine = drivers[j + 1]->sumOfFine;
					strcpy(drivers[j]->dateOfFine, drivers[j + 1]->dateOfFine);
				}
				free(drivers[*countDrivers - 1]);
				(*countDrivers)--;
			}
		}
	}
	printf("\n");
	return drivers;
}

//function for Test2 s(h)
void s(driver_t** drivers, int* countDrivers) {
	if (drivers != NULL) {
		char *charKey;
		int *amount;
		amount = (int*)malloc(2 * sizeof(int));
		charKey = (char*)malloc(27 * sizeof(char));
		charKey[0] = drivers[0]->plate[0];
		amount[0] = 0;
		int length = 1;
		for (int i = 0; i < *countDrivers; i++)
		{
			bool flag1 = false, flag2 = false, flag3 = false;
			for (int j = 0; j < length; j++)
			{
				if (charKey[j] == drivers[i]->plate[0]) {
					amount[j]++;
					flag1 = true;
				}
				if (charKey[j] == drivers[i]->plate[1]) {
					amount[j]++;
					flag2 = true;
				}
				if (drivers[i]->plate[0] == drivers[i]->plate[1]) {
					flag2 = true;
					flag3 = true;
				}
			}
			if (!flag1) {
				realloc(charKey, ++length);
				charKey[length - 1] = drivers[i]->plate[0];
				int *paTemp = (int*)malloc((length + 1) * sizeof(int));
				for (int k = 0; k < length - 1; k++)
					paTemp[k] = amount[k];
				paTemp[length - 1] = 1;
				if (flag3)
					paTemp[length - 1]++;
				free(amount);
				amount = (int*)malloc((length + 1) * sizeof(int));
				for (int k = 0; k < length; k++)
					amount[k] = paTemp[k];
				free(paTemp);
			}
			if (!flag2) {
				realloc(charKey, ++length);
				charKey[length - 1] = drivers[i]->plate[1];
				int *paTemp = (int*)malloc((length + 1) * sizeof(int));
				for (int k = 0; k < length - 1; k++)
					paTemp[k] = amount[k];
				paTemp[length - 1] = 1;
				free(amount);
				amount = (int*)malloc((length + 1) * sizeof(int));
				for (int k = 0; k < length; k++)
					amount[k] = paTemp[k];
				free(paTemp);
			}
		}

		//bubble sorting by alphabet
		for (int k = 1; k < length; k++)
			for (int j = 0; j < length - k; j++)
				if (charKey[j]>charKey[j + 1]) {
					char t = charKey[j];
					charKey[j] = charKey[j + 1];
					charKey[j + 1] = t;
				}

		for (int i = 0; i < length; i++)
		{
			printf("%c:%d\n", charKey[i], amount[i]);
		}
		printf("\n");
		free(charKey);
		free(amount);
	}
}

void k(driver_t** drivers, FILE**f, int* countDrivers) {
	//file closing
	if (*f != NULL) 
		fclose(*f); 
	//array cleaning
	if (drivers != NULL) {
		for (int i = 0; i < *countDrivers; i++)
			free(drivers[i]);
		*countDrivers = 0;
	}
	system("pause");
	exit(0);
}

int main() {
	FILE* f = NULL;
	driver_t** drivers = NULL;
	int countDrivers = 0;
	char c;
	while (true) {
		scanf_s("%c", &c);
		switch (c) {
		case 'o':
			drivers = o(drivers, &f, &countDrivers);
			break;
		case 'a':
			drivers = a(drivers, &countDrivers);
			break;
		case 'v':
			v(drivers, &countDrivers);
			break;
		case 'r':
			r(drivers, &countDrivers);
			break;
		case 'k':
			k(drivers, &f, &countDrivers);
			break;
		case 'x':
			x(drivers, &countDrivers);
			break;
		case 'p':
			p(drivers, &countDrivers);
			break;
		case 'c':
			drivers = n(drivers, &countDrivers);
			break;
		case 's':
			s(drivers, &countDrivers);
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}