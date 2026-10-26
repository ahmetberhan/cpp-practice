# 🧩 C++ Alıştırmalar

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![VS Code](https://img.shields.io/badge/VS%20Code-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white)
![Durum](https://img.shields.io/badge/Durum-Devam%20Ediyor-success?style=for-the-badge)

Okulda aldığım derslerden ve internetten takip ettiğim kaynaklardan öğrendiklerimi **pekiştirmek** için çözdüğüm alıştırmaların toplandığı kişisel alıştırma sahası.

Her alıştırma ayrı bir dosyadadır ve konusuna göre bir bölüm klasöründe yer alır. Her dosya tek başına derlenip çalıştırılabilir. Dosyaların başında alıştırmanın ne yaptığı, kullanılan formül ve işlenen konular yazılıdır.

---

## 🗺️ Yol Haritası

Alıştırmalar, Programlamaya Giriş dersinin 14 haftalık planına göre **bölümler** halinde klasörlenir. Her bölüm o haftalarda işlenen konuyu kapsar.

| Bölüm | Konu | Hafta | Durum |
|:-----:|------|:-----:|:-----:|
| 01 | [Temel Kavramlar](01-temel-kavramlar/) — Giriş, veri tipleri ve operatörler | 1–2 | ✅ |
| 02 | [Karar Yapıları](02-karar-yapilari/) — if / else, switch | 3 | ✅ |
| 03 | [Döngüler](03-donguler/) — for, while | 4 | ✅ |
| 04 | Diziler | 5 | ⏳ |
| 05 | String, Struct ve Enum | 6 | ⏳ |
| 06 | Fonksiyonlar | 7 | ⏳ |
| — | *Ara Sınav* | 8 | |
| 07 | İşaretçiler ve Dinamik Bellek | 9 | ⏳ |
| 08 | Dosya İşlemleri ve Hatalar | 10 | ⏳ |
| 09 | Sınıflar ve Nesneler | 11 | ⏳ |
| 10 | Şablonlar ve STL | 12 | ⏳ |
| 11 | Modern C++ ve İyi Pratikler | 13 | ⏳ |
| — | *Proje Sunumları* | 14 | |

---

## 📂 Bölüm 01 — Temel Kavramlar

### 📚 Temel Alıştırmalar

| #  | Alıştırma | Konular |
|:--:|-----------|---------|
| 01 | [Dört İşlem ve Mod Alma](01-temel-kavramlar/01_dort_islem.cpp) | Aritmetik operatörler, `%` |
| 02 | [Dikdörtgenin Alanı](01-temel-kavramlar/02_dikdortgen_alani.cpp) | `int`, `cin` / `cout` |
| 03 | [Celsius → Fahrenheit](01-temel-kavramlar/03_celsius_fahrenheit.cpp) | İşlem önceliği, tam sayı bölmesi |
| 04 | [Dairenin Alanı ve Çevresi](01-temel-kavramlar/04_daire_alan_cevre.cpp) | `const`, `double` |
| 05 | [Üç Sınavın Ortalaması](01-temel-kavramlar/05_sinav_ortalamasi.cpp) | Ondalıklı bölme |
| 06 | [Karakterin ASCII Kodu](01-temel-kavramlar/06_ascii_kodu.cpp) | `char`, `static_cast` |
| 07 | [Geçici Değişkensiz Takas](01-temel-kavramlar/07_degisken_takasi.cpp) | Toplama-çıkarma ile swap |
| 08 | [Basamaklara Ayırma](01-temel-kavramlar/08_basamak_ayirma.cpp) | `/`, `%`, `if` / `else` |

### 🚀 Ekstra Alıştırmalar

| #  | Alıştırma | Konular |
|:--:|-----------|---------|
| 01 | [Kişisel Sistem Bilgisi Kartı](01-temel-kavramlar/ekstra_01_kisisel_bilgi_karti.cpp) | `string`, veri tipi seçimi |
| 02 | [Ders Notu Hesaplayıcı](01-temel-kavramlar/ekstra_02_not_hesaplayici.cpp) | `bool`, ağırlıklı ortalama, `boolalpha` |
| 03 | [Uçuş Yakıtı ve Menzil Hesaplayıcısı](01-temel-kavramlar/ekstra_03_ucus_yakit_menzil.cpp) | `const`, yüzde hesabı |
| 04 | [Küçük Bir Finansal Karar Motoru](01-temel-kavramlar/ekstra_04_finansal_karar_motoru.cpp) | `&&`, üçlü operatör, `if` / `else if` |

### 🏁 Bitirme Projesi

#### [Uçuş Öncesi Kontrol ve Kalkış Kararı Sistemi](01-temel-kavramlar/bitirme_ucus_oncesi_kontrol.cpp)

Şimdiye kadar öğrenilen tüm konuları tek programda birleştiren proje. Kullanıcıdan uçuş bilgilerini alır; ağırlık, yakıt, hava, pilot dinlenmesi ve kontrol listesini denetler, hizalı bir rapor yazdırır ve tek bir karar verir:

| Karar | Ne zaman? |
|-------|-----------|
| ✅ **GO** | Tüm kontroller uygun |
| ⏸️ **ERTELE** | Yalnızca tek bir giderilebilir sorun var (hava, ağırlık, yakıt veya pilot dinlenmesi) |
| ❌ **NO-GO** | Birden fazla sorun var veya kontrol listesi tamamlanmamış |

**Konular:** `const`, `int` / `double` / `char` / `string` / `bool`, `static_cast`, `/` ve `%` ile saat-dakika dönüşümü, yüzde hesabı, `&&` `||` `!`, üçlü operatör, `if` / `else if` / `else`, `\t` ile hizalı çıktı

<details>
<summary>Örnek çıktı</summary>

```
============================================
     UCUS ONCESI KONTROL RAPORU
============================================
Pilot:                          Ahmet
Ucus Kodu:                      TK1923

--- AGIRLIK ---
Bos Ucak Agirligi:              42000 kg
Yolcu Agirligi:                 14250 kg
Kargo Agirligi:                 3000 kg
Yakit Agirligi:                 16000 kg
Toplam Agirlik:                 75250 kg / 79000 kg
Doluluk Yuzdesi:                %95.2532
Durum:                          Uygun

--- YAKIT VE SURE ---
Ucus Suresi:                    2 saat 30 dakika
Gereken Yakit:                  7500 L
Emniyet Payi Ile Gereken Yakit: 8250 L
Depodaki Yakit:                 20000 L
Varista Kalacak Yakit:          12500 L
Durum:                          Uygun

(Bilgi) Depodaki toplam yakit ile azami ucus suresi: 6 saat 40 dakika, azami menzil: 5333.33 km

--- HAVA ---
Ruzgar Hizi:                    18 knot (sinir 30)
Gorus Menzili:                  10 km (min 5)
Durum:                          Uygun

--- PILOT VE KONTROL LISTESI ---
Dinlenme Suresi:                12 saat 0 dakika
Pilot Durum:                    Uygun
Kontrol Listesi:                Uygun

============================================
>>> KARAR: GO - Ucus kalkisa uygundur.
============================================
```

</details>

> Not: Bu bir programlama alıştırmasıdır; gerçek uçuş planlamasında kullanılmaz.

---

## 📂 Bölüm 02 — Karar Yapıları

| #  | Alıştırma | Konular |
|:--:|-----------|---------|
| 01 | [Pozitif, Negatif veya Sıfır](02-karar-yapilari/01_pozitif_negatif_sifir.cpp) | `if` / `else if` / `else` |
| 02 | [Artık Yıl Kontrolü](02-karar-yapilari/02_artik_yil.cpp) | `%`, birleşik koşullar `&&` `\|\|` |
| 03 | [Üç Sayının En Büyüğü ve En Küçüğü](02-karar-yapilari/03_en_buyuk_en_kucuk.cpp) | Bağımsız `if` blokları |
| 04 | [Sesli mi, Sessiz mi?](02-karar-yapilari/04_sesli_sessiz_harf.cpp) | `switch`, `case`, `default`, `break` |
| 05 | [Vücut Kitle İndeksi](02-karar-yapilari/05_vucut_kitle_indeksi.cpp) | Aralık kontrolü |
| 06 | [3'e ve 5'e Bölünebilirlik](02-karar-yapilari/06_bolunebilirlik_3_ve_5.cpp) | `%`, `==` / `!=`, durum ayırma |
| 07 | [İkinci Dereceden Denklem (a = 0 kontrolü)](02-karar-yapilari/07_ikinci_derece_denklem.cpp) | İç içe `if`, `sqrt`, diskriminant |
| 08 | [Hesap Makinesi (else if ile)](02-karar-yapilari/08_hesap_makinesi_else_if.cpp) | `switch` → `else if` dönüşümü |

---

## 📂 Bölüm 03 — Döngüler

| #  | Alıştırma | Konular |
|:--:|-----------|---------|
| 01 | [1'den N'e Toplam ve Ortalama](03-donguler/01_toplam_ve_ortalama.cpp) | `for`, toplayıcı değişken |
| 02 | [Basamakların Toplamı](03-donguler/02_basamak_toplami.cpp) | `while`, `% 10` ve `/ 10` |
| 03 | [Sayının Tersi](03-donguler/03_sayinin_tersi.cpp) | `while`, sayıyı basamak basamak kurma |
| 04 | [3'e Bölünenlerin Toplamı](03-donguler/04_uce_bolunenlerin_toplami.cpp) | Döngü içinde `if` |
| 05 | [0 Girilene Kadar En Büyük Sayı](03-donguler/05_en_buyuk_sayi_sifira_kadar.cpp) | `while`, bitiş değeri (sentinel) |
| 06 | [Mükemmel Sayı](03-donguler/06_mukemmel_sayi.cpp) | Bölen bulma |
| 07 | [Üs Alma (pow olmadan)](03-donguler/07_us_alma.cpp) | `*=`, `long long` |
| 08 | [1–100 Arası Asal Sayılar](03-donguler/08_asal_sayilar.cpp) | İç içe `for`, `bool` bayrak, `break` |

---

## 🧠 Şimdiye Kadar İşlenen Konular

- Değişkenler ve veri tipleri: `int`, `double`, `char`, `string`, `bool`
- `cin` ve `cout` ile kullanıcıdan veri alma ve ekrana yazdırma
- Aritmetik operatörler: `+` `-` `*` `/` `%`
- Tam sayı bölmesi ve ondalıklı bölme arasındaki fark
- `const` ile sabit tanımlama
- `static_cast` ile tür dönüşümü
- Karşılaştırma ve mantıksal operatörler: `>=` `<=` `&&` `||` `!`
- Üçlü operatör `koşul ? a : b`
- `if` / `else if` / `else` yapıları, iç içe koşullar
- `switch` / `case` / `default` / `break`
- `for` ve `while` döngüleri, iç içe döngüler
- Toplayıcı ve bayrak (`bool`) değişkenler, bitiş değeriyle döngü sonlandırma
- `<cmath>` ve `sqrt`, `long long`

---

## ⚙️ Nasıl Çalıştırılır?

Bilgisayarında bir C++ derleyicisi (ör. `g++`) kurulu olmalıdır.

```bash
# Derle
g++ 01-temel-kavramlar/01_dort_islem.cpp -o program

# Çalıştır (Windows)
program.exe

# Çalıştır (macOS / Linux)
./program
```

VS Code kullanıyorsan **C/C++** eklentisiyle dosyayı açıp doğrudan çalıştırabilirsin.

---

> 📌 Bu repo öğrenme sürecimin bir parçasıdır; yeni konular öğrendikçe alıştırmalar eklenmeye devam edecek.