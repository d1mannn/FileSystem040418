#include "Header.h"

void main()
{	
	setlocale(LC_ALL, "Rus");
	
	int task;
	printf("номер задания - ");
	scanf("%d", &task);
	switch (task)
	{
		case 1:
		{	
			FILE *file;
			char s[80];
			int n;
			if ((file = fopen("ClWork1.txt", "w")) == NULL)
			{
				printf("Ошибка! Выходим из файла\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("Введите строку и число: ");
				fscanf(stdin, "%s %d", s, &n); // считываем с клавиатуры если вместо stdin ставим file то будет считывать с файла

				fprintf(file, "# %d. %s", n, s);
			}
			int res = fclose(file);
			if (res == NULL)
			{
				printf("Поток закрыт\n");
			}
			else
			{
				printf("ERROR\n");
			}
			if ((file = fopen("ClWork1.txt", "r")) == NULL)
			{
				printf("Ошибка! Выходим из файла\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				char name[80];
				int i = 0;
				fscanf(file, "# %d. %s", &i, name); // считывает с файла по шаблону
				fprintf(stdout, "# %d. %s\n", i, name); // по шаблону выводи на экран
			}
			res = fclose(file);
			if (res == NULL)
			{
				printf("Поток закрыт\n");
			}
			else
			{
				printf("ERROR\n");
			}
		} break;

		case 2:
		{	
			getchar();
			FILE *file;
			char words[40];
			if ((file = fopen("part2", "a+")) == NULL)
			{
				fprintf(stdout, "Не удалось открыть файл\n");
				exit(1);
			}
			else
			{
				puts("Введите слова. Нажмите Enter");
				puts("в начале строки для завершения программы");
				while (gets_s(words) != NULL && words[0] != '\0')
				{	
					fprintf(file, "%s\n", words);
				}
				puts("Содержимое файла: ");
				rewind(file); // вернет указатель начала файла чтобы всегда читал сначала
				while (fscanf(file, "%s", words) == 1) // 
				{
					//puts(words); // puts добавляет enter при выводе на экран
					printf("%s ", words);
				}
				if (fclose(file) != 0)
				{
					fprintf(stderr, "Ошибка при закрытии файла\n"); // записывает в буффер что ошибка
				}
			}
		} break;

		case 3:
		{
			getchar();
			FILE *file;
			int t = 0;
			// КОГДА НЕ ЗНАЕШЬ ДЛИНЫ СТРОКИ В ФАЙЛЕ
			char buffer[10];
			char *input = NULL;
			size_t curLen = 0;
			while (fgets(buffer, sizeof(buffer), stdin) != 0)
			{
				size_t bufLen = strlen(buffer);
				char * extra = (char*)realloc(input, bufLen + curLen + 1);
				if (extra == NULL)
				{
					printf("ERROR---\n");
					break;
				}
				input = extra;
				strcpy(input + curLen, buffer); // справа копируется налево
				curLen += bufLen;
				t++;
				if (t > 3)
					break;
			}
			printf("%s [%d]", input, (int)strlen(input));
			free(input);
		} break;

		case 4:
		{
			FILE *file;
			double d = 12.23, newD;
			int i = 101, newI;
			long l = 123879L, newL; // когда тип лонг пишет L  в конце
			if ((file = fopen("case4", "wb+")) == NULL)
			{
				printf("Ошибка\n");
				exit(1);
			}
			else
			{
				fwrite(&d, sizeof(double), 1, file);
				fwrite(&i, sizeof(int), 1, file);
				fwrite(&l, sizeof(long), 1, file);

				rewind(file); // перекидывает в начало файла после записи выше
				fread(&newD, sizeof(double), 1, file);
				fread(&newI, sizeof(int), 1, file);
				fread(&newL, sizeof(long), 1, file);

				printf("%lf - %d - %d\n", newD, newL, newI);
				fclose(file);
			}
			
		} break;
	}
	
	
}
		