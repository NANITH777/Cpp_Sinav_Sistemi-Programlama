#include<iostream>
#include <conio.h>					// _getche fonksiyonu kutuphanes
#include <Windows.h>                 // yazi rengi için
#include <string>					//string kutuphanesi 
#include <iomanip>					//setw() kullanabilmek icin
#include <locale.h>					// Diller ve karakter setleri kütüphanesi
#include <fstream>                  // Dosyalama kütüphanesi

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



	if (secenek == '1')
	{
		cout << "\n\t\t______________________________________________________" << endl;

		cout << "\n\t\t\tKullanci Adi giriniz	   : ";
		cin >> kullanci_adi;

		cout << "\n\t\t\tKullanci Soyadi giriniz	   : ";
		cin >> kullanci_soyadi;

		ifstream kullanciOku;
		kullanciOku.open("kullancilar.txt", ios::in);

		if (kullanciOku.is_open()) // Once dosyayi acik olup olmadigini kosulyla kontrol etme
		{
			//Kullanicilar.txt dosyada (Kullanici Adi ve sifresi okuma)
			kullanciOku >> kullanciAdi >> kullanciSoyadi >> KullanciSifresi;

			while (!kullanciOku.eof())
			{
				//Kullanici girdigi Adi ve sifresi dosyadi ile karsilastirma
				if (kullanciAdi == kullanci_adi && kullanciSoyadi == kullanci_soyadi)
				{
					cout << "\n\t\t\tKullanci sifresini giriniz : ";
					cin >> kullanci_sifresi;

					if (KullanciSifresi == kullanci_sifresi)
					{
						Menufonksiyonu1(); //Asagidaki barindiran islemler 'menu fonksiyonu' cagirma
					}
					else
					{
						cout << "\n\t\t\tYanlis sifre girdiniz!!\n" << endl;
						system("pause");
						exit(0);
					}
				}
				kullanciOku >> kullanciAdi >> kullanciSoyadi >> KullanciSifresi; //Dosyayi okumayi devami
			}
			if (kullanciAdi != kullanci_adi || kullanciSoyadi != kullanci_soyadi)
			{
				cout << "\n\t\t\tYanlis kullanci adi veya soyadi girdiniz!!\n" << endl;
				system("pause");
				exit(0);
			}
			kullanciOku.close(); //Dosyayi kapatmak
		}
		else
		{
			cout << "\n\t\t\tKullanci dosyayi acilmadi" << endl;
			system("pause");
		}
	}


	long long ogrenci_TcNo;
	string ogrenci_sifre;

	if (secenek == '2')
	{
		Sinav::ogrenci og;

		cout << "\n\t\t______________________________________________________" << endl;

		cout << "\n\t\t\tOgrenci Kimligi giriniz	   : ";
		cin >> ogrenci_TcNo;

		ifstream ogrenciOku;
		ogrenciOku.open("ogrenci.txt", ios::in);

		if (ogrenciOku.is_open()) // Once dosyayi acik olup olmadigini kosulyla kontrol etme
		{
			//Kullanicilar.txt dosyada (Kullanici Adi Soyadi ve sifresi okuma)
			ogrenciOku >> og.TcNo >> og.ad >> og.soyad >> og.bolum >> og.sifre;

			while (!ogrenciOku.eof())
			{
				//Ogrenci girdigi Adi ve sifresi dosyadi ile karsilastirma
				if (og.TcNo == ogrenci_TcNo)
				{
					cout << "\n\t\t\tOgrenci sifresi giriniz: ";
					cin >> ogrenci_sifre;

					if (og.sifre == ogrenci_sifre)
					{
						Menufonksiyonu2(); //Asagidaki barindiran islemler 'menu fonksiyonu' cagirma
					}
					else
					{
						cout << "\n\t\t\tYanlis sifre girdiniz!!\n" << endl;
						system("pause");
						exit(0);
					}
				}
				ogrenciOku >> og.TcNo >> og.ad >> og.soyad >> og.bolum >> og.sifre; //Dosyayi okumayi devami
			}
			if (og.TcNo != ogrenci_TcNo || og.sifre != ogrenci_sifre)
			{
				cout << "\n\t\t\tYanlis kimligi veya ogrenci adi veya soyadi girdiniz!!\n" << endl;
				system("pause");
				exit(0);
			}
			ogrenciOku.close(); //Dosyayi kapatmak
		}
		else
		{
			cout << "\n\t\t\tOgrenci dosyayi acilmadi" << endl;
			system("pause");
		}
	}

	if (secenek == '3')
	{
		Kullancikaydi(); // Yeni kullanici kaydetme fonksiyonu cagirmak
	}

	if (secenek == '4')
	{
		cout << "\n\n\t\t\t cikis yaptiniz" << endl;
		exit(0); // Sistemden cikmak
	}

	return 0;
}


