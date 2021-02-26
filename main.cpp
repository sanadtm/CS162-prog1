// Sanad Thapa
// CS 162
// Program 1
// THis program will compute how much money an employee should deposit in the bank at the end of the day of sales.
// The cash drawer will have at least five $1’s, two $5’s, one $10, and two $20’s at the end of the day. If can't,
// then employee needs to break a $20 or a $100 at the bank before finalizing the daily sales
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// This randoms the RNG every thing i use rand Function
	srand(time(0));

	// Variable declaration
	int start_amount = 0; // variable for the starting amount 
	int keep_register = 0, deposit = 0; // Variable for keep_register and amount to be deposited

	// Variable declaration to count no of notes in the cash register
	int no_20s = 0,no_10s = 0, no_5s = 0, no_1s = 0;

	// ASKING the employee for the necessary data
	cout << "*********************\n ";
	cout << "Welcome employee !! \n";
	cout << "*********************\n ";
	cout << "Enter the Cash in the register at the start your shift which is greater or in between $70 to $85\n";

	// Asking for the input from the eployee 
	cin >> start_amount;
	cout << "The amount in the register at the start of your shift is " << start_amount << endl;

	//************ Now we calculate how many 1's 5's 10's and 20's are there
	no_20s = start_amount/20;
	no_10s = (start_amount - 20*no_20s)/10;
	no_5s = (start_amount - 20*no_20s-10*no_10s)/5;
	no_1s = (start_amount - 20*no_20s-10*no_10s-5*no_5s); 
	cout <<"No of 20s are : " <<  no_20s << endl << "No of 10s are : "  << no_10s << endl;
	cout << "No of 5s :" <<  no_5s << endl << "No of 1s :"  << no_1s << endl;
	cout << "------------------------------------------------- \n";

	//************ Randomly generate the number of sales and sales amounts
	// Declaring the variables from Random sales number, each sales and Total Sales_sum
	int rand_sales=0;
	int sales=0, sales_sum=0;	
	rand_sales = rand() %20+1;
	cout << "After a long shift, the total number of sales for the day was: " << rand_sales <<endl;

	//************ LOOP for adding all the sales for the day
	for (int i=1; i <= rand_sales ; ++i)
	{
		// BODY of the LOOP
		sales = rand() %100;
		cout << "Sale No:" << i <<" -> "  << sales << endl;
		sales_sum += sales;
	}
	// Calculating the total number of sales by adding all the sales amount
	cout << "The total sales for this day is : " << sales_sum << endl;
	cout << "------------------------------------------------- \n";

	// Creating random number between 70 to 85 to be left in the  cash register
	keep_register  = (rand()%15+1)+70;
	cout << "The amount of money that is going to be in the Register is :" << keep_register <<endl;
	cout << "-------------------------------------------------\n";	

	//*************  Breaking down how many 20s, 10s ,5s and 1s are going to be left in the register
	cout << "Which is ::  \n";
	no_20s = keep_register/20;
	no_10s = (keep_register - 20*no_20s)/10;
	no_5s = (keep_register - 20*no_20s-10*no_10s)/5;
	no_1s = (keep_register - 20*no_20s-10*no_10s-5*no_5s); 

	// Checking if The 20s 10s 5s and 1s are 0 before displaying
	if(no_20s!=0)
		cout << "No of 20s left in the register is : " <<  no_20s << endl;
	if(no_10s !=0)
		cout << "No of 10s left in the register is : "  << no_10s << endl;
	if(no_5s !=0)
		cout << "No of 5s left in the register is : " <<  no_5s << endl;
	if(no_1s !=0)
		cout << "No of 1s left in the register is :"  << no_1s << endl;
	cout << "-------------------------------------------------\n";	

	//************* Calculating Amount deposited into thet Bank by substracting Total sales by Cash left in the register
	cout << "Start Amount Was : " << start_amount <<endl;
	cout << "Total Sales Was  : " << sales_sum <<endl;
	cout << "Amount Left in the Register is " << keep_register<<endl;
	deposit = (sales_sum - keep_register)+start_amount;

	// Checking if deposit is not negative
	if(deposit >=0)
	{
		cout << "------------------------------------------------- \n";
		// Displaying the Deposited Amount in the bank
		cout << "The Amount Deposited in the Bank is : " << deposit << endl;
		cout << "-------------------------------------------------\n";
	}else
		cout << " We didnt make any profit today\n";
	return 0;
}

