// ============================================================================
//  03.04 — 1–100 Arasında 3'e Bölünenlerin Toplamı
// ----------------------------------------------------------------------------
//  Açıklama : 1'den 100'e kadar olan sayılardan 3'e tam bölünenlerin
//             toplamını bulur.
//  Sonuç    : 3 + 6 + 9 + ... + 99 = 1683
//  Konular  : for döngüsü içinde if, % (mod), += operatörü
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int toplam(0);

	// 1'den 100'e kadar tüm sayılar tek tek dolaşılır;
	// yalnızca 3'e tam bölünenler toplama eklenir.
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			toplam += i;            // toplam = toplam + i ile aynı
		}
	}

	cout << "Birden yuze kadar olan uce bolunen sayilarin toplami: " << toplam << endl;
}
