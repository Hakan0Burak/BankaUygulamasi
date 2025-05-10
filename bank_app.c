#include "bank_app.h"

int main()
{
    char secim = '0';
    char secim2 = '0';
    char secim3 = '0';
    int w = 1;
    int w2 = 1;
    int w3 = 1;
    int with = 0;
    if (login_app() == 0)
    {
        while (w)
        {
            bank_main_menu();
            printf("Lutfen yapmak istediginiz islemi giriniz: ");
            scanf(" %c",&secim);
            if (secim == '1')
            {
                while (w2)
                {
                    customer_management_menu();
                    printf("Lutfen yapmak istediginiz islemi giriniz: ");
                    scanf(" %c",&secim2);
                    if (secim2 == '1')
                    {
                        while (w3)
                        {
                            information_view(filename);
                            printf("Cikis yapilsin mi(E,H): \n");
                            scanf(" %c",&secim3);
                            if (secim3 == 'E' || secim3 == 'e')
                                break;
                            else if (secim3 == 'H' || secim3 == 'h')
                                w3 = 1;
                            else
                            printf("Gecersiz islem numarasi girdiniz...\n");
                        }
                    }
                    else if (secim2 == '2')
                    {
                        while (w3)
                        {
                            information_update(filename);
                            printf("Cikis yapilsin mi(E,H): \n");
                            scanf(" %c",&secim3);
                            if (secim3 == 'E' || secim3 == 'e')
                                break;
                            else if (secim3 == 'H' || secim3 == 'h')
                                w3 = 1;
                            else
                            printf("Gecersiz islem numarasi girdiniz...\n");
                        }
                    }
                    else if (secim2 == '3')
                    {
                        if (log_delete(filename) == 0)
                        {
                            printf("\nVerileriniz guvenli sekilde silinmistir...\nCikisiniz yapiliyor...");
                            return 0;
                        }
                    }
                    else if (secim2 == '4')
                    {
                        break;
                    }
                    else
                    {
                        printf("Gecersiz islem numarasi girdiniz...\n");
                    }
                }
            }
            else if (secim == '2')
            {
                while (w2)
                {
                    account_operations();
                    printf("Lutfen yapmak istediginiz islemi giriniz: ");
                    scanf(" %c",&secim2);
                    if (secim2 == '1')
                    {
                        while (w3)
                        {
                            balance_view(balance);
                            printf("Cikis yapilsin mi(E,H): \n");
                            scanf(" %c",&secim3);
                            if (secim3 == 'E' || secim3 == 'e')
                                break;
                            else if (secim3 == 'H' || secim3 == 'h')
                                w3 = 1;
                            else
                            printf("Gecersiz islem numarasi girdiniz...\n");
                        }
                    }
                    else if (secim2 == '2')
                    {
                        while (w3)
                        {
                            printf("Lutfen yatirmak istediginiz miktari giriniz: ");
                            scanf("%d",&with);
                            deposit(with,balance);
                            balance_view(balance);
                            printf("Cikis yapilsin mi(E,H): \n");
                            scanf(" %c",&secim3);
                            if (secim3 == 'E' || secim3 == 'e')
                                break;
                            else if (secim3 == 'H' || secim3 == 'h')
                                w3 = 1;
                            else
                            printf("Gecersiz islem numarasi girdiniz...\n");
                        }
                    }
                    else if (secim2 == '3')
                    {
                        while (w3)
                        {
                            printf("Lutfen cekmek istediginiz miktari giriniz: ");
                            scanf("%d",&with);
                            withdrawal(with,balance);
                            balance_view(balance);
                            printf("Cikis yapilsin mi(E,H): \n");
                            scanf(" %c",&secim3);
                            if (secim3 == 'E' || secim3 == 'e')
                                break;
                            else if (secim3 == 'H' || secim3 == 'h')
                                w3 = 1;
                            else
                            printf("Gecersiz islem numarasi girdiniz...\n");
                        }
                    }
                    else if (secim2 == '4')
                    {
                        break;
                    }
                    else
                    {
                        printf("Gecersiz islem numarasi girdiniz...\n");
                    }
                }
                
            }
            else if (secim == '3')
            {
                history_wiev(history);
                while (w3)
                {
                    printf("Cikis yapilsin mi(E,H): \n");
                    scanf(" %c",&secim3);
                    if (secim3 == 'E' || secim3 == 'e')
                        break;
                    else if (secim3 == 'H' || secim3 == 'h')
                        w3 = 1;
                    else
                        printf("Gecersiz islem numarasi girdiniz...\n");
                }
                
            }
            else if (secim == '4')
            {
                printf("\nCikisiniz yapiliyor...");
                return 0;
            }
            else
            {
                printf("Gecersiz islem numarasi girdiniz...\n");
            }
            
        }
    }
    else
    {
        printf("Uygulamaya giriş yapilamadi...");
    }
}