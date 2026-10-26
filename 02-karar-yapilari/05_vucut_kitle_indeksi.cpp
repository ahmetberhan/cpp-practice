// ============================================================================
//  02.05 — Vücut Kitle İndeksi (VKİ)
// ----------------------------------------------------------------------------
//  Açıklama : Kilo ve boydan vücut kitle indeksini hesaplar ve sınıflandırır.
//  Formül   : VKİ = kilo / (boy * boy)        (kilo: kg, boy: metre)
//  Sınıflar : < 18.5 Zayıf | 18.5 – 25 Normal | 25 – 30 Fazla Kilolu | ≥ 30 Obez
//  Konular  : double, aralık kontrolü, if / else if / else
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	double boy, kilo, vki;

	cout << "Kilonuzu giriniz (kg): ";
	cin >> kilo;

	cout << "Boyunuzu giriniz (metre cinsinden, örn: 1.75): ";
	cin >> boy;

	vki = (kilo / (boy * boy));

	// Her koşul bir aralığı temsil eder: alt sınır dahil (>=), üst sınır hariç (<).
	// Böylece 25.0 gibi sınırdaki bir değer yalnızca tek bir sınıfa girer.
	if (vki < 18.5) {
		cout << "Kategori: Zayif" << endl;
	}
	else if (vki >= 18.5 && vki < 25.0) {
		cout << "Kategori: Normal" << endl;
	}
	else if (vki >= 25.0 && vki < 30.0) {
		cout << "Kategori: Fazla Kilolu" << endl;
	}
	else {
		cout << "Kategori: Obez" << endl;
	}
}
