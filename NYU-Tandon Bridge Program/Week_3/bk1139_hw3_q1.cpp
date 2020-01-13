//This code assumes the user will only enter valid responses when prompted****
//Precision set to match output exactly as shown in homework prompt

#include <iostream>
using namespace std;

//declare and initialize constants for half off, additional 10% discount, and decimal conversion values for tax rate
const double HALF_OFF = 0.5, ADDITIONAL_10 = 0.9, DECIMAL_CONVERT = 100.0, TAX_RATE_DECIMAL_ADD_ON = 1.0;

int main()
{
	//declare variables of type double and char for all user entered information
	double user_item_price_1, user_item_price_2;
	double user_tax_rate; 
	char has_club_card;

	//declare variables needed to determine output results to the user
	double higher_priced_item, lower_priced_item;
	double tax_rate_as_decimal;
	double base_price, price_after_discounts, total_price;

	//set precision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);


	//Prompt user to enter item prices, whether or not they have a club card, and the tax rate
	cout << "Enter price of first item: ";
	cin >> user_item_price_1;

	cout << "Enter price of second item: ";
	cin >> user_item_price_2;

	cout << "Does customer have a club card? (Y/N): ";
	cin >> has_club_card;
		
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> user_tax_rate;


	//use if-else statenent to determine which item price should receive the half off discount
	if (user_item_price_1 >= user_item_price_2)
	{
		higher_priced_item = user_item_price_1;
		lower_priced_item = user_item_price_2;
	}
	else
	{
		higher_priced_item = user_item_price_2;
		lower_priced_item = user_item_price_1;
	}

	//use if-else statement to determine if the user has a club card or not to apply an additional 10% off
	if (has_club_card == 'Y' || has_club_card == 'y')
	{
		price_after_discounts = (higher_priced_item + (HALF_OFF * lower_priced_item)) * ADDITIONAL_10;
	}
	else
	{
		price_after_discounts = higher_priced_item + (HALF_OFF * lower_priced_item);
	}

	//determine the base price, tax rate as a decimal, and total price
	base_price = user_item_price_1 + user_item_price_2;
	tax_rate_as_decimal = user_tax_rate / DECIMAL_CONVERT;
	total_price = price_after_discounts * (tax_rate_as_decimal + TAX_RATE_DECIMAL_ADD_ON);

	//set precision at one decimal and output to the user the base price and price after discounts
	cout.precision(1);
	cout << "Base price: " << base_price << "\nPrice after discounts: " << price_after_discounts << endl;

	//set precision at five decimals and output to the user the total price                                                             
	cout.precision(5);
	cout << "Total price: " << total_price << endl;

	return 0;
}

