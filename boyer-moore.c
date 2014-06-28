#include<stdio.h>
#define DEBUG 0
//
// Boyer-Moore Algorithm
// Ref: http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html
//
// KalaKuo @ 2014.6.28
//

// Bad char index
int charIdx(char s[], char t){
    int idx = 0;
    while(s[idx] && s[idx]!=t) idx++;
    if(s[idx]=='\0') return -1;
    else return idx;
}

int matchIdx(char s[],char t[]){
    int i=0;
    int len = 0;
    while(t[len]!='\0') len++;
    if(DEBUG) printf("%d |",len);
    while(i<len && s[i]==t[i]) i++;
    if(i==len) return i;
    return -1;
}

int bm(char s[],int ss, char t[],int ts){

    // Good suffix table
    int h[ts];
    int k, len;
    for(k=ts-1;k!=0;k--){
        len = ts-k;
        if(DEBUG) printf("%d ",len);
        if(DEBUG) printf("%d => %d\n",k,matchIdx(s,t+ts-len));
        h[k-1]=matchIdx(s,t+ts-len);
    }

    ss--;ts--;
    int i=ts-1,j=ts-1;
    while(i<ss){
        if(DEBUG) printf("%c %c | ",s[i],t[ts-1]);
        if(s[i]!=t[ts-1]){
            if(DEBUG) printf("%d += %d - %d | ", i, j, charIdx(t,s[i]));
            i += j-charIdx(t,s[i]);
            if(DEBUG) printf("%d\n",i);
        } else { 
            int idx=1;
            while((idx!=ts-1) && s[i-idx]==t[ts-1-idx]) {
                if(DEBUG) printf("%c %c | ",s[i-idx],t[ts-1-idx]);
                idx++;
            }
            if(idx==ts-1) {
                if(DEBUG) printf("FOUND\n");
                int n = i-ts+1;
                if(DEBUG){ 
                    for(i=0;i<ts;i++)
                        printf("%c",s[n+i]);
                    printf("\n");
                }
                return n;
            } else {
                int max = -1;
                for(k=ts-idx;k<ts;k++)
                    if(h[k]>max)
                        max=h[k];
                if(DEBUG) printf("%d %d |",ts-idx,max);

                // Use Bad Character
                //if(DEBUG) printf("%d += %d - %d | ", i, j, charIdx(t,s[i-idx]));
                //i += j-charIdx(t,s[i-idx]);
               
                // Use Good Suffix
                if(DEBUG) printf("%d += %d - %d | ", i, j, max);
                i += j - max;
                if(DEBUG) printf("%d\n",i);
            }
        }
    }
    return -1;
}

int main(){
    //char s[]="HERE IS A SIMPLE EXAMPLE";
    //char t[]="EXAMPLE";
    char s[]="BBC ABCDAB ABCDABCDABDE";
    char t[]="ABCDABD";
    int ss =sizeof(s)/sizeof(s[0]);
    int ts =sizeof(t)/sizeof(t[0]);
    printf("%s | %d\n",s,ss);
    printf("%s | %d\n",t,ts);
    printf("%d\n",bm(s,ss,t,ts));
    return 0;
}
