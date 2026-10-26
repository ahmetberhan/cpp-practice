// ============================================================================
//  02.06 — 3'e ve 5'e Bölünebilirlik
// ----------------------------------------------------------------------------
//  Açıklama : Kullanıcıdan alınan sayının 3'e ve 5'e bölünebilirliğini kontrol
//             eder; dört durumu ayrı ayrı belirtir:
//               her ikisine, yalnızca 5'e, yalnızca 3'e, hiçbirine
//  Konular  : % (mod), ==, !=, &&, if / else if / else
// ============================================================================

#include <iostream>
using namespace std;

int main()
{
	int sayi;

	cout << "Lutfen bir sayi giriniz. ";
	cin >> sayi;

	// sayi % n == 0  ->  sayı n'e tam bölünür (kalan sıfır)
	// sayi % n != 0  ->  sayı n'e tam bölünmez
	// "Her ikisi" durumu en başta kontrol edilir; aksi halde 15 gibi bir sayı
	// önce "yalnızca 3'ün katı" koşuluna takılabilirdi.
	if (sayi % 3 == 0 && sayi % 5 == 0)
	{
		cout << "Sayiniz hem ucun hem de besin kati.  ";
	}
	else if (sayi % 3 != 0 && sayi % 5 == 0)
	{
		cout << "Sayiniz besin kati.  ";
	}
	else if (sayi % 3 == 0 && sayi % 5 != 0)
	{
		cout << "Sayiniz ucun kati.  ";
	}
	else
	{
		cout << "Sayiniz ne ucun ne de besin kati.  ";
	}
}
