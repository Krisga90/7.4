#include <iostream>

long double prawdopodobienstwo(unsigned int ilosc_liczb, unsigned int losowanych, unsigned int power_ball);
long double prawdopodobienstwo(unsigned int macierz[]);
void pobieranie(unsigned int[]);
unsigned int pobieranie_uint(void);

int main()
{
	unsigned int loteria[3] = { 0,0,0 };
	std::cout << "program oblicza prawdopodobiensto wygranej w loterii liczbowej.\n";
	pobieranie(loteria);
	std::cout << "\n\nTwoje szanse na wygrana sa jak 1 do " << prawdopodobienstwo(loteria);




	std::cin.get();
	std::cin.get();
	return 0;
}

unsigned int pobieranie_uint(void)
{
	unsigned int liczba;
	while (!(std::cin >> liczba))
	{

		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "podano nieprawidlowy znak\n podaj liczbe:";
	}
	return liczba;
}
void pobieranie(unsigned int macierz[])
{
	std::cout << "Podaj ilosc wszystkich liczb: ";
	macierz[0] = pobieranie_uint();
	std::cout << "Podaj ilosc losowanych liczb: ";
	macierz[1] = pobieranie_uint();
	std::cout << "Podaj ilosc wszystkich liczb dla power ball, 0 jezeli nie bierzesz udzialu: ";
	macierz[2] = pobieranie_uint();
}

long double prawdopodobienstwo(unsigned int ilosc_liczb, unsigned int losowanych, unsigned int power_ball)
{
	long double chance=1.0;
	while (losowanych > 0)
	{
		chance *= double(ilosc_liczb) / losowanych;
		ilosc_liczb--;
		losowanych--;
	}
	if (power_ball)
		chance *= power_ball;

	return chance;
}

long double prawdopodobienstwo(unsigned int macierz[])
{
	long double chance = 1.0;
	unsigned int losowanych = macierz[1];
	unsigned int ilosc_liczb = macierz[0];
	unsigned int power_ball = macierz[2];

	while (losowanych > 0)
	{
		chance *=double( ilosc_liczb )/ losowanych;
		ilosc_liczb--;
		losowanych--;
	}
	if (power_ball)
		chance *= power_ball;

	return chance;
}