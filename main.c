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
	void *ndPtr; //void pointer for linked list node
	

	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r"); 
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while (fgetc(fp)!=EOF) /* read name, country, runtime and score*/ 
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		fscanf(fp, "%s %s %d %f",&name,&country,&runTime,&score);
		mvInfo=mv_genMvInfo(name, score, runTime, country);
		list_addTail(mvInfo, list);
		mv_print(mvInfo);
		
	}
	printf("Reading the data files\n");
	printf("read done! %d items are read\n\n",list_len(list));

	//1.4 FILE close
	fclose(fp);
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("------------------Menu------------------\n");
		printf("1. print all the movies in the list \n2. search for specific country movies \n3. search for specific runtime movies \n");
		printf("4. search for specific score movies \n5. exit\n");
		printf("------------------Menu------------------\n");
		printf("select an option : ");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n");
				printf("-------------------------------------------\n");
				
				ndPtr = list;
				while ( list_isEndNode(ndPtr) == 0) /* repeat until the ndPtr points to the end node */
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr=list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo=list_getNdObj(ndPtr);
					//print the contents of the mvInfo
					mv_print(mvInfo);
				}
				
				break;
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				printf("\nsearching for specific country movies..... \n\n\n");
				ndPtr = list;
					while ( list_isEndNode(ndPtr) == 0)/* repeat until the ndPtr points to the end node */
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					char input;
					
					//ndPtr = the next node of the ndPtr;
					ndPtr=list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo=list_getNdObj(ndPtr);
					
					//if the input country matches to the country of the movie,
					printf("input a country to find: ");
					scanf("%s",&input);
					list_srchNd(int (*matchFunc)(void* obj, void* cond), void* cond, void* list);
					
					
					//then print the contents of the mvInfo
					mv_print(mvInfo);
				}
				
				break;
				
		
		
			default:
				printf("wrong command! input again\n");
				break;
		}
	}
	
	return 0;
}
