// ============================================================================
//  07 — Geçici Değişken Kullanmadan Takas (Swap)
// ----------------------------------------------------------------------------
//  Açıklama : İki değişkenin değerlerini üçüncü bir değişken kullanmadan
//             yer değiştirir.
//  Yöntem   : Toplama - çıkarma
//  Konular  : Atama operatörü, değişken başlatma
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int a(20), b(10);   // Başlangıç: a = 20, b = 10

	a = a + b;          // a = 30  ->  İki sayının toplamı a'da tutulur
	b = a - b;          // b = 20  ->  Toplamdan b çıkarılınca a'nın eski değeri kalır
	a = a - b;          // a = 10  ->  Toplamdan yeni b çıkarılınca b'nin eski değeri kalır

	cout << "a: " << a << endl << "b: " << b << endl;
}
