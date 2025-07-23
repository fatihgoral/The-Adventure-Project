#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ALTIN 0
#define SEVIYE 1
#define TECRUBE 2
#define CAN 3
#define TOKLUK 4
#define UYKU 5
#define HIJYEN 6
#define SU 7
#define ENERJI 8
#define MORAL 9
#define GUC 10
#define CEVIKLIK 11
#define DAYANIKLILIK 12
#define KARIZMA 13
#define TOPLAYICILIK 14


float ozellikler[15] = {10, 1, 0, 100, 100, 100, 100, 100, 100, 100, 3, 3, 3, 3, 3};    //Karakterlerin ozelliklerini bir dizide tuttuk

char ad[50]; //ozan adi
char calgi[50]; //calgi adi

//fonksiyon protitipleri
void menuGoster();
void kampAlani(float[]);
void sifahane(float[]);
void han(float[]);
void macera(float[]);
void seviyeAtla(float[]);
void durumGoster(float[]);
void oyundanCik();

int main() {

    //oyun tanitimi
    printf("*************************** OZANIN MACERASI ****************************\n\n");
    printf("Ozan, koy meydaninda sessizce oturmus, hayal dunyasinda geziniyordu.\n");
    printf("Koyde herkes onu neseli sarkilariyla taniyordu, ama ozanin aklinda daha buyuk bir hayal vardi:\nGercek bir maceraya atilarak kendine koy halkina ispat etmek .\n\n");

    printf("Bir sabah, koyun muhtari ona yaklasti ve dedi ki:\n");
    printf("\"Ozan, koyumuzun cevresindeki ormanlarda garip seyler oluyor.\n");
    printf("Cesur birinin gidip bunu arastirmasi gerek.\n");
    printf("Senin sarkilarin ve cesaretin bize yardim edebilir.\"\n\n");

    printf("Ozan, bu atesten gomlegi giydi,gozunu karartti ve maceraya atilmak icin koy meydanindan ayrilmaya karar verdi.\n");
    printf("Onunde kesfedilecek ormanlar, atlatilacak tehlikeler ve koya donus yolunda anlatilacak yeni hikayeler vardi.\n");
    printf("Simdi, onun macerasi basliyordu.\n");
    printf("Haydi, siz de bu eglenceye ortak olmak icin verilen talimatlara uyarak oyun baslayin.\n\n");
    printf("*\n\n");

    srand(time(NULL)); // Rastgele sayi uretimi

    printf("Ozanin adini girin: ");
    gets(ad);
    printf("Ozanin kullandigi calgiyi girin: ");
    gets(calgi);

    int secim;
    while (1) {  //sonsuz dongu
        menuGoster();
        printf("Bir secenek secin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Kamp alanina gidiyorsunuz...\n");
                kampAlani(ozellikler);
                break;
            case 2:
                printf("Sifahaneye gidiyorsunuz...\n");
                sifahane(ozellikler);
                break;
            case 3:
                printf("Hana gidiyorsunuz...\n");
                han(ozellikler);
                break;
            case 4:
                printf("Macera alanina gidiyorsunuz...\n");
                macera(ozellikler);
                break;
            case 5:
                printf("Seviye atlaya gidiyorsunuz...\n");
                seviyeAtla(ozellikler);
                break;
            case 6:
                printf("Durumlar gosteriliyor...\n");
                durumGoster(ozellikler);
                break;
            case 7:
                printf("Oyundan cikmak istiyorsunuz...\n");
                oyundanCik();
                break;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
        //kritik niteliklerin 20 ve altina dusmesi
        if (ozellikler[TOKLUK] <= 20)
                printf("Tokluk seviyesi %.2f ye kadar dustu dikkat !!! \n",ozellikler[TOKLUK]);
        if (ozellikler[UYKU] <= 20)
                printf("Uyku seviyesi %.2f ye kadar dustu dikkat !!! \n",ozellikler[UYKU]);
        if (ozellikler[HIJYEN] <= 20)
                printf("Hijyen seviyesi %.2f ye kadar dustu dikkat !!! \n",ozellikler[HIJYEN]);
        if (ozellikler[SU] <= 20)
                printf("Su seviyesi %.2f ye kadar dustu dikkat !!! \n",ozellikler[SU]);
        if (ozellikler[ENERJI] <= 20)
                printf("Enerji seviyesi %.2f ye kadar dustu dikkat !!! \n",ozellikler[ENERJI]);
        // Kritik niteliklerin kontrol edilmesi
        if (ozellikler[TOKLUK] <= 0 || ozellikler[UYKU] <= 0 || ozellikler[HIJYEN] <= 0 || ozellikler[SU] <= 0 || ozellikler[ENERJI] <= 0) {

            int canKaybi = 0;

            if (ozellikler[TOKLUK] <= 0)
                canKaybi += 20;
            if (ozellikler[UYKU] <= 0)
                canKaybi += 10;
            if (ozellikler[HIJYEN] <= 0)
                canKaybi += 15;
            if (ozellikler[SU] <= 0)
                canKaybi += 10;
            if (ozellikler[ENERJI] <= 0)
                canKaybi += 25;

            ozellikler[CAN] -= canKaybi;
            printf("Nitelikler kritik seviyede! Caniniz %d azaldi.\n", canKaybi);

            if (ozellikler[CAN] <= 0) {
                printf("Caniniz tükendi. Oyun sona erdi!\n");
                return 0;
            }
        }
    }

    return 0;
}

void menuGoster() {
    printf("\n******* ANA MENU ******\n");
    printf("1. Kamp alanina git\n");
    printf("2. Sifahane git\n");
    printf("3. Hana git\n");
    printf("4. Maceraya atil\n");
    printf("5. Seviye atla\n");
    printf("6. Durumu goster\n");
    printf("7. Oyundan cik\n");
}

