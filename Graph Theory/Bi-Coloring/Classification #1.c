#include<stdio.h>
#include<string.h>

typedef struct{

    int now, lst[ 100 ];

} graph;

int n, ok, block[ 100 ];

graph g[ 100 ];

void dfs( int vertex ) {

    int i;
    for( i = 0; i < g[ vertex ].now; i ++ )
        if( block[ g[ vertex ].lst[ i ] ] == -1 ) {
            if( block[ vertex ] == 0 ) {
                block[ g[ vertex ].lst[ i ] ] = 1;
            }
            else{
                block[ g[ vertex ].lst[ i ] ] = 0;
            }
            dfs( g[ vertex ].lst[ i ] );
        }
        else if( block[ vertex ] == block[ g[ vertex ].lst[ i ] ]) {
            ok = 0;
            return;
        }
}

int main( ) {
    int r, u, v, index, i;

    ok = 1;

    scanf( "%d %d", &n, &r );

    for( i = 0; i < r; i ++ ) {
        scanf( "%d %d", &u, &v );
        g[ u ].lst[ g[ u ].now ] = v;
        g[ v ].lst[ g[ v ].now ] = u;
        ++ g[ u ].now;
        ++ g[ v ].now;
    }


    memset( block, -1, sizeof( block ) );

    for( i = 1; i <= n; i ++ ) {
        if( block[ i ] == -1 ) {
            block[ i ] = 0;
            dfs( i );
        }
    }

    if( ok ) {
        printf( "yes\n" );
    }
    else {
        printf( "no\n" );
    }
}

