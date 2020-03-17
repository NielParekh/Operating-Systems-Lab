#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h>  
#include<string.h> 
#include<stdlib.h>
int main(int argc,char *argv[]) 
{ 
	if ( argc <4 && strcmp(argv[1],"-b")!=0) {
		printf("Inadequate number of arguments\n");
		return 0;
	}
	
	if (strcmp(argv[1],"-f")==0){
		int fd = open(argv[2] , O_RDONLY | O_CREAT);
		char *buffer = (char *) calloc(250, sizeof(char));
		int sz = read(fd, buffer, 100); 
		printf("Source file contains :\n%s\n",buffer);
		int fd1 = open(argv[3] , O_WRONLY | O_CREAT);
		sz = write (fd1 , buffer , strlen(buffer));
		printf("\n\nFILE COPIED\n\n");}

	else if (strcmp(argv[1],"-i")==0){
		int fd = open(argv[2] , O_RDONLY | O_CREAT);
		char *buffer = (char *) calloc(250, sizeof(char));
		int sz = read(fd, buffer, 100); 
		printf("Source file contains :\n%s\n",buffer);
		printf("Are you sure you want to override the destination file ?\n");
		char ch;
		scanf("%c",&ch);
		if(ch=='y' || ch == 'Y'){
			int fd1 = open(argv[3] , O_WRONLY | O_CREAT);
			sz = write (fd1 , buffer , strlen(buffer));
			printf("\n\nFILE COPIED\n\n");}
		else{
			printf("\n\nCopying terminated\n\n");
			return 0;}}

	else if (strcmp(argv[1],"-b")==0){
		if(argc > 3){
			printf("Only one argument is required\n");
			return 0;}
		int fd = open(argv[2] , O_RDONLY | O_CREAT);
		char *buffer = (char *) calloc(250, sizeof(char));
		int sz = read(fd, buffer, 100); 
		printf("Source file contains :\n %s\n",buffer);
		int fd1 = open("backup" , O_WRONLY | O_CREAT);
		sz = write (fd1 , buffer , strlen(buffer));
		printf("\n\nBACKUP CREATED\n\n");}

	else if (strcmp(argv[1],"-v")==0){
		int fd = open(argv[2] , O_RDONLY | O_CREAT);
		char *buffer = (char *) calloc(250, sizeof(char));
		int sz = read(fd, buffer, 100); 
		int fd1 = open(argv[3] , O_WRONLY | O_CREAT);
		sz = write (fd1 , buffer , strlen(buffer));
		printf("'%s' -> '%s'\n",argv[2],argv[3]);}


	else	
		printf("\nEnter a valid option\n");
}	
