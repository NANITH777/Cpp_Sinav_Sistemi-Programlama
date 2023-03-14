#include<iostream>
#include <conio.h>					// _getche fonksiyonu kutuphanes
#include <Windows.h>                 // yazi rengi için
#include <string>					//string kutuphanesi 

using namespace std;


class Sinav
{

public:

	// OGRENCI ONBILDIRMELER
	struct ogrenci
	{
		string ad;
		string soyad;
		string bolum;
		long long TcNo;
		string sifre;
	};

	void Ogrencikaydi();
	void OgrenciListesi(ogrenci);
	void OgrenciEkleme();
	void OgrenciSilme(long long tc);


	// SORU ONBILDIRMELER
	struct sorular
	{
		string soru, A, B, C, D, dogcev;   // soru ve siklari
		string sinavtipi;
		int sorusayisi;
		int sure;
		int sayi;                    // kacinci soru
		float puan;
		string cevap;
		string cevaplar[50];
		string dizi[50][6];           // dizi olusturmak icin bir satir ve 6 sutun
	};

	void SoruEkleme();
	void SoruListesi(sorular);;


	// SINAV ONBİLDİRMELER

	struct sinavlar
	{
		int sinavNo;
		string sinavturu; // sinav turu
		int sorusay;     // sorular sayisi
		int sure;        // sinav suresi
		string sinavtarihi; // sinav tarihi;
	};

	void Sinavbilgileri();
	void Sinavkaydi();
	void SinavListesi(sinavlar);
	void SinavEkleme();   // sinavkaydi ve sinavekleme fonksiyonlari ayni rol oynayip metotlari aynidir.
	void SinavSilme(int no);

	// SINAV SONUCLARI
	struct singirenler    // Sinava girenler metotu
	{
		long long TcNo;
		string ad;
		string soyad;
		int sorusay;
		int sorupuan;
		int docevsayi;    // dogru cevap sayisi
		int yavevsayi;    // yanlis cevap sayisi
		int puan;
	};

	void SinavSonuc();
	void Sinavagirenler();
	void SinavSonuclari(singirenler);  // Ogrenci menusunde bulunan 

}  sinav;   // sinav sinif tipindeki kutuphane degiskeni tanimlama
//Sinif bittigi yeri

int main()
{

	setlocale(LC_ALL, "Turkish");
	system("color 9F");

	char secenek;

	do
	{
		cout << "\n\t\t******************************************************" << endl;

		cout << "\n\n\t\t\t---Ne yapmak istiyorsunuz ?--- \n\n" << endl;
		cout << "\t\t\t1) Programa giris Hocalar icin" << endl;
		cout << "\t\t\t2) Programa giris Ogrenciler icin" << endl;
		cout << "\t\t\t3) Kullanci kaydi  " << endl;
		cout << "\t\t\t4) Sistemden çik " << endl;

		cout << "\n\t\t******************************************************" << endl;

		cout << "\n\t\t\t Secim numarasini girin:  "; /*cin >> secenek*/;
		secenek = _getche();

		if (secenek != '1' && secenek != '2' && secenek != '3' && secenek != '4')
		{
			cout << "\a"; // Kullanci, yanlis tusa bastigindan ses cikma
			system("cls"); // Onceki girdikleri silmek
		}

	} while (secenek != '1' && secenek != '2' && secenek != '3' && secenek != '4');



	//KUllanicidan isteyecek kullanici Adi ve sifresi degiskenler tanimlama
	string kullanci_adi;
	string kullanci_soyadi;
	string kullanci_sifresi;



	return 0;
}