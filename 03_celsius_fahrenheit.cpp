// ============================================================================
//  03 — Celsius'tan Fahrenheit'a Dönüşüm
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan Celsius değerini Fahrenheit'a çevirir.
//  Formül   : F = (C * 9 / 5) + 32
//  Konular  : int, işlem önceliği, tam sayı bölmesi
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int celsius, fahrenheit;

	cout << "Lutfen Celsius degerini giriniz: ";
	cin >> celsius;

	// Not: Değişkenler int olduğu için sonucun ondalık kısmı atılır.
	//      Örneğin 1 °C = 33.8 °F olması gerekirken 33 olarak hesaplanır.
	fahrenheit = (celsius * 9 / 5) + 32;

	cout << "Fahrenheit degeri: " << fahrenheit << endl;
}
