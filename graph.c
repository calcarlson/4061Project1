#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
/*
struct node{
  int index;
  char* cmd[40];
  struct node* left;
  struct node* right;
};
*/
void dfs(struct node*nod,char* emptystr[]){
	if(nod==NULL){return;}
	pid_t pidp=getpid();
	pid_t pid1=fork();
	
		if (pid1==0)
		{	
			
			if (nod->left==NULL && nod->right==NULL)
			{
				printf ("Node %d \n",nod->index);
				//printf (emptystr[nod->index]);
				//printf("\n");
				//execl(emptystr[nod->index],(char*)NULL);
				execl("/bin/echo","echo",emptystr[nod->index],(char*)NULL);
				return;
			}
			else
			{
				dfs(nod->left,emptystr);
				dfs(nod->right,emptystr);
				printf("Node %d \n",nod->index);
				//printf (emptystr[nod->index]);
				//printf("\n");
				//execl(emptystr[nod->index],(char*)NULL);
				execl("/bin/echo","echo",emptystr[nod->index],(char*)NULL);
			}
	
		}
		else
		{
			wait(NULL);
			//waitpid(pid1,NULL,0);
		}
  char outline[30];
  sprintf (outline,"%d %d",pid1,pidp);
  printf(outline);printf("\n\n\n");
  return;
  }



struct node* create_tree(struct node* head,int nodes,int*direction,int szofd){
	//printf("size of direction %d \n",szofd);
    //create first node
    struct node* nod[nodes];
    
//
    head->index=direction[0];
   // head->cmd=comd[0];
    //head->index=direction[0];
    head->left=NULL;
    head->right=NULL;
    nod[0]=head;
	int temp=-9999;
	
  
    for (int i=0; i<=(szofd-2);i+=2){
   
		if (direction[i]!=temp){
			 struct node* ch= (struct node*)malloc(sizeof(struct node));
			 ch->left=NULL;
			 ch->right=NULL;
			 ch->index=direction[i+1];
			 nod[direction[i]]->left=ch;
			 nod[direction[i+1]]=ch;
			 temp=direction[i];
			//printf("left %d",direction[i]);
			}
      else {
	   struct node* ch= (struct node*)malloc(sizeof(struct node));
       ch->left=NULL;
       ch->right=NULL;
       ch->index=direction[i+1];
       nod[direction[i]]->right=ch;
       nod[direction[i+1]]=ch;
       //ch->cmd=comd[direction[i+1]];
         //printf("right %c", direction[i]);
       }

		 }
		  
	 
     return head;
	 }
/*
	 int main(){
     int direction[]= {0,1,0,2,2,3};
     size_t size=(sizeof(direction)/4);
     char* cmd[32];
    struct node* head= (struct node*)malloc(sizeof(struct node));
	head->index=5;
    head = create_tree(head,4,direction,size,cmd);
     //printf("%d",head->right->right->index);
     printf("\n next \n");
     char k[200]="bibi";
     dfs(head,k);
     printf("\n");
     printf(k);

	/*	 char* direction= "010223";

    head = create_tree(head,direction);
    head->index='r';
    char list[12];
    list[0]='w';

    //dfs(head,list);
    printf(list);
     return 0;
   }
*/
