#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Ad: Haluk
  Soyadı: Bayatlı
  Ogrenci Numarasi: 23100011030
*/
int k_parola;
int parola=987654;
char *kullanici_adi="yonetici";
char *universite_adi="NECMETTIN ERBAKAN UNVIVERSITESI";

typedef struct akademik_calismasi
{
    char tez[50];
    char makale[50];
    char kitap[50];
} calisma;

typedef struct egitim_bilgisi
{
    char lisans_bilgisi[100];
    char yukseklisans_bilgisi[100];
    char doktora_bilgisi[100];
} egitim;

typedef struct akademisyen_bilgisi
{
    char ad_soyad[50];
    int akademik_id;
    char akademik_unvan[50];
    char akademik_gorevi[50];
    int gorev_derecesi;
    int gorev_suresi;
    int eb_sayisi;/*egitim bilgisi sayisi*/
    egitim *egitim_bilgileri;
    int cb_sayisi;/*calisma bilgisi sayisi*/
    calisma *calisma_bilgileri;
    int maas;
    int izin_sayisi;
} akademisyen;

akademisyen *akademisyenbilgisi;
int boyut;

void *bilgieklemesistemi();
void bilgilistelemesistemi();
void bilgiguncellemesistemi();
void bilgisilmesistemi();
void maassistemi();
void izinsistemi();

int main()
{
    int s;
    while(1)
    {
        printf("    -------------------------------------------------------------\n");
        printf("    | %s AKADEMIK PERSONAL SISTEMI |\n",universite_adi);
        printf("    -------------------------------------------------------------\n\n");
        printf("    -------------------------------------------------------------\n");
        printf("    AKADEMISYEN BILGILERI EKLEMEK ICIN                    ----->1\n");
        printf("    AKADEMISYEN BILGILERI LISTELEMEK ICIN                 ----->2\n");
        printf("    AKADEMISYEN BILGILERI GUNCELLEMEK ICIN                ----->3\n");
        printf("    AKADEMISYEN BILGILERI SILMEK ICIN                     ----->4\n");
        printf("    AKADEMISYEN MAAS ISLEMLERI ICIN                       ----->5\n");
        printf("    AKADEMISYEN IZIN ISLEMLERI ICIN                       ----->6\n");
        printf("    CIKMAK ICIN                                           ----->7\n");
        printf("    ------------------------------------------------------------- \n\n");
        printf("    ISLEM: ");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            bilgieklemesistemi();
            system("cls");
            break;
        case 2:
            bilgilistelemesistemi();
            system("cls");
            break;
        case 3:
            bilgiguncellemesistemi();
            system("cls");
            break;
        case 4:
            bilgisilmesistemi();
            system("cls");
            break;
        case 5:
            maassistemi();
            system("cls");
            break;
        case 6:
            izinsistemi();
            break;
        case 7:
            free(akademisyenbilgisi);
            exit(7);
        default:
            break;
        }
    }
    return 0;
}

