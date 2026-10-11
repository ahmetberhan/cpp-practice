// ============================================================================
//  06 — Karakterin ASCII Kodu
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan bir karakterin ASCII kodunu yazdırır.
//  Konular  : char, static_cast ile tür dönüşümü
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	char karakter;

	cout << "Lutfen bir karakter giriniz: ";
	cin >> karakter;

	// static_cast<int> ile karakter, sayısal karşılığına çevrilir.
	// Örnek: 'A' -> 65, 'a' -> 97, '0' -> 48
	cout << "Girilen karakterin ASCII degeri: " << static_cast<int>(karakter) << endl;
}
