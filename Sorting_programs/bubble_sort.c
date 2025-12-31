#include <stdio.h>

int main() {
   int A[]={3,2,1,4,5,12,33};
   int i,j,temp,n=7;
   for(i=0;i<n-1;i++){
       for(j=0;j<n-1;j++){
           if(A[j]>A[j+1]){
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
           }
       }
   }
printf("\n After bubble sorting ");

for(i=0;i<n;i++){
    printf("\n %d",A[i]);
}
    return 0;
}
