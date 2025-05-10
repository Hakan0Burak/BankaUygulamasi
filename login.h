#include <stdio.h>
#include <string.h>
FILE *dosya = NULL;
char *filename = "log";
char *balance = "balance";
char *history = "history";
int start = 0;

int login_control(const char *file)
{
    dosya = fopen(file, "r");
    if (dosya == NULL)
        return 0;
    fclose(dosya);
    return 1;
}
void loginmenu()
{
    printf("********************************************\n* Lutfen yapmak istediginiz islemi giriniz *\n*                                          *\n*  [1] Kayit ol                            *\n*  [2] Giris                               *\n*  [3] Cikis                               *\n********************************************\n");
}
void create_file(const char *file)
{
    dosya = fopen(file, "w");
    if (dosya == NULL)
    {
        printf("Dosya olusturulamadi!\n");
        return;
    }
    fclose(dosya);
}
void user_loger(const char *username, const char *password, const char *file)
{
    dosya = fopen(file, "w");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }
    fprintf(dosya, "%s\n", username);
    fprintf(dosya, "%s\n", password);
    fclose(dosya);
}
int log_control(const char *username, const char *password, const char *file)
{
    char data_u[100];
    char data_p[20];

    dosya = fopen(file, "r");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return -1;
    }
    fgets(data_u, sizeof(data_u), dosya);
    data_u[strcspn(data_u, "\n")] = '\0';

    fgets(data_p, sizeof(data_p), dosya);
    data_p[strcspn(data_p, "\n")] = '\0';
    fclose(dosya);
    if (strcmp(data_u, username) == 0 && strcmp(data_p, password) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int bankapp_menu()
{
    printf("*******************************************************\n* Lutfen yapmak istediginiz bir banka islemi giriniz  *\n*                                                     *\n*  [1] Bakiye Sorgulama                               *\n*  [2] Para Transferi                                 *\n*  [3] Kredi Cekme                                    *\n*  [4] Hesap Bilgileri Sorgulama                      *\n*  [5] Cikis                                          *\n*******************************************************\n");
}
void balance_loger(const char *file)
{
    int bakiye = 0;
    dosya = fopen(file, "w");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }
    fprintf(dosya, "%d\n", bakiye);
    fclose(dosya);
}
int login_app()
{
    char secim;
    int w = 1;
    char username[100];
    char password[20];
    int hak = 3;
    int r = 1;

    while (w)
    {
        loginmenu();
        printf("Lutfen yapmak istediginiz islemi seciniz: ");
        if (scanf(" %c", &secim) != 1) 
        {
            printf("Hatali giris yaptiniz. Lutfen tekrar deneyiniz.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (secim == '1')
        {
            if (login_control(filename) == '1')
            {
                printf("Daha once kayit olunmus...\n");
            }
            else
            {
                printf("Dosya olusturuluyor...\n\n");
                create_file(filename);
                printf("Lutfen kullanici adi belirleyiniz: ");
                scanf("%99s", username);
                printf("Lutfen sifre belirleyiniz: ");
                scanf("%19s", password);
                user_loger(username, password, filename);
                printf("Kayit basariyla tamamlandi\nAnamenuye yonlendiriliyorsunuz\n\n");
                create_file(balance);
                balance_loger(balance);
                create_file(history);
            }
        }
        else if (secim == '2')
        {
            if (login_control(filename) == 0)
            {
                printf("Daha once kayit olunmamis. Lutfen once kayit olun.\n\n");
            }
            else
            {
                while (hak > 0)
                {
                    printf("Lutfen kullanici adinizi giriniz: ");
                    scanf("%99s", username);
                    printf("Lutfen sifrenizi giriniz: ");
                    scanf("%19s", password);
                    if (log_control(username, password, filename) == 0)
                    {
                        printf("Bankamiza hosgeldiniz!!\n");
                        r = 0;
                        w = 0;
                        break;
                    }
                    else
                    {
                        printf("Kullanici adinizi ya da sifrenizi yanlis girdiniz. Tekrar deneyiniz...\n");
                        hak--;
                        printf("Kalan hakkiniz: %d\n", hak);
                        if (hak == 0)
                        {
                            printf("\nMaalesef haklariniz tukenmistir.\nDaha sonra tekrar deneyiniz...\n");
                            w = 0;
                            r = 1;
                            printf("Cikis yapiliyor...\nTekrar gorusmek dilegiyle.\n");
                            break;
                        }
                    }
                }
            }
        }
        else if (secim == '3')
        {
            printf("Cikis yapiliyor...\nTekrar gorusmek dilegiyle.\n");
            r = 1;
            break;
        }
        else
        {
            printf("Gecerli bir deger giriniz...\n");
        }
    }
    return r;
}