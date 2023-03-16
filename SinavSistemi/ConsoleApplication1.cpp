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



void Menufonksiyonu2()       // ÖĞRENCİLER ICIN
{
	system("cls");  // Onceki girdikleri silme

	cout << "\n\t\t\t Sinav sistemine HOSGELDINIZ OGRENCIMIZ" << "  " << og.TcNo << endl;
	cout << "\n\t\t\t---Tum ogrencilerimize BASARILAR dileriz-----\n" << endl;

	char secim;

	do
	{
		//Yapabilecek islemler (Menu)

		cout << "\n\t\t______________________________________________________" << endl;
		cout << "\t\t\t\t\tMENÜ" << endl;
		cout << "\t\t------------------------------------------------------" << endl;

		cout << "\n\n\t\t\t---Ne yapmak istiyorsunuz ?--- \n\n" << endl;

		cout << "\t\t\t{1} Sinav Listesi" << endl;;
		cout << "\t\t\t{2} Sinav sonuclari" << endl;
		cout << "\t\t\t{0} Cikis " << endl;

		cout << "\n\t\t******************************************************" << endl;
		cout << "\n\t\t\t Secim numarasini girin:  "; /*cin >> secim;*/
		secim = _getche();

		switch (secim)
		{
		case '1':
		{
			Sinav::sinavlar sin;
			system("cls");
			cout << "\n\n\n\t\t\t\t SINAV LISTESI... " << endl;
			sinav.SinavListesi(sin);
			system("pause");
			break;
		}

		case '2':
		{
			Sinav::singirenler gir;
			system("cls");
			cout << "\n\n\n\t\t\t\tSINAV SONUCLARI..." << endl;
			sinav.SinavSonuclari(gir);
			system("pause");
			break;
		}


		case '0':
		{
			system("cls");
			cout << "\n\n\n\n\t\t\tCikis yaptiniz" << endl;
			system("pause");

			exit(0); //Sistemden cikis 
		}
		default:cout << "\a"; // Yanlis tusa basinca ses cikma
		}
		system("cls");

	} while (secim != '0'); // Sifir karakteri basincaya kadar dongude (sistemde) olma kosulu

}



void Sinav::Sinavbilgileri()
{
	char secim;

	do
	{
		//Yapabilecek islemler (Menu)

		cout << "\n\t\t______________________________________________________" << endl;
		cout << "\t\t\t\t\tSINAV BILGILERI" << endl;
		cout << "\t\t------------------------------------------------------" << endl;

		cout << "\n\n\t\t\t---Ne yapmak istiyorsunuz ?--- \n\n" << endl;

		cout << "\t\t\t{1} Sinav kaydi" << endl;
		cout << "\t\t\t{2} Sinav listesi" << endl;
		cout << "\t\t\t{3} Sinav ekleme" << endl;
		cout << "\t\t\t{4} sinav silme" << endl;
		cout << "\t\t\t{0} Cikis " << endl;

		cout << "\n\t\t******************************************************" << endl;
		cout << "\n\t\t\t Secim numarasini girin:  "; /*cin >> secim;*/
		secim = _getche();

		switch (secim)
		{
		case '1':
		{
			system("cls");
			cout << "\n\n\n\t\t\t\tSINAV  KAYDI... " << endl;
			sinav.Sinavkaydi();
			break;
		}

		case '2':
		{
			Sinav::sinavlar sin;
			system("cls");
			cout << "\n\n\n\t\t\t\t SINAV LISTESI... " << endl;
			sinav.SinavListesi(sin);
			system("pause");
			break;
		}

		case '3':
		{
			system("cls");
			/*long long tc;*/
			cout << "\n\n\n\t\t\t\tSINAV EKLEME... " << endl;
			sinav.Sinavkaydi();       // sinav kaydi ve sinav ekleme ayni fonksiyon oldugu icin
			break;
		}

		case '4':
		{
			system("cls");
			int no;
			cout << "\n\n\n\t\t\t\tSINAV SILME..." << endl;
			cout << "\n\n\t\t\tSilenecek sinav numarasini giriniz : ";
			cin >> no;
			sinav.SinavSilme(no);
			system("pause");
			break;
		}

		case '0':
		{
			//Kullanici, sistemden ciktigi zaman 'cikis=dogru' ve 'giris degil' oldugu belirleme
			cikis = true;
			giris = false;

			system("cls");
			cout << "\n\n\n\n\t\t\t Sinav bilgilerinden cikis yaptiniz menuye geri donuyorsunuz " << endl;
			cout << endl;

			Menufonksiyonu1();

		}
		default:cout << "\a"; // Yanlis tusa basinca ses cikma
		}
		system("cls");

	} while (secim != '0'); // Sifir karakteri basincaya kadar dongude (sistemde) olma kosulu

}



