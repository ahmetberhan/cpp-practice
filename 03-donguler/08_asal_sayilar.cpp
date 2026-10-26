// ============================================================================
//  03.08 — 1'den 100'e Kadar Asal Sayılar
// ----------------------------------------------------------------------------
//  Açıklama : 1 ile 100 arasındaki asal sayıları listeler.
//  Tanım    : Asal sayı, yalnızca 1'e ve kendisine bölünebilen, 1'den büyük
//             doğal sayıdır.  (2, 3, 5, 7, 11, ...)
//  Konular  : İç içe for döngüleri, bool bayrak (flag) değişkeni, break
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	cout << "1'den 100'e kadar olan asal sayilar:" << endl;

	// Dış döngü: 2'den 100'e kadar her sayıyı tek tek ele alır.
	// (1 asal sayı olmadığı için 2'den başlanır.)
	for (int sayi = 2; sayi <= 100; sayi++) {
		bool asalMi = true;         // Aksi kanıtlanana kadar sayı asal kabul edilir

		// İç döngü: 2'den sayının kendisine kadar bölen arar.
		for (int i = 2; i < sayi; i++) {
			if (sayi % i == 0) {
				asalMi = false;     // Bir bölen bulundu -> asal değil
				break;              // Daha fazla aramaya gerek yok, iç döngüden çık
			}
		}

		if (asalMi) {
			cout << sayi << endl;
		}
	}
}
