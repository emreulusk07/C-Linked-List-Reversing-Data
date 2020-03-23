#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    EMRE ULUISIK
    18010011013
*/
typedef struct LinkedList
{
    char data[20];
    struct LinkedList *next;

} list;

list *root = NULL;

list *ListeyeEkle(list *p, int i)
{
    char veri[20];

    if(p == NULL)
    {
        p = (list*) malloc(sizeof(list));
        printf("%d. Veri: ", i+1);
        scanf("%s", veri);
        strcpy(p->data, veri);
        p->next = NULL;
        return p;
    }

    else
    {
        root = p;
        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = (list *) malloc(sizeof(list));
        printf("%d. Veri: ", i+1);
        scanf("%s", veri);
        strcpy(p->next->data, veri);
        p->next->next = NULL;
        return root;
    }

}


list *TersCevirme(list *p, list * temp, list * prev)
{
    if(p == NULL)
        return prev;

    temp = p->next;
    p->next = prev;
    prev = p;
    p = temp;
    return TersCevirme(p,temp,prev);

}

void ListeyiYazdir(list *p)
{
    if(p == NULL)
        printf("Liste Bos..");

    while(p->next != NULL)
    {
        printf("%s * ", p->data);
        p = p->next;
    }
    printf("%s", p->data);
    printf("\n\n");

}

int main()
{
    int secim, veriSayisi, i=0, sayac=0;
    list *start = NULL;
    list *prev = NULL;
    list *temp = NULL;

    while(1==1)
    {
        printf("    ANA MENU\n\n");
        printf("1- Veri Ekle..\n2- Verileri Ters Cevirip Yazdir..\n3- Cikis Yap..\n\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if(secim == 1)
        {
            printf("Girmek istediginiz veri sayisi: ");
            scanf("%d", &veriSayisi);
            while(1==1)
            {
                if(sayac != veriSayisi)
                {
                    start = ListeyeEkle(start, i);
                    i++;
                    sayac++;
                }
                else
                {
                    ListeyiYazdir(start);
                    break;
                }
            }
        }

        else if(secim == 2)
        {
            printf("# Onceki Liste\n");
            ListeyiYazdir(start);
            start = TersCevirme(start,temp,prev);
            printf("# Sonraki Liste\n");
            ListeyiYazdir(start);
        }

        else if(secim == 3)
        {
            printf("Program sonlandi..\n");
            break;
        }

        else
        {
            printf("Yanlis secim tusladiniz. Istediginiz islemi tekrar tuslayiniz..\n\n");
        }
        sayac=0;
    }

}
