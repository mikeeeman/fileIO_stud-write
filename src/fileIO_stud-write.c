/*

 * fileIO_stud-write.c
 *
 *  Created on: 04.04.2016
 *      Author: mcmey
 */

#include <stdio.h>
#define SIZE 10
int main(void)
{
	setbuf(stdout, NULL);

	struct STUDENT
	{
		char name[30];
		int grade;
	};
	int studnNum = 0;
	FILE *fp;


	printf("Enter number of students: ");
	scanf("%d", &studnNum);

	struct STUDENT class[studnNum];


	int cnt = 0;
	for(cnt = 0 ; cnt < studnNum ; cnt++)
	{
		printf("Enter Name for Student Nbr %d: ", cnt+1);
		scanf("%s", class[cnt].name);
		printf("Enter grade for Student Nbr %d: ", cnt+1);
		scanf("%d", &class[cnt].grade);
	}

	if((fp = fopen("list.txt", "w")) == NULL)
		{
			fprintf(stderr, "Error writing file");
			return -1;
		}
	if(fwrite(class, sizeof(class), 1, fp) != 1)
		{
			fprintf(stderr, "Error writing file.");
			return -1;
		}
		fclose(fp);







	return 0;
}

