#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable

	typedef struct movInfo {
		char name[100];
		float score;
		int runTime;
		char madeIn[10];
	} movInfo_t;

	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r"); 
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while ( 1 )/* read name, country, runtime and score*/
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		
		mv_genMvInfo(name, score, runTime, country);
		cnt=fscanf(fp, "%c %c %d %f", name, country, runTime, score);
			if(cnt==EOF)
				break;
		
		printf("%c %c %d %f", name, country, runTime, score);
	
		list_addTail(mvInfo, list);
	}

	//1.4 FILE close
		fclose(fp);
	//2. program start
	while(exit_flag == 0)
	{	
		//2.1 print menu message and get input option
		printf("------------------Menu------------------\n");
		printf("1. print all the movies in the list \n2. search for specific country movies \n3. search for specific runtime movies n\4. search for specific score movies \n5. exit\n ");
		printf("select an option : ");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("-------------------------------------------\n");
				
				repFunc = mv_printAll;
				arg = NULL;
				break;
				
			case 2: //print movies of specific country
				printf("\nsearching for specific country movies..... \n\n\n");
				break;
				
			case 3: //print movies with long runtime
				printf("\nsearching for specific runtime movies..... \n\n\n");

				break;
				
			case 4: //print movies with high score
				printf("\nsearch for specific score movies..... \n\n\n");
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		//2.3 print number of movies
	}
	
	return 0;
}