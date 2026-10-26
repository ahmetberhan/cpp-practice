// ============================================================================
//  03.06 — Mükemmel Sayı Kontrolü
// ----------------------------------------------------------------------------
//  Açıklama : Bir sayının mükemmel sayı olup olmadığını kontrol eder.
//  Tanım    : Kendisi hariç pozitif bölenlerinin toplamı kendisine eşit olan
//             sayıdır.  Ör: 6 = 1 + 2 + 3,  28 = 1 + 2 + 4 + 7 + 14
//  Konular  : for döngüsü, % ile bölen bulma, += ile toplama
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int sayi;
	int toplam(0);

	cout << "Bir sayi giriniz. ";
	cin >> sayi;

	// 1'den sayının kendisine kadar (kendisi hariç: i < sayi) tüm sayılar denenir.
	// Sayıyı tam bölen her i, bir bölendir ve toplama eklenir.
	for (int i = 1; i < sayi; i++)
	{
		if (sayi % i == 0)
		{
			toplam += i;
		}
	}

	// sayi > 0 şartı, 0 ve negatif sayıların yanlışlıkla
	// "mükemmel" çıkmasını engeller.
	if (toplam == sayi && sayi > 0)
	{
		cout << "Sayiniz mukemmel sayidir. ";
	}
	else
	{
		cout << "Sayiniz mukemmel sayi degildir. ";
	}
}