void kampAlani(float ozellikler[]) {

    int secim;
    do{
        printf("\n***** KAMP ALANI ****\n");
    printf("1. Kamp atesinin basinda calgi cal/sarki soyle\n");
    printf("2. Nehirde yikan\n");
    printf("3. Cadirina girip uyu\n");
    printf("4. Koy meydanina don\n");


    printf("Bir secenek secin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            printf("Calginizi calmaya basladiniz...\n");
            ozellikler[MORAL] += 10;
            ozellikler[ENERJI] -= 5;
            ozellikler[SU] -=5;
            ozellikler[UYKU] -=15;
            ozellikler[TOKLUK] -=15;
            break;
        case 2:
            printf("Nehirde yikaniyorsunuz...\n");
            ozellikler[HIJYEN] += 20;
            ozellikler[SU] += 15;
            ozellikler[UYKU] -=10;
            ozellikler[TOKLUK] -=10;
            break;
        case 3:
            printf("Cadirinizda uyuyorsunuz...\n");
            ozellikler[UYKU] += 30;
            ozellikler[ENERJI] += 20;
            ozellikler[MORAL] += 20;
            ozellikler[DAYANIKLILIK] += 10;
            ozellikler[GUC] += 10;
            ozellikler[TOKLUK] -=20;
            ozellikler[SU] -=10;
            break;
        case 4:
            printf("Koy meydanina geri donuyorsunuz...\n");
            return;
        default:
            printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
            return;
    }
    }while(secim<1 || secim>4);

    if(ozellikler[TOKLUK]>100)
        ozellikler[TOKLUK]=100;
    if(ozellikler[TOKLUK]<0)
        ozellikler[TOKLUK]=0;
    if(ozellikler[UYKU]>100)
        ozellikler[UYKU] =100;
    if(ozellikler[UYKU]<0)
        ozellikler[UYKU] = 0;
    if(ozellikler[SU] > 100)
        ozellikler[SU] = 100;
    if(ozellikler[SU] < 0)
        ozellikler[SU] = 0;
    if(ozellikler[HIJYEN] > 100)
        ozellikler[HIJYEN]= 100;
    if(ozellikler[HIJYEN] < 0)
        ozellikler[HIJYEN] = 0;
    if(ozellikler[ENERJI] > 100)
        ozellikler[ENERJI] = 100;
    if(ozellikler[ENERJI] < 0)
        ozellikler[ENERJI] = 0;
    if(ozellikler[CAN] > 100)
        ozellikler[CAN] = 100;
    if(ozellikler[CAN] < 0)
        ozellikler[CAN] = 0;

      if(ozellikler[MORAL] > 25)
        ozellikler[MORAL]= 25;
       if(ozellikler[MORAL] < 3)
        ozellikler[MORAL]= 3;
       if(ozellikler[GUC] > 25)
        ozellikler[GUC]= 25;
       if(ozellikler[GUC] < 3)
        ozellikler[GUC]= 3;

       if(ozellikler[CEVIKLIK] > 25)
        ozellikler[CEVIKLIK]= 25;
       if(ozellikler[CEVIKLIK] < 3)
        ozellikler[CEVIKLIK]= 3;

       if(ozellikler[DAYANIKLILIK] > 25)
        ozellikler[DAYANIKLILIK]= 25;
       if(ozellikler[DAYANIKLILIK] < 3)
        ozellikler[DAYANIKLILIK]= 3;

       if(ozellikler[KARIZMA] > 25)
        ozellikler[KARIZMA]= 25;
       if(ozellikler[KARIZMA] < 3)
        ozellikler[KARIZMA]= 3;


       if(ozellikler[TOPLAYICILIK] > 25)
        ozellikler[TOPLAYICILIK]= 25;
       if(ozellikler[TOPLAYICILIK] < 3)
        ozellikler[TOPLAYICILIK]= 3;

    printf("Karakterin Temel Niteliklerinin Guncel Durumu -> Can:%.2f ,Tokluk: %.2f, Uyku: %.2f, Hijyen: %.2f, Su: %.2f, Enerji: %.2f\n",ozellikler[CAN] , ozellikler[HIJYEN], ozellikler[UYKU], ozellikler[SU], ozellikler[ENERJI], ozellikler[MORAL]);
}

