// ============================================================================
//  04 — Dairenin Alanı ve Çevresi
// ----------------------------------------------------------------------------
//  Açıklama : Dairenin yarıçapını alır; alanını ve çevresini hesaplar.
//  Formül   : Alan = PI * r * r   |   Çevre = 2 * PI * r
//  Konular  : const, double, int ile double arasında işlem
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	// PI sabit bir değer olduğu için const ile tanımlanır;
	// program boyunca değiştirilemez.
	const double PI = 3.14;
	int yaricap;

	cout << "Lutfen dairenin yaricapini giriniz: ";
	cin >> yaricap;

	// int * double işleminin sonucu double olduğundan ondalıklı sonuç elde edilir.
	cout << "Dairenin alani: "   << PI * yaricap * yaricap << endl
	     << "Dairenin cevresi: " << 2 * PI * yaricap       << endl;
}
