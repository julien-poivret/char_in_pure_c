#include<stdio.h> 
#include<stdlib.h> 
#include<stdint.h> 

/*function protype for compiler*/
void my_string_cpy(char* input_txt, char* memory,int len);

int main(int argc,char** argv){

	/*
	   all about string and char in pure c.
	   as reminder when you don't code every days.
	 */

	char buffer[9] = {0}; //init the 9 bytes at zero
	uint8_t i = 0;
	while(i<8){
		*(buffer+i) = '-'; 
		i++;
	}
	printf("%s\n",buffer);

	char buffer_type2[8][20]={0};// init every thing at zero

	/* set char or string */
	buffer_type2[2][4] = 'y';
	char txt[8] = "lithium";
	char txt2[20] = "diamond_battery";

	/* 
	   like strcpy(); from string.h
	   with a double sweep and raw pointers access.
	 */

	i = 0;
	uint8_t j = 0;
	while(j<20){
		*(*(buffer_type2+1)+i)=*(txt+i);
		*(*(buffer_type2+3)+j)=*(txt2+j);
		i++;
		j++;
	}

	printf("\33[35m-->%c\n",buffer_type2[2][4]); // print one char
	printf("\33[33m-->%s\n",buffer_type2[1]);// print the whole string (ended by 0 see in gdb)
	printf("\33[34m-->%s\n",buffer_type2[3]);
        
        /* the same with custom c function... */
        char buffer3[24] = {0};
        my_string_cpy("home_sweet_home_my_home",buffer3,24);
	printf("\33[32m-->%s\n",buffer3);
        
        // with memory heap allocation and initialization at zero.
        char* buf  = calloc(6,sizeof(char));
        my_string_cpy("Bizon",buf,5);
	printf("-->\33[31m%s\33[0m\n",buf);
        free(buf); // free the ram

}

/* fill a memory shunk with bytes */
void my_string_cpy(char* input_txt, char* memory,int len){
	int ct = 0;
		while(ct<len){
			memory[ct] = input_txt[ct];
                        ct++;
		}
}
