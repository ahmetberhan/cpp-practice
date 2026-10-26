// ============================================================================
//  03.07 — Üs Alma (pow kullanmadan)
// ----------------------------------------------------------------------------
//  Açıklama : Girilen tabanın, girilen üs kadar kuvvetini hesaplar.
//  Yöntem   : Sonuç 1'den başlar ve döngüde "üs" kadar tabanla çarpılır.
//  Örnek    : 2^5 = 1 * 2 * 2 * 2 * 2 * 2 = 32
//  Konular  : for döngüsü, *= operatörü, long long
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int taban, us;

	// Sonuç 1'den başlar: Çarpmada etkisiz eleman 1'dir (toplamadaki 0 gibi).
	// Üslü sayılar çok hızlı büyüdüğü için int yerine daha geniş olan long long
	// kullanılır. (int ~2.1 milyara, long long ~9.2 kentilyona kadar sayı tutar.)
	long long sonuc(1);

	cout << "Lutfen sayi ve ussunu sirasi ile giriniz. ";
	cin >> taban >> us;

	for (int i = 1; i <= us; i++)
	{
		sonuc *= taban;             // sonuc = sonuc * taban ile aynı
	}

	cout << taban << "^" << us << " = " << sonuc << endl;
}
