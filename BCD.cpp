// BCD.cpp : Defines the entry point for the console application.
// Converts decimal value to BCD value.

#include "stdafx.h"
#include <iostream>
using namespace std;

void show_bcd(unsigned int bin_wrd, unsigned int bcd_wts[16]);

int main()
{
	unsigned bin_wrd;
	unsigned int bcd_values[17], pos_val, index;

	// Build array with BCD values for comparison
	pos_val = 1;
	for (index = 1; index < 17; index++)
	{
		switch (pos_val)
		{
		case 16:
			pos_val = 10;
			break;
		case 160:
			pos_val = 100;
			break;
		case 1600:
			pos_val = 1000;
			break;
		}
		bcd_values[index] = pos_val;
		pos_val = pos_val * 2;
	}
	
	cout << "Enter a number between 0 and 9999: ";
	cin >> bin_wrd;

	show_bcd(bin_wrd, bcd_values);

	return 0;
}

// Show data function
void show_bcd(unsigned int bin_wrd, unsigned int bcd_wts[16])
{
	int idx;
	unsigned int tmp_wrd;
	tmp_wrd = bin_wrd;
	for (idx = 16; idx > 0; idx--)
	{
		if (tmp_wrd >= bcd_wts[idx])
		{
			cout << "1 ";
			tmp_wrd = tmp_wrd - bcd_wts[idx];
		}
		else cout << "0 ";

		// Create a space every 4 bits
		if (idx == 13 || idx == 9 || idx == 5) cout << " ";
	}
	cout << "\n";

}

