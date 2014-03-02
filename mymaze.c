//Jethro Chan

#include <stdio.h>

int find_path(char mz[][8], int a, int b);

int main(int argc, char *argv[])
{
  FILE *fp;
  char grid[8][8];
  char garbage;
  int i, a = 7, b = 7, j;

  if(argc != 2)
  {
    printf("usage: %s filename\n", argv[0]);
    return -1; 
  }

  fp = fopen(argv[1], "r"); 

  for (i = 0; i < 8; i++)
  {
    for (j = 0; j < 8; j++)
    {
      fscanf(fp, "%c", &grid[i][j]);
    }

    fscanf(fp, "%c", &garbage);
  }

  find_path(grid, a, b);

return 0;
}

int find_path(char mz[][8], int a, int b)
{
  
  if (((mz[a-1][b]) == 'O') && !(b < 0 || (a-1) > 7 || b > 7 || (a-1) < 0))
  {
    printf("up\n");
    mz[a][b] = 'X';
    if((find_path(mz, a - 1 ,b)) == 1)
    { 
      printf("(%d, %d)\n", a, b);
      return 1;
    }
  }
  
  else if (((mz[a][b - 1])) == 'O' && !((b-1) < 0 || a > 7 || (b-1) > 7 || a < 0))
  {
    printf("left\n");
    mz[a][b] = 'X';
    if ((find_path(mz, a, b - 1)) == 1)
    {
      printf("(%d, %d)\n", a, b);
      return 1;
    }
  }
  
  
  else if (((mz[a+1][b]) == 'O') && !(b < 0 || (a+1) > 7 || b > 7 || (a+1) < 0))
  {
    printf("down\n");
    mz[a][b] = 'X';
    if((find_path(mz, a + 1 ,b)) == 1)
    { 
      printf("(%d, %d)\n", a, b);
      return 1;
    }
  }

  else if (((mz[a][b+1]) == 'O') && !((b+1) < 0 || a > 7 || (b+1) > 7 || a < 0))
  {
    printf("right\n");
    mz[a][b] = 'X';
    if ((find_path(mz, a, b + 1)) == 1)
    {
      printf("(%d, %d)\n", a, b);
      return 1;
    }
  }

  else if ((a == 0) && (b == 1))
  {
    printf("(0, 1)\n");
    return 1; 
  }

  
  else 
  {
    printf("No path was found.\n");
    return 0;
  }
 
  return 0;
}
