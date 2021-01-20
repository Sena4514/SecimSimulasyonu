#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 //il birinciligi
 int il_birincilikleri[6];

 //1. Fonksiyon
 void millet_vekili_hesaplama(double partiler_oy[6], int kontenjan, char il_ismi)
 {
     int a, b, parti_isimleri[6], temp2,  millet_vekili_sayisi[6], toplam_millet_vekili=0;
     double parti_oylari[6], temp, toplam_oy=0, oy_yuzdeleri[6], ortalama_oy;

     //Parti isimlerini atama
     for(a=0;a<6;a++){
        parti_isimleri[a] = a+1;
     }

     //ilde kullanilmis toplam oyun hesaplanmasi
     for(a=0;a<6;a++){
        toplam_oy = toplam_oy + partiler_oy[a];
     }

     //ildeki ortalama oyu hesaplam
     ortalama_oy = toplam_oy/6;

     //Oylarin buyukten kucuge siralnmasi
     for(a=0;a<6;a++){
        for(b=1;b<6-a;b++){
            if(partiler_oy[b] > partiler_oy[b-1]){
                temp = partiler_oy[b];
                partiler_oy[b] = partiler_oy[b-1];
                partiler_oy[b-1] = temp;

                temp2 = parti_isimleri[b];
                parti_isimleri[b] = parti_isimleri[b-1];
                parti_isimleri[b-1] = temp2;
            }
        }
     }

     //Oylarin siralanmiþs hallerini baska bir diziye aktarma
     for(a=0;a<6;a++){
        parti_oylari[a] = partiler_oy[a];
     }



     //Oylarin yuzdelik dilimmleinin hesaplanmasi
     for(a=0;a<6;a++){
        oy_yuzdeleri[a] = (parti_oylari[a]/toplam_oy)*100;
     }
     //Millet vekili sayisi hesaplama
     a=0;
     do{
        if(partiler_oy[a] > ortalama_oy){
            millet_vekili_sayisi[a]++;
            toplam_millet_vekili++;
        }
        a++;
     }while(toplam_millet_vekili < kontenjan);
     //

     printf("\n\n");
     printf("%c ili Secim Verileri --------\n\n", il_ismi);
     printf("%c ilindeki millet vekili kontenjani sayisi: %d\n\n", il_ismi, kontenjan);
     printf(" Parti isimi        Part Oylari       Oy Yuzdeleri      Millet Vekili Sayisi\n");
     printf("-------------      -------------     --------------    ----------------------\n");

     for(a=0;a<6;a++){
         printf(" Parti %d\t        %.0lf\t        %% %.2lf\t          %.0lf\n",parti_isimleri[a], parti_oylari[a],oy_yuzdeleri[a],millet_vekili_sayisi[a]);
     }

     printf("\nToplam kullanilmis gecerli oy sayisi: %.0lf",toplam_oy);


 }

 //2. Fonksiyon
 void partiler_genel_toplam_oy(double partiler_genel_oy[6], int genel_kontenjan)
 {
    int a, b;
    double toplam_oy2 = 0, oy_yuzdeleri[6];

    printf("\n\n");
    printf("Secim Genel Verileri --------\n\n");

    printf("Ulke geneli millet vekili kontenjani: %d\n\n",genel_kontenjan);

    //Secimde kullanilan toplam oyu hesaplama
    for(a=0;a<6;a++){
        toplam_oy2 = toplam_oy2 + partiler_genel_oy[a];
    }

    //Genel oy yuzdelerini hesaplama
    for(a=0;a<6;a++){
        oy_yuzdeleri[a] = (partiler_genel_oy[a]/toplam_oy2)*100;
    }

    printf(" Parti ismi        Oy Sayisi     Oy Yuzdesi       MV Sayisi      Mv Yuzdesi\n");
    printf("------------      -----------   ------------     -----------    ------------\n");

    for(a=0;a<6;a++){
        printf("Parti %d\t\t      %.0lf \t   %% %.2lf\t      %d\t\t %%\n",a+1,partiler_genel_oy[a],oy_yuzdeleri[a],0,0);
    }

    printf("\nUlke geneli kullanimis toplam gecerli oy sayisi: %.0lf\n\n",toplam_oy2);
    //printf("Partilerin il birincilikleri:\n\n");

 }

 //3. Fonksiyon
 void SiralamaVeBirincilikler(double toplam_oylar[6])
 {
     int a, b, parti_isimleri[6], temp2;
     double temp, oy_genel_toplam = 0, genel_oy_yuzdeleri[6];

     //Parti isimlerini atama
     for(a=0;a<6;a++){
        parti_isimleri[a] = a+1;
     }

     //Oylari Siralama
     for(a=0;a<6;a++){
        for(b=1;b<6-a;b++){
            if(toplam_oylar[b] > toplam_oylar[b-1]){
                temp = toplam_oylar[b];
                toplam_oylar[b] = toplam_oylar[b-1];
                toplam_oylar[b-1] = temp;

                temp2 = parti_isimleri[b];
                parti_isimleri[b] = parti_isimleri[b-1];
                parti_isimleri[b-1] = temp2;

            }
        }
     }

     //Genelde kullanilmis toplam oyu hesaplama
     for(a=0;a<6;a++){
        oy_genel_toplam = oy_genel_toplam + toplam_oylar[a];
     }

     //Oylarin yuzdelik dilimlerin hesaplama
     for(a=0;a<6;a++){
        genel_oy_yuzdeleri[a] = (toplam_oylar[a]/oy_genel_toplam)*100;
     }


     printf("\n\n");
     printf(" Siralama    Parti ismi       Toplam Oy Sayisi         Oy Yuzdesi\n");
     printf("----------  -----------      ------------------       ------------\n");

     for(a=0;a<6;a++){
        printf("  %d.\t      Parti %d\t\t   %.0lf\t\t\t%% %.3lf\n",a+1, parti_isimleri[a], toplam_oylar[a], genel_oy_yuzdeleri[a]);
     }

     printf("\niktidar parti %.0lf oy ile 'Parti %d' partisidir.\n\n",toplam_oylar[0],parti_isimleri[0]);
     printf("Anamuhalefet partisi %.0lf oy ile 'Parti %d' partisidir.",toplam_oylar[1],parti_isimleri[1]);

 }