void *bilgieklemesistemi()
{
    while(k_parola!=parola)
    {
        printf("    Parola: ");
        scanf("%d",&k_parola);
    }
    printf("\n");
    int secim;
    int i,j;
    printf("    -------------------------------\n");
    printf("    SIFIRDAN LISTE EKLEMEK ICIN ->1\n");
    printf("    ILAVE KISI EKLEMEK ICIN     ->2\n");
    printf("    ANA MENUYE DONMEK ICIN      ->3\n");
    printf("    -------------------------------\n");
    printf("    ISLEM SECIMI: ");
    scanf("%d",&secim);
    if(secim==1)
    {
        printf("    Boyut giriniz: ");
        scanf("%d",&boyut);
        getchar();
        akademisyenbilgisi=(akademisyen*)calloc(boyut,sizeof(akademisyen));

        for(i=0; i<boyut; i++)
        {
            printf("    AD SOYAD: ");
            gets((akademisyenbilgisi+i)->ad_soyad);
            printf("\n");

            printf("    AKADEMIK ID: ");
            scanf("%d",&(akademisyenbilgisi+i)->akademik_id);
            getchar();
            printf("\n");

            printf("    AKADEMIK UNVANI: ");
            gets((akademisyenbilgisi+i)->akademik_unvan);
            printf("\n");

            printf("    AKADEMIK GOREVI: ");
            gets((akademisyenbilgisi+i)->akademik_gorevi);
            printf("\n");

            printf("    GOREV DERECESI: ");
            scanf("%d",&(akademisyenbilgisi+i)->gorev_derecesi);
            getchar();
            printf("\n");

            printf("    GOREV SURESI: ");
            scanf("%d",&(akademisyenbilgisi+i)->gorev_suresi);
            getchar();
            printf("\n");

            (akademisyenbilgisi+i)->maas=10000;
            (akademisyenbilgisi+i)->izin_sayisi=60;

            printf("    EGITIM BILGISI SAYISI: ");
            scanf("%d",&(akademisyenbilgisi+i)->eb_sayisi);
            getchar();
            printf("\n");

            (akademisyenbilgisi+i)->egitim_bilgileri=(egitim*)calloc((akademisyenbilgisi+i)->eb_sayisi,sizeof(egitim));
            printf("    EGITIM BILGILERI:\n");
            for(j=0; j<(akademisyenbilgisi+i)->eb_sayisi; j++)
            {
                printf("        LISANS: ");
                gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->lisans_bilgisi);
                printf("\n");
                printf("        YUKSEK LISANS: ");
                gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->yukseklisans_bilgisi);
                printf("\n");
                printf("        DOKTORA: ");
                gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->doktora_bilgisi);
                printf("\n");
            }

            printf("    CALISMA BILGISI SAYISI: ");
            scanf("%d",&(akademisyenbilgisi+i)->cb_sayisi);
            getchar();
            printf("\n");

            (akademisyenbilgisi+i)->calisma_bilgileri=(calisma*)calloc((akademisyenbilgisi+i)->cb_sayisi,sizeof(calisma));
            printf("    CALISMA BILGILERI\n");
            for(j=0; j<(akademisyenbilgisi+i)->cb_sayisi; j++)
            {

                printf("        TEZ: ");
                gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->tez);
                printf("\n");
                printf("        MAKALE: ");
                gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->makale);
                printf("\n");
                printf("        KITAP: ");
                gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->kitap);
                printf("\n");
            }
        }
        return akademisyenbilgisi;
    }
    else if(secim==2)
    {
        int ekboyut;
        printf("   Yeniden boyut giriniz: ");
        scanf("%d",&ekboyut);
        getchar();
        akademisyenbilgisi=(akademisyen*)realloc(akademisyenbilgisi,ekboyut*sizeof(akademisyen));

        for(i=boyut-1; i<ekboyut; i++)
        {
            printf("    AD SOYAD: ");
            gets((akademisyenbilgisi+i)->ad_soyad);
            printf("\n");

            printf("    AKADEMIK ID: ");
            scanf("%d",&(akademisyenbilgisi+i)->akademik_id);
            getchar();
            printf("\n");

            printf("    AKADEMIK UNVANI: ");
            gets((akademisyenbilgisi+i)->akademik_unvan);
            printf("\n");

            printf("    AKADEMIK GOREVI: ");
            gets((akademisyenbilgisi+i)->akademik_gorevi);
            printf("\n");

            printf("    GOREV DERECESI: ");
            scanf("%d",&(akademisyenbilgisi+i)->gorev_derecesi);
            getchar();
            printf("\n");

            printf("    GOREV SURESI: ");
            scanf("%d",&(akademisyenbilgisi+i)->gorev_suresi);
            getchar();
            printf("\n");

            (akademisyenbilgisi+i)->maas=10000;
            (akademisyenbilgisi+i)->izin_sayisi=60;

            printf("    EGITIM BILGISI SAYISI: ");
            scanf("%d",&(akademisyenbilgisi+i)->eb_sayisi);
            getchar();
            printf("\n");

            (akademisyenbilgisi+i)->egitim_bilgileri=(egitim*)calloc((akademisyenbilgisi+i)->eb_sayisi,sizeof(egitim));
            printf("    EGITIM BILGILERI:\n");
            for(j=0; j<(akademisyenbilgisi+i)->eb_sayisi; j++)
            {
                printf("        LISANS: ");
                gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->lisans_bilgisi);
                printf("\n");
                printf("        YUKSEK LISANS: ");
                gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->yukseklisans_bilgisi);
                printf("\n");
                printf("        DOKTORA: ");
                gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->doktora_bilgisi);
                printf("\n");
            }

            printf("    CALISMA BILGISI SAYISI: ");
            scanf("%d",&(akademisyenbilgisi+i)->cb_sayisi);
            getchar();
            printf("\n");

            (akademisyenbilgisi+i)->calisma_bilgileri=(calisma*)calloc((akademisyenbilgisi+i)->cb_sayisi,sizeof(calisma));
            printf("    CALISMA BILGILERI\n");
            for(j=0; j<(akademisyenbilgisi+i)->cb_sayisi; j++)
            {

                printf("        TEZ: ");
                gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->tez);
                printf("\n");
                printf("        MAKALE: ");
                gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->makale);
                printf("\n");
                printf("        KITAP: ");
                gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->kitap);
                printf("\n");
            }
        }
        boyut=ekboyut;
        return akademisyenbilgisi;
    }
}

