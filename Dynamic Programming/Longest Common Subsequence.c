/*#include<stdio.h>

int seq(char arr[],char crr[],int n,int m)
{
    //printf("%s %s\n",arr,crr);
    int i,j=0,count=0,p,flag=0,found=0;
    for(i=0; i<n; i++)
    {
        //p=j;
        printf("\t%d\n",i);
        for(j; j<m; j++)
        {
            found++;
            printf("\t\t%d\n",j);
            //if(flag==0 && i!=n-1)
            //{
               //p=j;
               //flag=1;
            //}
            //printf("%c %c\n",arr[i],crr[j]);
            if(arr[i]==crr[j])
            {
                printf("%c %c\n",arr[i],crr[j]);
                printf("%d\n",j);
                //flag=1;
                count++;
                j++;
                break;
            }
            //flag=0;
        }
        //if(flag==0 && found==j-1)
            //j=p;
        //flag=0;
    }
    return count;
}

int main()
{
    char arr[1111],crr[1111];
    int i,a,c,temp;
    while(scanf("%s %s",arr,crr)==2)
    {
    a=strlen(arr);
    c=strlen(crr);
    if(a<c)
    {
        printf("%d\n",seq(arr,crr,a,c));
    }
    else
    {
        printf("%d\n",seq(crr,arr,c,a));
    }
    }
    return 0;
}*/


#include<stdio.h>
#include<string.h>

char arr[1111],brr[1111];

int max(int a, int b)
{
    return (a>b)? a:b;
}

int seq(int m, int n)
{
    int lcs[m+1][n+1],i,j;
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(arr[i-1]==brr[j-1])
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
        }
    }
    return lcs[m][n];
}

int main()
{
    int m,n;
    while(gets(arr))
    {
        gets(brr);
        m=strlen(arr);
        n=strlen(brr);
        if(m==0 || n==0)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",seq(m,n));
    }
    return 0;
}


/*
#include <stdio.h>
#include <string.h>


char s[1010],t[1010];
int myTable[1010][1010];

void initializeTable(){
     int i,j;
   for(i=0;i<1010;i++){
     for(j=0;j<1010;j++){
       myTable[i][j]=-1;
     }
    }

}
int max(int num1,int num2){
   if(num1>num2)return num1;
   return num2;
}

int calculateLCSLength(int len1,int len2){
    if(len1<=0 || len2<=0)return 0;

    if(myTable[len1][len2]==-1){

    if(s[len1-1]==t[len2-1])myTable[len1][len2]=(1+calculateLCSLength(len1-1,len2-1));
    else myTable[len1][len2] = max(calculateLCSLength(len1-1,len2),calculateLCSLength(len1,len2-1));
    }

    return myTable[len1][len2];
}


int main(){
    int len1,len2,n;
    int i,j;


    while (gets(s)){
    gets(t);
    initializeTable();
    len1 = strlen(s);
    len2 = strlen(t);

    n = calculateLCSLength(len1,len2);

    printf("%d\n",n);


    }



    return 0;


}
*/
