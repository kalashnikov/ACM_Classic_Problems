#include<stdio.h>
// 
// Hanoi
//  

void hanoi(int n, char x, char y, char z){
    if(n==1){
        printf("%d from %c to %c\n", n, x, z);
        return ;
    } else {
        hanoi(n-1, x, z, y);
        printf("%d from %c to %c\n", n, x, z);
        hanoi(n-1, y, x, z);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("Total steps: %d\n", (1<<n)-1);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
