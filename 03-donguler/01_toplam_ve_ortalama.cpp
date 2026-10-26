// ============================================================================
//  03.01 — 1'den N'e Kadar Toplam ve Ortalama
// ----------------------------------------------------------------------------
//  Açıklama : 1'den kullanıcının girdiği N sayısına kadar olan sayıların
//             toplamını ve ortalamasını bulur.
//  Örnek    : N = 5  ->  1 + 2 + 3 + 4 + 5 = 15, ortalama = 3
//  Konular  : for döngüsü, toplayıcı (akümülatör) değişken, static_cast
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int N, toplam(0);       // toplam 0'dan başlamalı; her turda üzerine eklenecek

	cout << "Bir N dogal sayisini giriniz. ";
	cin >> N;

	// N, 1 veya daha büyük bir doğal sayı olmalı. 0 ya da negatif girilirse
	// ortalama hesabında sıfıra (veya anlamsız bir sayıya) bölme olurdu.
	if (N < 1)
	{
		cout << "Lutfen 1 veya daha buyuk bir sayi giriniz. " << endl;
	}
	else
	{
		// for (başlangıç; koşul; artış)
		// i, 1'den başlar ve N'e eşit olana kadar her turda 1 artar.
		for (int i = 1; i <= N; i++)
		{
			toplam = toplam + i;
		}

		// toplam ve N ikisi de int; doğrudan bölünse tam sayı bölmesi olurdu
		// (ör. 10 / 4 = 2). static_cast<double> ile ondalıklı sonuç elde edilir.
		double ortalama = static_cast<double>(toplam) / N;


		cout << "1'den n'e kadar olan sayilarin toplami: " << toplam << endl;
		cout << "Aritmetik ortalamasi: " << ortalama;
	}
}
