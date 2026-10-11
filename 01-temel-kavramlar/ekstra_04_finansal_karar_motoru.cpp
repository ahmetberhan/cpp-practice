// ============================================================================
//  EKSTRA 04 — Küçük Bir Finansal Karar Motoru
// ----------------------------------------------------------------------------
//  Açıklama : Öğrencinin aylık bütçesi ve giderleri üzerinden toplam gideri,
//             kalan parayı, gider oranını ve borç / rezerv durumunu hesaplar.
//  Konular  : double, bool, &&, üçlü operatör (?:), if / else if / else
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	// Para tutarlarında kuruş (ör. 1250.75 TL) olabileceği için double seçildi.
	double aylikButce, yurtGideri, yemekGideri, ulasimGideri;

	cout << "Lutfen Aylik butcenizi giriniz ";
	cin >> aylikButce;
	cout << "Lutfen sirasiyla yurt, yemek ve ulasim giderlerinizi giriniz. ";
	cin >> yurtGideri >> yemekGideri >> ulasimGideri;

	double toplamGider = yurtGideri + yemekGideri + ulasimGideri;
	double kalanPara = aylikButce - toplamGider;

	// ---------------- Finansal Özet ----------------
	cout << "\n--- FINANSAL OZET ---" << endl;
	cout << "Bu Ayki Toplam Gideriniz: " << toplamGider << " tl" << endl;
	cout << "Bu Ay Elinizde Kalan Toplam Miktar: " << kalanPara << " tl" << endl;

	// Gider oranı (%) = (Toplam gider / Aylık bütçe) * 100
	cout << "Bu Ayki Giderleriniz Aylik Butcenize Yuzdekik Olarak Orani: " << ((toplamGider / aylikButce) * 100) << endl;

	// ---------------- Kontroller ----------------
	cout << "\n--- KONTROLLER VE DURUM ---" << endl;

	// Üçlü operatör (koşul ? "Evet" : "Hayir"):
	// Koşul doğruysa ilk değer, yanlışsa ikinci değer yazdırılır.
	bool borcsuzMu = kalanPara >= 0;
	cout << "Kalan para 0'a esit veya buyuk mu? " << (borcsuzMu ? "Evet" : "Hayir") << endl;

	bool enAz1000TLMi = kalanPara >= 1000;
	cout << "Kalan para en az 1000TL mi: " << (enAz1000TLMi ? "Evet" : "Hayir") << endl;

	// ---------------- Karar ----------------
	// && (VE) operatörü: İki koşul da doğruysa sonuç true olur.
	if (kalanPara > 0 && kalanPara >= 1000)
	{
		cout << "Ogrenci hem borcsuz hem de en az 1000 TL rezervli! ";
	}
	else if (kalanPara > 0)
	{
		cout << "Ogrenci borcsuz ancak 1000 TL rezerv hedefinin altinda. ";
	}
	else
	{
		cout << "Ogrenci bu ay eksiye dustu veya parasi tamamen bitti! ";
	}
}

// ----------------------------------------------------------------------------
//  Ek Görev 1: x = 1000 ile x == 1000 arasındaki fark nedir?
// ----------------------------------------------------------------------------
//  x = 1000   ->  ATAMA operatörüdür. x değişkenine 1000 değerini verir.
//  x == 1000  ->  KARŞILAŞTIRMA operatörüdür. x'in 1000'e eşit olup olmadığını
//                 kontrol eder; sonuç olarak true veya false döndürür.
//
//  if (x = 1000) gibi bir yazım hatası x'i 1000 yapar ve koşulu her zaman
//  doğru kabul ettirir. Bu, fark edilmesi zor bir mantık hatasıdır.
//
// ----------------------------------------------------------------------------
//  Ek Görev 2: Bütçe hesaplarında neden int yerine double?
// ----------------------------------------------------------------------------
//  Para tutarları kuruşlu olabilir (ör. 349.90 TL). int kullanılsaydı
//  küsuratlar atılır ve toplamlar hatalı çıkardı. Ayrıca gider oranı
//  hesabında int / int tam sayı bölmesi yapılacağı için oran çoğu zaman
//  0 olarak hesaplanırdı.
// ----------------------------------------------------------------------------
