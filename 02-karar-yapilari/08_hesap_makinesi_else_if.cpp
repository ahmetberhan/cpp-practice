// ============================================================================
//  02.08 — Dört İşlemli Hesap Makinesi (else if ile)
// ----------------------------------------------------------------------------
//  Açıklama : "5 * 3" biçiminde girilen işlemi hesaplar. Derste switch ile
//             yazılan hesap makinesinin if / else if ile yeniden yazılmış hali.
//  Konular  : char ile operatör okuma, if / else if / else, sıfıra bölme kontrolü
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	double a(0), b(0);
	char islem;

	// cin tek satırda üç değeri sırayla okur: sayı, işlem karakteri, sayı.
	cout << "Islem (orn: 5 * 3): ";
	cin >> a >> islem >> b;

	// Her else if, switch yapısındaki bir case'in karşılığıdır.
	if (islem == '+')
	{
		cout << a + b << endl;
	}
	else if (islem == '-')
	{
		cout << a - b << endl;
	}
	else if (islem == '*')
	{
		cout << a * b << endl;
	}
	else if (islem == '/' && b != 0)     // Bölen sıfırsa bölme yapılmaz
	{
		cout << a / b << endl;
	}
	else if (islem == '/' && b == 0)     // Operatör doğru ama bölen sıfır
	{
		cout << "Sifira bolme yapilamaz. " << endl;
	}
	else                                 // switch'teki default'un karşılığı
	{
		cout << "Hatali operator girdiniz. " << endl;
	}
}
