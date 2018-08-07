#include<stdio.h>

int main()
{
    int n,k,a,b,i,j,arr[500][500],visited[500],que[1000];

    scanf("%d %d",&n,&k);

    for(i=0; i<k; i++){
        scanf("%d %d",&a,&b);
        arr[a][b]=1;
        arr[b][a]=1;
    }

    int flag=0,begin=0,end=0;

    for(i=1; i<=n; i++){

        if(visited[i]==0){
            que[end]=i;
            ++end;
            visited[i]=1;

            while(begin<=end){
                int x=que[begin];
                ++begin;

                for(j=1; j<=n; j++){

                    if(arr[x][j]==1){

                        if(visited[j]==0){

                            if(visited[x]==1){
                                visited[j]=2;
                                que[end]=j;
                                ++end;
                            }

                            else if(visited[x]==2){
                                visited[j]=1;
                                que[end]=j;
                                ++end;
                            }

                        }

                        else{

                            if(visited[x]==visited[j] && x!=j){
                                flag=1;
                            }
                        }
                    }
                }
            }
        }
    }

    if(flag==0) printf("yes\n");

    else printf("no\n");

    return 0;
}
