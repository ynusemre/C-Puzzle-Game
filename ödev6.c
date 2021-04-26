#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*comment line 636 for better review*/
/*I used the last letter coordinate with the pointer to print the word large*/
/*The letter grows as the conditions in the main function are met*/
#define MAX_WORD   20
#define NUM_WORDS  10
char random_Character(){
    char ch = 'a' + (rand() % 26);
    return ch;
}
void puzzle_draft(char puzzle[20][20]){
	for(int i=0;i<20;i++){
    	for(int j=0;j<20;j++){
    		puzzle[i][j]=' ';
    	}
    }
}
void fill_space_puzzle(char puzzle[20][20]){
	for(int i=0;i<20;i++){
    	for(int j=0;j<20;j++){
    		if(puzzle[i][j]==' '){
    			puzzle[i][j]=random_Character();
    		}
    	}
    }
}
void puzzle_drawing(char puzzle[20][20]){
	int u=97;
	int l=1;
	char c;
	char numbers[20];

    printf("     ");
    for(int k=0;k<20;k++){
    	numbers[k]=l;
    	printf("%d ",numbers[k]);
		l++;
    }
    	printf("\n");
    	printf("     ");
    for(int k=0;k<20;k++){
    	printf("_ ");
    }
    printf("\n");
    for(int i=0;i<20;i++){
    	c=u;
    	printf("%c   |",c);
    	u++;
    	for(int j=0;j<20;j++){
    		printf("%c ",puzzle[i][j]);
    	}
    	printf("\n");
    }
    printf("\n");
}
void get_random_word_from_text(char word[MAX_WORD],char buffer[NUM_WORDS][MAX_WORD]){

	/* Open words file */
   	srand(time(NULL));
    FILE *fp = fopen("words.txt", "r");

    if (fp == NULL) {
        perror("Unable to locate word list");
        exit(EXIT_FAILURE);
    }
	/* Count words in file */
    while (!feof(fp)) {
        fgets(word,100,fp);
    }
      
  	for (int i = 0; i < 10; i++) {
       	fseek(fp,0,SEEK_SET);
        int sel = rand() % 100 + 1;
        for (int j = 0; j < sel; j++) {
            if (fgets(word,100, fp) == NULL) {
                printf("Error in fgets()");
            }
        }
        strcpy(buffer[i], word);
    }

     fclose(fp);
       
   
}
void left_to_right(int x,char puzzle[20][20],int *px,int *py){
	
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	int t=0,m=0;
		t=rand()%20;
	 	m=rand()%20;
     	z=(strlen(buffer[x])-2);
	
	 	int counter=0;
     	int temp_m=m;
     	int temp_t=t;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[t][m]!=' ' || temp_m+z>20){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            m++;
       	}
       	
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            t=rand()%20;
            m=rand()%20;
            temp_m=m; 
            temp_t=t;                               
        }                                                       
    }
    *px=t;                  
    *py=m;                    
    for(int j=0;j<z;j++){
     		puzzle[temp_t][temp_m]=buffer[x][j];
       		temp_m++;
       	}
       	
}
void right_to_left2(int x,char puzzle[20][20],int *cx,int *cy){
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	int c=0,d=0;
	
	 	c=rand()%20;
	 	d=rand()%20;
	 	
     	z=(strlen(buffer[x])-2);
       	
       	int counter=0;
     	int temp_d=d;
     	int temp_c=c;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[c][d]!=' ' || temp_d+z>20){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            (d)++;
                                         
        }
        
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            c=rand()%20;
            d=rand()%20;
            temp_d=d;
            temp_c=c;                                
        }                                                       
    }
    *cx=c;
    *cy=d;
      	
      	for(int j=z-1;j>=0;j--){
     		puzzle[temp_c][temp_d]=buffer[x][j];
       		temp_d++;
       	}
}
void right_to_left(int x,char puzzle[20][20],int *ax,int *ay){
	
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	int c=0,d=0; 
	
	 	c=rand()%20;
	 	d=rand()%20;
	 	
     	z=(strlen(buffer[x])-2);
       	
       	int counter=0;
     	int temp_d=d;
     	int temp_c=c;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[c][d]!=' ' || temp_d+z>20){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            (d)++;
                                         
        }
        
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            c=rand()%20;
            d=rand()%20;
            temp_d=d;
            temp_c=c;                                
        }                                                       
    }
    *ax=c;
    *ay=d;
      	
      	for(int j=z-1;j>=0;j--){
     		puzzle[temp_c][temp_d]=buffer[x][j];
       		temp_d++;
       	}
}
void up_to_down(int x,char puzzle[20][20],int *sx,int *sy){
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	int e=0,r=0;  
	
	 	e=rand()%20;
	 	r=rand()%20;
	 	
     	z=(strlen(buffer[x])-2);
       	 
       		 int counter=0;
     		int temp_e=e;
     		int temp_r=r;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[e][r]!=' ' || temp_e+z>20){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }

            (e)++;
                                         
        }
        
        if(counter==1){
            break;
        }

        if(counter==0){                        
            e=rand()%20;
            r=rand()%20;
            temp_e=e;
            temp_r=r;                                
        }                                                       
    }
    *sx=e;
    *sy=r;
      	for(int j=0;j<z;j++){
     		puzzle[temp_e][temp_r]=buffer[x][j];
       		temp_e++;
       	}
       	
}
void down_to_up2(int x,char puzzle[20][20],int *rx,int *ry){
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	
	int s=0,f=0;	
		
		s=rand()%20;
	 	f=rand()%20;
	 	
       	z=(strlen(buffer[x])-2);
       
       	int counter=0;
     	int temp_s=s;
     	int temp_f=f;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[s][f]!=' ' || temp_s+z>20){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            (s)++;
                                         
        }
        
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            s=rand()%20;
            f=rand()%20;
            temp_s=s;
            temp_f=f;                                
        }                                                       
    }
    *rx=s;
    *ry=f;

      	for(int j=z-1;j>=0;j--){
       		puzzle[temp_s][temp_f]=buffer[x][j];
       		temp_s++;
       	}
       
}
void down_to_up(int x,char puzzle[20][20],int *gx,int *gy){
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	
	int s=0,f=0;	
		
		s=rand()%20;
	 	f=rand()%20;
	 	
       	z=(strlen(buffer[x])-2);
       
       	int counter=0;
     	int temp_s=s;
     	int temp_f=f;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[s][f]!=' ' || temp_s+z>20){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            (s)++;
                                         
        }
        
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            s=rand()%20;
            f=rand()%20;
            temp_s=s;
            temp_f=f;                                
        }                                                       
    }
    *gx=s;
    *gy=f;

      	for(int j=z-1;j>=0;j--){
       		puzzle[temp_s][temp_f]=buffer[x][j];
       		temp_s++;
       	}
       
}
void left_down_cross(int x,char puzzle[20][20],int *ex,int *ey){
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
       	
	int v=0,w=0;
	
	 	v=rand()%20;
	 	w=rand()%20;
	 	
     	z=(strlen(buffer[x])-2);
       	 
       	int counter=0;
     	int temp_v=v;
     	int temp_w=w;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[v][w]!=' ' || temp_v+z>20 || puzzle[v][w]!=' '|| temp_w+z>20){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            (v)++;
            (w)++;
                                         
        }
        
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            v=rand()%20;
            w=rand()%20;
            temp_v=v;
            temp_w=w;                                
        }                                                       
    }
    *ex=v;
    *ey=w;
      	for(int j=0;j<z;j++){
     		puzzle[temp_v][temp_w]=buffer[x][j];
       		temp_v++;
       		temp_w++;
       	}
       
}
void left_up_cross(int x,char puzzle[20][20],int *ux,int *uy){
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	int a=0,g=0;
       	
	
	 	a=rand()%20;
	 	g=rand()%20;
	 	
     	z=(strlen(buffer[x])-2);
       	
       	int counter=0;
     	int temp_a=a;
     	int temp_g=g;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[a][g]!=' ' || temp_a+z>20 || puzzle[a][g]!=' '|| temp_g+z>20){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            (a)++;
            (g)++;
                                         
        }
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            a=rand()%20;
            g=rand()%20;
            temp_a=a;
            temp_g=g;                                
        }                                                       
    }
    *ux=a;
    *uy=g;
      	for(int j=z-1;j>=0;j--){
     		puzzle[temp_a][temp_g]=buffer[x][j];
       		temp_a++;
       		temp_g++;

       	}
       	
}

