#include <stdio.h>
/*zerowanie tablicy int*/
void clear_table_int(int *table, int size_table);
/*funkcja sprawdza czy jest to interesujący nas znak*/
int czy_to_znak(int a);
/*funkcja wypisuje n razy podany znak*/
void wypisz_n_znakow(int n, char *znak);
/*funkcja wypisuje znaki ascii w zrozumiałej dla nas formie, wraz z: \n \t \v \f \r spacja */
void wypisz_znaki_ascii(int a);

int main()
{
    int table_ascii_numbers[128];
    int table_ascii_numbers_size =
        sizeof(table_ascii_numbers) / sizeof(int);
    int c;
    int wypisz;
    int liczba_znakow;

    clear_table_int(table_ascii_numbers, table_ascii_numbers_size);

    while ((c = fgetc(stdin)) != EOF) {
        if (czy_to_znak(c)) {
            table_ascii_numbers[c]++;
        }
    }

    printf("\nZnak\tLiczba znaków\n");
    printf("---------------------\n");

    wypisz = 0;
    while (wypisz++ < 128) {
        liczba_znakow = table_ascii_numbers[wypisz];
        if (czy_to_znak(wypisz) && (liczba_znakow != 0)) { /*wypisujemy tylko interesujące nas znaki*/
            wypisz_znaki_ascii(wypisz);
            printf("\t%d ", liczba_znakow);
            wypisz_n_znakow(liczba_znakow, "*");
        }
    }

    return 0;
}

void clear_table_int(int *table, int size_table)
{
    while (size_table-- > 0)
        table[size_table] = 0;
}

int czy_to_znak(int a)
{
    if (a > 0 && a < 127)
        return 1;
    else
        return 0;
}

void wypisz_n_znakow(int n, char *znak)
{

    while (n--)
    printf(znak);
    printf("\n");
}

void wypisz_znaki_ascii(int a)
{
    if (a == '\n')
        printf("\\n");
    else if (a == '\v')
        printf("\\v");
    else if (a == '\t')
        printf("\\t");
    else if (a == '\r')
        printf("\\r");
    else if (a == '\f')
        printf("\\f");
    else if (a == ' ')
        printf("spacja");
    else
        printf("%c", a);
}