void sifahane(float ozellikler[]) {

    int secim;
    do{
        printf("\n******* SIFAHANE ******\n");
    printf("1. Pahali tedavi.Sifacidan yaralarini satmasini iste (3 altin, +30 Can)\n");
    printf("2. Orta tedavi.Sifacidan merhem yapip surmesini iste (2 altin, +20 Can)\n");
    printf("3. Ucuz tedavi.Sifacidan merhem isteyip yaralarina kendin sur (1 altin, +10 Can)\n");
    printf("4. Koy meydanina don\n");


    printf("Bir secenek secin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            if (ozellikler[ALTIN] >= 3) {
                printf("Pahali tedavi aliniyor...\n");
                ozellikler[ALTIN] -= 3;
                ozellikler[CAN] += 30;
                ozellikler[GUC] +=4;
                ozellikler[DAYANIKLILIK]+=6;
                ozellikler[CEVIKLIK] +=5;
                ozellikler[MORAL] +=20;
            } else{
                    printf("Yeterli altininiz yok su kadar altininiz var : %.2f\n",ozellikler[ALTIN]);

                }
            break;
        case 2:
            if (ozellikler[ALTIN] >= 2) {
                printf("Orta tedavi aliniyor...\n");
                ozellikler[ALTIN] -= 2;
                ozellikler[CAN] += 20;
                ozellikler[GUC] +=2;
                ozellikler[DAYANIKLILIK]+=3;
                ozellikler[CEVIKLIK] +=3;
                ozellikler[MORAL] +=15;
            } else{
                    printf("Yeterli altininiz yok su kadar altininiz var : %.2f\n",ozellikler[ALTIN]);

                }
            break;
        case 3:
            if (ozellikler[ALTIN] >= 1) {
                printf("Ucuz tedavi aliniyor...\n");
                ozellikler[ALTIN] -= 1;
                ozellikler[CAN] += 10;
                ozellikler[GUC] +=1;
                ozellikler[DAYANIKLILIK]+=2;
                ozellikler[CEVIKLIK] +=2;
                ozellikler[MORAL] +=10;
            }else{
                    printf("Yeterli altininiz yok su kadar altininiz var : %.2f\n",ozellikler[ALTIN]);

                }
            break;
        case 4:
            printf("Koy meydanina geri donuyorsunuz...\n");
            return;
        default:
            printf("Gecersiz secim! Tekrar deneyin.\n");
    }
    }while(secim<1 || secim >4);


    if(ozellikler[TOKLUK]>100)
        ozellikler[TOKLUK]=100;
    if(ozellikler[TOKLUK]<0)
        ozellikler[TOKLUK]=0;
    if(ozellikler[UYKU]>100)
        ozellikler[UYKU] =100;
    if(ozellikler[UYKU]<0)
        ozellikler[UYKU] = 0;
    if(ozellikler[SU] > 100)
        ozellikler[SU] = 100;
    if(ozellikler[SU] < 0)
        ozellikler[SU] = 0;
    if(ozellikler[HIJYEN] > 100)
        ozellikler[HIJYEN]= 100;
    if(ozellikler[HIJYEN] < 0)
        ozellikler[HIJYEN] = 0;
    if(ozellikler[ENERJI] > 100)
        ozellikler[ENERJI] = 100;
    if(ozellikler[ENERJI] < 0)
        ozellikler[ENERJI] = 0;
    if(ozellikler[CAN] > 100)
        ozellikler[CAN] = 100;
    if(ozellikler[CAN] < 0)
        ozellikler[CAN] = 0;


    if(ozellikler[MORAL] > 25)
        ozellikler[MORAL]= 25;
    if(ozellikler[MORAL] < 3)
        ozellikler[MORAL]= 3;
    if(ozellikler[GUC] > 25)
        ozellikler[GUC]= 25;
    if(ozellikler[GUC] < 3)
        ozellikler[GUC]= 3;

    if(ozellikler[CEVIKLIK] > 25)
        ozellikler[CEVIKLIK]= 25;
    if(ozellikler[CEVIKLIK] < 3)
        ozellikler[CEVIKLIK]= 3;

    if(ozellikler[DAYANIKLILIK] > 25)
        ozellikler[DAYANIKLILIK]= 25;
    if(ozellikler[DAYANIKLILIK] < 3)
        ozellikler[DAYANIKLILIK]= 3;

    if(ozellikler[KARIZMA] > 25)
        ozellikler[KARIZMA]= 25;
    if(ozellikler[KARIZMA] < 3)
        ozellikler[KARIZMA]= 3;


    if(ozellikler[TOPLAYICILIK] > 25)
        ozellikler[TOPLAYICILIK]= 25;
    if(ozellikler[TOPLAYICILIK] < 3)
        ozellikler[TOPLAYICILIK]= 3;

    printf("Karakterin Temel Niteliklerinin Guncel Durumu -> Can:%.2f ,Tokluk: %.2f, Uyku: %.2f, Hijyen: %.2f, Su: %.2f, Enerji: %.2f\n",ozellikler[CAN] , ozellikler[HIJYEN], ozellikler[UYKU], ozellikler[SU], ozellikler[ENERJI], ozellikler[MORAL]);


}

