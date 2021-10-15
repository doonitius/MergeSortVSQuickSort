#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "quickSort.h"

void swapP(int *x,int *y)
{
  int temp = *x;

  *x = *y;
  *y = temp;
}

int partition(int *number,int l,int r)
{
  int p = number[l];
  int i = l;
  int j = r + 1;

  while(1)
  {
    do
    {
       i++;
    } while(number[i] < p);
    do
    {
      j--;
    } while(number[j] > p);

    swapP(&number[i],&number[j]);

    if(i >= j)
    {
      break;
    }
  }

  swapP(&number[i],&number[j]);
  swapP(&number[l],&number[j]);

  return j;
}

void quickSort(int *number,int l,int r)
{
  if (l < r)
  {

    int s = partition(number,l,r);
    quickSort(number,l,s-1);
    quickSort(number,s+1,r);
  }

}

