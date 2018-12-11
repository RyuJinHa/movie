#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[100]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node
	
	int count;
	char inputCountry[100];
	int inputRuntime;
	float inputScore;
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r"); 
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while (fgetc(fp)!=EOF) /* read name, country, runtime and score*/ 
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		fscanf(fp,"%s %s %d %f",&name,&country,&runTime,&score);
		mvInfo=mv_genMvInfo(name, score, runTime, country);
		list_addTail(mvInfo, list);//list 만들기  
		
	}
	printf("Reading the data files\n");
	printf("read done! %d items are read\n\n",list_len(list));//영화 개수 알려주기  

	//1.4 FILE close
	fclose(fp);
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("---------------------Menu---------------------\n");
		printf("1. print all the movies in the list \n2. search for specific country movies \n3. search for specific runtime movies \n");
		printf("4. search for specific score movies \n5. exit\n");
		printf("---------------------Menu---------------------\n");
		printf("select an option : ");
		scanf("%d",&option);
	
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n");
				printf("----------------------------------------------\n");
				
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
				count=0;
				ndPtr = list;
				printf("--input a country to find: ");
				scanf("%s",&inputCountry);//사용자로부터 원하는 값 받기  
				printf("----------------------------------------------\n");	
				while ( list_isEndNode(ndPtr) == 0)/* repeat until the ndPtr points to the end node */
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr=list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo=list_getNdObj(ndPtr);
					//if the input country matches to the country of the movie,
					if(strcmp(mv_getCountry(mvInfo), inputCountry)==0)
					{
						mv_print(mvInfo);
						printf("----------------------------------------------\n");
						count++;//영화 개수 세기  
					}
					//then print the contents of the mvInfo
				}
				if(count==0)//사용자가 원하는 영화가 없을 경우  
				{
					printf("there is no movie that you find\n");
				}
				printf("\n  -totally %d items are read!\n\n",count++);//영화 개수 print  
				
				break;
				
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				count=0;	
				ndPtr = list;
				printf("--input a runtime to find: ");
				scanf("%d",&inputRuntime);
				printf("----------------------------------------------\n");	
				while ( list_isEndNode(ndPtr) == 0/* repeat until the ndPtr points to the end node */)
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr=list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo=list_getNdObj(ndPtr);
					//if the input runtime is lower than the runtime of the movie,
					mv_getRunTime(mvInfo);
					if(mv_getRunTime(mvInfo)>inputRuntime)
					{
						mv_print(mvInfo);
						printf("----------------------------------------------\n");
						count++;
					}
					//then print the contents of the mvInfo
				}
				
				if(count==0)
				{
					printf("there is no movie that you find\n");
				}
				
				printf(" \n -totally %d items are read!\n\n",count);
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				count=0;
				ndPtr = list;
				printf("--input a score to find: ");
				scanf("%f",&inputScore);
				printf("----------------------------------------------\n");
				
				while (list_isEndNode(ndPtr) == 0/* repeat until the ndPtr points to the end node */)
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr=list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo=list_getNdObj(ndPtr);
					//if the input score is lower than the score of the movie,
					mv_getScore(mvInfo);
					if(mv_getScore(mvInfo)>inputScore)
					{
						mv_print(mvInfo);
						printf("----------------------------------------------\n");
						count++;
					}
					//then print the contents of the mvInfo
				}
				
				if(count==0)
				{
					printf("there is no movie that you find\n");
				}
				
				printf("\n  -totally %d items are read!\n\n",	count++);
				break;
				
			case 5:
				printf("Bye Bye!\n\n");
				exit_flag = 1;
				break;	
				
			
		}
	}
	free(ndPtr);//메모리 정리  
	return 0;
}
