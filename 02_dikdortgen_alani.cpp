// ============================================================================
//  02 — Dikdörtgenin Alanı
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan dikdörtgenin iki kenarını alır ve alanını hesaplar.
//  Formül   : Alan = a * b
//  Konular  : int, cin / cout, çarpma operatörü
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int aKenarı, bKenarı;

	// Kenar uzunlukları kullanıcıdan alınır.
	cout << "Lutfen dikdortgenin a kenarini giriniz: ";
	cin >> aKenarı;

	cout << "Lutfen dikdortgenin b kenarini giriniz: ";
	cin >> bKenarı;

	// Alan doğrudan cout içinde hesaplanıp yazdırılır.
	cout << "Dikdortgenin alani: " << aKenarı * bKenarı << endl;
}
