#include<stdio.h>
#include<string.h>
#include"server.h"                         /*user defined header file which contains all the prototypes of the functions used in 												this program*/ 


int main(int argc, char **argv)           /*command line arguments arc----> stores number of arguments passes and 
												argue--->stores pointers of all the arguments*/ 
{
int counter,res;                          //variable res is used to compare the stings
char arg[100];                            //array used to store all the command line arguments given  
while(argc>1)
{
	for(int i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
		arg[i]=*argv[i];					 //pointers stored into array 
	}
	if(strcmp(arg,"passwd")!=0)			 //comapring strings [we assume her the user to be the root user always]
	{
		//printf("function 1\n");		//statement used to check the flow of code into the block
		fun1();							//function call which mimics passwd command in linux 
		break;			
	}
	else
	{
		printf("ERROR:No Such Keyword Found");		//we should use passwd keyword to run this code as it is based to mimic it 
	}											  //if we don't use passwd and use something else this part of code is executed
}
return 0;
}


