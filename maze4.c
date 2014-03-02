//Jethro Chan
//Anthony Le

#include <stdio.h>
#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1

int find_path(char grid[][8], int i, int k); 

int main(int argc, char *argv[])
{
  FILE *fp = fopen(argv[1], "r");
  char grid[8][8]; 
  int col, row;
  int i, k;
  char garbage;
  col = row = 7;
  
  for(i = 0; i <= row; i++)
      {
	for(k = 0; k <= col; k++)
	  {
	    fscanf(fp, "%c", &grid[i][k]);
	  }//inner for
        fscanf(fp, "%c", &garbage);
      }//large for

  find_path(grid, 0, 1); //change this to [7][7] if you want it to print backwards

  fclose(fp);

  return (0);
}//end main


int find_path(char grid[][8], int i, int k) 
{
   
  if(grid[i][k] != 'O' && grid[i][k] != 'X')//if out of bound
    return (FAIL);

  if(grid[0][1] ==  'X')
    {
      printf("No path was found.\n");
      return (FAIL);
    }

  if(grid[i][k] == 'X')//if current position is X
    {
      return (FAIL);
    }  

  if(i == 7 && k == 7 && grid[7][7] == 'O')
    {
      printf("(%d, %d)\n", i, k);
      return (SUCCESS); 
    }
//----END BASE CASE CHECKING----------//
  
  if(grid[i][k] == 'O')//if current grid is 'O'
    {
      grid[i][k] = 'X';//set current called position to 'X'

      printf("(%d, %d)\n", i, k);
      //THE RECURSION IS NOT HAPPENING~! 	  
      find_path(grid, i-1, k);//check up
      find_path(grid, i+1, k);//check up  
      find_path(grid, i, k+1);//check right --> am i repetitive calling?
      find_path(grid, i, k-1);//check left
	  
      return (SUCCESS);
    }//if

  //no else needed because you are will exit if the if is set
  return (FAIL); //default cause  
}//find_path
