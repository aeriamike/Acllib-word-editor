#include "acllib.h"
#define MLEN 100

int len = 0;
char str[MLEN];
int x0 = 0;
int y0 = 16;
int flag = 0;

void charEvent(char c)
{	
	int x_move = 9;
	/*
    if(len+1>=MLEN)
    {
        memset(str,0,sizeof(str));
        len = 0;
    }
    */
    
    if (flag==0){
    	
		if(c!=8 ){
			
  		printf("the location of x0/9 is: %d\n", (x0/9));
  		printf("the len of string is: %d\n", len);
  		
  		if((x0/9)==len){
  			str[x0/9] = c;
		  	++len;
		  }else{
		  	len++;
		  	int pos = len;
		  	while(pos>=(x0/9)){
		  		str[pos]=str[pos-1];
		  		--pos;
			  }
		  	str[x0/9]=c;
		  }
		  
   		beginPaint();

    	setTextSize(16);
    	paintText(0,16,str);
	
    	endPaint();
	}
    
    }
    
    printf("the len is: %d\n",len);
    printf("str[len-1] is: %c\n",str[len-1]);
    printf("str[len-2] is: %c\n",str[len-2]);
    printf("str[len-3] is: %c\n",str[len-3]);
    printf("c is: %c\n",c);
    printf("\n");
	
	if(c!=8){
		x0=x0+x_move;
		setCaretPos(x0,16);
    	showCaret();  
	}else{
		setCaretPos(x0,16);
    	showCaret(); 
	}
	

   int aa=0;
   if(c=='\r' && flag==0){
   		printf("The final string of character is: ");
   	//	printf("\n");
   	    printf("%s",str);
	    beginPaint();
   		hideCaret();
   		endPaint();
	   flag=1;
	   printf("\n");
	   printf("End of the program. ");
   }
  
  
   
}

void keyEvent(int key, int event) {

    if(event==0){
		if(key==VK_LEFT){
			if(x0>0){
				x0=x0-9;
				setCaretPos(x0,16);
				
				printf("the left location is: %c\n", str[(x0/9)-1]);
				printf("the right location is: %c\n", str[(x0/9)]);
					printf("The left len is: %d\n", x0/9-1);
					printf("The right len is: %d\n", x0/9);
				
				
			}
			
		}else if(key==VK_RIGHT){
			if(x0<len*9){
				x0=x0+9;
				setCaretPos(x0,16);
				
				printf("\n");
				printf("the left location is: %c\n", str[(x0/9)-1]);
				printf("the right location is: %c\n", str[(x0/9)]);
				printf("\n");
					printf("The left len is: %d\n", x0/9-1);
					printf("The right len is: %d\n", x0/9);
			
			}
			
		}
		else if(key==VK_DELETE){
				if(str[x0/9]!='\0'){
					printf("delete\n");
					printf("about to be deleted is: %c\n", str[(x0/9)]);
					
					int del=x0/9;
					int len_a = strlen(str);
					while (del-1<len_a-1){
						str[del]=str[del+1];
						printf("str[del] is: %c\n", str[del]);
						del++;
					}
					--len;

					printf("the len is: %d\n",len);
					printf("the current location (right) is: %c\n",str[len-1] );
					beginPaint();
					//clearDevice();
					setTextSize(16);
					paintText(0,16,str);
					endPaint();
					
				}
	
					
				}
				
			
		else if(key==VK_BACK){
					if(len>0 && x0>0){
					printf("backspace\n");
					printf("about to be backspaced is: %c\n", str[(x0/9)-1]);
					
					int back=x0/9;
					int len_a = strlen(str);
					while (back-1<=len_a-1){
						
						 if(back!=len_a-1){
							printf("before: back-1 = %c and back: %c\n", str[back-1], str[back]);
						
							str[back-1]=str[back];
	
							printf("after: back-1 = %c and back: %c\n", str[back-1], str[back]);
						}else{
							
							printf("before: back-1 = %c and last: %c\n", str[back-1], str[back]);
						
							str[back-1]=str[back];
							str[back]='\0';
	
							printf("after: back-1 = %c and last: %c\n", str[back-1], str[back]);
						}
						
						back++;			
					
					}
					
					/*
					printf("the left location is: %c\n", str[(x0/9)-1]);
					printf("the right location is: %c\n", str[(x0/9)]);
					printf("The left len is: %d\n", x0/9-1);
					printf("The right len is: %d\n", x0/9);
					*/
					
					printf("the current location (left) is: %c\n",str[len] );
					--len;
					x0=x0-9;
					beginPaint();
				//	clearDevice();
					setTextSize(16);
					paintText(0,16,str);
					endPaint();
					}
					
		}else{
					setCaretSize(1,16);
					printf("\n");
					printf("x0 is: %d\n", x0); 
					printf("\n");
					showCaret();
						}
					
				}
				
			
	
	}


int Setup()
{
    initWindow("",DEFAULT,DEFAULT,800,600);
	initConsole();
	
    registerCharEvent(charEvent);
    registerKeyboardEvent(keyEvent);

    return 0;
}