int main()
{
    //5 farkli il
    //6 Farkli parti


    double A_ili[6], B_ili[6], C_ili[6], D_ili[6], E_ili[6], partilerin_toplam_oylari[6];
    int kontenjan[5], a, toplam_kontenjan = 0;
    char secim;

    printf("A ili -----\n\n");

    printf("A ili icin millet vekili kontenjanini girin: ");
    scanf("%d",&kontenjan[0]);
    printf("\n");

    for(a=0;a<6;a++){
        printf("Parti %d icin oy sayisi girin: ",a+1);
        scanf("%lf",&A_ili[a]);
    }
    printf("\n\n");

    printf("B ili -----\n\n");

    printf("B ili icin millet vekili kontenjanini girin: ");
    scanf("%d",&kontenjan[1]);
    printf("\n");

    for(a=0;a<6;a++){
        printf("Parti %d icin oy sayisi girin: ",a+1);
        scanf("%lf",&B_ili[a]);
    }
    printf("\n\n");

    printf("C ili -----\n\n");

    printf("C ili icin millet vekili kontenjanini girin: ");
    scanf("%d",&kontenjan[2]);
    printf("\n");

    for(a=0;a<6;a++){
        printf("Parti %d icin oy sayisi girin: ",a+1);
        scanf("%lf",&C_ili[a]);
    }
    printf("\n\n");

    printf("D ili -----\n\n");

    printf("D ili icin millet vekili kontenjanini girin: ");
    scanf("%d",&kontenjan[3]);
    printf("\n");

    for(a=0;a<6;a++){
        printf("Parti %d icin oy sayisi girin: ",a+1);
        scanf("%lf",&D_ili[a]);
    }
    printf("\n\n");

    printf("E ili -----\n\n");

    printf("E ili icin millet vekili kontenjanini girin: ");
    scanf("%d",&kontenjan[4]);
    printf("\n");

    for(a=0;a<6;a++){
        printf("Parti %d icin oy sayisi girin: ",a+1);
        scanf("%lf",&E_ili[a]);
    }
    printf("\n\n");


    //Ulke geneli toplam kontenjan hesaplama
    for(a=0;a<5;a++){
        toplam_kontenjan = toplam_kontenjan + kontenjan[a];
    }

    //Ulke geneli partilerin toplam oylarini hesaplama
    for(a=0;a<6;a++){
        partilerin_toplam_oylari[a] = A_ili[a] + B_ili[a] + C_ili[a] + D_ili[a] + E_ili[a];

    }


    do{
    printf("Verilerini gormek istedigniz ilin ismini girin.\n");
    printf("Genel veriler icin 'G' ye basin.\n");
    printf("Partilerin il birincilikleri ve oy siralamalari icin 'S' ye basin.\n");
    printf("Cikis icin 'F' ye basin.\n");
    printf("Seciminiz: ");
    scanf(" %c",&secim);

       switch(secim)
       {

         case 'A':
            {
              millet_vekili_hesaplama(A_ili,kontenjan[0],'A');
              printf("\n\n");
              break;
            }

          case 'B':
            {
              millet_vekili_hesaplama(B_ili,kontenjan[1],'B');
              printf("\n\n");
              break;
            }

          case 'C':
            {
              millet_vekili_hesaplama(C_ili,kontenjan[2],'C');
              printf("\n\n");
              break;
            }

          case 'D':
            {
              millet_vekili_hesaplama(D_ili,kontenjan[3],'D');
              printf("\n\n");
              break;
            }

          case 'E':
            {
              millet_vekili_hesaplama(E_ili,kontenjan[4],'E');
              printf("\n\n");
              break;
            }

          case 'G':
            {
               partiler_genel_toplam_oy(partilerin_toplam_oylari,toplam_kontenjan);
               printf("\n\n");
               break;
            }

          case 'S':
            {
                SiralamaVeBirincilikler(partilerin_toplam_oylari);
                printf("\n\n");
                break;
            }

          default:
            {
                if(secim != 'F'){
                printf("Lutfen gecerli bir karakter girin yada il ismini buyuk harfle girin.\n"); }
                printf("\n");
                break;
            }

       }

    }while(secim != 'F');

    printf("Sistemimizi kullandiginiz icin tesekkurler.\n\n");


    return 0;
}
