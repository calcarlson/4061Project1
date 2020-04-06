#include "main.h"
#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "limits.h"

struct inputParse{
    int numNodes;
    char nodes[1000];
    int vertex[64];
//    struct inputParse *next;
};

int main(int argc, char **argv) {
    int pid,pid2;
    struct inputParse *input;
    input = (struct inputParse *)malloc(sizeof(struct inputParse));
        int size =32;
        char *filename = (char *)malloc(sizeof(char)*size);
        //char c;
        printf("Please Enter a .txt input file name:\n");
    //used for testing purposes ( checks current directory)
       char cwd[PATH_MAX];
       if (getcwd(cwd, sizeof(cwd)) != NULL) {
           printf("Current working dir: %s\n", cwd);
       } else {
           perror("getcwd() error");
           return 1;
       }
    
    //input for filename
        scanf("%s", filename);
        FILE *fptr;
        printf("filename is %s\n",filename);
        fptr = fopen(filename,"r+");
        if (fptr==NULL)
        {
            perror("error no file!\n");
            exit(1);
        } 
  
   /*   fseek(fptr, -sizeof(struct inputParse), SEEK_SET);
        fscanf(fptr, "%d[^\n]", &input->numNodes);
    
        for(int i=0;i<3;i++){
            fgets(input->nodes, 1000, fptr);
        }
    */
      //printing the input Parse Structure
       // printf("%d\n", input->numNodes);
    //    printf("%s\n", &input->nodes[0]);
       // printf("%d\n", input->vertex[0]);
		int numberofnodes=0;
		char c=' ';
		int flag=0;
		char* cmd[32];
		char line[20];
		
	 int direction[64];
      char readnumberofnode[10];
      int ind=0;
      while(c!='\n')
      {  readnumberofnode[ind]=c;
		  c = fgetc(fptr);
		  ind++;
		 }
		numberofnodes=atoi(readnumberofnode);	 
		ind=0;
        printf("number of nodes %d \n\n\n",numberofnodes);
      
        c=fgetc(fptr);
        c=fgetc(fptr);
        int cmlines=0;
        int temp=0;
         
         while (1)
       { c = fgetc(fptr);
		 
		 if(c!='\n'){temp=0;line[ind]=c; ind++;}
		 else{temp++;}
		 if (temp==2){break;}
		 if(c=='\n'){
			 
		     
			 char *longstr = (char *) malloc(50);
			 strcpy(longstr,line);
			 strcpy(line,"                       ");
			 cmd[cmlines]=longstr;
			 //printf(longstr);
			 //printf("\n");
			 ind=0;
			 cmlines++;}		 
		}
		int ai=0;
		strcpy(line,"                       ");
		ind=0;
		while(c != EOF){
			c = fgetc(fptr);
			line[ind]=c;
			ind++;
			//if(c=='\n'){strcpy(line,"                       ");}
			 if (c==' ' || c=='\n'){
				 int num=atoi(line);
				 strcpy(line,"                       ");
				 direction[ai]=num;ai++;
				 ind=0;
				 }
			}
		/*printf("%d \n",ai);
	/*	printf(cmd[0]);
		
		 printf(cmd[1]);
		
		 printf(cmd[2]);
		 
		 printf(cmd[3]);*/
		 
        printf("\n\n\n");
        
      //  for (int i=0;i<ai;i++)   {printf("%d \n",direction[i]);	}
			
			
		char* emptylist;	
		
		struct node* head= (struct node*)malloc(sizeof(struct node));
		//size_t sz=(sizeof(direction)/4);
		
		head = create_tree(head,numberofnodes,direction,ai);
		dfs(head,cmd);
		
		
			
			
			
        fclose(fptr);
        
     
/*		//printf("Usage: ./proctree input_text_file\n");
        printf("\nend\n");
*/

	return 0;
}
