#include<stdio.h>
#define DEBUG 0
// 
// Knuth-Morris-Pratt Algorithm 
// Ref: http://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
//      http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html (Chinese)
// 
// KalaKuo @ 2014.6.27
//


// Copy the sub-string
void pstrcpy(char to[], char from[], int size){
    int i=0;
    while(i<size){ 
        to[i]=from[i];
        i++;
    }
    to[i]='\0';
}

// Return True if matched
int getPartialMatch(char a[], char b[]){
    int cnt = 0;
    while(a[cnt] && b[cnt]){
        if(a[cnt]!=b[cnt])
            return 0;
        else{ 
            cnt++;
        }
    }
    return cnt;
}

// Brute Force
void createTable(char t[], int h[], int ts){
    int i,ii,j,k;
    for(i=0;i<ts;i++) h[i]=0;
    for(i=1;i<ts;i++){ // Length 
    
        // prefix
        char as[i][ts+1];
        for(j=0;j<i-1;j++){
            pstrcpy(as[j],t,j+1);
            if(DEBUG) printf("%s ",as[j]);
        }
       
        if(DEBUG) printf(" | ");

        // suffix
        char de[i][ts+1];
        for(j=0;j<i;j++){
            pstrcpy(de[j],t+i-j,j);
            if(DEBUG) printf("%s ",de[j]);
        }
        if(DEBUG) printf("\n");

        int cnt = 0;
        for(j=0;j<i;j++)
            cnt+=getPartialMatch(as[j],de[j]);

        h[i]=cnt;
    }

    for(i=0;i<ts;i++)
        if(DEBUG) printf("%d ",h[i]);
    if(DEBUG) printf("\n");
}

int kmp(char s[], int ss, char t[], int ts){
    int h[ts]; //Partial Table
    createTable(t,h,ts);

    int i=0,j=0;
    while(i<ss){    
        while(s[i]!=t[0]) i++;
        j=1;
        while(s[i+j]==t[j]) j++;
        if(j==ts-1) {
            if(DEBUG) { 
                int k = 0;
                for(k=0;k<j;k++)
                    printf("%c",s[i+k]);
                printf("\n");
            }
            return i;
        } else {
            i += j - 1 - h[j-1];
            if(DEBUG) printf("Advance :%d\n",j-1-h[j-1]);
        }
    }

    return -1;
}

int main(){
    char s[]="BBC ABCDAB ABCDABCDABDE";
    char t[]="ABCDABD";
    int  ss =sizeof(s)/sizeof(s[0]);
    int  ts =sizeof(t)/sizeof(t[0]);
    printf("%s : %d\n", s, ss);
    printf("%s : %d\n", t, ts);
    printf("%d\n",kmp(s,ss,t,ts));
    return 0;
}