//______________________________________________________________________________________________
/////////////////////////-----ÖĞRENCİ ÜZERINDE METOTLAR-------///////////////////
//----------------------------------------------------------------------------------------------

void Sinav::Ogrencikaydi()
{
	ofstream DosyaYaz; //ofstream tipinde (Yazmak icin) DosyaYaz degiskeni tanimlama
	DosyaYaz.open("ogrenci.txt", ios::app); //ogrenci.txt dosyayi acma (olmasa da olusturacak)

	char secim;

	ogrenci og; // Sinav siniftaki  ogrenci struct tipindeki ok degisken tanimlama (bilgileri erismek icin) 

	do
	{
		// Kullanicidan ogrenci bilgileri istemek

		int haneSayisi;
		cout << "\n\t\t\tTC numarasini giriniz			:"; cin >> og.TcNo;
		cin.clear(); // Karakter bir girdigi zaman sonsuz donguye gitmemesi icin kullanildi
		cin.ignore();
		haneSayisi = log10(og.TcNo) + 1; // TC numara hanesini belirtmek icin

		if (haneSayisi == 11) // TC numara 11 haneli oldugu zaman islemleri devami
		{
			cout << "\n\t\t\tAdi giriniz				:"; getline(cin, og.ad);
			cout << "\n\t\t\tSoyadi giriniz				:"; getline(cin, og.soyad);
			cout << "\n\t\t\tBolumunu giriniz			:"; getline(cin, og.bolum);
			cout << "\n\t\t\tSifresini giriniz		    :"; cin >> og.sifre;


			//Ogrenci.txt dosayaya yazma
			DosyaYaz.setf(ios::left);
			DosyaYaz << setw(15) << og.TcNo << setw(15) << og.ad << setw(15) << og.soyad <<
				setw(15) << og.bolum << setw(15) << og.sifre
				<< "\n" << endl;

			cout << "\n\n\t\t\tBaska eklemeyi ister misin... ? (e/h)";
			cin >> secim;
		}
		else
		{
			if (haneSayisi <= 0)
			{
				cout << "\n\t\t\t\a" << "0 veya Karakter veya Negatif TC numara olamaz, lütfen 11 haneli ve pozitif bir TC giriniz." << endl;
			}
			else
				cout << "\n\t\t\t\a" << haneSayisi << " haneli TC numara olamaz, lütfen 11 haneli bir TC giriniz." << endl;


			secim = 'e'; //dongu devami
		}

	} while (secim == 'e' || secim == 'E');

	cout << "\n\t\t\tOgrenci kaydi basardi...\n\n\n" << endl;

	DosyaYaz.close(); //ogrenci.txt dosyayi kapatma
}


void Sinav::OgrenciListesi(ogrenci og)
{

	ifstream DosyaOku;
	DosyaOku.open("ogrenci.txt", ios::in);

	cout << "\n\t\t\t" << "     TC   " << setw(14) << "    AD    " << setw(10) << "     SOYAD   " << setw(8) << "    BOLUM   " << endl;

	while (!(DosyaOku.eof()))
	{
		DosyaOku >> og.TcNo >> og.ad >> og.soyad >> og.bolum >> og.sifre;
		cout << "\n\t\t\t" << og.TcNo << setw(12) << og.ad << setw(12) << og.soyad << setw(12) << og.bolum << endl;
	}


	DosyaOku.close();

}



