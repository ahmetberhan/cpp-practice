// ============================================================================
//  02.04 — Sesli mi, Sessiz mi? (switch)
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan harfin sesli mi sessiz mi olduğunu
//             switch-case yapısıyla bulur.
//  Konular  : switch, case, default, break, char
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	char harf;

	cout << "Lutfen bir harf giriniz. ";
	cin >> harf;

	// switch, değişkenin değerini case etiketleriyle tek tek eşleştirir.
	// Arka arkaya yazılan case'ler aynı kodu paylaşır: Büyük ve küçük
	// sesli harflerin hepsi aşağıdaki tek cout satırına düşer.
	// break, switch'ten çıkmayı sağlar; yazılmasaydı alttaki case'ler de çalışırdı.
	switch (harf) {
	case 'a': case 'A':
	case 'e': case 'E':
	case 'i': case 'I':
	case 'o': case 'O':
	case 'u': case 'U':
		cout << "Sesli harf sectiniz." << endl;
		break;

	// default: Hiçbir case ile eşleşmezse çalışır (if / else'teki else gibi).
	default:
		cout << "Sessiz harf sectiniz." << endl;
		break;
	}
}
