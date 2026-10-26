// ============================================================================
//  03.03 — Sayının Tersi
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan sayıyı ters çevirerek yazdırır.
//  Örnek    : 123  ->  321
//  Yöntem   : Her turda son basamak koparılır ve ters sayının sonuna eklenir.
//  Konular  : while döngüsü, % 10 ve / 10, sayıyı basamak basamak kurma
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int sayi, basamak;
	int tersSayi = 0; // Ters çevrilmiş sayıyı biriktireceğimiz kumbara

	cout << "Bir sayi giriniz: ";
	cin >> sayi;

	int gecici = sayi; // Orijinal sayıyı bozmamak için bir yedek alıyoruz

	// Örnek (123):  tur 1 -> basamak 3, tersSayi = 0*10 + 3   = 3,   gecici 12
	//               tur 2 -> basamak 2, tersSayi = 3*10 + 2   = 32,  gecici 1
	//               tur 3 -> basamak 1, tersSayi = 32*10 + 1  = 321, gecici 0
	// tersSayi'yı 10 ile çarpmak, mevcut basamakları bir sola kaydırıp
	// en sağda yeni basamak için yer açar.
	while (gecici != 0) {
		basamak = gecici % 10;                // 1. Son basamağı kopar
		tersSayi = (tersSayi * 10) + basamak; // 2. Basamağı ters sayının sonuna ekle
		gecici = gecici / 10;                 // 3. Sayıyı 10'a bölerek son basamaktan kurtul
	}

	cout << sayi << " sayisinin tersi: " << tersSayi << endl;
}
