#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

struct node{
  int index;
  char cmd[40];
  struct node* left;
  struct node* right;
};

//void dfs(struct node*nod,char* emptystr);
void dfs(struct node*nod,char* emptystr[]);
//struct node* create_tree(struct node* head,int nodes,int*direction,int szofd,char* cmd[]);
struct node* create_tree(struct node* head,int nodes,int*direction,int szofd);
#endif