void han(float ozellikler[]) {
    int secim;
    do{
        printf("\n******* HAN *********\n");
    printf("1. Yiyecek satin al ve ye\n");
    printf("2. Icecek satin al, ic ve eglen\n");
    printf("3. Enstruman cal ve sarki soyle\n");
    printf("4. Koy meydanina don\n");


    int yiyecek_secimi;
    int icecek_secimi;
    printf("Bir secenek secin: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:

            do{
                printf("Yemek yiyorsunuz...\n");
                printf("Yiyecekler ve fiyatlari listesi...\n");
                printf("1-)Lahmacun=Tokluk 30 puan , fiyat = 3 altin \n");
                printf("2-)Iskender=Tokluk 50 puan , fiyat = 5 altin \n");
                printf("3-)Muz=Tokluk 10 puan , fiyat = 1 altin \n");

                printf("Hangi yiyecegi sectiniz \n");
                scanf("%d",&yiyecek_secimi);
                if(yiyecek_secimi == 1){
                    if(ozellikler[ALTIN]>=3){
                    ozellikler[TOKLUK] += 30;
                    ozellikler[ALTIN] -= 3;
                    ozellikler[MORAL] += 10;
                    ozellikler[UYKU] -=10;
                    ozellikler[HIJYEN] -=20;
                    ozellikler[SU] -=15;
                    ozellikler[ENERJI] +=15;
                    }else{
                        printf("Yeterli altininiz yok su kadar altininiz var : %.2f\n",ozellikler[ALTIN]);

                    }

                }else if(yiyecek_secimi == 2){
                    if(ozellikler[ALTIN]>=5){
                    ozellikler[TOKLUK] += 50;
                    ozellikler[ALTIN] -= 5;
                    ozellikler[MORAL] += 10;
                    ozellikler[UYKU] -=10;
                    ozellikler[HIJYEN] -=25;
                    ozellikler[SU] -=20;
                    ozellikler[ENERJI] +=25;
                    }else{
                        printf("Yeterli altininiz yok su kadar altininiz var : %.2f\n",ozellikler[ALTIN]);

                    }

                }
                else if(yiyecek_secimi == 3){
                    if(ozellikler[ALTIN]>=1){
                    ozellikler[TOKLUK] += 10;
                    ozellikler[ALTIN] -= 1;
                    ozellikler[MORAL] += 10;
                    ozellikler[UYKU] -=5;
                    ozellikler[HIJYEN] -=10;
                    ozellikler[SU] -=5;
                    ozellikler[ENERJI] +=10;
                    }else{
                        printf("Yeterli altininiz yok su kadar altininiz var : %.2f\n",ozellikler[ALTIN]);

                    }

                }
            else
                printf("Hatali secim yaptiniz.Tekrar seciniz.\n...");
            }while(yiyecek_secimi<0 || yiyecek_secimi>3);


            break;
        case 2:
    do {
        printf("Icecek iciyorsunuz...\n");
        printf("1-) Su (1 altin, Su +30)\n");
        printf("2-) Enerji Icecegi (2 altin, Su +20, Enerji +30)\n");
        printf("3-) Milkshake (3 altin, Su +10, Enerji +20)\n");
        printf("Hangi icecegi sectiniz: ");
        scanf("%d", &icecek_secimi);

        if (icecek_secimi == 1 && ozellikler[ALTIN] >= 1) {
            ozellikler[SU] += 30;
            ozellikler[ALTIN] -= 1;
            ozellikler[MORAL] += 10;
            printf("Su icildi. Su seviyeniz: %.2f\n", ozellikler[SU]);
        } else if (icecek_secimi == 2 && ozellikler[ALTIN] >= 2) {
            ozellikler[SU] += 20;
            ozellikler[ALTIN] -= 2;
            ozellikler[MORAL] += 10;
            ozellikler[ENERJI] += 30;
            ozellikler[CEVIKLIK] += 4;
            ozellikler[GUC] += 2;
            ozellikler[DAYANIKLILIK] += 1;
            printf("Enerji icecegi icildi. Enerji seviyeniz: %.2f\n", ozellikler[ENERJI]);
        } else if (icecek_secimi == 3 && ozellikler[ALTIN] >= 3) {
            ozellikler[SU] += 10;
            ozellikler[ALTIN] -= 3;
            ozellikler[MORAL] += 10;
            ozellikler[ENERJI] += 20;
            printf("Milkshake icildi. Enerji seviyeniz: %.2f\n", ozellikler[ENERJI]);
        } else {
            printf("Yeterli altininiz yok veya gecersiz secim yaptiniz.\n");
        }
    } while (icecek_secimi < 1 || icecek_secimi > 3);
    break;

        case 3:
            if (ozellikler[HIJYEN] > 20) {
                printf("Hana Hosgeldiniz...\n");
                float kazanc = 10 + (ozellikler[KARIZMA] * ozellikler[HIJYEN]) / 100;
                printf("Sarki soyleyerek %.2f altin kazandiniz!\n", kazanc);
                ozellikler[ALTIN] += kazanc;
                ozellikler[TECRUBE] += 20;
                if (ozellikler[TECRUBE] >= 100)
                        seviyeAtla(ozellikler);
            } else {
                printf("Hijyeniniz dusuk, sarki soyleyemezsiniz!\n");
                return;
            }
            break;
        case 4:
            printf("Koy meydanina geri donuyorsunuz...\n");
            return;
        default:
            printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
            return;
    }
    }while(secim<1 || secim>4);


    if(ozellikler[TOKLUK]>100)
        ozellikler[TOKLUK]=100;
    if(ozellikler[TOKLUK]<0)
        ozellikler[TOKLUK]=0;
    if(ozellikler[UYKU]>100)
        ozellikler[UYKU] =100;
    if(ozellikler[UYKU]<0)
        ozellikler[UYKU] = 0;
    if(ozellikler[SU] > 100)
        ozellikler[SU] = 100;
    if(ozellikler[SU] < 0)
        ozellikler[SU] = 0;
    if(ozellikler[HIJYEN] > 100)
        ozellikler[HIJYEN]= 100;
    if(ozellikler[HIJYEN] < 0)
        ozellikler[HIJYEN] = 0;
    if(ozellikler[ENERJI] > 100)
        ozellikler[ENERJI] = 100;
    if(ozellikler[ENERJI] < 0)
        ozellikler[ENERJI] = 0;
    if(ozellikler[CAN] > 100)
        ozellikler[CAN] = 100;
    if(ozellikler[CAN] < 0)
        ozellikler[CAN] = 0;

       if(ozellikler[MORAL] > 25)
        ozellikler[MORAL]= 25;
       if(ozellikler[MORAL] < 3)
        ozellikler[MORAL]= 3;
       if(ozellikler[GUC] > 25)
        ozellikler[GUC]= 25;
       if(ozellikler[GUC] < 3)
        ozellikler[GUC]= 3;

       if(ozellikler[CEVIKLIK] > 25)
        ozellikler[CEVIKLIK]= 25;
       if(ozellikler[CEVIKLIK] < 3)
        ozellikler[CEVIKLIK]= 3;

       if(ozellikler[DAYANIKLILIK] > 25)
        ozellikler[DAYANIKLILIK]= 25;
       if(ozellikler[DAYANIKLILIK] < 3)
        ozellikler[DAYANIKLILIK]= 3;

       if(ozellikler[KARIZMA] > 25)
        ozellikler[KARIZMA]= 25;
       if(ozellikler[KARIZMA] < 3)
        ozellikler[KARIZMA]= 3;


       if(ozellikler[TOPLAYICILIK] > 25)
        ozellikler[TOPLAYICILIK]= 25;
       if(ozellikler[TOPLAYICILIK] < 3)
        ozellikler[TOPLAYICILIK]= 3;

     printf("Karakterin Temel Niteliklerinin Guncel Durumu -> Can:%.2f ,Tokluk: %.2f, Uyku: %.2f, Hijyen: %.2f, Su: %.2f, Enerji: %.2f\n",ozellikler[CAN] , ozellikler[HIJYEN], ozellikler[UYKU], ozellikler[SU], ozellikler[ENERJI], ozellikler[MORAL]);
}

