#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "mergeSort.h"
#include "quickSort.h"

int getMenu()
{
  char input[128];
  int choice = 0;

  printf("1.Merge sort\n");
  printf("2.Quick sort\n");
  printf("3.performance comparison\n");
  printf("4.Exit\n");
  printf("Please select: ");
  fgets(input,sizeof(input),stdin);
  sscanf(input,"%d",&choice);

  return choice;

}

int main() 
  {
  int * number;
  int * number2;
  int element = 0;
  char input[128];
  int i, f, r =0;
  int choice = 0;
  double time_spent = 0.0;
  while (1)
    {
      
    choice = getMenu();
    if(choice == 4)
    {
      exit(0);
    }
    
    printf("Enter the number of element(enter negative number to exit): ");
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%d",&element);

    if(element < 0)
      {
      exit(0);
      }
    srand(time(0));

    number = (int*) calloc(element,sizeof(int));

      printf("Elements of the array before sorting\n");
      for (i = 0; i < element; i++)
      {     
        number[i] = rand() % 1000;
        if(choice == 1 || choice == 23)
          printf("%d \t",number[i]); 
      }
      number2 = number;
    printf("\n");
    r = element - 1;
    if(choice == 1)
    {
      mergeSau(number,f,r);
    }
    else if(choice == 2)
    {
      quickSort(number,0,element-1);
    }
    else if(choice == 3)
    {
      clock_t begin = clock();
      mergeSau(number,f,r);
      clock_t end = clock();
      time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n(Merge sort)running time for %d elements is %f seconds\n",element,time_spent);
      time_spent = 0.0;

      clock_t begin2 = clock();
      quickSort(number2,0,element-1);
      clock_t end2 = clock();
      time_spent += (double)(end2 - begin2) / CLOCKS_PER_SEC;
      printf("\n(Quick sort)running time for %d elements is %f seconds\n\n",element,time_spent);
      time_spent = 0.0;
    }
    if(choice == 1 || choice == 2)
    {
      printf("After merge\n");
      for(i = 0; i < element; i++)
        {
        printf("%d\t",number[i]);  
        }
      printf("\n");
    }
    free(number);
    }
  }
