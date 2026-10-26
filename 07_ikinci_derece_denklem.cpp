// ============================================================================
//  02.07 — İkinci Dereceden Denklemin Kökleri (a = 0 kontrolü ile)
// ----------------------------------------------------------------------------
//  Açıklama : ax² + bx + c = 0 denkleminin köklerini bulur. a = 0 ise denklem
//             ikinci dereceden değildir; bu durumda birinci dereceden denklem
//             (bx + c = 0) olarak çözülür.
//  Formül   : Δ = b² - 4ac
//             x1,2 = (-b ± √Δ) / 2a
//  Konular  : İç içe if, sqrt (<cmath>), sıfıra bölme kontrolü
// ============================================================================

#include <iostream>
#include <cmath>        // sqrt (karekök) fonksiyonu için
using namespace std;

int main()
{
	double a, b, c, delta;

	cout << "Lutfen denklemin a, b ve c degerlerini sirasiyla giriniz. ";
	cin >> a >> b >> c;


	// ---------------- a = 0: İkinci dereceden değil ----------------
	// Formülde 2a ile bölme var; a = 0 iken bu sıfıra bölme olurdu.
	if (a == 0)
	{
		cout << "a = 0 oldugu icin bu ikinci dereceden bir denklem degildir!" << endl;

		// bx + c = 0  ->  x = -c / b   (b de 0 ise çözüm yok)
		if (b != 0) {
			cout << "Birinci dereceden denklemin koku: " << -c / b << endl;
		}
		else {
			cout << "Gecersiz denklem." << endl;
		}
	}

	// ---------------- a ≠ 0: Diskriminant (Δ) ile çözüm ----------------
	else
	{
		delta = (b * b) - (4 * a * c);

		// Δ > 0 -> iki farklı kök | Δ = 0 -> çakışık (çift) kök | Δ < 0 -> reel kök yok
		if (delta > 0)
		{
			cout << "Denklem iki farkli reel koke sahiptir. " << endl;
			cout << "x1: " << (-b + sqrt(delta)) / (2 * a) << endl;
			cout << "x2: " << (-b - sqrt(delta)) / (2 * a) << endl;
		}
		else if (delta == 0)
		{
			cout << "Denklem cift reel koke sahiptir. " << endl;
			cout << "x1: " << (-b + sqrt(delta)) / (2 * a) << endl;
		}
		else
		{
			cout << "Denklem reel koke sahip degildir. " << endl;
		}
	}
}
