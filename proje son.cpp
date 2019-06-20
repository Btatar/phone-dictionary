#include<stdio.h>
#include<conio.h>
#include<string.h>

struct rehber
{
	char ad[10];
	char soyad[10];
	long int ceptel;
    char mail[15];
	int dogyil;
	char il[10];
	char ilce[10];
	char mahalle[10];
	int sokak;	
	
};
void Kisiekle();
void Kisigoruntule();
void Kisiara(char *a, char *b);
void Kisiara2(int x);
void Kisiguncelle(char *k, char *m);
void Kisisil(char *t);

main ()
{
	int sec2,ara6,i=1;
	char sec;
	char ara[10],ara2[10],ara3[10],ara4[10],ara5[10];
	printf("Telefon Rehberi Uygulamasina Hosgeldiniz.\n");

	while(i>0)
	{
		printf("\n  A-Kisi ekle\n  B-Goruntule\n  C-Kisi Ara\n  D-Guncelle\n  E-Kisi Sil\n  F-Cikis\n");
		printf("Luften Menude Yapmak Istediginiz Uygulamanin Harfini Giriniz : ");
		sec = getche() ;

		if(sec=='A')
		{
			Kisiekle();
		}

		 else if(sec=='B')
		{
			Kisigoruntule();
		}

		else if(sec=='C')
		{
			char cev;
			printf("Lutfen Arama Yapacaginiz Secenegi Giriniz : ");
			printf("\n  1-Ada Gore Arama Yapmak Icin \n 2-Dogum Yilina Gore Arama Yapmak Icin : ");
			scanf("%d",&cev);
			if(cev==1)
			{
				printf("\nAramak Istediginiz Ismi Giriniz :");
				scanf("%s",&ara);
				printf("\nAramak Istediginiz Soyismi Giriniz :");
				scanf("%s",&ara2);
				Kisiara(ara, ara2);		
			}
		    else if(cev==2)
		    {
		    	printf("\nAramak Istediginiz Kisinin Dogum Yilini Giriniz : ");
				scanf("%d",&ara6);
				Kisiara2(ara6);
			}
	    }
		else if(sec=='D')
		{
			printf("\nLutfen Guncellemek Istediginiz Kisinin Adini Giriniz : ");
			scanf("%s",&ara3);
			printf("\nLutfen Guncellemek Istediginiz Kisinin Soyadini Giriniz : ");
			scanf("%s",&ara4);
		    Kisiguncelle(ara3,ara4);
		}
		else if(sec=='E')
		{
			printf("\nLutfen Silmek Istediginiz Kisinin Adini Giriniz : ");
			scanf("%s",&ara5);
			Kisisil(ara5);
	    }
		else if(sec=='F')
		{
			i=0;
			printf("\nRehber Programi Kapaniyor");
		}
    	else
    		printf("\nMenude Olmayan Bir Tusa Bastiniz!!");
		
    	}
}

void Kisiekle()
{
	struct rehber veri;
	FILE *dosya;
	dosya=fopen("PROJE.txt","a");
	printf("\nLutfen Yeni Kisiye Ait Bilgileri Giriniz : ");
	printf("\nAd, Soyad, Telefon, E-mail, Dogum Yili : ");
	scanf("%s%s%ld%s%d",&veri.ad,&veri.soyad,&veri.ceptel,&veri.mail,&veri.dogyil);
	printf("\nAdres Bilgisi Icin Il, Ilce, Mahalle, Sokak : ");
	scanf("%s%s%s%d",&veri.il,&veri.ilce,&veri.mahalle,&veri.sokak);
	fprintf(dosya,"%s   %s   %ld   %s   %d   ",veri.ad,veri.soyad,veri.ceptel,veri.mail,veri.dogyil);
	fprintf(dosya,"%s   %s   %s   %d\n",veri.il,veri.ilce,veri.mahalle,veri.sokak);
	fclose(dosya);
}
	
