// ============================================================================
//  EKSTRA 02 — Ders Notu Hesaplayıcı
// ----------------------------------------------------------------------------
//  Açıklama : Vize, final ve ödev notlarından toplam, aritmetik ortalama ve
//             ağırlıklı ortalamayı hesaplar; dersi geçip geçmediğini belirler.
//  Ağırlık  : Vize %30  |  Ödev %20  |  Final %50
//  Konular  : double, bool, karşılaştırma operatörü, boolalpha
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	double vize, final, odev, aritmetikOrtalama, notToplamı, AgirlikliOrtalama;

	cout << "Lutfen vize basari puaninizi giriniz. ";
	cin >> vize;
	cout << "Lutfen final basari puaninizi giriniz. ";
	cin >> final;
	cout << "Lutfen odev basari puaninizi giriniz. ";
	cin >> odev;

	// Hesaplamalar
	aritmetikOrtalama = (vize + odev + final) / 3;
	notToplamı = vize + odev + final;
	AgirlikliOrtalama = (vize * 0.3) + (odev * 0.2) + (final * 0.5);

	// Karşılaştırmanın sonucu (true / false) bool değişkende saklanır.
	bool gectiMi = AgirlikliOrtalama >= 50.0;

	cout << "Notlarinizin Toplami: " << notToplamı << endl;
	cout << "Notlarinizin Aritmekik Ortalamasi: " << aritmetikOrtalama << endl;
	cout << "Agirlikli Basari Puaniniz: " << AgirlikliOrtalama << endl;

	// boolalpha sayesinde sonuç 1 / 0 yerine true / false olarak yazdırılır.
	cout << "Donemi Gecme Durumunuz: " << boolalpha << gectiMi << endl;
}
