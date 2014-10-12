#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
  int value;
  struct node * next;
  struct node * prev;
} * node_t;

void enqueue(int x, node_t * head){
  
  if((*head)->prev == NULL){
    (*head)->value = x;
    (*head)->prev = *head;
    (*head)->next = *head;
  }
  else{
    node_t current = (node_t)malloc(sizeof(struct node));;
    
    current->value = x;
    current->next = *head;
    current->prev = (*head)->prev;
    (current->prev)->next = current;
    (*head)->prev = current;
    
    *head = current;
    }
}

void dequeue(int * x, node_t * head){

  *x = (*head)->prev->value;
  node_t deleted = (*head)->prev;
  ((*head)->prev->prev)->next = *head;
  (*head)->prev = ((*head)->prev)->prev;
  free(deleted);

}

void print_queue(node_t head, int size){
  int i;
  printf("-> ");
  for(i=0; i < size; i++){
    printf("%d ", head->value);
    head = head->next;
  }
  printf("->\n");
}

void documentation(){
  printf("\n");
  printf("Welcome to Hector Cardenas' Queue Documentation.\n");
  printf("\n");
  printf("Flags:\n");
  printf("\t-f FILENAME.txt | Accepts a text file as input, elements of the queue should be either separated by a space or a newline.\n");
  printf("\t-s enables size | Specify a number after the flag to be the maximum size of the queue.\n");
  printf("\t**Flags -f and -s cannot be used simultaneously**\n");
  printf("\n");
  printf("Running ./queue by itself will prompt the user for a queue size, then proceed to the regular menu.\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, char **argv){
  
  /* Variable Declaration */
  int i,max_size = 0, flag, menu, request, size = 0;
  char arg;
  FILE *fp;
  node_t head = (node_t)malloc(sizeof(struct node)); //head node
  
  /* Reading From File, Argument, or Standard I/O */
  if((argc-1)%2 == 0 && argc > 1){ //even number of arguments, excluding executable 
    for(i=1; i < argc; i++){
      
      arg = argv[i][1];
      switch(arg){
        
      case 'f': //reads queue from text file
        if(max_size == 0){
          fp = fopen(argv[i+1],"r"); //open file, r = reading
          if(fp == NULL){
            printf("Error, %s does not exist.\n", argv[2]);
            exit(EXIT_FAILURE);
          }
          else{
            int scan;
            while(fscanf(fp, "%d",&scan) != EOF){
              enqueue(scan, &head);            
              size++;
            }
          }
          max_size = size;
          i++; //skipping file name
          fclose(fp);
        }
        else{
          printf("[ERROR] - Sorry, you can't set both the file and size flags\n");
          exit(EXIT_FAILURE);
        }
        break;
        
      case 's': //size
        if(max_size == 0){
          max_size = atoi(argv[i+1]);
          printf("Size: %s\n", argv[i+1]);
          i++; //skipping size num
        }
        else{
          printf("[ERROR] - Sorry, you can't set both the file and size flags\n");
          exit(EXIT_FAILURE);
        }
        break;
      default:
        printf("Wow! Looks like %s is not an acceptable flag, please try again.\n", argv[i]); 
        exit(EXIT_FAILURE);
        break;
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
    else{
      printf("Wow! Looks like %s is not an acceptable flag, please try again.\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  }
  
  /* Main Menu */
  
  flag = TRUE; //keeps menu running
  while(flag == TRUE){
    
    printf("Do you want to:\n1 - Enqueue\n2 - Dequeue\n3 - Print Current Queue\n4 - Exit\n");
    scanf("%d", &menu);
    
    switch(menu){
    
    case 1:
      if(size < max_size){
      printf("Type the integer you want to enqueue\n");
      scanf("%d", &request);
      enqueue(request, &head);
      size++;
      //printf("Added: %d\n",head->value);
      }
      else
        printf("[ERROR] - Size limit reached. Please dequeue some elements first\n");
      break;
      
    case 2:
      if(size > 0){
        dequeue(&request, &head);
        size--;
        printf("Dequeued: %d\n", request);
      }
      else
        printf("There's no elements to dequeue. Please add some first\n");
      break;
    
    case 3:
      print_queue(head, size);
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