void bilgilistelemesistemi()
{
    int islem;
    int i,j;

listelemesekmesi:
    printf("    --------------------------------------------- \n");
    printf("    AKADEMISYENLERI LISTELEMEK                ->1\n");
    printf("    AKADEMISYENLERIN CALISMALARINI LISTELEMEK ->2\n");
    printf("    AKADEMISYENLERIN MAASINI LISTELEMEK       ->3\n");
    printf("    AKADEMISYENLERIN IZIN SAYISINI LISTELEMEK ->4\n");
    printf("    ANA MENU ICIN                             ->5\n");
    printf("    --------------------------------------------- \n\n");
    printf("    ISLEM SECIMI: ");
    scanf("%d",&islem);
    printf("\n");
    if(islem==1)
    {
        printf("    --------------------------------------------------------------------------------------------------------------------------------\n");
        printf("    | AD SOYAD            | AKADEMIK ID | AKADEMIK UNVAN    | AKADEMIK GOREVI    | LISANS | YUKSEK LISANS | DOKTORA |\n");
        printf("    --------------------------------------------------------------------------------------------------------------------------------\n");
        for (i=0; i<boyut; i++)
        {
            printf("    | %-20s | %-11d | %-17s | %-18s |",
                   (akademisyenbilgisi+i)->ad_soyad,
                   (akademisyenbilgisi+i)->akademik_id,
                   (akademisyenbilgisi+i)->akademik_unvan,
                   (akademisyenbilgisi+i)->akademik_gorevi);
            for (j=0; j<(akademisyenbilgisi+i)->eb_sayisi; j++)
            {
                printf("     %-6s | %-13s | %-7s |",
                       ((akademisyenbilgisi+i)->egitim_bilgileri+j)->lisans_bilgisi,
                       ((akademisyenbilgisi+i)->egitim_bilgileri+j)->yukseklisans_bilgisi,
                       ((akademisyenbilgisi+i)->egitim_bilgileri+j)->doktora_bilgisi);
            }
            printf("\n    --------------------------------------------------------------------------------------------------------------------------------\n");
        }
        printf("    ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                system("cls");
                goto listelemesekmesi;
                break;
            case '2':
                system("cls");
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(3);
                break;
            default:
                break;
            }
        }
    }
    else if(islem==2)
    {
        printf("    ----------------------------------------------------------------------------------------\n");
        printf("    | AD SOYAD            | AKADEMIK ID | AKADEMIK UNVAN    | TEZ | MAKALE | KITAP |\n");
        printf("    ----------------------------------------------------------------------------------------\n");
        for (i=0; i<boyut; i++)
        {
            printf("    | %-20s | %-11d | %-17s |",
                   (akademisyenbilgisi+i)->ad_soyad,
                   (akademisyenbilgisi+i)->akademik_id,
                   (akademisyenbilgisi+i)->akademik_unvan);
            for (j=0; j<(akademisyenbilgisi+i)->cb_sayisi; j++)
            {
                printf("     %-3s | %-5s | %-4s |",
                       ((akademisyenbilgisi+i)->calisma_bilgileri+j)->tez,
                       ((akademisyenbilgisi+i)->calisma_bilgileri+j)->makale,
                       ((akademisyenbilgisi+i)->calisma_bilgileri+j)->kitap);
            }
            printf("\n    ----------------------------------------------------------------------------------------\n");
        }
        printf("    ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                system("cls");
                goto listelemesekmesi;
                break;
            case '2':
                system("cls");
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(3);
                break;
            default:
                break;
            }
        }
    }
    else if(islem==3)
    {
        while(k_parola!=parola)
        {
            printf("    Parola: ");
            scanf("%d",&k_parola);
        }
        printf("\n");
        printf("    ---------------------------------------------------------------------\n");
        printf("    | AD SOYAD            | AKADEMIK ID | AKADEMIK UNVAN    | MAAS |\n");
        printf("    ---------------------------------------------------------------------\n");
        for (i=0; i<boyut; i++)
        {
            printf("    | %-20s | %-11d | %-17s | %-4d |\n",
                   (akademisyenbilgisi + i)->ad_soyad,
                   (akademisyenbilgisi + i)->akademik_id,
                   (akademisyenbilgisi + i)->akademik_unvan,
                   (akademisyenbilgisi + i)->maas);
            printf("    ---------------------------------------------------------------------\n");
        }
        printf("    ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                system("cls");
                goto listelemesekmesi;
                break;
            case '2':
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(3);
                break;
            default:
                break;
            }
        }
    }
    else if(islem==4)
    {
        while(k_parola!=parola)
        {
            printf("    Parola: ");
            scanf("%d",&k_parola);
        }
        printf("\n");
        printf("    --------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (i = 0; i < boyut; i++)
        {
            printf("    | %s | %d | %d |\n",
                   (akademisyenbilgisi + i)->ad_soyad,
                   (akademisyenbilgisi + i)->akademik_id,
                   (akademisyenbilgisi + i)->izin_sayisi);
            printf("    --------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        }
        printf("    ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                system("cls");
                goto listelemesekmesi;
                break;
            case '2':
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(3);
                break;
            default:
                break;
            }
        }
    }
    else if(islem==5)
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
        goto listelemesekmesi;
    }
}

