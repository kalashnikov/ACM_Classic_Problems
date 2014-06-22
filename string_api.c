#include<stdio.h>
// 
// 2014.6.22 @ KalaKuo
//

size_t strlen_p(const char *str){
    const char* ptr=str;
    while(*++ptr) ;
    return ptr-str;
}

char *strcpy_p(char *to, const char *from){
    char *pf=from, *pt=to;
    //while(*pf) *pt++=*pf++;
    //*pt='\0';
    while((*pt++ = *from++)!='\0') ; // Copy first, check null char later
    return to;
}

char *strstr_p(const char *haystack, const char *needle){

    if(!*needle) return (char*) haystack;

    const char *ptr=haystack;
    const char *hptr=haystack;
    const char *nptr=needle;

    while(*ptr){
        hptr=ptr;
        nptr=needle;
        while(*nptr==*hptr)
            nptr++,hptr++;
        if(!*nptr)
            return (char*) ptr;
        else
            ptr++;
    }
    return NULL;
}

//
// Document: http://www.cplusplus.com/reference/cstdlib/atoi/
// No handle error case'++1' or ' - -5' 
//
int atoi(const char *str){
    int i;
    int sign=1;
    int num=0;
    int len=1;
    char *ptr=str;
    while(*++ptr) len++; // Get Length
    for(i=0;i<len;i++){
        if( *(str+i)==' ' || *(str+i)=='+' ) {
            continue;
        } else if( *(str+i)=='-' ) {
            sign=-1;
        } else if( *(str+i)<'0' || *(str+i)>'9') {
            break; // no overflow
        } else { 
            num = *(str+i)-'0' + num*10;
        }
    }
    return sign*num;
}

int main(){
    
    char a[]="asbsad";
    printf("%zd\n",strlen_p(a));

    char b[7];
    strcpy_p(b,a);
    printf("%s\n",b);
    printf("%zd\n",strlen_p(b));

    printf("%s\n",strstr_p(a,"sbs"));
    
    printf("%d\n",atoi("   - 233&df"));
    printf("%d\n",atoi("++1"));

    return 0;
}
