#include<stdio.h>
int main(){
    int key,mid;
int A[]={2,9,49,22,33,1,34,55,90};
int found=0, left=0 , right=8;
printf("Enter the value of key");
scanf("%d",&key);

while (left<= right)
{
   mid=(left+right)/2;
   if(key == A[mid]){
    found=1;
   }else if(key<A[mid]){
    right=mid-1;
   }else{
    left=mid+1;
   }
}
if(found == 1){
    printf("Element found");
}else{
    printf("Element not found");
}
return 0;
}