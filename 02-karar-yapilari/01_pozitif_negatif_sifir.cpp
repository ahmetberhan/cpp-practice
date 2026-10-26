// ============================================================================
//  02.01 — Pozitif, Negatif veya Sıfır
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan bir sayının pozitif, negatif veya sıfır
//             olduğunu ekrana yazdırır.
//  Konular  : if / else if / else, karşılaştırma operatörleri (>, <)
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int sayi;

	cout << "Lutfen bir sayi giriniz. ";
	cin >> sayi;

	// Koşullar yukarıdan aşağı kontrol edilir; ilk doğru olan çalışır.
	// Sayı ne 0'dan büyük ne de 0'dan küçükse, geriye tek ihtimal kalır: sıfır.
	if (sayi > 0)
	{
		cout << "Sectiginiz sayi pozitif. ";
	}
	else if (sayi < 0)
	{
		cout << "Sectiginiz sayi negatif. ";
	}
	else
	{
		cout << "Sectiginiz sayi sifir. ";
	}
}
