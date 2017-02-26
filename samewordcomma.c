#include <stdio.h>
#include<string.h>


/*
find if same word exist across comma separator
Hello world,world should print 1
but Hello world,small should print 0

*/

char s[]="Hello world,world"; 


int main()
{
 
    char*found;
    char*next;
    found=strchr(s,',');
    *found='\0';
    next=found+1;
    
    while(*(found--)!=' ');
    found=found+2;
    
    if(strcmp(found,next))
    printf("0");
    else
    printf("1");

    
}

