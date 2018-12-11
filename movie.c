#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{
	char name[200];
	float score;
	int runTime;
	char madeIn[100];
} movInfo_t;


void* mv_genMvInfo(char *name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	
	//allocate memory and set the member variables
	mvPtr=(movInfo_t*)malloc(sizeof(movInfo_t));
	
	strcpy(mvPtr->name,name);//문자열 복사  
	mvPtr->name[200]=*name;//name 설정  
	mvPtr->score=score;//score 설정  
	mvPtr->runTime=runTime;	//runTime 설정  
	
	strcpy(mvPtr->madeIn,country);//문자열 복사  
	mvPtr->madeIn[10]=*country;//country 설정  
	
	return (void*)mvPtr;
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	return  mvPtr->score;
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	return mvPtr->runTime;
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	return (void*)mvPtr->name;
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	return (void*)mvPtr->madeIn;
}


