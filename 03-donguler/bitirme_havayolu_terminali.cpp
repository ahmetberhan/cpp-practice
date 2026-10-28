// ============================================================================
//  BİTİRME PROJESİ (Bölüm 02–03) — Mini Havayolu Bilet Terminali ✈️
// ----------------------------------------------------------------------------
//  Açıklama : Bir havalimanı bankosunu taklit eden menülü program. Kullanıcı
//             "Çıkış" diyene kadar açık kalır; her işlem hafızada birikir.
//
//               1 - Bilet sat              -> Yaşa ve sınıfa göre fiyat, bilet numarası
//               2 - Bagaj kontrolü         -> Hatalı bagajı atla, fazla kg ücreti
//               3 - Bilet numarası doğrula -> Kontrol hanesi ile doğrulama
//               4 - Gün sonu raporu        -> Gelirler, doluluk, koltuk haritası
//               0 - Çıkış
//
//  Konular  : do-while (menü ve giriş doğrulama), switch / default,
//             if / else if, iç içe switch, while, continue, break,
//             iç içe for, % 10 ve / 10 ile basamak işlemleri, ?: operatörü,
//             sayaç / toplayıcı / en büyük takibi, static_cast, const
//
//  Not: Bu bir programlama alıştırmasıdır; gerçek bilet satışında kullanılmaz.
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// ------------------------------------------------------------------------
	//  SABİTLER — Programın kuralları; çalışırken değişmezler.
	// ------------------------------------------------------------------------
	const int kapasite(10);                     // Uçaktaki koltuk sayısı
	const int siraBasinaKoltuk(5);              // Koltuk haritasında bir sıradaki koltuk
	const double ekonomiFiyat(1500), businessFiyat(4000);          // Taban fiyatlar (TL)
	const double ucretsizBagajKg(20), fazlaKgUcreti(50), maxBagajKg(32);
	const int maxBagajAdedi(3);                 // Yolcu başına en fazla bagaj

	// ------------------------------------------------------------------------
	//  SAYAÇLAR — Ana döngüden ÖNCE tanımlanır ki menü turları boyunca
	//  değerlerini korusunlar. Döngünün içinde tanımlansalardı her turda
	//  sıfırlanır, gün sonu raporu hep 0 gösterirdi.
	// ------------------------------------------------------------------------
	int secim, satilanKoltuk(0), ekonomiSayisi(0), businessSayisi(0), indirimliYolcu(0);
	double biletGeliri(0), enYuksekFiyat(0), bagajGeliri(0);


	// ========================================================================
	//  ANA MENÜ — do-while: Menü en az bir kez gösterilir, 0 girilene kadar
	//  tekrar eder.
	// ========================================================================
	do
	{
		cout << "\n========== MINI HAVAYOLU TERMINALI ==========" << endl;
		cout << "1 - Bilet sat" << endl;
		cout << "2 - Bagaj kontrolu" << endl;
		cout << "3 - Bilet numarasi dogrula" << endl;
		cout << "4 - Gun sonu raporu" << endl;
		cout << "0 - Cikis" << endl;
		cout << endl;
		cout << "Seciminiz: ";
		cin >> secim;
		cout << endl;

		switch (secim)
		{
		// ====================================================================
		//  1 — BİLET SAT
		//  (case içinde değişken tanımlandığı için blok { } ile sarılmıştır)
		// ====================================================================
		case 1:
		{
			if (satilanKoltuk == kapasite)
			{
				cout << "Ucak dolu! Bilet satilamaz." << endl;
			}
			else
			{
				// ---------- Yaş: Geçerli bir değer girilene kadar tekrar sor ----------
				int yas;
				do
				{
					cout << "Yolcunun yasini giriniz: ";
					cin >> yas;

					if (yas < 0 || yas > 120)
					{
						cout << "Gecersiz yas!" << endl;
					}

				} while (yas < 0 || yas > 120);

				// ---------- Sınıf: E / B dışında bir harf girilirse tekrar sor ----------
				char sinif;
				bool sinifGecerli;      // while koşulunda kullanılacağı için do'dan önce tanımlandı

				do
				{
					cout << "Yolcunun koltuk sinifini giriniz (E: Ekonomi, B: Business): ";
					cin >> sinif;

					// char yalnızca ilk harfi alır. "ekonomi" yazılırsa kalan "konomi"
					// klavye tamponunda kalır ve sonraki menü seçimini bozar.
					// ignore, satırda kalan karakterleri temizler.
					cin.ignore(1000, '\n');

					sinifGecerli = (sinif == 'E' || sinif == 'e' || sinif == 'B' || sinif == 'b');

					if (!sinifGecerli)
					{
						cout << "Gecersiz sinif!" << endl;
					}

				} while (!sinifGecerli);

				// ---------- Taban fiyat: Sınıfa göre (iç içe switch) ----------
				double tabanFiyat;

				switch (sinif)
				{
				case 'E': case 'e':
					tabanFiyat = ekonomiFiyat;
					ekonomiSayisi++;
					break;

				default:                // Doğrulamadan geçtiği için buraya yalnızca B / b gelir
					tabanFiyat = businessFiyat;
					businessSayisi++;
					break;
				}

				// ---------- İndirim: Yaşa göre (else if sırayla kontrol eder) ----------
				double indirimOrani; string yolcuTuru;
				if (yas < 2)
				{
					yolcuTuru = "Bebek";
					indirimOrani = 90;
				}
				else if (yas < 12)
				{
					yolcuTuru = "Cocuk";
					indirimOrani = 50;
				}
				else if (yas >= 65)
				{
					yolcuTuru = "65 yas ve ustu";
					indirimOrani = 30;
				}
				else
				{
					yolcuTuru = "Yetiskin";
					indirimOrani = 0;
				}

				if (indirimOrani > 0)
				{
					indirimliYolcu++;
				}

				// Fiyat = Taban fiyat × (1 − indirim / 100)   ör. 4000 × (1 − 0.5) = 2000
				double fiyat = tabanFiyat * (1 - indirimOrani / 100.0);

				// ---------- Sayaçları güncelle ----------
				satilanKoltuk++;                    // Yeni değer, aynı zamanda koltuk numarası
				biletGeliri += fiyat;
				if (fiyat > enYuksekFiyat)
				{
					enYuksekFiyat = fiyat;
				}

				// ---------- Bilet numarası: İlk 5 hane + kontrol hanesi ----------
				//  ör. koltuk 2 -> 12002 -> 1+2+0+0+2 = 5 -> 5 % 10 = 5 -> 120025
				int ilkBesHane = 12000 + satilanKoltuk;
				int basamakToplami(0);
				int gecici = ilkBesHane;            // Asıl sayı bozulmasın diye kopya üzerinde çalışılır

				while (gecici > 0)
				{
					basamakToplami += gecici % 10;  // Son basamağı ekle
					gecici = gecici / 10;           // Son basamağı at
				}

				int kontrolHanesi = basamakToplami % 10;            // Toplamı tek haneye indir
				int biletNo = ilkBesHane * 10 + kontrolHanesi;      // Sağa ekle

				cout << "\n--- BILET ---" << endl;
				cout << "Bilet No:\t" << biletNo << endl;
				cout << "Koltuk:\t\t" << satilanKoltuk << endl;
				cout << "Yolcu Turu:\t" << yolcuTuru << " (%" << indirimOrani << " indirim)" << endl;
				cout << "Fiyat:\t\t" << fiyat << " TL" << endl;
			}
			break;
		}

		// ====================================================================
		//  2 — BAGAJ KONTROLÜ
		//  Kurallar: 0 -> bitir | negatif veya 32 kg üstü -> atla (continue)
		//            3. geçerli bagaj -> dur (break) | 20 kg üstü her kg 50 TL
		// ====================================================================
		case 2:
		{
			// Her yolcunun bagajı ayrı tartılır; bu yüzden case içinde,
			// sıfırdan başlayan değişkenler kullanılır.
			double kg, toplamKg(0);
			int bagajAdedi(0);

			cout << "Bagaj agirliklarini giriniz (bitirmek icin 0'i tuslayin):" << endl;

			do
			{
				cout << "Bagaj " << bagajAdedi + 1 << ": ";
				cin >> kg;

				// continue: Bu turun geri kalanını atla, döngü koşuluna geç.
				// (cin döngünün başında olduğu için tekrar sorulur.)
				if (kg > maxBagajKg)
				{
					cout << "32 kg ustu bagaj kabul edilmez, atlandi." << endl;
					continue;
				}
				if (kg < 0)
				{
					cout << "Gecersiz agirlik, atlandi." << endl;
					continue;
				}
				if (kg > 0)                         // 0 bir bagaj sayılmaz, yalnızca bitirir
				{
					toplamKg += kg;
					bagajAdedi++;
				}
				if (bagajAdedi == maxBagajAdedi)
				{
					// break: Bagaj döngüsünden tamamen çık (switch'ten değil).
					cout << "En fazla 3 bagaj hakki bulunmaktadir." << endl;
					break;
				}

			} while (kg != 0);

			// Fazla ağırlık: Toplam 20 kg'ı aşıyorsa aşan kısım, aşmıyorsa 0.
			double fazlaKg = (toplamKg > ucretsizBagajKg) ? toplamKg - ucretsizBagajKg : 0;
			double ucret = fazlaKg * fazlaKgUcreti;
			bagajGeliri += ucret;

			cout << "\nKabul edilen bagaj:\t" << bagajAdedi << " adet, " << toplamKg << " kg" << endl;
			cout << "Fazla agirlik:\t\t" << fazlaKg << " kg" << endl;
			cout << "Fazla bagaj ucreti:\t" << ucret << " TL" << endl;

			break;
		}

		// ====================================================================
		//  3 — BİLET NUMARASI DOĞRULA
		//  Son hane, ilk beş hanenin basamak toplamının % 10'una eşitse geçerlidir.
		//  (Biletin satılıp satılmadığına değil, numaranın kurala uyup uymadığına bakar.)
		// ====================================================================
		case 3:
		{
			int biletNo;

			do
			{
				cout << "6 haneli bilet numarasini giriniz: ";
				cin >> biletNo;

				if (biletNo < 100000 || biletNo > 999999)
				{
					cout << "Bilet numarasi 6 haneli olmali!" << endl;
				}

			} while (biletNo < 100000 || biletNo > 999999);

			int sonHane = biletNo % 10;             // 120025 -> 5
			int besHane = biletNo / 10;             // 120025 -> 12002
			int basamakToplami2(0);

			while (besHane > 0)
			{
				basamakToplami2 += besHane % 10;
				besHane = besHane / 10;
			}

			// % 10 şart: 120092 gibi numaralarda toplam (12) iki basamaklıdır.
			if (basamakToplami2 % 10 == sonHane)
			{
				cout << "Gecerli bilet." << endl;
			}
			else
			{
				cout << "Gecersiz bilet." << endl;
			}

			break;
		}

		// ====================================================================
		//  4 — GÜN SONU RAPORU
		// ====================================================================
		case 4:
		{
			cout << "========== GUN SONU RAPORU ==========" << endl;
			cout << "Satilan bilet:\t\t" << satilanKoltuk << " / " << kapasite << endl;
			cout << "Ekonomi / Business:\t" << ekonomiSayisi << " / " << businessSayisi << endl;
			cout << "Indirimli yolcu:\t" << indirimliYolcu << endl;

			// İki int'in bölümü tam sayı olurdu (3 / 10 = 0); static_cast ile ondalıklı bölme yapılır.
			cout << "Doluluk orani:\t\t%" << static_cast<double>(satilanKoltuk) / kapasite * 100 << endl;

			cout << "Bilet geliri:\t\t" << biletGeliri << " TL" << endl;
			cout << "Bagaj geliri:\t\t" << bagajGeliri << " TL" << endl;
			cout << "Toplam gelir:\t\t" << biletGeliri + bagajGeliri << " TL" << endl;

			// Hiç bilet satılmadıysa ortalama hesabı sıfıra bölme olurdu.
			if (satilanKoltuk > 0)
			{
				cout << "Ortalama bilet fiyati:\t" << biletGeliri / satilanKoltuk << " TL" << endl;
				cout << "En yuksek bilet:\t" << enYuksekFiyat << " TL" << endl;
			}
			else
			{
				cout << "Henuz bilet satilmadi." << endl;
			}

			// ---------- Koltuk haritası (iç içe for) ----------
			//  Dış döngü sıraları, iç döngü sıradaki koltukları dolaşır.
			//  Koltuk no = (sıra − 1) × 5 + sütun   ->  1. sıra: 1–5, 2. sıra: 6–10
			//  Koltuklar sırayla satıldığı için no ≤ satılan koltuk ise koltuk doludur.
			cout << "\nKoltuk Haritasi:" << endl;

			for (int sira = 1; sira <= kapasite / siraBasinaKoltuk; sira++)
			{
				cout << "  ";
				for (int sutun = 1; sutun <= siraBasinaKoltuk; sutun++)
				{
					int koltukNo = (sira - 1) * siraBasinaKoltuk + sutun;
					cout << (koltukNo <= satilanKoltuk ? "[X]" : "[ ]");
				}
				cout << endl;                       // Sıra bitti, alt satıra geç
			}

			break;
		}

		// ====================================================================
		//  0 — ÇIKIŞ  |  Diğer — Geçersiz seçim
		// ====================================================================
		case 0:
			cout << "Iyi ucuslar!" << endl;
			break;

		default:
			cout << "Gecersiz secim!" << endl;
			break;
		}

	} while (secim != 0);
}
