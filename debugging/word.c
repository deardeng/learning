#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  LEN 10

void spiral(int dim)
{
	int row;
//	int column;
	int round;
	int i, j;
	for( i=0;i<dim;i++)
	{
		for( j=0;j<dim;j++)
		{
			row=dim-i-1;

			round=dim-j-1;
			if(j>=i&&j<dim-i)
			{
				//cout<<setw(4)<<1+4*i*(dim-i)+j-i<<" ";
				printf("%*d", 4, 1+4*i*(dim-i)+j-i);
			}
			//row start from bottom right
			else if(j>=row&&j<dim-row)
			{
				//cout<<setw(4)<<1+4*row*(dim-row)+2*(dim-2*row-1)+(dim-row-1-j)<<" ";
				printf("%*d", 4, 1+4*row*(dim-row)+2*(dim-2*row-1)+(dim-row-1-j));
			}
			//column start from bottom left
			else if(i>j&&i<dim-j-1)
			{
				//cout<<setw(4)<<1+4*j*(dim-j)+3*(dim-2*j-1)+(dim-j-1-i)<<" ";
				printf("%*d", 4, 1+4*j*(dim-j)+3*(dim-2*j-1)+(dim-j-1-i));
			}
			//column start from top right
			else if(i>round&&i<dim-round-1)
			{
				//cout<<setw(4)<<1+4*round*(dim-round)+(dim-2*round-1)+(i-round)<<" ";
				printf("%*d", 4, 1+4*round*(dim-round)+(dim-2*round-1)+(i-round));
			}
		}
		//cout<<endl;
		printf("\n");
	}
}

void spiral2(int dim, int ss[LEN][LEN] )
{
	int round;
	int i, j;
	int aa;
	for( i=0;i<dim;i++)
	{
		for( j=0;j<dim;j++)
		{
			if( j>=i && j<dim -1-i )	// up
			{
				round = i;
				aa = 1 + 4 * round * ( dim - round );
				ss[i][j] = aa + j - round;
			}
			else if( j>i && j>= dim-1-i ) // right
			{
				round = dim - 1 - j;
				aa = 1 + dim - (2 *round+1)  + 4 * round * ( dim - round );
				ss[i][j] = aa + i - round;
			}
			else if(j<=i && j >dim-1-i ) // down
			{
				round = dim -1 - i;
				aa = 1 + 2*(dim - (2 *round+1))  + 4 * round * ( dim - round );
				ss[i][j] = aa + dim -1-j - round;
			}
			else if(j<i && j<=dim-1-i) // left
			{
				round = j;
				aa = 1 + 3*(dim - (2 *round+1))  + 4 * round * ( dim - round );
				ss[i][j] = aa + dim -1 -i - round;
			}
		}
		printf("\n");
	}
}

void spiral3(int dim, int ss[LEN][LEN] )
{
	int round;
	int i, j;
	int aa;
	for( i=0;i<dim;i++)
	{
		for( j=0;j<dim;j++)
		{
			if( j>=i && j<dim -1-i )	// up
			{
				round = i;
				aa = 1 + 4 * round * ( dim - round );
				ss[i][j] = dim * dim - (aa + j - round);
			}
			else if( j>i && j>= dim-1-i ) // right
			{
				round = dim - 1 - j;
				aa = 1 + dim - (2 *round+1)  + 4 * round * ( dim - round );
				ss[i][j] = dim * dim - (aa + i - round);
			}
			else if(j<=i && j >dim-1-i ) // down
			{
				round = dim -1 - i;
				aa = 1 + 2*(dim - (2 *round+1))  + 4 * round * ( dim - round );
				ss[i][j] = dim * dim - (aa + dim -1-j - round);
			}
			else if(j<i && j<=dim-1-i) // left
			{
				round = j;
				aa = 1 + 3*(dim - (2 *round+1))  + 4 * round * ( dim - round );
				ss[i][j] = dim * dim - (aa + dim -1 -i - round);
			}
		}
		printf("\n");
	}
}

void show( int aa[LEN][LEN], int n )
{
	int i, j;
	for( i = 0; i < n; ++i )
	{
		for(j = 0; j < n; ++j )
			printf("%*d", 4, aa[i][j] );
		printf("\n");
	}
}

//#define dim 5
int aa[LEN][LEN];
int main()
{
	memset((void *)aa, 0x00, LEN*LEN*sizeof(int));
	spiral3(3, aa );
	//spiral(10);
	show(aa, 3);
	return 0;
}
