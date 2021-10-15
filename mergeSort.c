#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "mergeSort.h"

void merge(int number[],int f,int m,int l)
  {
  int i = f;
  int ns = m + 1;
  int nz = l + 1;
  int j = m + 1;
  int k = f;
  int mer[1000000];

  while((i < ns) && (j < nz))
    {
    if(number[i] < number[j])
      {
      mer[k] = number[i];
      k++;
      i++;
      }
    else
      {
      mer[k] = number[j];
      k++;
      j++;
      }
    }
  for(; i < ns; i++)
    {
    mer[k] = number[i];
    k++;
    }
  for(; j < nz; j++)
    {
    mer[k] = number[j];
    k++;
    }
  for(i = f; i < nz;i++)
    {
    number[i] = mer[i];
    }
  }
void mergeSau(int number[],int f,int l)
  {
  int m = 0;
  double doon = 0; 

  if(f < l)
    {
    doon = (f + l)/2;
    m = floor(doon);
    mergeSau(number,f,m);
    mergeSau(number,m+1,l);
    merge(number,f,m,l);
    }
  } 
