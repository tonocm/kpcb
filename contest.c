#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
  int value;
  struct node *next;
  struct node *prev;
} node_t;

void enqueue(int x/*, node_t *head*/){
  printf("HElllloo!!\n");
  
  //if(head == NULL)
  //printf("Good..\n");
  //head.value = x;
  printf("%d\n", head.value);
}

void dequeue(int x, node_t *head){


}

void documentation(){
  printf("Welcome to queue's documentation.\n");
  printf("Flags:\n");
  printf("\t-f filename.txt Accepts a premade typed queue as a text file.\n");
  printf("\t-v enables verbose. Will print extra steps throughout the process.\n");
  printf("\t-s enables silent. Will not print anything, except for when you call the print function.\n");
  printf("\nRunning ./queue by itself will prompt the user for a queue size, then proceed to the regular menu.\n");
  printf("Running ./queue NUM will allocate an empty queue of size NUM, then proceed to the regular menu.\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, char **argv){
  
  /* Variable Declaration */
  int i,max_size, flag, verbose=0, silent=0, menu, request;
  char arg;
  FILE *fp;

  /* Reading From File, Argument, or Standard I/O */
  if((argc-1)%2 == 0 && argc != 1){ //even number of arguments, excluding executable 
    for(i=1; i < argc; i++){
      
      arg = argv[i][1];
      switch(arg){
      case 'f': //reads queue from text file
        fp = fopen(argv[2],"r"); //open file, r = reading
        if(fp == NULL){
          printf("Error, %s does not exist.\n", argv[2]);
          exit(EXIT_FAILURE);
        }
        break;
      case 'v':
        if(silent == 0)
          verbose = 1; //enables verbose
        else{
          printf("Error, cannot request verbose and silent simultaneously\n");
          exit(EXIT_FAILURE);
        }
        break;
      case 's':
        if(verbose == 0)
          silent = 1; //enables silent
        else{
          printf("Error, cannot request verbose and silent simultaneously\n");
          exit(EXIT_FAILURE);
        }
        break;
      default:
        printf("Wow! Looks like %s is not an acceptable flag, please try again.\n", argv[i]); 
        exit(EXIT_FAILURE);
      }
    }
  }
  else if(argc < 2){ //executable run without arguments, user must set queue size
    printf("Please specify the maximum size of your queue\n");
    scanf("%d",&max_size);
  }
  else{ //argument interpreted as either help or queue size
    if(strcmp("--help", argv[1]) == 0)
      documentation();
    else
      max_size = atoi(argv[1]);
  }
  
  /* Main Menu */
  
  flag = TRUE; //keeps menu running
  
  //node_t queue = (node_t *)malloc(max_size*sizeof(struct node));
  node_t head; //head node
  while(flag == TRUE){
    
    printf("Do you want to:\n1 - Enqueue\n2 - Dequeue\n3 - Print Current Queue\n4 - Exit\n");
    scanf("%d", &menu);
    
    switch(menu){
    case 1:
      printf("Type the integer you want to enqueue\n");
      printf("Cool...\n");
      scanf("%d", &request);
      enqueue(request/*, &head*/);
      printf("Cool2...\n");
      break;
    case 2:
      printf("Type the integer you want to dequeue\n");
      scanf("%d", &request);
      dequeue(request, &head);
      break;
    case 3:
      break;
    case 4:
      printf("Thank you for using Hector Cardenas' Queue. Goodbye!\n");
      flag = FALSE;
      break;
    default:
      printf("Please type either 1, 2, 3, or 4 depending on the option you would like to select\n");
      break;
    }
  }
  
  return EXIT_SUCCESS; //finished normally
}