void macera(float ozellikler[]) {
    srand(time(NULL));
    int secim;
    do{
       printf("\n******** MACERA *********\n");
    printf("1. Yakin cevreden sifalil bitki topla ve avlan\n");
    printf("2. Ormani kesfe cik (Kolay)\n");
    printf("3. Kayaliklari kesfe cik (Orta)\n");
    printf("4. Vadiyi kesfe cik (Zor)\n");
    printf("5. Koy meydanina don\n");


    printf("Bir secenek secin: ");
    scanf("%d", &secim);


        switch (secim) {
            case 1:
            {
            // Þifalý bitki toplama ve avlanma iþlemi
                printf("Yakin cevreden sifali bitki toplama ve avlanma basladi!\n");

                int sans = rand() % 100; // Rastgele þans deðeri (0-99 arasý)
                double sifali_bitki_sans = (ozellikler[TOPLAYICILIK] * 4) / 100.0; // Yüzdelik oran hesaplama
                int sifali_bitki_sans2 = sifali_bitki_sans * 100; // Ondalýk deðeri tam sayý yapmak için

                if (sans < sifali_bitki_sans2) {
                // Þifalý bitki bulundu
                printf("sifali bitki buldunuz! +10 Can\n");
                ozellikler[CAN] += 10;
                ozellikler[TOKLUK]+=10;
                ozellikler[UYKU]-=15;
                ozellikler[ENERJI]+=15;
                ozellikler[MORAL]+=4;
                ozellikler[GUC]+=4;
                ozellikler[DAYANIKLILIK]+=7;
                ozellikler[CEVIKLIK]+=4;
                ozellikler[TOPLAYICILIK]+=15;


                // Ayný þansla meyve toplama kontrolü
                    int sans2 = rand() % 100; // Rastgele þans deðeri (0-99 arasý)
                    double meyve_sans = (ozellikler[TOPLAYICILIK] * 4) / 100.0; // Yüzdelik oran hesaplama
                    int meyve_sans2 = meyve_sans * 100; // Ondalýk deðeri tam sayý yapmak için
                    if (sans2< meyve_sans2) {
                    printf("Ayni zamanda meyve de topladiniz! +10 Tokluk\n");
                    ozellikler[TOKLUK]+=10;
                    ozellikler[UYKU]-=10;
                    ozellikler[ENERJI]+=10;
                    ozellikler[MORAL]+=3;
                    ozellikler[GUC]+=2;
                    ozellikler[DAYANIKLILIK]+=1;
                    ozellikler[CEVIKLIK]+=3;
                    ozellikler[TOPLAYICILIK]+=10;
                    ozellikler[TECRUBE]+=12;
                    if (ozellikler[TECRUBE] >= 100)
                            seviyeAtla(ozellikler);


                    // Meyve toplama gerçekleþirse yarý þansla avlanma kontrolü
                    int sans3 = rand() % 100; // Rastgele þans deðeri (0-99 arasý)
                    double av_sans = (ozellikler[TOPLAYICILIK] * 4) / 100.0; // Yüzdelik oran hesaplama
                    int av_sans2 = (av_sans * 100)/2 ; // Ondalýk deðeri tam sayý yapmak için
                    if (sans3 < av_sans2) { //
                        printf("Ve sanslisiniz! Bir av hayvani avladiniz! +50 Tokluk\n");
                        ozellikler[TOKLUK] += 50;
                        ozellikler[UYKU]-=10;
                        ozellikler[ENERJI]+=10;
                        ozellikler[MORAL]+=3;
                        ozellikler[GUC]+=2;
                        ozellikler[DAYANIKLILIK]+=1;
                        ozellikler[CEVIKLIK]+=3;
                        ozellikler[TOPLAYICILIK]+=15;
                        ozellikler[KARIZMA]+=7;
                        ozellikler[TECRUBE]+=15;
                        if (ozellikler[TECRUBE] >= 100)
                            seviyeAtla(ozellikler);
                    }
                }
            } else {
                printf("hicbir sey bulamadiniz.\n");
            }
            break;
        }

        case 2:
            // Ormaný kesfe çýk (Kolay)
            printf("Ormanda kolay bir kesfe ciktiniz!\n");

            // Kolay kesif- Haydutla savaþ
            {
                int dusmanGuc = rand() % 3 + 1;
                int dusmanCeviklik = rand() % 3 + 1;
                int dusmanDayaniklilik = rand() % 3 + 1;
                printf("Haydut: Guc: %d, Ceviklik: %d, Dayaniklilik: %d\n", dusmanGuc, dusmanCeviklik, dusmanDayaniklilik);

                int kacisBasarisi = 4 * (ozellikler[CEVIKLIK] / 100.0); // Kaçma þansý
                int kacis = rand() % 100;

                printf("Kacma sansi: %d, sans: %d\n", kacisBasarisi * 100, kacis);

                if (kacis < kacisBasarisi * 100) {
                    printf("Basariyla kactiniz!\n");
                } else {
                    printf("Kacaamadiniz, savas basliyor...\n");

                    // Savaþ baþlýyor
                    int oyuncuGuc = ozellikler[GUC];
                    int oyuncuCeviklik = ozellikler[CEVIKLIK];
                    int oyuncuDayaniklilik = ozellikler[DAYANIKLILIK];

                    // Çevikliði büyük olan önce baþlar
                    int oyuncuIlkSaldiri = 0;
                    if (oyuncuCeviklik > dusmanCeviklik) {
                        oyuncuIlkSaldiri = 1;
                    } else if (oyuncuCeviklik == dusmanCeviklik) {
                        if (rand() % 2 == 0) {
                            oyuncuIlkSaldiri = 1;
                        }
                    }

                    // Savaþ
                    int oyuncuCan = ozellikler[CAN];
                    int dusmanCan = 100; // Baþlangýçta haydutun caný 100

                    while (oyuncuCan > 0 && dusmanCan > 0) {
                        if (oyuncuIlkSaldiri) {
                            // Ozan saldýrýyor
                            int oyuncuSaldiri = 4 * oyuncuGuc;
                            dusmanCan -= oyuncuSaldiri;
                            printf("Ozan saldirdi: %d hasar verdi\n", oyuncuSaldiri);

                            if (dusmanCan <= 0) {
                                break;
                            }

                            // Haydut savunuyor
                            int dusmanSavunma = 4 * dusmanDayaniklilik;
                            int alinanHasar = dusmanSavunma - (dusmanSavunma * (4 * oyuncuDayaniklilik / 100.0));
                            oyuncuCan -= alinanHasar;
                            printf("Haydut savundu, Ozan'a %d hasar verdi\n", alinanHasar);
                        } else {
                            // Haydut saldýrýyor
                            int dusmanSaldiri = 4 * dusmanGuc;
                            oyuncuCan -= dusmanSaldiri;
                            printf("Haydut saldirdi: %d hasar verdi\n", dusmanSaldiri);

                            if (oyuncuCan <= 0) {
                                break;
                            }

                            // Ozan savunuyor
                            int oyuncuSavunma = 4 * oyuncuDayaniklilik;
                            int alinanHasar = oyuncuSavunma - (oyuncuSavunma * (4 * dusmanDayaniklilik / 100.0));
                            dusmanCan -= alinanHasar;
                            printf("Ozan savundu, Haydut'a %d hasar verdi\n", alinanHasar);
                        }

                        // Çevikliði büyük olan bir sonraki saldýrýyý yapar
                        oyuncuIlkSaldiri = 1 - oyuncuIlkSaldiri;
                    }

                    if (oyuncuCan > 0) {
                        // Kazanýldý
                        printf("Kazandiniz!\n");
                        ozellikler[TECRUBE] += 30;
                        ozellikler[TOKLUK]-=10;
                        ozellikler[UYKU]-=10;
                        if (ozellikler[TECRUBE] >= 100)
                            seviyeAtla(ozellikler);
                        ozellikler[ALTIN] += (rand() % 11 + 15);
                        printf("Haydut ganimeti: %.2f altin kazandiniz!\n", ozellikler[ALTIN]);
                    } else {
                        printf("Kaybettiniz!\n");
                        ozellikler[CAN] = 0;
                        oyundanCik();
                    }
                }
            }
            break;

        case 3:
            // Kayalýklarý keþfe çýk (Orta)
            printf("Kayaliklarda orta zorlukta bir kesfe ciktiniz!\n");

            // Orta keþif - Haydutla savaþ
            {
                int dusmanGuc = rand() % 3 + 4;
                int dusmanCeviklik = rand() % 3 + 4;
                int dusmanDayaniklilik = rand() % 3 + 4;
                printf("Haydut: Guc: %d, Ceviklik: %d, Dayaniklilik: %d\n", dusmanGuc, dusmanCeviklik, dusmanDayaniklilik);

                int kacisBasarisi = 4 * (ozellikler[CEVIKLIK] / 100.0); // Kaçma þansý
                int kacis = rand() % 100;

                printf("Kacma sansi: %d, sans: %d\n", kacisBasarisi * 100, kacis);

                if (kacis < kacisBasarisi * 100) {
                    printf("Basariyla kactiniz!\n");
                } else {
                    printf("Kacamadiniz, savas basliyor...\n");

                    // Savaþ baþlýyor
                    int oyuncuGuc = ozellikler[GUC];
                    int oyuncuCeviklik = ozellikler[CEVIKLIK];
                    int oyuncuDayaniklilik = ozellikler[DAYANIKLILIK];

                    // Çevikliði büyük olan önce baþlar
                    int oyuncuIlkSaldiri = 0;
                    if (oyuncuCeviklik > dusmanCeviklik) {
                        oyuncuIlkSaldiri = 1;
                    } else if (oyuncuCeviklik == dusmanCeviklik) {
                        if (rand() % 2 == 0) {
                            oyuncuIlkSaldiri = 1;
                        }
                    }

                    // Savas
                    int oyuncuCan = ozellikler[CAN];
                    int dusmanCan = 100; // Baþlangýçta haydutun caný 100

                    while (oyuncuCan > 0 && dusmanCan > 0) {
                        if (oyuncuIlkSaldiri) {
                            // Ozan saldýrýyor
                            int oyuncuSaldiri = 4 * oyuncuGuc;
                            dusmanCan -= oyuncuSaldiri;
                            printf("Ozan saldirdi: %d hasar verdi\n", oyuncuSaldiri);

                            if (dusmanCan <= 0) {
                                break;
                            }

                            // Haydut savunuyor
                            int dusmanSavunma = 4 * dusmanDayaniklilik;
                            int alinanHasar = dusmanSavunma - (dusmanSavunma * (4 * oyuncuDayaniklilik / 100.0));
                            oyuncuCan -= alinanHasar;
                            printf("Haydut savundu, Ozan'a %d hasar verdi\n", alinanHasar);
                        } else {
                            // Haydut saldýrýyor
                            int dusmanSaldiri = 4 * dusmanGuc;
                            oyuncuCan -= dusmanSaldiri;
                            printf("Haydut saldirdi: %d hasar verdi\n", dusmanSaldiri);

                            if (oyuncuCan <= 0) {
                                break;
                            }

                            // Ozan savunuyor
                            int oyuncuSavunma = 4 * oyuncuDayaniklilik;
                            int alinanHasar = oyuncuSavunma - (oyuncuSavunma * (4 * dusmanDayaniklilik / 100.0));
                            dusmanCan -= alinanHasar;
                            printf("Ozan savundu, Haydut'a %d hasar verdi\n", alinanHasar);
                        }

                        // Çevikliði büyük olan bir sonraki saldýrýyý yapar
                        oyuncuIlkSaldiri = 1 - oyuncuIlkSaldiri;
                    }

                    if (oyuncuCan > 0) {
                        // Kazanýldý
                        printf("Kazandiniz!\n");
                        ozellikler[TECRUBE] += 60;
                        ozellikler[TOKLUK]-=20;
                        ozellikler[UYKU]-=20;
                        if (ozellikler[TECRUBE] >= 100)
                            seviyeAtla(ozellikler);
                        ozellikler[ALTIN] += (rand() % 21 + 30);  // 30-50 arasýnda rastgele altýn
                        printf("Haydut ganimeti: %.2f altin kazandiniz!\n", ozellikler[ALTIN]);
                    } else {
                        printf("Kaybettiniz!\n");
                        ozellikler[CAN] = 0;
                        oyundanCik();
                    }
                }
            }
            break;

        case 4:
            // Vadiyi keþfe çýk (Zor)
            printf("Vadiye zor bir kesfe ciktiniz!\n");

            // Zor keþif - Haydutla savaþ
            {
                int dusmanGuc = rand() % 4 + 7;
                int dusmanCeviklik = rand() % 4 + 7;
                int dusmanDayaniklilik = rand() % 4 + 7;
                printf("Haydut: Guc: %d, Ceviklik: %d, Dayaniklilik: %d\n", dusmanGuc, dusmanCeviklik, dusmanDayaniklilik);

                int kacisBasarisi = 4 * (ozellikler[CEVIKLIK] / 100.0); // Kaçma þansý
                int kacis = rand() % 100;

                printf("Kacma sansi: %d, sans: %d\n", kacisBasarisi * 100, kacis);

                if (kacis < kacisBasarisi * 100) {
                    printf("Basariyla kactiniz!\n");
                } else {
                    printf("Kacamadiniz, savas basliyor...\n");

                    // Savaþ baþlýyor
                    int oyuncuGuc = ozellikler[GUC];
                    int oyuncuCeviklik = ozellikler[CEVIKLIK];
                    int oyuncuDayaniklilik = ozellikler[DAYANIKLILIK];

                    // Çevikliði büyük olan önce baþlar
                    int oyuncuIlkSaldiri = 0;
                    if (oyuncuCeviklik > dusmanCeviklik) {
                        oyuncuIlkSaldiri = 1;
                    } else if (oyuncuCeviklik == dusmanCeviklik) {
                        if (rand() % 2 == 0) {
                            oyuncuIlkSaldiri = 1;
                        }
                    }

                    // Savaþ
                    int oyuncuCan = ozellikler[CAN];
                    int dusmanCan = 100; // Baþlangýçta haydutun caný 100

                    while (oyuncuCan > 0 && dusmanCan > 0) {
                        if (oyuncuIlkSaldiri) {
                            // Ozan saldýrýyor
                            int oyuncuSaldiri = 4 * oyuncuGuc;
                            dusmanCan -= oyuncuSaldiri;
                            printf("Ozan saldirdi: %d hasar verdi\n", oyuncuSaldiri);

                            if (dusmanCan <= 0) {
                                break;
                            }

                            // Haydut savunuyor
                            int dusmanSavunma = 4 * dusmanDayaniklilik;
                            int alinanHasar = dusmanSavunma - (dusmanSavunma * (4 * oyuncuDayaniklilik / 100.0));
                            oyuncuCan -= alinanHasar;
                            printf("Haydut savundu, Ozan'a %d hasar verdi\n", alinanHasar);
                        } else {
                            // Haydut saldýrýyor
                            int dusmanSaldiri = 4 * dusmanGuc;
                            oyuncuCan -= dusmanSaldiri;
                            printf("Haydut saldirdi: %d hasar verdi\n", dusmanSaldiri);

                            if (oyuncuCan <= 0) {
                                break;
                            }

                            // Ozan savunuyor
                            int oyuncuSavunma = 4 * oyuncuDayaniklilik;
                            int alinanHasar = oyuncuSavunma - (oyuncuSavunma * (4 * dusmanDayaniklilik / 100.0));
                            dusmanCan -= alinanHasar;
                            printf("Ozan savundu, Haydut'a %d hasar verdi\n", alinanHasar);
                        }

                        // Çevikliði büyük olan bir sonraki saldýrýyý yapar
                        oyuncuIlkSaldiri = 1 - oyuncuIlkSaldiri;
                    }

                    if (oyuncuCan > 0) {
                        // Kazanýldý
                        printf("Kazandiniz!\n");
                        ozellikler[TECRUBE] += 90;
                        ozellikler[TOKLUK]-=25;
                        ozellikler[UYKU]-=25;
                         if (ozellikler[TECRUBE] >= 100)
                            seviyeAtla(ozellikler);
                        ozellikler[ALTIN] += (rand() % 56 + 20);  // 55-75 arasýnda rastgele altýn
                        printf("Haydut ganimeti: %.2f altin kazandiniz!\n", ozellikler[ALTIN]);
                    } else {
                        printf("Kaybettiniz!\n");
                        ozellikler[CAN] = 0;
                        oyundanCik();
                    }
                }
            }
            break;

        case 5:
            printf("Koy meydanina donuyorsunuz..\n");
            break;

        default:
            printf("Gecersiz secenek, tekrar deneyin.\n");
            break;
    }
    }while(secim < 1 || secim >5);




    if(ozellikler[TOKLUK]>100)
        ozellikler[TOKLUK]=100;
    if(ozellikler[TOKLUK]<0)
        ozellikler[TOKLUK]=0;
    if(ozellikler[UYKU]>100)
        ozellikler[UYKU] =100;
    if(ozellikler[UYKU]<0)
        ozellikler[UYKU] = 0;
    if(ozellikler[SU] > 100)
        ozellikler[SU] = 100;
    if(ozellikler[SU] < 0)
        ozellikler[SU] = 0;
    if(ozellikler[HIJYEN] > 100)
        ozellikler[HIJYEN]= 100;
    if(ozellikler[HIJYEN] < 0)
        ozellikler[HIJYEN] = 0;
    if(ozellikler[ENERJI] > 100)
        ozellikler[ENERJI] = 100;
    if(ozellikler[ENERJI] < 0)
        ozellikler[ENERJI] = 0;
    if(ozellikler[CAN] > 100)
        ozellikler[CAN] = 100;
    if(ozellikler[CAN] < 0)
        ozellikler[CAN] = 0;


    if(ozellikler[MORAL] > 25)
        ozellikler[MORAL]= 25;
    if(ozellikler[MORAL] < 3)
        ozellikler[MORAL]= 3;
    if(ozellikler[GUC] > 25)
        ozellikler[GUC]= 25;
    if(ozellikler[GUC] < 3)
        ozellikler[GUC]= 3;

    if(ozellikler[CEVIKLIK] > 25)
        ozellikler[CEVIKLIK]= 25;
    if(ozellikler[CEVIKLIK] < 3)
        ozellikler[CEVIKLIK]= 3;

    if(ozellikler[DAYANIKLILIK] > 25)
        ozellikler[DAYANIKLILIK]= 25;
    if(ozellikler[DAYANIKLILIK] < 3)
        ozellikler[DAYANIKLILIK]= 3;

    if(ozellikler[KARIZMA] > 25)
        ozellikler[KARIZMA]= 25;
    if(ozellikler[KARIZMA] < 3)
        ozellikler[KARIZMA]= 3;


    if(ozellikler[TOPLAYICILIK] > 25)
        ozellikler[TOPLAYICILIK]= 25;
    if(ozellikler[TOPLAYICILIK] < 3)
        ozellikler[TOPLAYICILIK]= 3;


       printf("Karakterin Temel Niteliklerinin Guncel Durumu -> Can:%.2f ,Tokluk: %.2f, Uyku: %.2f, Hijyen: %.2f, Su: %.2f, Enerji: %.2f\n",ozellikler[CAN] , ozellikler[HIJYEN], ozellikler[UYKU], ozellikler[SU], ozellikler[ENERJI], ozellikler[MORAL]);
}


