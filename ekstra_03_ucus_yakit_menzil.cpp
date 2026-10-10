// ============================================================================
//  EKSTRA 03 — Uçuş Yakıtı ve Menzil Hesaplayıcısı ✈️
// ----------------------------------------------------------------------------
//  Açıklama : Uçağın yakıt tüketimi, depodaki yakıt, ortalama hız ve emniyet
//             yüzdesine göre kullanılabilir yakıtı, tahmini uçuş süresini,
//             menzili ve emniyet payının menzile etkisini hesaplar.
//  Konular  : double, const, yüzde hesabı, tam sayı bölmesinden kaçınma
//
//  Not: Bu bir programlama alıştırmasıdır; gerçek uçuş planlamasında kullanılmaz.
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	// Tüm değerler ondalıklı olabileceği için double seçildi.
	double saateYakit, depoYakit, ortalamaHiz;   // litre/saat, litre, km/saat
	double tempYuzdesi;                           // Kullanıcıdan alınan geçici yüzde değeri

	cout << "Lutfen sirasiyla litre cinsinde ucagin saatte tukettigi yakit miktarini ve depodaki mevcut yakit miktarini giriniz. ";
	cin >> saateYakit >> depoYakit;
	cout << "Lutfen ucagin saatteki ucus hizini km/h cinsinden giriniz. ";
	cin >> ortalamaHiz;
	cout << "Lutfen emniyet icin gereken yakit yuzdesini giriniz. ";
	cin >> tempYuzdesi;

	// cin ile doğrudan const bir değişkene değer yazılamaz. Bu yüzden yüzde önce
	// geçici bir değişkene alınır, ardından değiştirilemez (const) hale getirilir.
	const double emniyetYuzdesi = tempYuzdesi;
	double tahminiSure, tahminiMenzil, menzilFark;

	// Kullanılabilir yakıt = Depodaki yakıt - (Depodaki yakıt * yüzde / 100)
	// Tahmini süre         = Kullanılabilir yakıt / Saatlik tüketim
	tahminiSure = ((depoYakit)-(depoYakit * (emniyetYuzdesi/100.0))) / (saateYakit);

	// Tahmini menzil = Tahmini süre * Ortalama hız
	tahminiMenzil = (((depoYakit)-(depoYakit * (emniyetYuzdesi/100.0))) / (saateYakit)) * (ortalamaHiz);

	// Menzil farkı = Emniyet payı ayrılmadan önceki menzil - Ayrıldıktan sonraki menzil
	menzilFark = ((depoYakit / saateYakit) * ortalamaHiz) - (((depoYakit)-(depoYakit * (emniyetYuzdesi/100))) / (saateYakit)) * (ortalamaHiz);

	cout << "Kullanabilir Yakit Miktari: " << (depoYakit)-(depoYakit * (emniyetYuzdesi / 100.0)) << " litre" << endl;
	cout << "Tahmini Ucus Suresi: " << tahminiSure << " saat" << endl;
	cout << "Tahmini Menzil: " << tahminiMenzil << " km" << endl;
	cout << "Emniyet Payi Dahil Edilmeyerek Ve Edilerek Ucus Menzili Farkı: " << menzilFark << " km" << endl;
}

// ----------------------------------------------------------------------------
//  Ek Görev: Emniyet yüzdesi int olarak alınsaydı ne olurdu?
// ----------------------------------------------------------------------------
//  int / int işlemi tam sayı bölmesi yapar. Örneğin 15 / 100 = 0 olur ve
//  emniyet yakıtı hiç ayrılmamış gibi hesaplanırdı.
//
//  Bu yüzden yüzdenin 100'e bölündüğü (emniyetYuzdesi / 100.0) kısımda double
//  kritik önem taşır. 100 yerine 100.0 yazmak da işlemi ondalıklı bölmeye zorlar.
//  (menzilFark satırında /100 yazılmış olsa da emniyetYuzdesi double olduğu
//  için orada da ondalıklı bölme yapılır.)
// ----------------------------------------------------------------------------
