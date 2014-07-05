#include<stdio.h>
const int MAX=64; // Use 64 bit for 64bit System (Maximum of base 2 bit count)

int restore(const char s[], const int d){
    int i,c;
    int re = 0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9') c = s[i]-'0';
        else if (s[i]>='A'&&s[i]<='F') c = s[i]-'A' + 10;
        else c = s[i] - 'a' + 10;
        re = re*d + c;
    }
    return re;
}

void convert(int n, const int d){
    int top = 0;
    int stack[MAX];
    while(n!=0){
        stack[top++]=n%d;
        n/=d;
    }
    while(top>=0)
        printf("%X",stack[top--]);
    printf("\n");
}

int main(){
    convert(100,5);
    printf("%d\n",restore("0400",5));
    return 0;
}
