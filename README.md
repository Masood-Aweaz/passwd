# passwd
Mimicking passwd command on linux

A program in C to mimic the “passwd” command on Linux. This command will help the user to change the password. The encryption and decryption of the password is part of this project.


Steps to execute and flow of code:

1.We should use the command <make -f make.mk> to run the make.mk file which links both .c files I.e.,(main.c and fun.c) and one .h file i.e., (server.h).
  
2.Then use the command ./a.out passwd this command uses concept of command line argument using ‘passwd’ as the argument passed.Assuming that the user is always the root user.
  
3.Passing this argument invokes an if condition in the main function which contains a function call fun1() 
fun1() is a function which helps the user to change his password. 
  
4.The function body contains two file pointers to open the file password.txt (assuming it as a shadow file which stores the password in encrypted form).
  
5.I have used the basic file handling and string handling operations to do the specific task.
  
6.I have used different arrays to store old Password , new Password and confirmation password.
  
7.Once you enter the function it asks you to enter the old or existing Password. It checks the entered password and compares it with the password stored in the shadow file after decrypting it.
  
8.If they match then you are allowed to generate a new password and confirm the password.
  
9.When you enter tow different passwords when prompted in new password and confirmation Password it takes u out of the function popping up an error that passwords entered to change do not match.
  
10.When you enter the new password correctly it gets encrypted and gets stored in the shadow file by over writing the existing password.
This is all how the code functions.

The last password stored is masood1222 use this to change the password.
