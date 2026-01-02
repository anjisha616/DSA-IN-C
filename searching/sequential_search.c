#include<stdio.h>
int main(){
    int key,i,found=0;
int A[]={2,9,49,22,33,1,34,55,90};
printf("Enter the value of key");
scanf("%d",&key);
for(i=0;i<9;i++){
    if(key == A[i]){
        found=1;
    }
}
if(found = 1){
    printf("Its sequentially found");
}else{
    printf("Element not found");
}

return 0;
}