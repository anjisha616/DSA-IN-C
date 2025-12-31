#include <stdio.h>

int main() {
  int A[]={1,9,10,2,33,16,79};
  int i,j,n=7,temp;
  
  for(i=1;i<n;i++){
      temp=A[i];
      j=i-1;
      while(j>=0 && temp<A[j]){
          A[j+1]=A[j];
          j=j-1;
      }
      A[j+1]=temp;
     
  }
  
  printf("Insertion sorting : ");
  for(i=0;i<n;i++){
      printf("\n %d",A[i]);
      
  }
    return 0;
}