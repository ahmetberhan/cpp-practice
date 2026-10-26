// ============================================================================
//  02.03 — Üç Sayının En Büyüğü ve En Küçüğü
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan üç sayı alır; en büyüğünü ve en küçüğünü yazdırır.
//  Yöntem   : İlk sayı hem en büyük hem en küçük kabul edilir, diğer sayılar
//             bununla tek tek karşılaştırılıp gerekirse güncellenir.
//  Konular  : Bağımsız if blokları, karşılaştırma, double
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	double sayi1(0), sayi2(0), sayi3(0);

	cout << "Lutfen birinci sayiyi giriniz. ";
	cin >> sayi1;
	cout << "Lutfen ikinci sayiyi giriniz. ";
	cin >> sayi2;
	cout << "Lutfen ucuncu sayiyi giriniz. ";
	cin >> sayi3;

	// Başlangıçta elimizdeki tek sayı birincisi; o hem en büyük hem en küçük.
	double enBuyuk = sayi1;
	double enKucuk = sayi1;

	// En büyüğü bul: Daha büyük bir sayı görülürse enBuyuk güncellenir.
	// Burada else if değil ayrı if kullanılır; çünkü her sayının
	// mutlaka kontrol edilmesi gerekir.
	if (sayi2 > enBuyuk)
	{
		enBuyuk = sayi2;
	}
	if (sayi3 > enBuyuk)
	{
		enBuyuk = sayi3;
	}

	// En küçüğü bul: Aynı mantık, karşılaştırma ters yönde.
	if (sayi2 < enKucuk)
	{
		enKucuk = sayi2;
	}
	if (sayi3 < enKucuk)
	{
		enKucuk = sayi3;
	}

	cout << "En buyuk sayi: " << enBuyuk << endl;
	cout << "En kucuk sayi: " << enKucuk << endl;
}
