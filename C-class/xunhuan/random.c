#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, n, m;
	srand( time( 0 ) );
	for ( i = 0; i < 3; i++ )
	{
		m = rand() % 2;
		if ( m == 0 )
			printf( "正面\n" );
		else printf( "反面\n" );
	}
}