void right_down_cross(int x,char puzzle[20][20],int *kx,int *ky){
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	int p=0,u=0;
       
	
	 	p=rand()%20;
	 	u=rand()%20;
	 	
     	z=(strlen(buffer[x])-2);
       	
       	int counter=0;
     	int temp_p=p;
     	int temp_u=u;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[p][u]!=' ' || temp_p+z>20 || puzzle[p][u]!=' '|| temp_u-z<0){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            (p)++;
            (u)--;
                                         
        }
        
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            p=rand()%20;
            u=rand()%20;
            temp_p=p;
            temp_u=u;                                
        }                                                       
    }
    *kx=p;
    *ky=u;
      	for(int j=0;j<z;j++){
     		puzzle[temp_p][temp_u]=buffer[x][j];
       		temp_p++;
       		temp_u--;
       	}
       
}
void right_up_cross(int x,char puzzle[20][20],int *vx,int *vy){
	srand(time(NULL));
	char word[MAX_WORD];
	char buffer[NUM_WORDS][MAX_WORD];
	get_random_word_from_text(word,buffer);

	int z=0;
	int o=0,h=0;
       	
		
	 	o=rand()%20;
	 	h=rand()%20;
	 
		
     	z=(strlen(buffer[x])-2);
       	
      	int counter=0;
     	int temp_o=o;
     	int temp_h=h;
	 	
    while(1){
        for(int i=0;i<z;i++){
            if(puzzle[o][h]!=' ' || temp_o+z>20 || puzzle[o][h]!=' '|| temp_h-z<0){              
                counter=0;
                break;
            }
            else{
                counter=1;
            }
            (o)++;
            (h)--;
                                         
        }
        
        if(counter==1){
            break;
        }   
        if(counter==0){                        
            o=rand()%20;
            h=rand()%20;
            temp_o=o;
            temp_h=h;                                
        }                                                       
    }
	 *vx=o;
	 *vy=h;	
	 	
      	for(int j=z-1;j>=0;j--){
     		puzzle[temp_o][temp_h]=buffer[x][j];
       		temp_o++;
       		temp_h--;
       	}

}

