#include <stdio.h>

long double silnia(int a);
int podaj_liczbe(char *prompt);
void silnia_n_pierwszych(int x);

int main()
{
    int a;

    a = podaj_liczbe("Podaj liczbę naturlną: ");

    silnia_n_pierwszych(a);

    return 0;
}

int podaj_liczbe(char *prompt)
{
    int n;

    printf(prompt);
    scanf("%d", &n);

    if (n < 1) {
	while (n < 1) {
	    printf
		("Blad: liczba mniejsza niz '1'\n Podaj liczbe wieksza niz 1: \n");
	    scanf("%d", &n);
	}
    }
    return n;
}

long double silnia(int a)
{
    int i = a--;

    while (a) {
	i *= a--;
    }

    return i;
}

void silnia_n_pierwszych(int x){
    long double sil;

    while (x > 0) {

	sil = silnia(x);

	printf("Silnia z %d to: %Lf\n", x, sil);

	x--;
    }
}
