// ============================================================================
//  02.02 — Artık Yıl Kontrolü
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan yılın artık yıl olup olmadığını bulur.
//  Kural    : 4'e bölünüyorsa artıktır; ancak 100'e bölünüyorsa artık değildir,
//             400'e bölünüyorsa yine artıktır.
//  Konular  : % (mod), && (VE), || (VEYA), birleşik koşullar
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int yil;

	cout << "Lutfen bir yil giriniz. ";
	cin >> yil;

	// Kural tek bir koşulda birleştirilmiştir. Yıl artıktır, eğer:
	//   400'e tam bölünüyorsa                              (ör. 2000 -> artık)
	//   VEYA  4'e bölünüp 100'e bölünmüyorsa               (ör. 2024 -> artık)
	// 1900 gibi 100'e bölünüp 400'e bölünmeyen yıllar iki şartı da sağlamaz.
	if ((yil % 400 == 0) || (yil % 4 == 0 && yil % 100 != 0)) {
		cout << yil << " bir artik yildir. (Subat 29 gun ceker. )" << endl;
	}
	else {
		cout << yil << " bir artik yil degildir. (Subat 28 gun ceker. )" << endl;
	}
}