void bilgiguncellemesistemi()
{
    int islem,egitimislem,calismaislem;
    int i,j;
    while(k_parola!=parola)
    {
        printf("    Parola: ");
        scanf("%d",&k_parola);
    }
    printf("\n\n");
    printf("    -------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("    |SIRA| AD SOYAD            | AKADEMIK ID | AKADEMIK UNVAN    | AKADEMIK GOREVI    | LISANS | YUKSEK LISANS | DOKTORA | TEZ | MAKALE | KITAP |\n");
    printf("    -------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (i=0; i<boyut; i++)
    {
        printf("    %d | %-20s | %-11d | %-17s | %-18s |",
               (i+1),
               (akademisyenbilgisi+i)->ad_soyad,
               (akademisyenbilgisi+i)->akademik_id,
               (akademisyenbilgisi+i)->akademik_unvan,
               (akademisyenbilgisi+i)->akademik_gorevi);

        for (j=0; j<(akademisyenbilgisi+i)->eb_sayisi; j++)
        {
            printf("     %-6s | %-13s | %-7s |",
                   ((akademisyenbilgisi+i)->egitim_bilgileri+j)->lisans_bilgisi,
                   ((akademisyenbilgisi+i)->egitim_bilgileri+j)->yukseklisans_bilgisi,
                   ((akademisyenbilgisi+i)->egitim_bilgileri+j)->doktora_bilgisi);
        }
        for (j=0; j<(akademisyenbilgisi+i)->cb_sayisi; j++)
        {
            printf("     %-3s | %-5s | %-4s |",
                   ((akademisyenbilgisi+i)->calisma_bilgileri+j)->tez,
                   ((akademisyenbilgisi+i)->calisma_bilgileri+j)->makale,
                   ((akademisyenbilgisi+i)->calisma_bilgileri+j)->kitap);
        }
        printf("\n    ------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
guncellemesekmesi:
    printf("    ---------------------------- \n");
    printf("    AD SOYAD DEGISIKLIGI ICIN ->1\n");
    printf("    AKADEMIK UNVAN ICIN       ->2\n");
    printf("    AKADEMIK POZISYONU ICIN   ->3\n");
    printf("    EGITIM BILGILERI ICIN     ->4\n");
    printf("    CALISMA BILGILERI ICIN    ->5\n");
    printf("    CIKMAK ICIN               ->6\n");
    printf("    ---------------------------- \n\n");
    printf("    ISLEM SECIMI: ");
    scanf("%d",&islem);
    getchar();
    printf("\n");
    if(islem==1)
    {
        printf("    KACINCI SATIRDAKI KISININ ADI VE SOYADI DEGISECEK: ");
        scanf("%d",&i);
        getchar();
        i-=1;
        printf("\n");
        printf("    AD SOYAD: ");
        gets((akademisyenbilgisi+i)->ad_soyad);
        printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
        printf("    ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                goto guncellemesekmesi;
                system("cls");
                break;
            case '2':
                system("cls");
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(4);
                break;
            default:
                break;
            }
        }
    }
    else if(islem==2)
    {

        printf("    KACINCI SATIRDAKI KISININ AKADEMIK UNVANI DEGISECEK: ");
        scanf("%d",&i);
        getchar();
        i-=1;
        printf("\n");
        printf("    AKADEMIK UNVAN: ");
        gets((akademisyenbilgisi+i)->akademik_unvan);
        printf("\n  ISLEM BASARI ILE TAMAMLANDI...");
        printf("\n  ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        printf("");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                system("cls");
                goto guncellemesekmesi;
                break;
            case '2':
                system("cls");
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(3);
                break;
            default:
                break;
            }
        }
    }
    else if(islem==3)
    {
        printf("    KACINCI SATIRDAKI KISININ AKADEMIK POZISYONU DEGISECEK: ");
        scanf("%d",&i);
        getchar();
        i-=1;
        printf("\n");
        printf("    AKADEMIK GOREVI: ");
        gets((akademisyenbilgisi+i)->akademik_gorevi);
        printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
        printf("    ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                system("cls");
                goto guncellemesekmesi;
                break;
            case '2':
                system("cls");
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(3);
                break;
            default:
                break;
            }
        }
    }
    else if(islem==4)
    {
egitimsekmesi:
        printf("    ---------------------- \n");
        printf("    LISANS ICIN        ->1\n");
        printf("    YUKSEK LISANS ICIN ->2\n");
        printf("    DOKTORA ICIN       ->3\n");
        printf("    ---------------------- \n\n");
        printf("    HANGI EGITIM TURU KATEGORISI DEGISECEK: ");
        scanf("%d",&egitimislem);
        getchar();
        printf("\n");
        if(egitimislem==1)
        {
            printf("    LISANS DEGISTIRME ISLEMI:\n");
            printf("    KACINCI SATIR VE SUTUNDAKI KISININ LISANS EGITMI DEGISECEK: ");
            scanf("%d %d",&i,&j);
            getchar();
            i-=1;
            j-=1;
            printf("    LISANS: ");
            gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->lisans_bilgisi);
            printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
            printf("    -------------------------------- \n");
            printf("    BIR UST ISLEME DONMEK ICIN     ->1\n");
            printf("    BIR UST MENUYE DONMEK ICIN     ->2\n");
            printf("    ANA MENUYE DONMEK ICIN         ->3\n");
            printf("    CIKMAK ICIN                    ->4\n");
            printf("    ---------------------------------- \n\n");
            while(1)
            {
                printf("");
                switch(getch())
                {
                case '1':
                    system("cls");
                    goto egitimsekmesi;
                    break;
                case '2':
                    system("cls");
                    goto guncellemesekmesi;
                    break;
                case '3':
                    system("cls");
                    main();
                    break;
                case '4':
                    free(akademisyenbilgisi);
                    exit(4);
                    break;
                default:
                    break;
                }
            }
        }
        else if(egitimislem==2)
        {
            printf("    YUKSEK LISANS DEGISTIRME ISLEMI:\n");
            printf("    KACINCI SATIR VE SUTUNDAKI KISININ YUKSEK LISANS EGITMI DEGISECEK: ");
            scanf("%d %d",&i,&j);
            getchar();
            i-=1;
            j-=1;
            printf("    YUKSEK LISANS: ");
            gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->yukseklisans_bilgisi);
            printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
            printf("    -------------------------------- \n");
            printf("    BIR UST ISLEME DONMEK ICIN     ->1\n");
            printf("    BIR UST MENUYE DONMEK ICIN     ->2\n");
            printf("    ANA MENUYE DONMEK ICIN         ->3\n");
            printf("    CIKMAK ICIN                    ->4\n");
            printf("    ---------------------------------- \n\n");
            while(1)
            {
                printf("");
                switch(getch())
                {
                case '1':
                    system("cls");
                    goto egitimsekmesi;
                case '2':
                    system("cls");
                    goto guncellemesekmesi;
                case '3':
                    system("cls");
                    main();
                case '4':
                    free(akademisyenbilgisi);
                    exit(4);
                }
            }
        }
        else if(egitimislem==3)
        {
            printf("    DOKTORA DEGISTIRME ISLEMI:\n");
            printf("    KACINCI SATIR VE SUTUNDAKI KISININ DOKTORA EGITMI DEGISECEK: ");
            scanf("%d %d",&i,&j);
            getchar();
            i-=1;
            j-=1;
            printf("    DOKTORA: ");
            gets(((akademisyenbilgisi+i)->egitim_bilgileri+j)->doktora_bilgisi);
            printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
            printf("    -------------------------------- \n");
            printf("    BIR UST ISLEME DONMEK ICIN     ->1\n");
            printf("    BIR UST MENUYE DONMEK ICIN     ->2\n");
            printf("    ANA MENUYE DONMEK ICIN         ->3\n");
            printf("    CIKMAK ICIN                    ->4\n");
            printf("    ---------------------------------- \n\n");
            while(1)
            {
                printf("");
                switch(getch())
                {
                case '1':
                    system("cls");
                    goto egitimsekmesi;
                    break;
                case '2':
                    system("cls");
                    goto guncellemesekmesi;
                    break;
                case '3':
                    system("cls");
                    main();
                    break;
                case '4':
                    free(akademisyenbilgisi);
                    exit(4);
                    break;
                default:
                    break;
                }
            }
        }
    }
    else if(islem==5)
    {
calismasekmesi:
        printf("    ------------------ \n");
        printf("    TEZ ICIN       ->1\n");
        printf("    MAKALE ICIN    ->2\n");
        printf("    KITAP ICIN     ->3\n");
        printf("    ------------------ \n\n");
        printf("    HANGI CALISMA TURU KATEGORISI DEGISECEK: ");
        scanf("%d",&calismaislem);
        getchar();
        printf("\n");
        if(calismaislem==1)
        {
            printf("    TEZ DEGISTIRME ISLEMI:\n");
            printf("    KACINCI SATIR VE SUTUNDAKI KISININ TEZ CALISMASI DEGISECEK: ");
            scanf("%d %d",&i,&j);
            getchar();
            i-=1;
            j-=1;
            printf("    TEZ: ");
            gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->tez);
            printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n ");
            printf("    -------------------------------- \n");
            printf("    BIR UST ISLEME DONMEK ICIN     ->1\n");
            printf("    BIR UST MENUYE DONMEK ICIN     ->2\n");
            printf("    ANA MENUYE DONMEK ICIN         ->3\n");
            printf("    CIKMAK ICIN                    ->4\n");
            printf("    ---------------------------------- \n\n");
            while(1)
            {
                printf("");
                switch(getch())
                {
                case '1':
                    system("cls");
                    goto calismasekmesi;
                    break;
                case '2':
                    system("cls");
                    goto guncellemesekmesi;
                    break;
                case '3':
                    system("cls");
                    main();
                    break;
                case '4':
                    free(akademisyenbilgisi);
                    exit(4);
                    break;
                }
            }
        }
        else if(calismaislem==2)
        {
            printf("    MAKALE DEGISTIRME ISLEMI:\n");

            printf("    KACINCI SATIR VE SUTUNDAKI KISININ MAKALE CALISMASI DEGISECEK: ");
            scanf("%d %d",&i,&j);
            getchar();
            i-=1;
            j-=1;
            printf("    MAKALE: ");
            gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->makale);
            printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
            printf("    -------------------------------- \n");
            printf("    BIR UST ISLEME DONMEK ICIN     ->1\n");
            printf("    BIR UST MENUYE DONMEK ICIN     ->2\n");
            printf("    ANA MENUYE DONMEK ICIN         ->3\n");
            printf("    CIKMAK ICIN                    ->4\n");
            printf("    ---------------------------------- \n\n");
            while(1)
            {
                printf("");
                switch(getch())
                {
                case '1':
                    system("cls");
                    goto calismasekmesi;
                    break;
                case '2':
                    system("cls");
                    goto guncellemesekmesi;
                    break;
                case '3':
                    system("cls");
                    main();
                    break;
                case '4':
                    free(akademisyenbilgisi);
                    exit(4);
                    break;
                default:
                    break;
                }
            }
        }
        else if(calismaislem==3)
        {
            printf("    KITAP DEGISTIRME ISLEMI:\n");
            printf("    KACINCI SATIR VE SUTUNDAKI KISININ KITAP CALISMASI DEGISECEK: ");
            scanf("%d %d",&i,&j);
            getchar();
            i-=1;
            j-=1;
            printf("    KITAP: ");
            gets(((akademisyenbilgisi+i)->calisma_bilgileri+j)->kitap);
            printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
            printf("    -------------------------------- \n");
            printf("    BIR UST ISLEME DONMEK ICIN     ->1\n");
            printf("    BIR UST MENUYE DONMEK ICIN     ->2\n");
            printf("    ANA MENUYE DONMEK ICIN         ->3\n");
            printf("    CIKMAK ICIN                    ->4\n");
            printf("    ---------------------------------- \n\n");
            while(1)
            {
                printf("");
                switch(getch())
                {
                case '1':
                    system("cls");
                    goto calismasekmesi;
                    break;
                case '2':
                    system("cls");
                    goto guncellemesekmesi;
                    break;
                case '3':
                    system("cls");
                    main();
                    break;
                case '4':
                    free(akademisyenbilgisi);
                    exit(4);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void bilgisilmesistemi()
{
    int secim,silmesecim,i,j;
    while(k_parola!=parola)
    {
        printf("Parola: ");
        scanf("%d",&k_parola);
    }
    printf("\n\n");
    printf("    -------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("    |SIRA| AD SOYAD            | AKADEMIK ID | AKADEMIK UNVAN    | AKADEMIK GOREVI    | LISANS | YUKSEK LISANS | DOKTORA | TEZ | MAKALE | KITAP |\n");
    printf("    -------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (i=0; i<boyut; i++)
    {
        printf("    %d | %-20s | %-11d | %-17s | %-18s |",
               (i+1),
               (akademisyenbilgisi+i)->ad_soyad,
               (akademisyenbilgisi+i)->akademik_id,
               (akademisyenbilgisi+i)->akademik_unvan,
               (akademisyenbilgisi+i)->akademik_gorevi);

        for (j=0; j<(akademisyenbilgisi+i)->eb_sayisi; j++)
        {
            printf("     %-6s | %-13s | %-7s |",
                   ((akademisyenbilgisi+i)->egitim_bilgileri+j)->lisans_bilgisi,
                   ((akademisyenbilgisi+i)->egitim_bilgileri+j)->yukseklisans_bilgisi,
                   ((akademisyenbilgisi+i)->egitim_bilgileri+j)->doktora_bilgisi);
        }
        for (j=0; j<(akademisyenbilgisi+i)->cb_sayisi; j++)
        {
            printf("     %-3s | %-5s | %-4s |",
                   ((akademisyenbilgisi+i)->calisma_bilgileri+j)->tez,
                   ((akademisyenbilgisi+i)->calisma_bilgileri+j)->makale,
                   ((akademisyenbilgisi+i)->calisma_bilgileri+j)->kitap);
        }
        printf("\n    ------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
silmesekmesi:
    printf("    -------------------------------- \n");
    printf("    BELLI BIR VERIYI SILMEK      ->1\n");
    printf("    VERILERI TAMAMEN SILMEK ICIN ->2\n");
    printf("    -------------------------------- \n\n");
    printf("    ISLEM SECIMI: ");
    scanf("%d",&secim);
    getchar();
    if(secim==1)
    {
        printf("    KACINCI SIRADAKI VE SUTUNDAKI KISIYI SILMEK ISTIYORSUNUZ: ");
        scanf("%d",&i);
        getchar();
        i-=1;
        strcpy((akademisyenbilgisi+i)->ad_soyad," -- ");
        (akademisyenbilgisi+i)->akademik_id=0;
        strcpy((akademisyenbilgisi+i)->akademik_unvan," -- ");
        strcpy((akademisyenbilgisi+i)->akademik_gorevi," -- ");
        (akademisyenbilgisi+i)->maas=0;
        (akademisyenbilgisi+i)->izin_sayisi=0;
        for(j=0; j<(akademisyenbilgisi+i)->eb_sayisi; j++)
        {
            strcpy(((akademisyenbilgisi+i)->egitim_bilgileri+j)->lisans_bilgisi," -- ");
            strcpy(((akademisyenbilgisi+i)->egitim_bilgileri+j)->yukseklisans_bilgisi," -- ");
            strcpy(((akademisyenbilgisi+i)->egitim_bilgileri+j)->doktora_bilgisi," -- ");
        }
        for(j=0; j<(akademisyenbilgisi+i)->cb_sayisi; j++)
        {
            strcpy(((akademisyenbilgisi+i)->calisma_bilgileri+j)->tez," -- ");
            strcpy(((akademisyenbilgisi+i)->calisma_bilgileri+j)->makale," -- ");
            strcpy(((akademisyenbilgisi+i)->calisma_bilgileri+j)->kitap," -- ");
        }
        printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
        printf("    ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                system("cls");
                goto silmesekmesi;
                break;
            case '2':
                system("cls");
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(3);
                break;
            default:
                break;
            }
        }
    }
    else if(secim==2)
    {
        for(i=0; i<boyut; i++)
        {
            strcpy((akademisyenbilgisi+i)->ad_soyad," -- ");
            (akademisyenbilgisi+i)->akademik_id=0;
            strcpy((akademisyenbilgisi+i)->akademik_unvan," -- ");
            strcpy((akademisyenbilgisi+i)->akademik_gorevi," -- ");
            (akademisyenbilgisi+i)->maas=0;
            (akademisyenbilgisi+i)->izin_sayisi=0;
            for(j=0; j<(akademisyenbilgisi+i)->eb_sayisi; j++)
            {
                strcpy(((akademisyenbilgisi+i)->egitim_bilgileri+j)->lisans_bilgisi," -- ");
                strcpy(((akademisyenbilgisi+i)->egitim_bilgileri+j)->yukseklisans_bilgisi," -- ");
                strcpy(((akademisyenbilgisi+i)->egitim_bilgileri+j)->doktora_bilgisi," -- ");
            }
            for(j=0; j<(akademisyenbilgisi+i)->cb_sayisi; j++)
            {
                strcpy(((akademisyenbilgisi+i)->calisma_bilgileri+j)->tez," -- ");
                strcpy(((akademisyenbilgisi+i)->calisma_bilgileri+j)->makale," -- ");
                strcpy(((akademisyenbilgisi+i)->calisma_bilgileri+j)->kitap," -- ");
            }
        }
        printf("\n  ISLEM BASARI ILE TAMAMLANDI...\n");
        printf("    ------------------------------ \n");
        printf("    BIR UST MENUYE DONMEK ICIN ->1\n");
        printf("    ANA MENUYE DONMEK ICIN     ->2\n");
        printf("    CIKMAK ICIN                ->3\n");
        printf("    ------------------------------ \n\n");
        while(1)
        {
            printf("");
            switch(getch())
            {
            case '1':
                goto silmesekmesi;
                break;
            case '2':
                system("cls");
                main();
                break;
            case '3':
                free(akademisyenbilgisi);
                exit(3);
                break;
            default:
                break;
            }
        }
    }
}

void maassistemi()
{
    int i;
    double derecekatsayi=1.5,surekatsayi=1.2;
    int maasmiktari=0;
    for(i=0; i<boyut; i++)
    {
        if((akademisyenbilgisi+i)->gorev_derecesi==4)
        {
            maasmiktari=(int)5000*derecekatsayi*(akademisyenbilgisi+i)->gorev_derecesi;
            (akademisyenbilgisi+i)->maas+=maasmiktari;
        }
        else if((akademisyenbilgisi+i)->gorev_derecesi==3)
        {
            maasmiktari=(int)5000*derecekatsayi*(akademisyenbilgisi+i)->gorev_derecesi;
            (akademisyenbilgisi+i)->maas+=maasmiktari;
        }
        else if((akademisyenbilgisi+i)->gorev_derecesi==2)
        {
            maasmiktari=(int)5000*derecekatsayi*(akademisyenbilgisi+i)->gorev_derecesi;
            (akademisyenbilgisi+i)->maas+=maasmiktari;
        }
        else if((akademisyenbilgisi+i)->gorev_derecesi==1)
        {
            maasmiktari=(int)5000*derecekatsayi*(akademisyenbilgisi+i)->gorev_derecesi;
            (akademisyenbilgisi+i)->maas+=maasmiktari;
        }

        if((akademisyenbilgisi+i)->gorev_suresi<=10)
        {
            maasmiktari=(int)2000*surekatsayi*(akademisyenbilgisi+i)->gorev_suresi;
            (akademisyenbilgisi+i)->maas+=maasmiktari;
        }
        else if((akademisyenbilgisi+i)->gorev_suresi<=20)
        {
            maasmiktari=(int)2000*surekatsayi*(akademisyenbilgisi+i)->gorev_suresi;
            (akademisyenbilgisi+i)->maas+=maasmiktari;
        }
        else if((akademisyenbilgisi+i)->gorev_suresi<=30)
        {
            maasmiktari=(int)2000*surekatsayi*(akademisyenbilgisi+i)->gorev_suresi;
            (akademisyenbilgisi+i)->maas+=maasmiktari;
        }
        else
        {
            maasmiktari=(int)2000*surekatsayi*(akademisyenbilgisi+i)->gorev_suresi;
            (akademisyenbilgisi+i)->maas+=maasmiktari;
        }
    }
}

void izinsistemi()
{
    char c/*cevap*/;
    int i,nyil,gorev_izni;
izinsekmesi:
    for(i=0; i<boyut; i++)
    {
        printf("    PERSONAL GERIYE DONUK YILLIK IZIN KULLANDI MI?(E/H): ");
        gets(c);
        if(c=='H')
        {
            printf("    KULLANMADIGI IZIN YIL SAYISI: ");
            scanf("%d",&nyil);
            if(nyil>5)
            {
                nyil=1;
            }
            (akademisyenbilgisi+i)->izin_sayisi+=(akademisyenbilgisi+i)->izin_sayisi*0.5*nyil;
        }
        printf("    PERSONAL GOREV ÝZNÝNE BAGLI BÝR DURUM VAR MI?(E/H): ");
        gets(c);
        if(c=='E')
        {
            printf("    GOREV IZNI SURESI: ");
            scanf("%d",&gorev_izni);
            (akademisyenbilgisi+i)->izin_sayisi+=gorev_izni;
        }
        printf(" ------------------------------\n");
        printf(" BIR UST ISLEME DONMEK ICIN ->1\n");
        printf(" ANA MENUYE DONMEK ICIN     ->2\n");
        printf(" CIKMAK ICIN                ->3\n");
        printf(" ------------------------------\n");
        while(1)
        {
            printf("");
            switch(getchar())
            {
            case '1':
                system("cls");
                goto izinsekmesi;
                break;
            case '2':
                system("cls");
                main();
                break;
            case '3':
                system("cls");
                exit(3);
                free(akademisyenbilgisi);
                break;
            }
        }
    }
}