void Sinav::OgrenciEkleme()
{
	ofstream DosyaYaz; //ofstream tipinde (Yazmak icin) DosyaYaz degiskeni tanimlama
	DosyaYaz.open("ogrenci.txt", ios::app); //ogrenci.txt dosyayi acma (olmasa da olusturacak)

	char secim;

	ogrenci og; // Sinav siniftaki  ogrenci struct tipindeki ok degisken tanimlama (bilgileri erismek icin) 

	do
	{
		// Kullancidan ogrenci bilgileri istemek

		int haneSayisi;
		cout << "\n\t\t\tTC numarasini giriniz			:"; cin >> og.TcNo;
		cin.clear(); // Karakter bir girdigi zaman sonsuz donguye gitmemesi icin kullanildi
		cin.ignore();
		haneSayisi = log10(og.TcNo) + 1; // TC numara hanesini belirtmek icin

		if (haneSayisi == 11) // TC numara 11 haneli oldugu zaman islemleri devami
		{
			cout << "\n\t\t\tAdi giriniz				:"; getline(cin, og.ad);
			cout << "\n\t\t\tSoyadi giriniz				:"; getline(cin, og.soyad);
			cout << "\n\t\t\tBolumunu giriniz			:"; getline(cin, og.bolum);
			cout << "\n\t\t\tSifresini giriniz		    :"; getline(cin, og.sifre);


			//Ogrenci.txt dosayaya yazma
			DosyaYaz.setf(ios::left);
			DosyaYaz << setw(15) << og.TcNo << setw(15) << og.ad << setw(15) << og.soyad <<
				setw(15) << og.bolum << setw(15) << og.sifre << setw(15)
				<< "\n" << endl;

			cout << "\n\n\t\t\tBaska eklemeyi ister misin... ? (e/h)";
			cin >> secim;
		}
		else
		{
			if (haneSayisi <= 0)
			{
				cout << "\n\t\t\t\a" << "0 veya Karakter veya Negatif TC numara olamaz, lütfen 11 haneli ve pozitif bir TC giriniz." << endl;
			}
			else
				cout << "\n\t\t\t\a" << haneSayisi << " haneli TC numara olamaz, lütfen 11 haneli bir TC giriniz." << endl;

			secim = 'e'; //dongu devami
		}

	} while (secim == 'e' || secim == 'E');

	cout << "\n\t\t\tOgrenci kaydi basardi...\n" << endl;

	DosyaYaz.close(); //ogrenci.txt dosyayi kapatma
}


void Sinav::OgrenciSilme(long long tc)
{
	ogrenci og;

	//Gecendeki gibi ayni mantikla islemleri dogru oldugu zaman kontrol degiskenleri tanimlama
	bool ogrenciSilindi = false;
	bool dogruTc = false;

	//Islemlere baslamadan girildigi tc var olup olmadigi kontrol ettirmek.
	ifstream DosyaOku1;
	DosyaOku1.open("ogrenci.txt", ios::in);

	if (DosyaOku1.is_open())//Dosyayi acik olup olmadigi bilme yontemi
	{
		DosyaOku1 >> og.TcNo >> og.ad >> og.soyad >> og.bolum >> og.sifre;


		while (!DosyaOku1.eof())
		{
			if (og.TcNo == tc)
			{
				dogruTc = true;
			}
			DosyaOku1 >> og.TcNo >> og.ad >> og.soyad >> og.bolum >> og.sifre;
		}
		DosyaOku1.close();
	}
	else
	{
		cout << "\n\t\t\tOgrenci dosyasi acilmadi" << endl;
	}

	if (dogruTc)//Demek ki Tc'yi bulunup islemler yapilabilir
	{

		bool silme;

		ifstream DosyaOku;
		DosyaOku.open("ogrenci.txt", ios::in);
		ofstream yeniDosyayaYaz;
		yeniDosyayaYaz.open("gecici.txt");

		DosyaOku >> og.TcNo >> og.ad >> og.soyad >> og.bolum >> og.sifre;

		while (!DosyaOku.eof())
		{
			if (og.TcNo != tc)
			{
				//Girildigi silecenek tc'li ogrenci haric tum ogrenciler yeni dosyaya (gecici) yazmak
				yeniDosyayaYaz.setf(ios::left);
				yeniDosyayaYaz << setw(15) << og.TcNo << setw(15) << og.ad << setw(15) << og.soyad
					<< setw(15) << og.bolum << setw(15) << og.sifre << setw(15) << "\n" << endl;

				ogrenciSilindi = true;
			}

			DosyaOku >> og.TcNo >> og.ad >> og.soyad >> og.bolum >>
				og.sifre; //Dosyayi okuma devami

		}
		if (ogrenciSilindi) //Silme basardi
		{
			cout << "\n\t\t\tOgrencimizde bu " << tc
				<< " numarali ogrenci silindi...\n" << endl;
		}
		/*islemleri tamamladiktan sonra dosyalari kapatip
		eski ogrenci dosyayi silip gecici dosyaya ogrenci adi verme */

		DosyaOku.close();
		yeniDosyayaYaz.close();

		remove("ogrenci.txt");
		rename("gecici.txt", "ogrenci.txt");

	}
	else
	{
		cout << "\n\t\t\tGirdiginiz TC numarasi bulunamadi"
			<< "\n\t\t\tLütfen kontrol edin." << endl;
	}

}



