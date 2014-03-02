//Jethro Chan
//Anthony Le

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
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


int find_path(char grid[][8], int i, int k) //passing array, C doesnt' care what position you passed in
{
  int call1, call2, call3, call4;
  call1 = call2 = call3 = call4 = 0;  
 
  if(grid[i][k] != 'O' && grid[i][k] != 'X')//if out of bound
      return (FAIL);
  
  if(grid[i][k] == 'X')
  {
    return (FAIL);
  }
    
  if(i == 7 && k == 7 && grid[7][7] == 'O')
    {
      printf("(%d, %d)\n", i, k);
      return (SUCCESS); //1 = success
    } 
//----END BASE CASE CHECKING----------//
  //ANALYZE THE RECURSION!!
  if(grid[i][k] == 'O')
    {
      call1 = find_path(grid, i+1, k);//check up
      call2 = find_path(grid, i-1, k);//check down
      call3 = find_path(grid, i, k+1);//check right
      call4 = find_path(grid, i, k-1);//check left
      
      if(call1 == SUCCESS || call2 == SUCCESS || call3 == SUCCESS || call4 == SUCCESS)//if any of the calls work, this is not a dead end
	{
	  printf("(%d, %d)\n", i, k);
	  grid[i][k] = 'X';
          return (SUCCESS);//lets make sure this call reutrns suces
	}//if
      return (SUCCESS); 
    }//if

  
  if(call1 != SUCCESS && call2 != SUCCESS && call3 != SUCCESS && call4 != SUCCESS)
    {
      printf("No path was found");
      return (FAIL);
    }//else no path
   
  return (FAIL); //default cause  
}//find_path
