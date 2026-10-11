// ============================================================================
//  01 — Dört İşlem ve Mod Alma
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan iki sayı alır; toplam, fark, çarpım, bölüm ve
//             kalanı ekrana yazdırır.
//  Konular  : int, cin / cout, aritmetik operatörler (+, -, *, /, %)
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int sayi1, sayi2;

	// Kullanıcıdan iki sayı istenir.
	cout << "Lutfen birinci sayi giriniz: ";
	cin >> sayi1;

	cout << "Lutfen ikinci sayi giriniz: ";
	cin >> sayi2;

	// Sonuçlar alt alta yazdırılır.
	// Not: Sayılar int olduğu için bölme işlemi tam sayı bölmesidir (ör. 7 / 2 = 3).
	//      % (mod) operatörü bölümden kalanı verir (ör. 7 % 2 = 1).
	cout << "Toplam: " << sayi1 + sayi2 << endl
	     << "Fark "    << sayi1 - sayi2 << endl
	     << "Carpim "  << sayi1 * sayi2 << endl
	     << "Bolum "   << sayi1 / sayi2 << endl
	     << "Kalan "   << sayi1 % sayi2 << endl;
}