//______________________________________________________________________________________________
/////////////////////////-----MENÜ FONKSIYONLAR-------///////////////////
//----------------------------------------------------------------------------------------------

void Menufonksiyonu1()       // HOCALAR ICIN
{
	//Sistem giris oldugu zaman 'Giris=dogru' fakat 'cikis =yanlis'(daha olmadi) belirleme
	cikis = false;
	giris = true;

	system("cls"); // Onceki girdikleri silme

	//Sisteme giriste ilk mesajlari (Selam, giris basarili oldugu ve giris saati ) gosterme
	cout << "\n\t\t\t Sinav sistemine HOSGELDINIZ HOCAMIZ" << "  " << kullanciAdi << "  " << kullanciSoyadi << endl;
	cout << "\n\t\t\tSisteme giris saati : "; getZaman(giris, cikis);

	char secim;

	do
	{
		//Yapabilecek islemler (Menu)

		cout << "\n\t\t______________________________________________________" << endl;
		cout << "\t\t\t\t\tMENÜ" << endl;
		cout << "\t\t------------------------------------------------------" << endl;

		cout << "\n\n\t\t\t---Ne yapmak istiyorsunuz ?--- \n\n" << endl;

		cout << "\t\t\t{1} Ogrenci kaydi" << endl;
		cout << "\t\t\t{2} Ogrenci listesi" << endl;
		cout << "\t\t\t{3} Ogrenci ekleme" << endl;
		cout << "\t\t\t{4} Ogrenci silme" << endl;
		cout << "\t\t\t{5} Soru ekleme" << endl;
		cout << "\t\t\t{6} Soru listesi" << endl;
		cout << "\t\t\t{7} Sinav bilgileri" << endl;
		cout << "\t\t\t{8} Sinav sonuclari" << endl;
		cout << "\t\t\t{0} Cikis " << endl;

		cout << "\n\t\t******************************************************" << endl;
		cout << "\n\t\t\t Secim numarasini girin:  "; /*cin >> secim;*/
		secim = _getche();

		switch (secim)
		{
		case '1':
		{
			system("cls");
			cout << "\n\n\n\t\t\t\tOGRENCI  KAYDI... " << endl;
			sinav.Ogrencikaydi();
			system("pause");
			break;
		}

		case '2':
		{
			Sinav::ogrenci og;
			system("cls");
			cout << "\n\n\n\t\t\t\tOGRENCI LISTESI... " << endl;
			sinav.OgrenciListesi(og);
			system("pause");
			break;
		}

		case '3':
		{
			system("cls");
			cout << "\n\n\n\t\t\t\tOGRENCI EKLEME... " << endl;
			sinav.OgrenciEkleme();
			system("pause");
			break;
		}

		case '4':
		{
			system("cls");
			long long tc;
			cout << "\n\n\n\t\t\t\tOGRENCI SILME..." << endl;
			cout << "\n\n\t\t\tSilenecek Ogrenci TC numarasini giriniz : ";
			cin >> tc;
			sinav.OgrenciSilme(tc);
			system("pause");
			break;
		}

		case '5':
		{
			system("cls");
			cout << "\n\n\n\t\t\t\tSORU EKLEME... " << endl;
			sinav.SoruEkleme();
			system("pause");
			break;
		}

		case '6':
		{
			Sinav::sorular sor;
			system("cls");
			cout << "\n\n\n\t\t\t\tSORU LISTESI... " << endl;
			sinav.SoruListesi(sor);
			system("pause");
			break;
		}

		case '7':
		{
			system("cls");
			cout << "\n\n\n\t\t\t\tSINAV  BILGILERI... " << endl;
			sinav.Sinavbilgileri();
			system("pause");
			break;
		}


		case '8':
		{
			system("cls");
			cout << "\n\n\n\t\t\t\tSINAV SONUCLARI..." << endl;
			sinav.SinavSonuc();
			system("pause");
			break;
		}


		case '0':
		{
			//Kullanici, sistemden ciktigi zaman 'cikis=dogru' ve 'giris degil' oldugu belirleme
			cikis = true;
			giris = false;

			system("cls");
			cout << "\n\n\n\n\t\t\tCikis yaptiniz" << endl;
			cout << "\n\n\n\n\t\t\tSistemden cikis saati : "; getZaman(giris, cikis);
			cout << endl;
			system("pause");

			exit(0); //Sistemden cikis 
		}
		default:cout << "\a"; // Yanlis tusa basinca ses cikma
		}
		system("cls");

	} while (secim != '0'); // Sifir karakteri basincaya kadar dongude (sistemde) olma kosulu

}