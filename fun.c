#include<stdio.h>
#include<string.h>
#include"server.h"
void fun1()
{
	FILE *fr,*fw;				//file pointers fr-->pointer to read file fw-->pointer to write in a file 
	int len_old,pass,len_conf,len_new,len_temp1,len_save,j;		//len_arrayname
	char old[25],save[25],new[25],conf[25],temp[25],temp1[25],temps;
	fr=fopen("password.txt","r+");			//password.txt is assumed to be a shadow file which holds the password in encrypted form
	printf("enter the current password");
	fgets(old,25,stdin);
	len_old=strlen(old);
	old[len_old-1]='\0';				//last character of the string is assigned NULL to terminate the string as we don't wanna lose or get our password changed
	fgets(save,25,fr);
	len_save=strlen(save);
	for(j=0;(j<len_save && save[j]!='\0');j++)		//for loop for decryption of encrypted and saved password 
	{
		temp1[j]=save[j]-3;				// simple decryption 
	}
	temp1[j]='\0';					//string termination statement
	len_temp1=strlen(temp1);
	
	fclose(fr);
	int res=strcmp(temp1,old);			//comparing the old password and entered password to grant access to change if they are similar 
	//printf("old = %s\tsave = %s\n",old,save); //these lines are used in the backend to check the flow of instructions and changes into the file and effect of 
	//printf("temp1 = %s\n",temp1);			   //it on the variables  
	//printf("res=%d",res);				   //you can just remove them from comments to understand the logic and flow
	if(res==0)						//when tow strings are similar they return int 0 when compared
	{
		fw=fopen("password.txt","w+");		//opening the file in write mode to erase the data and enter/write new password data into it
		printf("Enter new password:");
		fgets(new,25,stdin);				//asking for new password
		printf("Confirm new password:");
		fgets(conf,25,stdin);			//confirmation of new password 
		len_new=strlen(new);
		new[len_new-1]='\0';
		len_conf=strlen(conf);
		conf[len_conf-1]='\0';			//we use enter after typing password on the terminal so we got to negate that '\n' from our password
		pass=strcmp(new,conf);			//pass variable to compare new password and confirmation password 
		//printf("new = %s\tconf = %s\n",new,conf);
		//printf("%d\n",pass);
		if(pass==0)
		{
			for(int k=0;(k<len_new && new[k]!='\0');k++)		//loop for encryption
			{
				temp[k]=new[k]+3;						//encryption logic 

			}
			temp[len_new-1]='\0';
			fputs(temp,fw);								//writing new password into the file in encrypted form 
			printf("Password changed successfully\n");
			fclose(fw);								//closing file to ensure that data is not lost
		}
		else
		{
			printf("Password entered for conformation doesn't match the new password\n");		//if passwords do not match 
			fputs(save,fw);														//then old password remains in its place 
			fclose(fw);
		}
		
	}
	else
	{
		printf("ERROR Old password entered is wrong\n");	//this block if user enters the wrong password he/she won't be allowed to change the password 
	}
}
	
