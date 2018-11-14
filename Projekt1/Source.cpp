#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

driver_t** o(driver_t** drivers, FILE** f, int* count) {
	//cleaning array if it exists
	if (drivers != NULL) {
		for (int i = 0; i < *count; i++)
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
		*count = j / 8;
		fclose(*f);
	}
	
	if ((*f = fopen("priestupky.txt", "r")) != NULL) {
		//creating a new array
		for (int j = 0; j < *count; j++)
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

void v(driver_t** drivers, int* count) {
	if (drivers != NULL) {
		//printing all drivers
		for (int i = 0; i < *count; i++) {
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

void x(driver_t** drivers, int* count) {
	//getting year
	char *str = (char*)malloc(9);
	scanf("%8s", str);
	char year[5];
	strncpy(year, str, 4);
	year[4] = '\0';

	for (int i = 0; i < *count; i++)
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

void p(driver_t** drivers, int* count) {
	if (drivers != NULL) {
		for (int i = 0; i < *count; i++)
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

void r(driver_t** drivers, int* count) {
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
		for (int i = 0; i < *count; i++)
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

driver_t** a(driver_t** drivers, int* count) {
	//creating new array if there is no previous
	if (drivers == NULL) {
		drivers = (driver_t**)malloc(sizeof(driver_t*));
		drivers[0] = (driver_t*)malloc(sizeof(driver_t));
	}
	//incremening previous if it exists
	else {
		drivers[*count] = (driver_t*)malloc(sizeof(driver_t));
	}
	char *str = (char*)malloc(50);
	getchar();
	char c;
	int i = 0;
	while ((c = getchar()) != '\n') str[i++] = c;
	str[i] = '\0';
	strncpy(drivers[*count]->name, str, 50);
	scanf("%s", str);
	drivers[*count]->sex = str[0];
	scanf("%s", str);
	drivers[*count]->birthday = atoi(str);
	scanf("%s", str);
	strcpy(drivers[*count]->plate, str);
	scanf("%s", str);
	drivers[*count]->offence = str[0];
	scanf("%s", str);
	drivers[*count]->sumOfFine = atoi(str);
	scanf("%s", str);
	strcpy(drivers[*count]->dateOfFine, str);
	(*count)++;

	//bubble sorting by alphabet
	for (int k = 1; k < *count; k++) 
		for (int j = 0; j < *count - k; j++)
			if (strcmp(drivers[j]->name, drivers[j + 1]->name) > 0) {
				driver_t *driverTemp = (driver_t*)malloc(sizeof(driver_t));
				driverTemp = drivers[j];
				drivers[j] = drivers[j + 1];
				drivers[j + 1] = driverTemp;
			}

	return drivers;
}

//function for Test2 c(n)
driver_t** n(driver_t** drivers, int* count) {
	if (drivers != NULL) {
		int n = 0;
		char strn[5];
		scanf("%s", strn);
		n = atoi(strn);
		char str[9];
		scanf("%s", str);
		char spz1[3] = { str[0], str[1], '\0' };
		for (int i = 0; i < *count; i++)
		{
			char spz[3] = { drivers[i]->plate[0], drivers[i]->plate[1], '\0' };
			if (drivers[i]->sumOfFine < n && strcmp(spz1, spz) == 0) {
				for (int j = i; j < *count - 1; j++)
				{
					strcpy(drivers[j]->name, drivers[j + 1]->name);
					drivers[j]->sex = drivers[j + 1]->sex;
					drivers[j]->birthday = drivers[j + 1]->birthday;
					strcpy(drivers[j]->plate, drivers[j + 1]->plate);
					drivers[j]->offence = drivers[j + 1]->offence;
					drivers[j]->sumOfFine = drivers[j + 1]->sumOfFine;
					strcpy(drivers[j]->dateOfFine, drivers[j + 1]->dateOfFine);
				}
				free(drivers[*count - 1]);
				(*count)--;
			}
		}
	}
	printf("\n");
	return drivers;
}

//function for Test2 s(h)
void s(driver_t** drivers, int* count) {
	if (drivers != NULL) {
		char *x;
		int *amount;
		amount = (int*)malloc(2 * sizeof(int));
		x = (char*)malloc(27 * sizeof(char));
		x[0] = drivers[0]->plate[0];
		amount[0] = 0;
		int length = 1;
		for (int i = 0; i < *count; i++)
		{
			bool flag1 = false, flag2 = false, flag3 = false;
			for (int j = 0; j < length; j++)
			{
				if (x[j] == drivers[i]->plate[0]) {
					amount[j]++;
					flag1 = true;
				}
				if (x[j] == drivers[i]->plate[1]) {
					amount[j]++;
					flag2 = true;
				}
				if (drivers[i]->plate[0] == drivers[i]->plate[1]) {
					flag2 = true;
					flag3 = true;
				}
			}
			if (!flag1) {
				realloc(x, ++length);
				x[length - 1] = drivers[i]->plate[0];
				int *pa = (int*)malloc((length + 1) * sizeof(int));
				for (int k = 0; k < length - 1; k++)
					pa[k] = amount[k];
				pa[length - 1] = 1;
				if (flag3)
					pa[length - 1]++;
				free(amount);
				amount = (int*)malloc((length + 1) * sizeof(int));
				for (int k = 0; k < length; k++)
					amount[k] = pa[k];
				free(pa);
			}
			if (!flag2) {
				realloc(x, ++length);
				x[length - 1] = drivers[i]->plate[1];
				int *pa = (int*)malloc((length + 1) * sizeof(int));
				for (int k = 0; k < length - 1; k++)
					pa[k] = amount[k];
				pa[length - 1] = 1;
				free(amount);
				amount = (int*)malloc((length + 1) * sizeof(int));
				for (int k = 0; k < length; k++)
					amount[k] = pa[k];
				free(pa);
			}
		}

		//bubble sorting by alphabet
		for (int k = 1; k < length; k++)
			for (int j = 0; j < length - k; j++)
				if (x[j]>x[j + 1]) {
					char t = x[j];
					x[j] = x[j + 1];
					x[j + 1] = t;
				}

		for (int i = 0; i < length; i++)
		{
			printf("%c:%d\n", x[i], amount[i]);
		}
		printf("\n");
		free(x);
		free(amount);
	}
}

void k(driver_t** drivers, FILE**f, int* count) {
	//file closing
	if (*f != NULL) 
		fclose(*f); 
	//array cleaning
	if (drivers != NULL) {
		for (int i = 0; i < *count; i++)
			free(drivers[i]);
		*count = 0;
	}
	system("pause");
	exit(0);
}

int main() {
	FILE* f = NULL;
	driver_t** drivers = NULL;
	int count = 0;
	char c;
	while (true) {
		scanf_s("%c", &c);
		switch (c) {
		case 'o':
			drivers = o(drivers, &f, &count);
			break;
		case 'r':
			r(drivers, &count);
			break;
		case 'k':
			k(drivers, &f, &count);
			break;
		case 'x':
			x(drivers, &count);
			break;
		case 'p':
			p(drivers, &count);
			break;
		case 'v':
			v(drivers, &count);
			break;
		case 'a':
			drivers = a(drivers, &count);
			break;
		case 'c':
			drivers = n(drivers, &count);
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}