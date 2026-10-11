// ============================================================================
//  BİTİRME PROJESİ — Uçuş Öncesi Kontrol ve Kalkış Kararı Sistemi ✈️
// ----------------------------------------------------------------------------
//  Açıklama : Bir uçuştan önce yapılan kontrolleri taklit eder. Kullanıcıdan
//             uçuş bilgilerini alır; ağırlık, yakıt, hava durumu, pilotun
//             dinlenme süresi ve kontrol listesini tek tek denetler. Sonunda
//             düzenli bir rapor yazdırır ve tek bir karar verir:
//
//               GO     -> Uçuş kalkışa uygun
//               ERTELE -> Tek bir sorun var ve giderilebilir
//                         (hava, ağırlık, yakıt veya pilot dinlenmesi)
//               NO-GO  -> Uçuş iptal
//
//  Konular  : const, int, double, char, string, bool, static_cast,
//             / ve % ile saat-dakika dönüşümü, yüzde hesabı,
//             &&, ||, !, üçlü operatör (?:), if / else if / else, \t
//
//  Not: Bu bir programlama alıştırmasıdır; gerçek uçuş planlamasında kullanılmaz.
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ------------------------------------------------------------------------
    //  SABİTLER
    //  Her uçuşta aynı kalan değerler: uçağın özellikleri ve güvenlik kuralları.
    //  Kullanıcı bunları girmez; program boyunca değiştirilemezler.
    // ------------------------------------------------------------------------
    const double bos_ucakAgirligi(42000),       // Uçağın boş ağırlığı (kg)
                 max_kalkisAgirligi(79000),     // Güvenli kalkış için en fazla ağırlık (kg)
                 yakitYogunlugu(0.8),           // 1 litre yakıtın ağırlığı (kg)
                 emniyet_yakitYuzdesi(10.0),    // Gereken yakıta eklenecek emniyet payı (%)
                 maxRuzgar(30),                 // İzin verilen en yüksek rüzgar hızı (knot)
                 minGorus(5.0);                 // Gereken en az görüş mesafesi (km)
    const int min_dinlenmeDakika(600);          // Pilotun en az dinlenme süresi (10 saat)

    // ------------------------------------------------------------------------
    //  DEĞİŞKENLER
    // ------------------------------------------------------------------------
    // Metin bilgileri
    string pilotIsmi, ucusKodu;

    // Tam sayı olması gerekenler: yolcu sayısı ve dakika/saat değerleri.
    // (Saat-dakika dönüşümünde % kullanılacağı için bunlar int olmalıdır.)
    int yolcuSayisi, pilotDinlenme, ucusSaat, ucusDakika, dinlenmeSaat, dinlenmeDakika, azamiSaat, azamiDakika;

    // Ondalıklı olabilecek tüm ölçümler ve hesap sonuçları
    double yolcu_ortAgirligi, yolcu_topAgirligi, kargoAgirligi, depoYakit, saatlikTuketim, varistaYakit,
           ucusMesafesi, ortHiz, ruzgarHiz, gorusMesafesi, yakitAgirligi, ucakToplam, ucusSuresi,
           dolulukOranı, gerekenYakit, emniyetli_gerekenYakit;


    // ------------------------------------------------------------------------
    //  1. KULLANICIDAN BİLGİ ALMA
    //  Bu uçuşa özel, her seferinde değişen bilgiler.
    // ------------------------------------------------------------------------
    cout << "Lutfen Adinizi giriniz. ";
    cin >> pilotIsmi;
    cout << "Lutfen ucus kodunu giriniz. ";
    cin >> ucusKodu;

    cout << "Lutfen yolcu sayisini giriniz. ";
    cin >> yolcuSayisi;
    cout << "Lutfen yolcu basina ortalama agirligi cinsinden giriniz. ";
    cin >> yolcu_ortAgirligi;
    cout << "Lutfen kargo agirligini giriniz. ";
    cin >> kargoAgirligi;

    cout << "Lutfen depodaki yakit miktarini L cinsinden giriniz. ";
    cin >> depoYakit;
    cout << "Lutfen saatlik yakit tuketimini L/h cinsinden giriniz. ";
    cin >> saatlikTuketim;

    cout << "Lutfen ucus mesafesini km cinsinden giriniz. ";
    cin >> ucusMesafesi;
    cout << "Lutfen ucagin ortalama hizini km/h cinsinden giriniz giriniz. ";
    cin >> ortHiz;

    cout << "Lutfen ruzgar hizini knot cinsinden giriniz. ";
    cin >> ruzgarHiz;
    cout << "Lutfen gorus mesafesini km cinsinden giriniz. ";
    cin >> gorusMesafesi;

    cout << "Lutfen pilotun dinlenme suresini dakika cinsinden giriniz. ";
    cin >> pilotDinlenme;

    // char tek bir karakter tutar. Büyük ya da küçük E girilmesi
    // || (VEYA) ile kontrol edilir; ikisinden biri doğruysa liste tamamdır.
    char kontrolCevabi;
    cout << "Kontrol listesi tamamlandi mi? (E/H): ";
    cin >> kontrolCevabi;
    bool checklistTamam = (kontrolCevabi == 'E' || kontrolCevabi == 'e');


    // ------------------------------------------------------------------------
    //  2. HESAPLAMALAR
    // ------------------------------------------------------------------------
    // Ağırlık: Yakıt litre olarak girildiği için önce kilograma çevrilir;
    // aksi halde litre ile kilogram toplanmış olurdu.
    yolcu_topAgirligi = yolcuSayisi * yolcu_ortAgirligi;
    yakitAgirligi = yakitYogunlugu * depoYakit;
    ucakToplam = yolcu_topAgirligi + yakitAgirligi + bos_ucakAgirligi + kargoAgirligi;

    // Doluluk oranı: Uçağın taşıyabileceği sınırın yüzde kaçı kullanılıyor?
    dolulukOranı = (ucakToplam / max_kalkisAgirligi) * 100.0;

    // Yakıt: Rota için gereken süre ve yakıt; üstüne emniyet payı eklenir.
    // 100.0 yazılması, bölmenin ondalıklı yapılmasını garanti eder.
    ucusSuresi = ucusMesafesi / ortHiz;                     // saat
    gerekenYakit = ucusSuresi * saatlikTuketim;             // litre
    emniyetli_gerekenYakit = gerekenYakit + (gerekenYakit * (emniyet_yakitYuzdesi/100.0));
    varistaYakit = depoYakit - gerekenYakit;

    // Saat-dakika dönüşümü:
    //   1) Saat cinsinden süre 60 ile çarpılıp dakikaya çevrilir (ör. 2.5 saat -> 150 dk).
    //   2) static_cast<int> ile tam sayıya dönüştürülür; çünkü % yalnızca int ile çalışır.
    //   3) / 60 saati, % 60 kalan dakikayı verir (150 / 60 = 2, 150 % 60 = 30).
    int ucus_toplamDakika = static_cast<int>(ucusSuresi * 60);
    int azamiToplamDakika = static_cast<int>((depoYakit / saatlikTuketim) * 60);   // Depodaki yakıtla en fazla uçuş süresi

    ucusSaat = ucus_toplamDakika / 60;
    ucusDakika = ucus_toplamDakika % 60;

    // Dinlenme süresi zaten dakika ve int olduğu için doğrudan bölünür.
    dinlenmeSaat = pilotDinlenme / 60;
    dinlenmeDakika = pilotDinlenme % 60;

    azamiSaat = azamiToplamDakika / 60;
    azamiDakika = azamiToplamDakika % 60;


    // ------------------------------------------------------------------------
    //  3. KONTROLLER
    //  Her kontrolün sonucu (true / false) ayrı bir bool değişkende tutulur.
    // ------------------------------------------------------------------------
    bool agirlikUygun = ucakToplam <= max_kalkisAgirligi;
    bool yakitYeterli = depoYakit >= emniyetli_gerekenYakit;
    bool gorusUygun = gorusMesafesi >= minGorus;
    bool ruzgarUygun = ruzgarHiz <= maxRuzgar;
    bool havaUygun = ruzgarUygun && gorusUygun;             // İki hava koşulu da sağlanmalı
    bool dinlenmeUygun = pilotDinlenme >= min_dinlenmeDakika;


    // ------------------------------------------------------------------------
    //  4. RAPOR
    //  \t (tab) karakterleri değerlerin aynı sütunda, hizalı görünmesini sağlar.
    //  Üçlü operatör (koşul ? "Uygun" : "Uygun Degil") her kontrolün sonucunu yazar.
    // ------------------------------------------------------------------------
    cout << "\n============================================" << endl;
    cout << "     UCUS ONCESI KONTROL RAPORU" << endl;
    cout << "============================================" << endl;

    cout << "Pilot:\t\t\t\t" << pilotIsmi << endl;
    cout << "Ucus Kodu:\t\t\t" << ucusKodu << endl;

    // ---------------- Ağırlık ----------------
    cout << "\n--- AGIRLIK ---" << endl;
    cout << "Bos Ucak Agirligi:\t\t" << bos_ucakAgirligi << " kg" << endl;
    cout << "Yolcu Agirligi:\t\t\t" << yolcu_topAgirligi << " kg" << endl;
    cout << "Kargo Agirligi:\t\t\t" << kargoAgirligi << " kg" << endl;
    cout << "Yakit Agirligi:\t\t\t" << yakitAgirligi << " kg" << endl;
    cout << "Toplam Agirlik:\t\t\t" << ucakToplam << " kg" << " / " << max_kalkisAgirligi << " kg" << endl;
    cout << "Doluluk Yuzdesi:\t\t" << "%" << dolulukOranı << endl;
    cout << "Durum:\t\t\t\t" << (agirlikUygun ? "Uygun" : "Uygun Degil") << endl;

    // ---------------- Yakıt ve süre ----------------
    cout << "\n--- YAKIT VE SURE ---" << endl;
    cout << "Ucus Suresi:\t\t\t" << ucusSaat << " saat " << ucusDakika << " dakika" << endl;
    cout << "Gereken Yakit:\t\t\t" << gerekenYakit << " L" << endl;
    cout << "Emniyet Payi Ile Gereken Yakit:\t" << emniyetli_gerekenYakit << " L" << endl;
    cout << "Depodaki Yakit:\t\t\t" << depoYakit << " L" << endl;
    cout << "Varista Kalacak Yakit:\t\t" << varistaYakit << " L" << endl;
    cout << "Durum:\t\t\t\t" << (yakitYeterli ? "Uygun" : "Uygun Degil") << endl;

    // Bilgi satırı: Karara etki etmez; depodaki yakıtın tamamıyla uçağın
    // en fazla ne kadar uçabileceğini ve ne kadar uzağa gidebileceğini gösterir.
    // Azami menzil = (Depodaki yakıt / Saatlik tüketim) * Ortalama hız
    cout << "\n(Bilgi) Depodaki toplam yakit ile azami ucus suresi: "
         << azamiSaat << " saat " << azamiDakika << " dakika, "
         << "azami menzil: " << (depoYakit / saatlikTuketim) * ortHiz << " km" << endl;

    // ---------------- Hava ----------------
    cout << "\n--- HAVA ---" << endl;
    cout << "Ruzgar Hizi:\t\t\t" << ruzgarHiz << " knot (sinir 30)" << endl;
    cout << "Gorus Menzili:\t\t\t" << gorusMesafesi << " km (min 5)" << endl;
    cout << "Durum:\t\t\t\t" << (ruzgarUygun && gorusUygun ? "Uygun": "Uygun Degil") << endl;

    // ---------------- Pilot ve kontrol listesi ----------------
    cout << "\n--- PILOT VE KONTROL LISTESI ---" << endl;
    cout << "Dinlenme Suresi:\t\t" << dinlenmeSaat << " saat " << dinlenmeDakika << " dakika" << endl;
    cout << "Pilot Durum:\t\t\t" << (dinlenmeUygun ? "Uygun" : "Uygun Degil") << endl;
    cout << "Kontrol Listesi:\t\t" << (checklistTamam ? "Uygun" : "Uygun Degil") << endl;


    // ------------------------------------------------------------------------
    //  5. KARAR
    //  if / else if / else yukarıdan aşağı okunur; ilk doğru olan koşulun
    //  bloğu çalışır, geri kalanlara bakılmaz.
    //    - Beş kontrolün hepsi doğruysa                     -> GO
    //    - Yalnızca tek bir giderilebilir sorun varsa       -> ERTELE
    //      (! işareti koşulu tersine çevirir: !havaUygun = "hava uygun değil")
    //    - Birden fazla sorun varsa veya kontrol listesi
    //      tamamlanmamışsa                                  -> NO-GO
    // ------------------------------------------------------------------------
    cout << "\n============================================" << endl;

    if (agirlikUygun && yakitYeterli && havaUygun && dinlenmeUygun && checklistTamam)
    {
        cout << ">>> KARAR: GO - Ucus kalkisa uygundur." << endl;
    }
    else if (!havaUygun && agirlikUygun && yakitYeterli && dinlenmeUygun && checklistTamam)
    {
        // Sadece hava bozuk
        cout << ">>> KARAR: ERTELE - Hava kosullari uygun degil. Hava duzelene kadar bekleyin." << endl;
    }
    else if (havaUygun && !agirlikUygun && yakitYeterli && dinlenmeUygun && checklistTamam)
    {
        // Sadece ağırlık fazla (ör. kargo indirilebilir)
        cout << ">>> KARAR: ERTELE - Agirlik kritik duzeyin ustunde ekipler harekete gecene kadar bekleyin." << endl;
    }
    else if (havaUygun && agirlikUygun && !yakitYeterli && dinlenmeUygun && checklistTamam)
    {
        // Sadece yakıt yetersiz (yakıt doldurulabilir)
        cout << ">>> KARAR: ERTELE - Yakit yetersiz yakit dolumuna kadar bekleyin." << endl;
    }
    else if (havaUygun && agirlikUygun && yakitYeterli && !dinlenmeUygun && checklistTamam)
    {
        // Sadece pilot yeterince dinlenmemiş
        cout << ">>> KARAR: ERTELE - Pilot yeteri kadar dinlenmemis. Pilot dinlenene kadar bekleyin." << endl;
    }
    else
    {
        // Birden fazla sorun var veya kontrol listesi tamamlanmamış
        cout << ">>> KARAR: NO-GO - Ucus iptal edildi." << endl;
    }

    cout << "============================================" << endl;
}
