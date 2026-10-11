// ============================================================================
//  05 — Üç Sınavın Ortalaması
// ----------------------------------------------------------------------------
//  Açıklama : Üç sınav notunu alır ve ortalamayı ondalıklı olarak yazdırır.
//  Formül   : Ortalama = (not1 + not2 + not3) / 3
//  Konular  : double, ondalıklı bölme
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	// Notlar double tutulduğu için ortalama küsuratlı olarak hesaplanır.
	double sinav1, sinav2, sinav3;

	cout << "Lutfen birinci sinav notunu giriniz: ";
	cin >> sinav1;

	cout << "Lutfen ikinci sinav notunu giriniz: ";
	cin >> sinav2;

	cout << "Lutfen ucuncu sinav notunu giriniz: ";
	cin >> sinav3;

	cout << "Ortalama: " << (sinav1 + sinav2 + sinav3) / 3 << endl;
}
