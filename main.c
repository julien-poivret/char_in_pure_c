#include<stdio.h> 
#include<stdlib.h> 
#include<stdint.h> 

/* Function protype for compiler */
void my_string_cpy(char* input_txt, char* memory,int len);

int main(int argc,char** argv){

	/*
	   All about string and char in pure c.
	   as reminder when you don't code every days.
	 */

	char buffer[9] = {0}; //Init the 9 bytes at zero
	uint8_t i = 0;
	while(i<9){ // Write the stack memory.
		*(buffer+i) = '-'; 
		i++;
	}
	printf("%s\n",buffer);

	char buffer_type2[8][20]={0};// Init every thing at zero.

	/* Set char or string to copy from as source exemple memory */
	buffer_type2[2][4] = 'y';
	char txt[8] = "lithium";
	char txt2[20] = "diamond_battery"; 

	/* 
	   Almost like strcpy(); from string.h
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
        /* 
          Every printf with "%s" will stop to write string on stdout (console) when a 0 (not a '0') will be rich in the buffer
          that why each string should contain one more dedicated byte for holding the zero value or 8 bits of memory space (1 bytes)
          ( as a stop to write bytes for stdout ).
        */
	printf("\33[35m-->%c\n",buffer_type2[2][4]); // Print only one char
	printf("\33[33m-->%s\n",buffer_type2[1]);// Print the whole string (ended by 0 see in gdb)
	printf("\33[34m-->%s\n",buffer_type2[3]);
        
        /* The same with a custom C function... */
        char buffer3[24] = {0}; //Stack memory to write init at zero (main scope)
        my_string_cpy("home_sweet_home_my_home",buffer3,24);// memory writing done.
	printf("\33[32m-->%s\n",buffer3);
        
        // With memory heap allocation (os space reservation on ram) and initialization to zero. with calloc
        char* buf  = calloc(6,sizeof(char));
        my_string_cpy("Bizon",buf,5); // "buf" heap pointer is then writed on a reserved space on the ram memory.
	printf("\33[31m-->%s\33[0m\n",buf); //Check.
        free(buf); // Simply free the ram with a syscall to the unix OS.
}

/* 
  Fill a memory chunk with input bytes 
  as c is a powerful and sharp language... the "len" value 
  prevent the program to write outside the memory of the targeted memory on ram.
  it's simple enough, and if it's done, no need of cumbersome additional measures.
*/
void my_string_cpy(char* input_txt, char* memory,int len){
	int ct = 0;
		while(ct<len){
			memory[ct] = input_txt[ct];
                        ct++;
		}
}