void seviyeAtla(float ozellikler[]) {
    if (ozellikler[TECRUBE] >= 100) {
        printf("Tebrikler! Seviye atladiniz.\n");
        ozellikler[SEVIYE]++;
        ozellikler[TECRUBE] = 0;

        int puan = 5;
        while (puan > 0) {
            printf("Beceri dagilimi icin kalan puan: %d\n", puan);
            printf("1. Guc\n2. Ceviklik\n3. Dayaniklilik\n4. Karizma\n5. Toplayicilik\n");
            printf("Bir secim yapin: ");
            int secim;
            scanf("%d", &secim);

            switch (secim) {
                case 1:
                    ozellikler[GUC]++;
                    break;
                case 2:
                    ozellikler[CEVIKLIK]++;
                    break;
                case 3:
                    ozellikler[DAYANIKLILIK]++;
                    break;
                case 4:
                    ozellikler[KARIZMA]++;
                    break;
                case 5:
                    ozellikler[TOPLAYICILIK]++;
                    break;
                default:
                    printf("Gecersiz secim! Lütfen 1-5 arasinda bir secim yapin.\n");
                    continue; // Hatalý giriþte döngüye devam et
            }
            puan--;  // Her geçerli seçim sonrasý puan azaltýlýr
        }
    } else {
        printf("Seviye atlamak icin yeterli tecrubeniz yok!\n");
    }


    }

