#include "login.h"

void bank_main_menu()
{
    printf("********************************************\n* Lutfen yapmak istediginiz islemi giriniz *\n*                                          *\n*  [1] Musteri Yonetimi                    *\n*                                          *\n*  [2] Hesap Islemleri                     *\n*                                          *\n*  [3] Hareket Gecmisi                     *\n*                                          *\n*  [4] Cikis                               *\n********************************************\n");
}
void customer_management_menu()
{
    printf("********************************************\n* Lutfen yapmak istediginiz islemi giriniz *\n*                                          *\n*  [1] Musteri Bilgilerini Goruntuleme     *\n*                                          *\n*  [2] Musteri Bilgilerini Guncelleme      *\n*                                          *\n*  [3] Musteri Silme                       *\n*                                          *\n*  [4] Cikis                               *\n********************************************\n");
}
void account_operations()
{
    printf("********************************************\n* Lutfen yapmak istediginiz islemi giriniz *\n*                                          *\n*  [1] Bakiye Goruntuleme                  *\n*                                          *\n*  [2] Para Yatirma                        *\n*                                          *\n*  [3] Para Cekme                          *\n*                                          *\n*  [4] Cikis                               *\n********************************************\n");
}
void history_log(int i,int amount,const char *file)
{
    if (i == 1)
    {
        dosya = fopen(file, "a");
        if (dosya == NULL)
        {
            printf("Dosya acilamadi!\n");
            return;
        }
        fprintf(dosya, "Para cekme islemi : %d TL\n", amount);
        fclose(dosya);
    }
    else if (i == 2)
    {
        dosya = fopen(file, "a");
        if (dosya == NULL)
        {
            printf("Dosya acilamadi!\n");
            return;
        }
        fprintf(dosya, "Para yatirma islemi : %d TL\n", amount);
        fclose(dosya);
    }
    else
    {
        printf("Gecersiz kayit islemi\nIslem kaydedilemedi\n");
    }    
}
void information_view(const char *file)
{
    char data_u[100];
    char data_p[20];

    dosya = fopen(file, "r");
    if (dosya == NULL)
    {
        printf("Kullanici bilgileri dosyasi bulunamadi.\n");
        return;
    }

    if (fgets(data_u, sizeof(data_u), dosya) == NULL || 
        fgets(data_p, sizeof(data_p), dosya) == NULL)
    {
        printf("Dosya okuma hatasi.\n");
        fclose(dosya);
        return;
    }

    data_u[strcspn(data_u, "\n")] = '\0';
    data_p[strcspn(data_p, "\n")] = '\0';

    printf("Kullanici Adi: %s\n", data_u);
    printf("Sifre: %s\n", data_p);
    printf("\n");

    fclose(dosya);
}
void information_update(const char *file)
{
    char secim;
    int w = 1;
    char data_u[100];
    char data_p[20];

    dosya = fopen(file, "r");
    if (dosya == NULL)
    {
        printf("Kullanici bilgileri dosyasi bulunamadi.\n");
        return;
    }
    if (fgets(data_u, sizeof(data_u), dosya) == NULL || 
    fgets(data_p, sizeof(data_p), dosya) == NULL)
    {
        printf("Dosya okuma hatasi.\n");
        fclose(dosya);
        return;
    }
    data_u[strcspn(data_u, "\n")] = '\0';
    data_p[strcspn(data_p, "\n")] = '\0';
    fclose(dosya);
    
    while (w)
    {
        printf("Lutfen guncellemek istediginiz bilginin bas harfini giriniz: ");
        scanf(" %c",&secim);
        if (secim == 'k' || secim == 'K')
        {
            printf("Yeni kullanici adinizi giriniz: ");
            scanf("%s", &data_u);
            break;
        }
        else if (secim == 'S' || secim == 's')
        {
            printf("Yeni sifrenizi giriniz: ");
            scanf("%s", &data_p);
            break;
        }
        else
        {
            printf("Lutfen gecerli bir islem giriniz...");
        }
    }
    dosya = fopen(file, "w");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }
    fprintf(dosya, "%s\n", data_u);
    fprintf(dosya, "%s\n", data_p);
    fclose(dosya);
}
int log_delete(const char *file)
{
    if (remove(file) == 0)
        return 0;
    else
        return 1;
}
void balance_view(const char *file)
{
    int bakiye;

    dosya = fopen(file, "r");
    if (dosya == NULL)
    {
        printf("Bakiye dosyasi bulunamadi.\n");
        return;
    }

    if (fscanf(dosya, "%d", &bakiye) != 1)
    {
        printf("Bakiye bilgisi okunamadi.\n");
        fclose(dosya);
        return;
    }

    printf("Mevcut Bakiye: %d TL\n\n", bakiye);
    fclose(dosya);
}
void withdrawal(int b, const char *file)
{
     int i = 1;
    int bakiye;
    int new;

    dosya = fopen(file, "r");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
    }
    if (fscanf(dosya, "%d", &bakiye) != 1)
    {
        printf("Bakiye bilgisi okunamadi.\n");
        fclose(dosya);
    }
    fclose(dosya);

    if (bakiye >= b)
    {
        new = bakiye - b;
        dosya = fopen(file, "w");
        if (dosya == NULL)
        {    
            printf("Dosya acilamadi!\n");
        }
    fprintf(dosya, "%d\n", new);
    fclose(dosya);
    }
    else
        printf("Hesabinizda cekmek istediginiz kadar para bulunmamakta...\n");
    history_log(i,b,history);
}
void deposit(int b, const char *file)
{
    int i = 2;
    int bakiye;
    int new;

    dosya = fopen(file, "r");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
    }
    if (fscanf(dosya, "%d", &bakiye) != 1)
    {
        printf("Bakiye bilgisi okunamadi.\n");
        fclose(dosya);
    }
    fclose(dosya);

    if (b > 0)
    {
        new = bakiye + b;
        dosya = fopen(file, "w");
        if (dosya == NULL)
        {    
            printf("Dosya acilamadi!\n");
        }
    fprintf(dosya, "%d\n", new);
    fclose(dosya);
    }
    else
        printf("Eksi bakiye cekemezsiniz...\n");
    history_log(i,b,history);
}
void history_wiev(const char *filename) {
    dosya = fopen(filename, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi: %s\n", filename);
        return;
    }

    printf("\n=== %s dosya icerigi ===\n", filename);
    
    char line[256];
    int line_number = 1;
    while (fgets(line, sizeof(line), dosya)) {
        printf("%4d: %s", line_number++, line);
    }
    
    printf("=== %s dosya icerigi sonu ===\n\n", filename);
    fclose(dosya);
}