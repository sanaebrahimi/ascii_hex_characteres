#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

char *IntToString(int input){
	char digits[4];
	char *str=malloc(5*sizeof(char));
	
	if (input >= 100){
		digits[2] = (input % 10)+ '0';
		input /= 10;
		digits[1] = (input % 10)+ '0';
		input /= 10;
		digits[0] = (input % 10)+ '0';
		input /= 10;
		digits[3] ='\0';
	}
	else if(input >=10){
		digits[1] = (input % 10)+ '0';
		input /= 10;
		digits[0] =(input % 10)+ '0';
		input /= 10;
		digits[2] ='\0';
	}
	else{
		digits[1] = (input+ '0');
		digits[0] ='0';
		digits[2]='\0';
		
	}
	strcat(str,digits);
	return str;
	
		
}
	
char *IntToBinary(int input){
	char digits[8]={0};
	char *str=malloc(9*sizeof(char));
	digits[7]='\0';
	int i = 6;

	//int i = 1;
	if (input== 0){
		str[0] = '0';
		str[1] = '0';
		str[2] = '0';
		str[3] = '0';
		str[4] = '0';
		str[5] = '0';
		str[6] = '0';
		str[7] = '\0';
		return str;
	} 
	while(input !=0){
		digits[i] =(input%2) +'0';
		input /= 2;
		i--;

	}
	for(int k= i; k>=0;k--){
		digits[k] = '0';
	}

		
	strcat(str,digits);
	return str;
	
		
}
char *IntToOctal(int input){
	char digits[4]={0};
	char *str=malloc(5*sizeof(char));
	//digit[3] ='\0';

	if (input > 56){

		digits[2] = (input % 8)+ '0';
		input /= 8;
		digits[1] = (input % 8)+ '0';
		input /= 8;
		digits[0] = (input % 8)+ '0';
		input /= 8;
		digits[3] ='\0';
	}
	else if (input >7){
		digits[2] = (input % 8)+ '0';
		input /= 8;
		digits[1] = (input % 8)+ '0';
		input /= 8;
		digits[0] = '0';
		digits[3] ='\0';
	}
	else{
		digits[2] =(input % 8) +'0';
		input /= 8;
		digits[1] = '0';
		digits[0]= '0';
		digits[3] ='\0';
	}
	strcat(str,digits);
	return str;
	
		
}
	
char *IntToHex(int input){
	char digits[3]={0};
	char *str=malloc(4*sizeof(char));
	digits[2]='\0';
	int i = 1;
	if (input== 0){
		str[0] = '0';
		str[1] = '\0';
		return str;
	} 


	while(input !=0){
		if (input%16 == 10){
			digits[i] ='A';
		}
		else if (input%16 == 11){
			digits[i] ='B';
		}
		else if (input%16 == 12){
			digits[i] ='C';
		}
		else if (input%16 == 13){
			digits[i] ='D';
		}
		else if (input%16 == 14){
			digits[i] ='E';
		}
		else if (input%16 == 15){
			digits[i] ='F';
		}
		else{

			digits[i] =(input%16) +'0';
		}
		input /= 16;
		i--;

	}
	for(int j=i; j>=0;j--){
		
		digits[j] = '0';

	
	}
	strcat(str, digits);
	return str;
}

int main(int argc, char *argv[])
{
//	printf("%s\n",IntToHex(168));
//	printf("%s\n",IntToBinary(54));
  /*if (argc < 2) {
    printf("Usage: %s one of the destination file or source file is missing\n", argv[0]);
    return 0;
  }*/
	
     
    char msg[256] ;
    for(int row =0; row<32; row++){
	char str[100]={0};
    	for(int i=row; i<128;i+=32){
	
        	char tmp = i;
		
		msg[0]=0;
		char *num;
		if (argc <2){
			num = IntToString(i);
		}
		else{
			if(!strcmp(argv[1],"-h")){
				num = IntToHex(i);
			}
			else if( !strcmp(argv[1],"-b")){
				num = IntToBinary(i); 
			}
			else if( !strcmp(argv[1],"-o")){
				num = IntToOctal(i); 
			}
			else{
				return 0;
			}
		}
		//msg[1] = ':';
		strcat(msg,num);
		int n = strlen(num);
		msg[n]= ':';
		msg[n+1]= '\'';
		msg[n+2]=(isprint(tmp)) ? tmp : '.';
		msg[n+3] = '\'';
		msg[n+4]='\0';
		if( i<96){
			strcat(msg,"\t");
		}
		strcat(str, msg);
		free(num);
	}
        write(STDOUT_FILENO,str,strlen(str));
        write(STDOUT_FILENO,"\n",1);
	
    }

  return 0;
  }
/*  int i;
  printf("argc = %d\n", argc);
  for(i=0; i < argc; i++) {
    printf("argv[%d] = \"%s\"\n", i, argv[i]);
  }
  printf("argv[%d] = NULL\n", i);

  return 0;
}*/
