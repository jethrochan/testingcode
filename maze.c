//Jethro Chan
//Anthony Le

#include <stdio.h>
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

  if(FAIL == find_path(grid, 7, 7)) //start point
    {
      printf("No path was found\n");
    }//if

  fclose(fp);

  return (0);
}//end main



//*grid or use grid[][[]with malloc?
int find_path(char grid[][8], int i, int k)
{
  if(i < 0 || k > 7 || i > 7 || k < 0 || grid[i][k] == 'X')//if out of bound
      return (FAIL);
  grid[i][k] = 'X';

    
  if(i == 0 && k == 1) //if destination is good, don't call recursions again
    {
      grid[i][k] = 'X';//change current position to X
      printf("(%d, %d)\n", i, k);
      return (SUCCESS);
    }//if

  //----END BASE CASE CHECKING----------//
  
          if((find_path(grid, i-1, k)) == SUCCESS)//check up
	    { 
	      //    grid[i][k] = 'X';            
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
	  else if((find_path(grid, i+1, k)) == SUCCESS)//check down
	    { 
	      //grid[i][k] = 'X';
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
	  else if((find_path(grid, i, k-1)) == SUCCESS)//check left
	    {
	      //grid[i][k] = 'X';
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
	  else if((find_path(grid, i, k+1)) == SUCCESS)//check right
	    {	     
	      // grid[i][k] = 'X';
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
          else
	    return FAIL;
         
	  // return (SUCCESS); //--> is the way i am returning things bad? 
	
  
  return (FAIL); //default cause  
}//find_path