void durumGoster(float ozellikler[]) {
    printf("\n******* OZANIN DURUMU ********\n");
    printf("Ad: %s\n", ad);
    printf("Calgi: %s\n", calgi);
    printf("Altin: %.2f\n", ozellikler[ALTIN]);
    printf("Seviye: %.2f\n", ozellikler[SEVIYE]);
    printf("Tecrube: %.2f\n", ozellikler[TECRUBE]);
    printf("Can: %.2f\n", ozellikler[CAN]);
    printf("Tokluk: %.2f\n", ozellikler[TOKLUK]);
    printf("Uyku: %.2f\n", ozellikler[UYKU]);
    printf("Hijyen: %.2f\n", ozellikler[HIJYEN]);
    printf("Su: %.2f\n", ozellikler[SU]);
    printf("Enerji: %.2f\n", ozellikler[ENERJI]);
    printf("Moral: %.2f\n", ozellikler[MORAL]);
    printf("Guc: %.2f\n", ozellikler[GUC]);
    printf("Ceviklik: %.2f\n", ozellikler[CEVIKLIK]);
    printf("Dayaniklilik: %.2f\n", ozellikler[DAYANIKLILIK]);
    printf("Karizma: %.2f\n", ozellikler[KARIZMA]);
    printf("Toplayicilik: %.2f\n", ozellikler[TOPLAYICILIK]);
}
void oyundanCik(){
    if(ozellikler[CAN]<=0){
        printf("Caniniz 0 a dustugu icin oyun sonlandi...\n");
        printf("Oyun kapatiliyor...\n");
        exit(0);
    }
    printf("Cikmak istediginizden emin misiniz?(1:Evet , 2:Hayir)\n)");
    int onay;
    scanf("%d",&onay);

    if(onay == 1){
        printf("Oyun kapatiliyor...\n");
        exit(0);
    }
    else{
        printf("Oyuna devam ediliyor...\n");
    }
}