////////////////////////////SORU UZERINDE METOTLAR/////////////////////////////////////
void Sinav::SoruEkleme()
{
	ofstream DosyaYaz; //ofstream tipinde (Yazmak icin) DosyaYaz degiskeni tanimlama
	DosyaYaz.open("sorular.txt", ios::app); //ogrenci.txt dosyayi acma (olmasa da olusturacak)

	char secim;

	sorular sor; // Sinav siniftaki  sorular struct tipindeki sor degisken tanimlama (bilgileri erismek icin) 

	// dizi doldurmak 
	cout << "\t\t\t Sinav tipini girin: "; cin >> sor.sinavtipi;
	cout << "\t\t\t Soru sayisini girin: "; cin >> sor.sorusayisi;
	cout << "\t\t\t Sinav suresini girin: "; cin >> sor.sure;

	for (int i = 0; i < sor.sorusayisi; i++)
	{
		sor.soru = sor.dizi[i][0];
		sor.A = sor.dizi[i][1];
		sor.B = sor.dizi[i][2];
		sor.C = sor.dizi[i][3];
		sor.D = sor.dizi[i][4];
		sor.dogcev = sor.dizi[i][5];

		cout << "\n\t\t\t sorunun numarasini girin: "; cin >> sor.sayi;
		cout << "\n\t\t\t soru girin:   ";  cin >> sor.soru;
		cout << "\t\t\t A) ";  cin >> sor.A;
		cout << "\t\t\t B) ";  cin >> sor.B;
		cout << "\t\t\t C) ";  cin >> sor.C;
		cout << "\t\t\t D) ";  cin >> sor.D;
		cout << "\t\t\tDogru cevap girin: "; cin >> sor.dogcev;
		cout << "\t\t\t Puan: "; cin >> sor.puan;
		cout << endl << endl;
		cout << "\t\t\t" << sor.sayi << ". soru : " << sor.soru << setw(5) << " A)" << sor.A << setw(5) << " B)" << sor.B << setw(5) << " C)" << sor.C << setw(5) << " D)" << sor.D << setw(9) << " DoCev=" << sor.dogcev << setw(5) << " Puan=" << sor.puan;

		//DosyaYaz << sor.sayi << sor.soru << "  A)" << sor.A << "  B)" << sor.B << "  C)" << sor.C << "  D)" << sor.D << "  DoCev=" << sor.dogcev << "    Puan" << sor.puan << "\n";
		//Sorular.txt dosayaya yazma
		DosyaYaz.setf(ios::left);
		DosyaYaz << setw(8) << sor.sinavtipi << setw(8) << sor.sure << setw(8) << sor.sayi << setw(8) << sor.soru << setw(8) << sor.A << setw(8) << sor.B << setw(8) << sor.C << setw(8) << sor.D << setw(8) << sor.dogcev << setw(8) << sor.puan << "\n";
	}

	cout << "\n\t\t\tSoru kaydi basardi...\n\n\n" << endl;

	DosyaYaz.close(); //sorular.txt dosyayi kapatma
}


void Sinav::SoruListesi(sorular sor)
{
	ifstream DosyaOku; // sorular  .text dosyayi okuma
	DosyaOku.open("sorular.txt", ios::in);

	cout << "\t\t\t Sinav tipini :" << sor.sinavtipi << endl;

	while (!(DosyaOku.eof()))
	{
		DosyaOku >> sor.sinavtipi >> sor.sure >> sor.sayi >> sor.soru >> sor.A >> sor.B >> sor.C >> sor.D >> sor.dogcev >> sor.puan;
		cout << "\n\t\t\t" << sor.sayi << ".)" << sor.soru << "  A) " << sor.A << "  B)" << sor.B << "  C)" << sor.C << "  D) " << sor.D << "  DoCev=" << sor.dogcev << "  puan= " << sor.puan << endl;
	}
	DosyaOku.close();  //sorular.txt dosyayi kapatma
}