int main(){	
	
    char word[MAX_WORD];
	char buffer[100][20];
	get_random_word_from_text(word,buffer);
	
	
	
	char puzzle[20][20];
	
	puzzle_draft(puzzle);
	
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,k=0,l=0,m=0,n=0,j=0,v=0,s=0,x=0,y=0,x8=0,y8=0,x9=0,y9=0;
	
	left_to_right(7,puzzle,&a,&b);
    right_to_left(6,puzzle,&c,&d);
    up_to_down(5,puzzle,&e,&f);
    down_to_up(4,puzzle,&g,&k);
    left_down_cross(3,puzzle,&l,&m);
    left_up_cross(2,puzzle,&n,&j);
    right_down_cross(1,puzzle,&v,&s);
    right_up_cross(0,puzzle,&x,&y);
    
    right_to_left2(8,puzzle,&x8,&y8);
    down_to_up2(9,puzzle,&x9,&y9);
	
    int l0=0,l1=0,l2=0,l3=0,l4=0,l5=0,l6=0,l7=0,l8=0,l9=0;
	int c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
	
	char co;
	int ch;
	char control[100];
	
	int w=1;

    int flag=0;
	//fill_space_puzzle(puzzle);
	while(flag!=1){
		int w=1;
		puzzle_drawing(puzzle);
		for (int i = 0; i < NUM_WORDS; i++) {
        	printf("%s", buffer[i]);
		}
		printf("\n");
		printf("Please enter the coordinate and the word:");
       	scanf(" %c",&co);
      	scanf(" %d",&ch);
      	scanf(" %s",control);
       
       	
		l0=(strlen(buffer[0])-2);
      	l1=(strlen(buffer[1])-2);
      	l2=(strlen(buffer[2])-2);
      	l3=(strlen(buffer[3])-2);
      	l4=(strlen(buffer[4])-2);
      	l5=(strlen(buffer[5])-2);
      	l6=(strlen(buffer[6])-2);
      	l7=(strlen(buffer[7])-2);
      	l8=(strlen(buffer[8])-2);
      	l9=(strlen(buffer[9])-2);
      	
      	
      		
      	if(co=='E'){
			printf("Goodby\n");
    		flag=1;
		}


      	else if(co==97+(x-1) && ch==y+2 ){
      		w=1;
      			
      	
      		for(int j=0;j<l0;j++){
      			if(control[j]!= buffer[0][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){
				x=x-l0;	
       			y=y+l0;
       		
       			for(int j=l0-1;j>=0;j--){
     				buffer[0][j]=buffer[0][j]-32;
       			}
     			for(int j=l0-1;j>=0;j--){
     				puzzle[x][y]=' ';
       				x++;
       				y--;
       			}
       			x=x-l0;	
       			y=y+l0;
       			for(int j=l0-1;j>=0;j--){
     				puzzle[x][y]=buffer[0][j];
       				x++;
       				y--;
       			}
       			c0=1;}
      		}	
			
		else if(co==97+v-l1 && ch==s+(l1+1) && w==1){
				w=1;
      			
      	
      		for(int j=0;j<l1;j++){
      			if(control[j]!= buffer[1][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){
				v=v-l1;
       			s=s+l1;
       		
       			for(int j=0;j<l1;j++){
     				buffer[1][j]=buffer[1][j]-32;
       			}
       			for(int j=0;j<l1;j++){
     				puzzle[v][s]=' ';
       				v++;
       				s--;
       			}
       			v=v-l1;
       			s=s+l1;
       			for(int j=0;j<l1;j++){
     				puzzle[v][s]=buffer[1][j];
       				v++;
       				s--;
       			}
       			c1=1;}
       		}

       		else if(co==97+n-1 && ch==j && w==1){
       			w=1;
      			
      	
      		for(int j=0;j<l2;j++){
      			if(control[j]!= buffer[2][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){
       			n=n-l2;
       			j=j-l2;
       		
       			for(int j=0;j<l2;j++){
     				buffer[2][j]=buffer[2][j]-32;
       			}
       			for(int i=l2-1;i>=0;i--){
     				puzzle[n][j]=' ';
       				n++;
       				j++;
       			}
       			n=n-l2;
       			j=j-l2;
       			for(int i=l2-1;i>=0;i--){
     				puzzle[n][j]=buffer[2][i];
       				n++;
       				j++;
       			}
       			c2=1;}
       		}
       		else if(co==97+(l-l3) && ch==m-(l3-1) && w==1){
       			w=1;
      			
      	
      		for(int j=0;j<l3;j++){
      			if(control[j]!= buffer[3][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){
       		l=l-l3;
       		m=m-l3;
       		
       		for(int j=0;j<l3;j++){
     			buffer[3][j]=buffer[3][j]-32;
       		}
       		for(int j=0;j<l3;j++){
     			puzzle[l][m]=' ';
       			l++;
       			m++;
       		}
       		l=l-l3;
       		m=m-l3;
       		for(int j=0;j<l3;j++){
     			puzzle[l][m]=buffer[3][j];
       			l++;
       			m++;
       		}
       		c3=1;}
       	}
       	else if(co==97+(g-1) && ch==k+1 && w==1 ){
       		w=1;
      			
      	
      		for(int j=0;j<l4;j++){
      			if(control[j]!= buffer[4][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){
       		
       		
       		g=g-l4;
       		for(int j=0;j<l4;j++){
     			buffer[4][j]=buffer[4][j]-32;
       		}
       		for(int j=l4-1;j>=0;j--){
     			puzzle[g][k]=' ';
       			g++;
       		}
       		g=g-l4;
       		for(int j=l4-1;j>=0;j--){
     			puzzle[g][k]=buffer[4][j];
       			g++;
       		}
       		c4=1;}
       	}
       		else if(co==97+(e-l5) && ch==f+1 && w==1 ){
       		w=1;
      			
      	
      		for(int j=0;j<l5;j++){
      			if(control[j]!= buffer[5][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){	
       		
       		
       		e=e-l5;
       		for(int j=0;j<l5;j++){
     			buffer[5][j]=buffer[5][j]-32;
       		}
       		for(int j=0;j<l5;j++){
     			puzzle[e][f]=' ';
       			e++;
       		}
       		e=e-l5;
       		for(int j=0;j<l5;j++){
     			puzzle[e][f]=buffer[5][j];
       			e++;
       		}
       		c5=1;}
       	}
       	 else if(co==97+c && ch==d && w==1){
       	 	w=1;
      			
      	
      		for(int j=0;j<l6;j++){
      			if(control[j]!= buffer[6][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){
       		d=d-(l6);
       		for(int j=0;j<l6;j++){
     			buffer[6][j]=buffer[6][j]-32;
       		}
      		for(int j=l6-1;j>=0;j--){
     			puzzle[c][d]=' ';
       			d++;
       		}
       		d=d-(l6);
      		for(int j=l6-1;j>=0;j--){
     			puzzle[c][d]=buffer[6][j];
       			d++;
       		}
       		c6=1;}
       }
       else if(co==97+a && ch==b-(l7-1) && w==1){
       		w=1;
      			
      	
      		for(int j=0;j<l7;j++){
      			if(control[j]!= buffer[7][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){
       		b=b-l7;
       		for(int j=0;j<l7;j++){
     			buffer[7][j]=buffer[7][j]-32;
       		}
      		for(int j=0;j<l7;j++){
     			puzzle[a][b]=' ';
       			b++;
       		}
       		b=b-l7;
      		for(int j=0;j<l7;j++){
     			puzzle[a][b]=buffer[7][j];
       			b++;
       		}
       		c7=1;}
       }
       else if(co==97+x8 && ch==y8 && w==1){
       		w=1;
      			
      	
      		for(int j=0;j<l8;j++){
      			if(control[j]!= buffer[8][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){

       		y8=y8-(l8);
       		for(int j=0;j<l8;j++){
     			buffer[8][j]=buffer[8][j]-32;
       		}
      		for(int j=l8-1;j>=0;j--){
     			puzzle[x8][y8]=' ';
       			y8++;
       		}
       		y8=y8-(l8);
      		for(int j=l8-1;j>=0;j--){
     			puzzle[x8][y8]=buffer[8][j];
       			y8++;
       		}
       		c8=1;}
       }
       else if(co==97+(x9-1) && ch==y9+1 && w==1){
       		w=1;
      			
      	
      		for(int j=0;j<9;j++){
      			if(control[j]!= buffer[9][j]){
      				w=0;
      			}
      		}
      	
      		if(w==1){
       		
       		x9=x9-l9;
       		
       		for(int j=0;j<l9;j++){
     			buffer[9][j]=buffer[9][j]-32;
       		}
       		for(int j=l9-1;j>=0;j--){
     			puzzle[x9][y9]=' ';
       			x9++;
       		}
       		x9=x9-l9;
       		for(int j=l9-1;j>=0;j--){
     			puzzle[x9][y9]=buffer[9][j];
       			x9++;
       		}
       		c9=1;}
       	
       	}
       		
    	if(c0==1){
    		if(c1==1){
    			if(c2==1){
    				if(c3==1){
    					if(c4==1){
    						if(c5==1){
    							if(c6==1){
    								if(c7==1){
    									if(c8==1){
    										if(c9==1){
    											printf("Goodby\n");
    											flag=1;
    										}}}}}}}}}}
    
    	

    }
    									
    								
    							
   	return 0;
}