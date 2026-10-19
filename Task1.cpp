#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iomanip>

using namespace std;

void print_bit_doubles(double x)
{
	// Создаем 64 битные целые числа
	uint64_t bits;
	
	memcpy(&bits, &x, sizeof(bits));
	
	for (int i = 63; i >= 0; i--)
	{
		// Сдвигаем нужный бит на нулевую позицию
		int bit = (bits >> i) & 1;
		
		cout << bit;
		
		if (i == 63 || i == 52)
		{
			cout << " ";
		}
	}
	
	int sign = bits >> 63;
	cout << "\nЗнак: " << sign << endl;
	
	cout << "\nЭкспонента: ";
	for (int i = 62; i >= 52; i--)
	{
		int exponenta = (bits >> i) & 1;
		cout << exponenta;
	}
	cout << endl;
	
	cout << "\nМантисса: ";
	for (int i = 51; i >= 0; i--)
	{
		int mantissa = (bits >> i) & 1;
		cout << mantissa;
	}
	cout << endl;
	
}

int main()
{
	double res_1;
	double res_2;
	
	cout << endl;
	
	/*cout << "Bit operations 1:\n";
	print_bit_doubles(res_1);
	cout << endl;
	
	cout << "Bit operations 2:\n";
	print_bit_doubles(res_2);
	cout << endl;*/
	
	//for (int i = 1; i <= pow(10.0,n); i++)
	int i_1 = 1;
	while(true)
	{
		//cout << "Последовательность: 1 + 1/(10^n):" << " Шаг: " << i_1 << endl;
		res_1 = 1.0 + 1.0 / pow(10.0,i_1);
		cout << "ORIGINAL NUMBER: " << setprecision(20) <<res_1 << endl;
		print_bit_doubles(res_1);
		if(res_1 == 1.0)
		{
			cout << "Stopped..." << endl;
			cout << "n = " << i_1 << endl;
			break;
		}
		cout << endl;
		i_1++;
	}
	cout << "-----------------------------\n";
	//for (int i = 1; i <= pow(2.0,k); i++)
	int i_2 = 1;
	while(true)
	{
		//cout << "Последовательность: 1 + 1/(2^k):" << " Шаг: " << i_2 << endl;
		res_2 = 1.0 + 1.0 / pow(2.0,i_2);
		cout << "ORIGINAL NUMBER: " << setprecision(20) << res_2 << endl;
		print_bit_doubles(res_2);
		if(res_2 == 1.0)
		{
			cout << "Stopped..." << endl;
			cout << "k = " << i_2 << endl;
			break;
		}
		cout << endl;
		i_2++;
	}
}
