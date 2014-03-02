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

  find_path(grid, 7, 7); //start point

  fclose(fp);

  return (0);
}//end main

//*grid or use grid[][[]with malloc?
int find_path(char grid[][8], int i, int k)
{
if(grid[i][k] != 'O' && grid[i][k] != 'X' && !(i < 0 || (k) > 7 || i > 7 || (k) < 0))//if out of bound
      return (FAIL);

else{    
  if(grid[0][1] == 'X')//if startpt is X, print no path found
    {
      printf("No path was found.\n"); //--->when should we print out for no path found
      return (FAIL);
    }
  
  if(grid[i][k] == 'X')
    {
      return (FAIL);
    }
   
  //if(i == 7 && k == 7 && grid[7][7] == 'O')
  if(i == 0 && k == 1 && grid[0][1] == 'O') //check our endpt
    {
      printf("(%d, %d)\n", i, k);
      return (SUCCESS); //1 = success
    }
  
//----END BASE CASE CHECKING----------//
  
  // if(grid[i][k] == 'O' && !(i < 0 || (k-1) > 7 || i > 7 || (k-1) < 0))
    // {//upper outer if   
       if(grid[i+1][k] == 'O')
	{
	  grid[i][k] = 'X';
	  
	  if((find_path(grid, i-1, k)) == SUCCESS)//check return value with ==
	    {
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
	  else if((find_path(grid, i+1, k)) == SUCCESS)
	    {
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
	  else if((find_path(grid, i, k-1)) == SUCCESS)
	    {
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
	  else if((find_path(grid, i, k+1)) == SUCCESS)
	    {
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
          else
	    return FAIL;
         
          return (SUCCESS); 
	}//if


      else if(grid[i-1][k] == 'O')
        {
          grid[i][k] = 'X';

	  if((find_path(grid, i-1, k)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i+1, k)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i, k-1)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i, k+1)) == SUCCESS)
	    {
      	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
          else 
	    return FAIL;

        }//if
 	    

      else if(grid[i][k-1] == 'O')
        {
          //printf("(%d, %d)\n", i, k-1);
	  grid[i][k] = 'X';
	  
	  if((find_path(grid, i-1, k)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i+1, k)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i, k-1)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i, k+1)) == SUCCESS)
	    {
	      printf("(%d, %d)\n", i, k);
	      return SUCCESS;
	    }
          else
	    return FAIL;

        }//if

      else if(grid[i][k+1] == 'O')
        {
          //printf("(%d, %d)\n", i, k+1);
	  grid[i][k] = 'X';
	  

	  if((find_path(grid, i-1, k)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i+1, k)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i, k-1)) == SUCCESS)
            {
              printf("(%d, %d)\n", i, k);
              return SUCCESS;
            }
          else if((find_path(grid, i, k+1)) == SUCCESS)
	    {
		  printf("(%d, %d)\n", i, k);
		  return SUCCESS;
	    }
	  else 
	    return FAIL;
             
       }//if
      
      else if (grid[i][k] == 'O')
	{
	  printf("(0, 1)\n");
	  return SUCCESS;
	}
      
      else //if none of the above if else executed, all sides returns false
	{
	  printf("No path was found.\n"); //code added to solve this issue --> this gets printed out
	  return FAIL;
	}
 }//outer else
      // }//outer if
  
  return (FAIL); //default cause  
}//find_path