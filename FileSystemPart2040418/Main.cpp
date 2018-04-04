#include "Header.h"

void main()
{	
	setlocale(LC_ALL, "Rus");
	
	int task;
	printf("����� ������� - ");
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
				printf("������! ������� �� �����\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("������� ������ � �����: ");
				fscanf(stdin, "%s %d", s, &n); // ��������� � ���������� ���� ������ stdin ������ file �� ����� ��������� � �����

				fprintf(file, "# %d. %s", n, s);
			}
			int res = fclose(file);
			if (res == NULL)
			{
				printf("����� ������\n");
			}
			else
			{
				printf("ERROR\n");
			}
			if ((file = fopen("ClWork1.txt", "r")) == NULL)
			{
				printf("������! ������� �� �����\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				char name[80];
				int i = 0;
				fscanf(file, "# %d. %s", &i, name); // ��������� � ����� �� �������
				fprintf(stdout, "# %d. %s\n", i, name); // �� ������� ������ �� �����
			}
			res = fclose(file);
			if (res == NULL)
			{
				printf("����� ������\n");
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
				fprintf(stdout, "�� ������� ������� ����\n");
				exit(1);
			}
			else
			{
				puts("������� �����. ������� Enter");
				puts("� ������ ������ ��� ���������� ���������");
				while (gets_s(words) != NULL && words[0] != '\0')
				{	
					fprintf(file, "%s\n", words);
				}
				puts("���������� �����: ");
				rewind(file); // ������ ��������� ������ ����� ����� ������ ����� �������
				while (fscanf(file, "%s", words) == 1) // 
				{
					//puts(words); // puts ��������� enter ��� ������ �� �����
					printf("%s ", words);
				}
				if (fclose(file) != 0)
				{
					fprintf(stderr, "������ ��� �������� �����\n"); // ���������� � ������ ��� ������
				}
			}
		} break;

		case 3:
		{
			getchar();
			FILE *file;
			int t = 0;
			// ����� �� ������ ����� ������ � �����
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
				strcpy(input + curLen, buffer); // ������ ���������� ������
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
			long l = 123879L, newL; // ����� ��� ���� ����� L  � �����
			if ((file = fopen("case4", "wb+")) == NULL)
			{
				printf("������\n");
				exit(1);
			}
			else
			{
				fwrite(&d, sizeof(double), 1, file);
				fwrite(&i, sizeof(int), 1, file);
				fwrite(&l, sizeof(long), 1, file);

				rewind(file); // ������������ � ������ ����� ����� ������ ����
				fread(&newD, sizeof(double), 1, file);
				fread(&newI, sizeof(int), 1, file);
				fread(&newL, sizeof(long), 1, file);

				printf("%lf - %d - %d\n", newD, newL, newI);
				fclose(file);
			}
			
		} break;
	}
	
	
}
		