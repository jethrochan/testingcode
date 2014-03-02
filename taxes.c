/*Written by Jethro Chan and Anthony Le*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{ 
  double gross_income, taxable_income, taxes_owed;

  printf("Please enter your gross taxable_income for 2012: ");
  scanf("%lf", &gross_income);
  
  if(gross_income >= 5950)
    {
      taxable_income = gross_income - 5950;
    }
  else
    taxable_income = 0;
  if(taxable_income < 8700)
    taxes_owed = taxable_income * ((double)10/100);
  else//taxable_income greater than 8700
    if(taxable_income >= 8700 && taxable_income <= 35350)
      taxes_owed = 870 + ((double)15 / 100) * (taxable_income - 8700);
    else//taxable_income greater than 35350
      if(taxable_income > 35350 && taxable_income <= 85650)
        taxes_owed = 4867.5 + ((double)25 / 100) * (taxable_income - 35350);
      else//taxable_income greater than 85860
        if(taxable_income > 85650 && taxable_income <= 178650)
          taxes_owed = 17422.5 + ((double)28 / 100) * (taxable_income - 85650);
        else//taxable_income greater than 178650
          if(taxable_income > 178650 && taxable_income <= 388350)
            taxes_owed = 43482.5 + ((double)33 / 100) * (taxable_income - 178650);
          else//taxable_income greater than 178650
            if(taxable_income > 388350)
              taxes_owed = 112683.5 + ((double)35 / 100) * (taxable_income - 388350);


  printf("The tax on $%.2f is $%.2f.\n", gross_income, taxes_owed);

  return (0);

}//end main
