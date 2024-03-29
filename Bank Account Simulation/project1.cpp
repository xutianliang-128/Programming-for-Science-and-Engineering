// Programmer: Mengyao Huang
// Date: September
// Purpose: to calculate balance and interest in bank account for several months
#include <iostream>
using namespace std;

bool accrueOneMonthsInterest(double &balanceAmt,
	const bool doPrintInfo); //proto
bool accrueInterest(double &balanceAmt,
	const int numMonths,
	const bool doPrintEachMonth); //proto

int main()
{
	bool success;
	double initial_balance;
	int num_of_month;
	char show_month;

	cout << "Enter the initial balance of the account:";
	cin >> initial_balance;
	cout << "Enter the number of months to accrue interest:";
	cin >> num_of_month;
	cout << "Show month-by-month results - 'y' for yes, any other for no:";
	cin >> show_month;

	// show the balance amount each month
	if (show_month == 'y')
	{
		//accrueInterest(initial_balance, num_of_month, true);
		success = accrueInterest(initial_balance, num_of_month, true);

	}
	else // only show the total amount
	{
		//accrueInterest(initial_balance, num_of_month, false);
		success = accrueInterest(initial_balance, num_of_month, false);
	}
	if (success)
	{
		cout << endl;
		cout << "Main: Operation was successful!" << endl;
	}
	else
	{
		cout << endl;
		cout << "Main: Operation was NOT successful!" << endl;
	}
	return 0;
}


// define the function to calculate the balance for single month
bool accrueOneMonthsInterest(
	double &balanceAmt,
	const bool doPrintInfo)
{
	const double MINI_RATE = 0.0015;
	const double MAX_RATE = 0.004;
	const double STAND_RATE = 0.00225;
	double ratio;
	double previous_balance;
	double interest;

	if (balanceAmt >= 0)
	{
		previous_balance = balanceAmt;
		if (balanceAmt < 1000)
		{
			// calculate the interest and accumulate
			interest = previous_balance * MINI_RATE;
			ratio = MINI_RATE;
		}
		else if (balanceAmt >= 15000)
		{
			// calculate the interest and accumulate
			interest = previous_balance * MAX_RATE;
			ratio = MAX_RATE;
		}
		else
		{
			// calculate the interest and accumulate
			interest = previous_balance * STAND_RATE;
			ratio = STAND_RATE;
		}

		balanceAmt = balanceAmt + interest;

		// decide to print or not
		if (doPrintInfo)
		{
			cout << "Accruing interest for 1 month:" << endl;
			cout << "  Initial balance:" << previous_balance << endl;
			cout << "  Initial rate:" << ratio << endl;
			cout << "  Interest accrued:" << interest << endl;
			cout << "  New balance:" << balanceAmt << endl;
		}
		return 1;
	}
	else
	{
		// if the balanceAmt is negative--output error directly
		cout << "ERROR in accrueOneMonthsInterest:balanceAmt must be >= 0, but the value " \
			<< balanceAmt << " was provided!" << endl;
	}
	return 0;
}


// define the function to calculate the accumulated balance
bool accrueInterest(
	double &balanceAmt,
	const int numMonths,
	const bool doPrintEachMonth)
{
	if (balanceAmt >= 0 && numMonths > 0) // continue to calculate
	{
		double temp_balance = balanceAmt;
		int i = 0;
		// while loop execution
		while (i < numMonths)
		{
			accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
			i++;
		}
		// also give the output
		cout << "Interest accrued for " << numMonths << " months!" << endl;
		cout << endl;
		cout << "Initial balance: " << temp_balance << endl;
		cout << "Total interest accrued: " << (balanceAmt - temp_balance) << endl;
		cout << "Final balance: " << balanceAmt << endl;

		return 1;
	}
	else // give error output information
	{
		if (balanceAmt < 0)
		{
			accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
		}
		if (numMonths <= 0)
		{
			cout << "ERROR in accrueInterest : numMonths must be > 0, but the value " \
				<< numMonths << " was provided!" << endl;
		}
		cout << "Sorry, an error was detected.Unable to provide results!" << endl;

		return 0;
	}
}
