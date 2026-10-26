// ============================================================================
//  03.05 — 0 Girilene Kadar En Büyük Sayı
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcı 0 girene kadar sayı alır; girilenlerin en büyüğünü
//             yazdırır.
//  Yöntem   : İlk sayı en büyük kabul edilir; sonraki her sayı onunla
//             karşılaştırılır. 0 girildiğinde döngü biter.
//  Konular  : while döngüsü, bitiş değeri (sentinel), karşılaştırma
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int sayi, enBuyuk;


	cout << "Lutfen sayilari giriniz (Bitirmek icin 0 girin): ";
	cin >> sayi;

	// Elimizdeki ilk sayı, şimdilik en büyük sayıdır.
	enBuyuk = sayi;

	// Kaç sayı girileceği bilinmediği için while kullanılır.
	// 0, "girişi bitir" anlamına gelen özel bir değerdir.
	while (sayi != 0)
	{
		if (sayi > enBuyuk)
		{
			enBuyuk = sayi;
		}

		cin >> sayi;                // Bir sonraki sayıyı oku (0 ise döngü biter)

	}

	cout << "Girilen en buyuk sayi: " << enBuyuk;
}
