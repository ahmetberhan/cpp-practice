// ============================================================================
//  EKSTRA 01 — Kişisel Sistem Bilgisi Kartı
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcının isim, yaş ve çalışma bilgilerini alır; haftalık
//             toplam çalışma süresini hesaplayıp rapor olarak yazdırır.
//  Formül   : Haftalık süre = Gün sayısı * Günlük saat
//  Konular  : string, int, double, uygun veri tipi seçimi
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	// Veri tipi seçimleri:
	//   isim       -> string : Metin bilgisi
	//   yas, gun   -> int    : Her zaman tam sayıdır
	//   gunlukSaat -> double : 7.5 saat gibi ondalıklı değerler alabilir
	//   haftalik   -> double : Hesaplama sonucu ayrı bir değişkende tutulur
	string isim;
	int yas, gun;
	double gunlukSaat, haftalik;

	cout << "Lutfen isminizi giriniz. ";
	cin >> isim;
	cout << "Lutfen yasinizi giriniz. ";
	cin >> yas;
	cout << "Lutfen gunluk calisma surenizi saat cinsinden giriniz. ";
	cin >> gunlukSaat;
	cout << "Lutfen haftada kac gun calistiginizi giriniz. ";
	cin >> gun;

	// Haftalık toplam çalışma süresi hesaplanır.
	haftalik = gun * gunlukSaat;

	cout << "Isim: " << isim << endl
	     << "Yasi: " << yas  << endl
	     << "Haftalik Calisma Suresi: " << haftalik;
}

// ----------------------------------------------------------------------------
//  Ek Soru: Haftalık toplam çalışma süresinin ondalıklı çıkabilmesi neden önemli?
// ----------------------------------------------------------------------------
//  Günlük çalışma süresi 6.5 saat gibi küsuratlı olabilir.
//  5 gün * 6.5 saat = 32.5 saattir. Sonuç int tutulsaydı .5 kısmı atılır ve
//  32 saat yazılırdı; yani gerçek çalışma süresi eksik gösterilirdi.
// ----------------------------------------------------------------------------