void Kisigoruntule()
{
	struct rehber veri;
	FILE *dosya;
	dosya=fopen("PROJE.txt","r");
	printf("\n   AD        SOYAD        TELEFON     E-MAIL  DOGUM YILI    IL     ILCE    MAHALLE     SOKAK\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	while(fscanf(dosya,"%s  %s  %ld  %s  %d  %s  %s  %s  %d",&veri.ad,&veri.soyad,&veri.ceptel,&veri.mail,&veri.dogyil,&veri.il,&veri.ilce,&veri.mahalle,&veri.sokak)!=EOF)
	{
		printf("%s  %8s  %15ld  %8s  %8d  %8s  %8s  %8s  %8d\n",veri.ad,veri.soyad,veri.ceptel,veri.mail,veri.dogyil,veri.il,veri.ilce,veri.mahalle,veri.sokak);
	}
	fclose(dosya);
}
 
void Kisiara(char *a, char *b)
{
	struct rehber veri;
	FILE *dosya;
	dosya=fopen("PROJE.txt","r");
	while(fscanf(dosya,"%s  %s  %ld  %s  %d  %s  %s  %s  %d",&veri.ad,&veri.soyad,&veri.ceptel,&veri.mail,&veri.dogyil,&veri.il,&veri.ilce,&veri.mahalle,&veri.sokak)!=EOF)
	{
		if(!strcmp(veri.ad,a) && !strcmp(veri.soyad,b))
			printf("\n%s  %s  %ld  %s  %d  %s  %s  %s  %d\n",veri.ad,veri.soyad,veri.ceptel,veri.mail,veri.dogyil,veri.il,veri.ilce,veri.mahalle,veri.sokak);
	}
fclose(dosya);
}

void Kisiara2(int x)
{
	struct rehber veri;
	FILE *dosya;
	dosya=fopen("PROJE.txt","r");
	while(fscanf(dosya,"%s  %s  %ld  %s  %d  %s  %s  %s  %d",&veri.ad,&veri.soyad,&veri.ceptel,&veri.mail,&veri.dogyil,&veri.il,&veri.ilce,&veri.mahalle,&veri.sokak)!=EOF)
	{
		if((veri.dogyil==x))
			printf("\n%s  %s  %ld  %s  %d  %s  %s  %s  %d\n",veri.ad,veri.soyad,veri.ceptel,veri.mail,veri.dogyil,veri.il,veri.ilce,veri.mahalle,veri.sokak);
	}
	fclose(dosya);
}

void Kisiguncelle(char *k, char *m)
{
	char sec2,sec3,sec4,sec5;
	struct rehber veri;
	FILE *dosya, *temp;
	dosya=fopen("PROJE.txt","r");
	temp=fopen("PROJE2.txt","w");
	while(fscanf(dosya,"%s  %s  %ld  %s  %d  %s  %s  %s  %d",&veri.ad,&veri.soyad,&veri.ceptel,&veri.mail,&veri.dogyil,&veri.il,&veri.ilce,&veri.mahalle,&veri.sokak)!=EOF)
	{
		if(!strcmp(veri.ad,k) && !strcmp(veri.soyad,m))
		{
			printf("Kisinin Telefon Bilgisini Guncellemek Ister misiniz? E/H ");
			sec3= getche ();
			if(sec3=='E')
			{
				printf("\nGuncellenmis Telefon Bilgisi Giriniz:" );
				scanf("%ld",&veri.ceptel);
			}
			
			printf("\nKisinin Email Bilgisini Guncellemek Ister misiniz? E/H ");
			sec4= getche ();
			if(sec4=='E')
			{
				printf("\nGuncellenmis Email Bilgisi Giriniz: ");
				scanf("%s",&veri.mail);
			}
			
			printf("\nKisinin Soyad ve Dogum Yili Bilgisini Guncellemek Ister misiniz? E/H ");
			sec5= getche ();
			if(sec5=='E')
			{
				printf("\nGuncellenmis Soyad  Bilgisi Giriniz: ");
				scanf("%s",&veri.soyad);
				printf("\nGuncellenmis Dogum Yili  Bilgisi Giriniz: ");
				scanf("%d",&veri.dogyil);
				fprintf(temp,"%s   %s   %ld   %s   %d   ",veri.ad,veri.soyad,veri.ceptel,veri.mail,veri.dogyil);
			}
			else
				fprintf(temp,"%s   %s   %ld   %s   %d   ",veri.ad,veri.soyad,veri.ceptel,veri.mail,veri.dogyil);
		
			printf("\nKisinin Adres Bilgilerini Guncellemek Ister misiniz? E/H \n");
			sec2= getche ();
			if(sec2=='E')
			{
				printf("\nGuncellenmis Adres Bilgisi Icin Il, Ilce, Mahalle, Sokak Giriniz: ");
				scanf("%s%s%s%d",&veri.il,&veri.ilce,&veri.mahalle,&veri.sokak);
				fprintf(temp,"%s   %s   %s   %d",veri.il,veri.ilce,veri.mahalle,veri.sokak);
			}
			else
				fprintf(temp,"%s   %s   %s   %d",veri.il,veri.ilce,veri.mahalle,veri.sokak);
		}
		else
			fprintf(temp,"%s  %s  %ld  %s  %d  %s  %s  %s  %d\n",veri.ad,veri.soyad,veri.ceptel,veri.mail,veri.dogyil,veri.il,veri.ilce,veri.mahalle,veri.sokak);	
    }
	fclose(dosya);
	fclose(temp);
	remove("PROJE.txt");	
	rename("PROJE2.txt", "PROJE.txt");
}

void Kisisil(char *t)
{
	struct rehber veri;
	FILE *dosya, *temp;
	dosya=fopen("PROJE.txt","r");
	temp=fopen("PROJE2.txt","w");
	while(fscanf(dosya,"%s  %s  %ld  %s  %d  %s  %s  %s  %d",&veri.ad,&veri.soyad,&veri.ceptel,&veri.mail,&veri.dogyil,&veri.il,&veri.ilce,&veri.mahalle,&veri.sokak)!=EOF)
	{
		if(!strcmp(veri.ad,t))
		{
			printf("Silinen Kisi %s: \n",t);
		}
		else
			fprintf(temp,"%s   %s   %ld   %s   %d   %s   %s   %s   %d\n",veri.ad,veri.soyad,veri.ceptel,veri.mail,veri.dogyil,veri.il,veri.ilce,veri.mahalle,veri.sokak);
	}
	fclose(dosya);
	fclose(temp);
	remove("PROJE.txt");	
	rename("PROJE2.txt", "PROJE.txt");
 
}


