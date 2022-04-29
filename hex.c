#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *IntToBinary(int input){
	char digits[8]={0};
	char *str=malloc(9*sizeof(char));
	digits[7]='\0';
	int i = 6;

	while(input !=0){
		digits[i] =(input%2) +'0';
		input /= 2;
		i--;

	}
	for(int i=0; i<7;i++){
		char tmp = digits[7-i];
		digits[i] = tmp;

	}
	strcat(str,digits);
	return str;
	
		
}

	
char *IntToHex(int input){
	char digits[3]={0};
	char *str=malloc(4*sizeof(char));
	digits[2]='\0';
	int i = 1;
	if(input == 0){
		str[0] ='0';
		str[1] = '0';
		str[2] = '\0';
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
	if(i==0){
		digits[0] ='0';
	}
	/*for(int i=0; i<3;i++){
		char tmp = digits[2-i];
		digits[2-i] = digits[i];
		digits[i] = tmp;

	
	}*/
	strcat(str, digits);
	return str;
}
int main(int argc, char *argv[]){
  char s[16]={0};
  int fd;
  int rv;
  int total = 0;
  if (argc <2){
  	fd = 0;
  }
  else{
	fd = open(argv[1], O_RDONLY);
  }

  while((rv=read(fd,s,16))>0){
   	s[rv]=0;
  	//printf("rv: %d\n",rv);
	char offset[9]={'0'};
	char msg[256]={0};
	offset[8] = '\0';
	/*for (int i=0; i<8; i++){
		offset[i] = '0';
	}*/
	char *data = IntToHex(total);
  	//printf("offset: %s\n",offset);
  	//printf("data: %s\n",data);
	int j =0;
	for(int k=0; k<8;k++){
		//char *offset;
		if (k >= (8-strlen(data))){
			offset[k]= data[j];
			j++;
		}
		else{
			offset[k] = '0';
			
		}
	}
 // 	printf("offset: %s\n",offset);
	strcat(msg,offset);
	strcat(msg,":");
	strcat(msg," ");
	for(int i=0;i<sizeof(s);i++){
		int j = s[i];
		char *num = IntToHex(j);
		strcat(msg, num);
		strcat(msg, " ");	
	}
	
       // write(STDOUT_FILENO,msg,strlen(msg));
	strcat(msg, " ");
	strcat(msg, ":");
        write(STDOUT_FILENO,msg,strlen(msg));
	for(int i=0; i<16; i++){
		if(isprint(s[i])){
        		write(STDOUT_FILENO,&s[i], 1);
			}
		else{
			
        		write(STDOUT_FILENO,".",1);
		}
	}

	total += rv;
        write(STDOUT_FILENO,"\n",1);
		
  }
  return 0;
 }
