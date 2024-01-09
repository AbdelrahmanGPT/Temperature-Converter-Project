#include<iostream>
#include"ABODAstd.h"

using namespace std;

void PrintConversionMenu()
{
	cout << "-----------------------------------\n" <<
		"CELSIUS TO FAHRENHEIT : 1\n" <<
		"FAHRENHEIT TO CELSIUS : 2\n" <<
		"EXIT : 0\n" <<
		"-----------------------------------\n";

}

double ReadTemperature(string Message)
{
	double Temperature;

	cout << Message << "\n";
	cin >> Temperature;

	return Temperature;
}

double CelsiusToFahrenheit(double CelsiusTemperature)
{
	return (CelsiusTemperature * (9.0 / 5)) + 32;
}

void PrintCelsiusToFahrenheit(double CelsiusTemperature)
{
	cout << "TEMPERATURE IN FAHRENHEIT = " << CelsiusToFahrenheit(CelsiusTemperature) << " °F\n";
}

double FahrenheitToCelsius(double FahrenheitTemperature)
{
	return (FahrenheitTemperature - 32) * (5 / 9.0);
}

void PrintFahrenheitToCelsius(double FahrenheitTemperature)
{
	cout << "TEMPERATURE IN CELSIUS = " << FahrenheitToCelsius(FahrenheitTemperature) << " °C\n";
}

void TemperatureConverter()
{
	cout << "WELCOME TO TEMPERATURE CONVERTER\n";
	Menu : do
	{
		PrintConversionMenu();
		
		unsigned Choice;

		cin >> Choice;

		if (Choice == 1)
		{
			double CelsiusTemperature = ReadTemperature("ENTER TEMPERATURE IN CELSIUS");
			PrintCelsiusToFahrenheit(CelsiusTemperature);
		}

		else if (Choice == 2)
		{
			double FahrenheitTemperature = ReadTemperature("ENTER TEMPERATURE IN FAHRENHEIT");
			PrintFahrenheitToCelsius(FahrenheitTemperature);
		}

		else if (Choice == 0)
		{
			cout << "GOOD BYE :)\n";
			break;
		}

		else
		{
			cout << "INVALID CHOICE\n";
			goto Menu;
		}
	} while (DoYouWantToContinue());
}

int main()
{
	
	TemperatureConverter();

	return 0;
}