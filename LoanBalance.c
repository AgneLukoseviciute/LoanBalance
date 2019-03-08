#include <stdio.h>

    /***********************************************************************
     * Name: Agne Lukoseviciute                                            *
     * Box:  4129                                                          *
     * Assignment name:  Sup. Problem Number 2: Status of Loan Balance     *
     * Assignment for 2018-02-27                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     CSC 161 readings on Loops                                       *
     *   Help obtained                                                     *
     *      none                                                           *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

//This will be the suplemental problem for "Status of Loan Balance"

/*PRECONDITIONS: the initial_loan, interest_percentage, and payment must
all be positive real numbers.  */

/* POSTCONDITIONS: This program will produce a table with the headers
month and loan balance. The program will then print out different
loan balances associated with each month until the loan is completely payed
off. The program will then also disply the final payment, the total payments
made, and the 'cost' of the loan.  */


int main ()
{
  //declaration of variables
double initial_loan;
double interest_percentage;
double payment;
double current_monetary_interest;
int current_month = 1;
double total_payment = 0;


//the following lines promt the user to enter various values and then scans
//them and stores the value as an appropriate variable. 
printf ("This program displays the status of loan balance, total amount made");
printf (" in payments, and the cost of the loan\n");
printf ("Enter the initial balance of a loan\n");
scanf ("%lf", &initial_loan);
printf ("Enter the monthly interest rate\n");
scanf ("%lf", &interest_percentage);
printf ("Enter the constant monthly payment\n");
scanf ("%lf", &payment);

/* creates a separate variable for loan_balance which can be manipulated
   while keeping a copy of the original 'initial_loan' */
 double loan_balance = initial_loan;


 printf ("     month     loan balance\n"); /* sets up the header for 
                                              displaying results */

 //will perform the following loop as long as the balance is above zero
while (loan_balance > 0)
  {
    //prints current month and loan_balance
   printf ("       %d          $%5.2lf\n", current_month, loan_balance);
   //updates current_monetary_interest based on loan_balance
   current_monetary_interest = (loan_balance * (interest_percentage / 100));
   //updates loan_balance based on interest and payment made
   loan_balance = (loan_balance + current_monetary_interest - payment);
   //adds payment made to total_payment
   total_payment = (payment + total_payment);
    //increments the month value
   current_month++;

   /*if outstanding balance is less than the payment, the payment
     becomes the exact amount of the balance */
   if (loan_balance <= payment)
     {
       printf ("       %d          $%5.2lf\n", current_month, loan_balance);
       payment = loan_balance; 
       total_payment = (payment + total_payment);
       break;
     }
  
}

//defines loan_cost
 double loan_cost = (total_payment - initial_loan);

 //prints the last few remaining lines of information
 printf("Final payment is $%5.2lf\n", payment);
 printf("Total amount paid is $%5.2lf\n", total_payment);
 printf("Total cost of the loan is $%5.2lf\n", loan_cost);
 
return 0;

}
