// ============================================================================
//  03.02 — Basamakların Toplamı
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan sayının basamaklarının toplamını bulur.
//  Yöntem   : % 10 ile son basamak alınır, / 10 ile sayı küçültülür;
//             sayı 0 olana kadar tekrarlanır.
//  Örnek    : 472  ->  2 + 7 + 4 = 13
//  Konular  : while döngüsü, % ve / ile basamak ayırma
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int sayi, basamak, toplam(0);

	cout << "Lutfen bir sayi giriniz. ";
	cin >> sayi;

	// Asıl sayıyı sonda yazdırabilmek için işlemler bir kopya üzerinde yapılır.
	int gecici = sayi;

	// Kaç tur döneceği önceden bilinmediği için while kullanılır.
	// Örnek (472):  tur 1 -> basamak 2, gecici 47
	//               tur 2 -> basamak 7, gecici 4
	//               tur 3 -> basamak 4, gecici 0  -> döngü biter
	while (gecici > 0)
	{
		basamak = gecici % 10;      // Son basamağı al
		toplam += basamak;          // Toplama ekle
		gecici = gecici / 10;       // Son basamağı at

	}

	cout << sayi << " sayisinin basamaklari toplami: " << toplam << endl;
}
