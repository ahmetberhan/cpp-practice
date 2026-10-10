# 🧩 C++ Alıştırmalar

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![VS Code](https://img.shields.io/badge/VS%20Code-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white)
![Durum](https://img.shields.io/badge/Durum-Devam%20Ediyor-success?style=for-the-badge)

Okulda aldığım derslerden ve internetten takip ettiğim kaynaklardan öğrendiklerimi **pekiştirmek** için çözdüğüm alıştırmaların toplandığı kişisel alıştırma sahası.

Her alıştırma ayrı bir dosyadadır ve tek başına derlenip çalıştırılabilir. Dosyaların başında alıştırmanın ne yaptığı, kullanılan formül ve işlenen konular yazılıdır.

---

## 📚 Temel Alıştırmalar

| #  | Alıştırma | Konular |
|:--:|-----------|---------|
| 01 | [Dört İşlem ve Mod Alma](01_dort_islem.cpp) | Aritmetik operatörler, `%` |
| 02 | [Dikdörtgenin Alanı](02_dikdortgen_alani.cpp) | `int`, `cin` / `cout` |
| 03 | [Celsius → Fahrenheit](03_celsius_fahrenheit.cpp) | İşlem önceliği, tam sayı bölmesi |
| 04 | [Dairenin Alanı ve Çevresi](04_daire_alan_cevre.cpp) | `const`, `double` |
| 05 | [Üç Sınavın Ortalaması](05_sinav_ortalamasi.cpp) | Ondalıklı bölme |
| 06 | [Karakterin ASCII Kodu](06_ascii_kodu.cpp) | `char`, `static_cast` |
| 07 | [Geçici Değişkensiz Takas](07_degisken_takasi.cpp) | Toplama-çıkarma ile swap |
| 08 | [Basamaklara Ayırma](08_basamak_ayirma.cpp) | `/`, `%`, `if` / `else` |

## 🚀 Ekstra Alıştırmalar

| #  | Alıştırma | Konular |
|:--:|-----------|---------|
| 01 | [Kişisel Sistem Bilgisi Kartı](ekstra_01_kisisel_bilgi_karti.cpp) | `string`, veri tipi seçimi |
| 02 | [Ders Notu Hesaplayıcı](ekstra_02_not_hesaplayici.cpp) | `bool`, ağırlıklı ortalama, `boolalpha` |
| 03 | [Uçuş Yakıtı ve Menzil Hesaplayıcısı ✈️](ekstra_03_ucus_yakit_menzil.cpp) | `const`, yüzde hesabı |
| 04 | [Küçük Bir Finansal Karar Motoru](ekstra_04_finansal_karar_motoru.cpp) | `&&`, üçlü operatör, `if` / `else if` |

---

## 🧠 İşlenen Konular

- Değişkenler ve veri tipleri: `int`, `double`, `char`, `string`, `bool`
- `cin` ve `cout` ile kullanıcıdan veri alma ve ekrana yazdırma
- Aritmetik operatörler: `+` `-` `*` `/` `%`
- Tam sayı bölmesi ve ondalıklı bölme arasındaki fark
- `const` ile sabit tanımlama
- `static_cast` ile tür dönüşümü
- Karşılaştırma ve mantıksal operatörler: `>=` `<=` `&&`
- Üçlü operatör `koşul ? a : b`
- `if` / `else if` / `else` yapıları

---

## ⚙️ Nasıl Çalıştırılır?

Bilgisayarında bir C++ derleyicisi (ör. `g++`) kurulu olmalıdır.

```bash
# Derle
g++ 01_dort_islem.cpp -o program

# Çalıştır (Windows)
program.exe

# Çalıştır (macOS / Linux)
./program
```

VS Code kullanıyorsan **C/C++** eklentisiyle dosyayı açıp doğrudan çalıştırabilirsin.

---

> 📌 Bu repo öğrenme sürecimin bir parçasıdır; yeni konular öğrendikçe alıştırmalar eklenmeye devam edecek.
