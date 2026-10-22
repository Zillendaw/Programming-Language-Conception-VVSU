#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <iomanip>

using namespace std;

double convert_from_binary_to_decimal(uint64_t sign, uint64_t exponenta, uint64_t mantissa)
{
	double result = 0;
	int plus_sign = 0;
	int poryadok = 0;
	double drob = 0;
	double number_with_one = 0;
	
	if (sign == 0)
	{
		plus_sign = 1;
	}
	else
	{
		plus_sign = -1;
	}
	
	poryadok = exponenta - 1023;
	
	drob = mantissa / pow(2,52);
	
	number_with_one = 1 + drob;
	
	result = plus_sign * number_with_one * pow(2,poryadok);

	return result;
}

void print_bit_doubles(double x)
{
	cout << "Исходное число: " << x << endl;
	
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
	cout << endl;
	
	uint64_t sign = bits >> 63;
	cout << "\nЗнак: " << sign << endl;
	
	uint64_t exponenta_memory = (bits >> 52) & 0x7FF;
	cout << "\nЭкспонента: " << exponenta_memory;
	cout << endl;
	
	uint64_t mantissa = bits & 0xFFFFFFFFFFFFFULL;
	cout << "\nМантисса: " << mantissa;
	cout << endl << endl;
	
	double res = convert_from_binary_to_decimal(sign,exponenta_memory,mantissa);
	
	cout << "Результат после расчёта знака + экспонента + мантисса: " << res << endl;
}

int main()
{
	double res_1;
	double res_2;
	
	cout << endl;
	
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
	cout << "------------------------------------------------------------\n";
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
