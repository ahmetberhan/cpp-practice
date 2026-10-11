// ============================================================================
//  08 — Üç Basamaklı Sayının Basamakları
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan üç basamaklı bir sayının yüzler, onlar ve
//             birler basamağını ayrı ayrı yazdırır.
//  Konular  : Bölme (/) ve mod (%) operatörleri, if / else, &&
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int sayi;

	cout << "Lutfen uc basamakli bir sayi girin: ";
	cin >> sayi;

	// Girilen sayının gerçekten üç basamaklı olup olmadığı kontrol edilir.
	if (sayi >= 100 && sayi <= 999) {
		int yuzler = sayi / 100;          // Ör. 472 / 100 = 4
		int onlar  = (sayi / 10) % 10;    // Ör. 472 / 10 = 47  ->  47 % 10 = 7
		int birler = sayi % 10;           // Ör. 472 % 10 = 2

		cout << "Yuzler Basamagi: " << yuzler << endl;
		cout << "Onlar Basamagi: "  << onlar  << endl;
		cout << "Birler Basamagi: " << birler << endl;
	}
	else {
		// Sayı aralık dışındaysa kullanıcı uyarılır.
		cout << "Hata! Lutfen uc basamakli bir sayi giriniz!" << endl;
	}
}
