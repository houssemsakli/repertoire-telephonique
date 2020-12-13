#include "Projet_Houssem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/******************Fonction Taille******************/
int taille_liste_rep(liste_rep l)
{
    int n=0;
    while(l)
    {
        n++;
        l=l->suiv;
    }
    return n;
}

/******************Fonction Recherche Telephone******************/
liste_rep recherche_tel(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.numtel,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Nom******************/
liste_rep recherche_nom(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.nom,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Ville******************/
liste_rep recherche_ville(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.adresse.ville,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Indicatif******************/
liste_rep recherche_indicatif(liste_rep l, char mat[])
{
    liste_rep p=l;
    long int val,num;
    num=atol(mat);
    while(p)
    {
        val=atol(p->info.numtel);
        if(val/1000000==num)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Valide (Date)******************/
int valide(date d)
{
   int jmax;
   switch(d.m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:jmax=31;
        case 4:
        case 6:
        case 9:
        case 11:jmax=30;
        case 2:if(d.m%4)
            jmax=28;
            else
                jmax=29;
    }
    return (jmax>=d.j&&d.m>=1&&d.m<=12&&d.a>=1970&&d.a<=2010&&d.j>=1);
}

/******************Fonction Valide Numero******************/
int valide_num (char num[])
{
    int i;
    for(i=0;i<strlen(num);i++)
    {
        if (isdigit(num[i])!=1)
            return 0;
    }
}

/******************Fonction Valide Code Postal******************/
int valide_codep(adr x)
{
    int i;
    for(i=0;i<strlen(x.codep);i++)
    {
        if (isdigit(x.codep[i])!=1)
            return 0;
    }
}

/******************Fonction Valide Ville******************/
int valide_ville(adr x)
{
    int j;
    for(j=0;j<strlen(x.ville);j++)
    {
        if (isdigit(x.ville[j])==1)
            return 0;
    }
}

/******************Fonction Valide Nom******************/
int valide_nom(char x[])
{
    int j;
    for(j=0;j<strlen(x);j++)
    {
        if (isdigit(x[j])==1)
            return 0;
    }
}

/******************Fonction Valide Email******************/
int valide_email(char x[])
{
    int i,rep=0,j;
    for (j=0;j<strlen(x);j++)
    {
        if (x[j]=='@')
            rep++;
    }
    if (rep!=1)
        return 0;
    else
        if (x[1]=='@')
            return 0;
        else
            for(i=1;i<strlen(x)-5;i++)
            {
                if (x[i]=='@')
                    return 1;
            }
}

/******************Fonction Saisie Date******************/
date saisie_date()
{
    date d;
    do
    {
        printf("Donner la date sous la forme jj/mm/aaaa: ");
        fflush(stdin);
        scanf("%d/%d/%d",&d.j,&d.m,&d.a);
    }while(!valide(d));
    return d;
}

/******************Fonction Saisie Repertoire******************/
repertoire saisie_repertoire(liste_rep l)
{
    repertoire e;
    do
    {
        printf("Donner le numero de telephone (8 chiffres): ");
        fflush(stdin);gets(e.numtel);
    }while(recherche_tel(l,e.numtel)||strlen(e.numtel)!=8||valide_num(e.numtel)==0);
    do
    {
        printf("Donner le nom: ");
        fflush(stdin);gets(e.nom);
    }while(!(valide_nom(e.nom)!=0));
    do
    {
        printf("Donner le prenom: ");
        fflush(stdin);gets(e.prenom);
    }while(!(valide_nom(e.prenom)!=0));
    printf("Donner la date de naissance: \n");
    e.dn=saisie_date();
    printf("Donner l'adresse: ");
    printf("\n\tRue: ");
    fflush(stdin);gets(e.adresse.rue);
    do
    {
        printf("\n\tVille: ");
        fflush(stdin);gets(e.adresse.ville);
    }while(!(valide_ville(e.adresse)!=0));
    do
    {
        printf("\n\tCode Postal: ");
        fflush(stdin);gets(e.adresse.codep);
    }while(!(valide_codep(e.adresse)!=0));
    do
    {
        printf("Donner l'adresse email: ");
        fflush(stdin);gets(e.email);
    }while(!(valide_email(e.email)==1));
    return e;
}

/******************Fonction Insersion Tete du Telephone******************/
liste_rep insere_tete_tel(liste_rep l ,repertoire e)
{
    liste_rep p;
    p=malloc(sizeof(struct cellule1));
    p->info=e;
    p->suiv=l;
    l=p;
    return l;
}

/******************Fonction Insersion Queue du Telephone******************/
liste_rep insere_queue_tel(liste_rep l,repertoire e)
{
    liste_rep p,q=l;
    if(l==NULL)
        l=insere_tete_tel(l,e);
    else
    {
        while(q->suiv)
            q=q->suiv;
        p=malloc(sizeof(struct cellule1));
        p->info=e;
        p->suiv=NULL;
        q->suiv=p;

    }
return l;
}

/******************Fonction Insersion Pos du Telephone******************/
liste_rep insere_pos_tel(liste_rep l,repertoire e,int pos)
{
    int cp=1;
    liste_rep p,q=l;
    while(cp<pos-1)
    {
        cp++;
        q=q->suiv;
    }
    p=malloc(sizeof(struct cellule1));
    p->info=e;
    p->suiv=q->suiv;
    q->suiv=p;
    return l;
}

/******************Fonction Supprimer Tete du Telephone******************/
liste_rep supprimer_tete_tel(liste_rep l)
{liste_rep p=l;

    if(l==NULL)
        printf("\n Liste Vide\n");
    else
    {
        l=l->suiv;
        free(p);
    }
    return l;
}

/******************Fonction Supprimer Queue du Telephone******************/
liste_rep supprimer_queue_tel(liste_rep l)
{
    liste_rep p1=l;
    if(!l)
        printf("\n Liste Vide\n");
    else
    if(l->suiv==NULL)
    {
        l=l->suiv;
        free(p1);
    }
    else
    {
        while((p1->suiv)->suiv)
            p1=p1->suiv;
        free(p1->suiv);
        p1->suiv=NULL;
    }
    return l;
}

/******************Fonction Suppression Pos du Telephone******************/
void suppression_pos_tel(liste_rep l,int pos)
{
    liste_rep p1=l,p2;
    int i=1;
    if(pos!=1&&pos!=taille_liste_rep(l))
    {
        while(i<pos-1)
        {
            i++;
            p1=p1->suiv;
        }
        p2=p1->suiv;
        p1->suiv=p2->suiv;
        free(p2);
    }
}

/******************Fonction Suppression du Telephone Donne******************/
liste_rep suppression_tel_donne(liste_rep l,char num[])
{
    liste_rep p1=l,p2;
    int ok=0;

    if(strcmp(p1->info.numtel,num)==0)
        l=supprimer_tete_tel(l);
    else
    {
        while(p1->suiv)
        {
            if(strcmp(p1->suiv->info.numtel,num)==0)
            {
                ok=1;
                break;
            }
            else
                p1=p1->suiv;
        }

        if(ok==1)
        {
            p2=p1->suiv;
            p1->suiv=p2->suiv;
            free(p2);
        }
    }
    return l;
}

/******************Fonction Suppression du Ville Donnee******************/
liste_rep suppression_ville_donnee(liste_rep l,char v[])
{
    liste_rep p1=l,p2=l,p3=l;
    for (p3=l;p3;p3=p3->suiv)
    {
        if(strcmp(p1->info.adresse.ville,v)==0)
        {
            l=supprimer_tete_tel(l);
            p1=p1->suiv;
        }
        while(p1)
        {
            if(strcmp(p1->info.adresse.ville,v)==0)
            {
                while(p2->suiv!=p1)
                    p2=p2->suiv;
                    p2->suiv=p1->suiv;
                    free(p1);
            }
            p1=p1->suiv;
        }
        p1=l;
    }
    return l;
}

/******************Fonction Suppression d'un Indicatif Donne******************/
liste_rep suppression_indicatif_donnee(liste_rep l,char ind[])
{
    liste_rep p1=l,p2=l,p3=l;
    long int val,val2,num;
    num=atol(ind);
    for (p3=l;p3;p3=p3->suiv)
    {
        val=atol(p1->info.numtel);
        if(val/1000000==num)
        {
            l=supprimer_tete_tel(l);
            p1=p1->suiv;
        }
        while(p1)
        {
            val2=atol(p1->info.numtel);
            if(val2/1000000==num)
            {
                while(p2->suiv!=p1)
                p2=p2->suiv;
                p2->suiv=p1->suiv;
                free(p1);
            }
            p1=p1->suiv;
        }
        p1=l;
    }
    return l;
}

/******************Fonction Modification du Telephone Donne******************/
void modification_tel_donne(liste_rep l)
{
    liste_rep p1=l;
    int ok=0;
    char nump[10],numnouv[10];
    do
    {
        printf("Donner le numero telephone du contact que vous voulez modifier: ");
        fflush(stdin);gets(nump);
    }while(!(recherche_tel(l,nump)&&strlen(nump)==8&&valide_num(nump)!=0));
    do
    {
        printf("\nDonner un nouveau telephone: ");
        fflush(stdin);gets(numnouv);
    }while(recherche_tel(l,numnouv)||strlen(numnouv)!=8||valide_num(numnouv)==0);
    while (p1&&ok==0)
    {
        if(strcmp(p1->info.numtel,nump)==0)
        {
            strcpy(p1->info.numtel,numnouv);
            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

/******************Fonction Modification d'une Adresse Donnee******************/
void modification_adresse_donnee(liste_rep l)
{
    liste_rep p1=l;
    int ok=0;
    char nump[10];
    adr nvadresse;
    do
    {
        printf("Donner le numero telephone du contact que vous voulez modifier: ");
        fflush(stdin);gets(nump);
    }while(!(recherche_tel(l,nump)&&strlen(nump)==8&&valide_num(nump)!=0));
    printf("\n\n\t\tSAISIE DE LA NOUVELLE ADRESSE\n");
    printf("\n\tRue: ");
    fflush(stdin);gets(nvadresse.rue);
    do
    {
        printf("\n\tVille: ");
        fflush(stdin);gets(nvadresse.ville);
    }while(!(valide_ville(nvadresse)!=0));
    do
    {
        printf("\n\tCode Postal: ");
        fflush(stdin);gets(nvadresse.codep);
    }while(!(valide_codep(nvadresse)!=0));

    while (p1&&ok==0)
    {
        if(strcmp(p1->info.numtel,nump)==0)
        {
            strcpy(p1->info.adresse.rue,nvadresse.rue);
            strcpy(p1->info.adresse.codep,nvadresse.codep);
            strcpy(p1->info.adresse.ville,nvadresse.ville);
            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

/******************Fonction Affiche d'un Telephone donne******************/
void affiche_tel_donne(liste_rep l)
{
    char nump[10];
    do
    {
        printf("Donner le numero telephone du contact que vous voulez afficher: ");
        fflush(stdin);gets(nump);
    }while(!(recherche_tel(l,nump)&&strlen(nump)==8&&valide_num(nump)!=0));
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    affiche1(l,nump);
}

/******************Fonction Affiche d'un Nom Donne******************/
void affiche_nom_donne(liste_rep l)
{
    liste_rep p1=l;
    char nvnom[10];
    do
    {
        printf("Donner le nom du contact que vous voulez afficher: ");
        fflush(stdin);gets(nvnom);
    }while(!(recherche_nom(l,nvnom)&&valide_nom(nvnom)!=0));
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        if (strcmp(p1->info.nom,nvnom)==0)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

/******************Fonction Affiche d'un Indicatif Donne******************/
void affiche_indicatif_donne(liste_rep l)
{
    liste_rep p1=l;
    long int val,num;
    char ind[10];
    do
    {
        printf("Donner un indicatif du contact que vous voulez afficher (2 chiffres): ");
        fflush(stdin);gets(ind);
    }while(!(valide_num(ind)!=0&&strlen(ind)==2&&recherche_indicatif(l,ind)));
    num=atol(ind);
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        val=atol(p1->info.numtel);
        if (val/1000000==num)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

/******************Fonction Affiche d'une Ville Donnee******************/
void affiche_ville_donne(liste_rep l)
{
    liste_rep p1=l;
    adr nv;
    do
    {
        printf("\n\tDonner la ville du contact que vous voulez afficher: ");
        fflush(stdin);gets(nv.ville);
    }while(!(recherche_ville(l,nv.ville)&&valide_ville(nv)!=0));
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        if (strcmp(p1->info.adresse.ville,nv.ville)==0)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

/******************Fonction Affiche1******************/
void affiche1(liste_rep l,char x[])
{
    liste_rep p=l;
    while(p)
    {
        if (strcmp(x,p->info.numtel)==0)
        {
            printf("%s\t%s\t%s\t\t%d/%d/%d\t\t%s %s %s\t%s\n",p->info.numtel,p->info.nom,p->info.prenom,p->info.dn.j,p->info.dn.m,p->info.dn.a,p->info.adresse.rue,p->info.adresse.ville,p->info.adresse.codep,p->info.email);
            break;
        }
        else
            p=p->suiv;
    }
}

/******************Fonction Affiche2******************/
void affiche2(liste_rep l)
{
 if(l==NULL)
  printf("LISTE VIDE");
 else
 {
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(l)
    {
        printf("%s\t%s\t%s\t\t%d/%d/%d\t\t%s %s %s\t%s\n",l->info.numtel,l->info.nom,l->info.prenom,l->info.dn.j,l->info.dn.m,l->info.dn.a,l->info.adresse.rue,l->info.adresse.ville,l->info.adresse.codep,l->info.email);
        l=l->suiv;
    }
 }
}

/******************Fonction Tri1******************/
void tri1(liste_rep l)
{
    repertoire aux;
    liste_rep p1=l,p2;
    long int v1,v2;
    while(p1->suiv)
    {
        p2=p1->suiv;
        while(p2)
        {
            v1=atol(p1->info.numtel);
            v2=atol(p2->info.numtel);
            if(v1<v2)
            {
                aux=p1->info;
                p1->info=p2->info;
                p2->info=aux;
            }
                p2=p2->suiv;
        }
        p1=p1->suiv;
    }
}

/******************Fonction Tri2******************/
void tri2(liste_rep l)
{
    repertoire aux;
    liste_rep p1=l,p2;
    long int v1,v2;
    while(p1->suiv)
    {
        p2=p1->suiv;
        while(p2)
        {
            v1=atol(p1->info.numtel);
            v2=atol(p2->info.numtel);
            if(v1<v2)
            {
                aux=p1->info;
                p1->info=p2->info;
                p2->info=aux;
            }
                p2=p2->suiv;
        }
        p1=p1->suiv;
    }
}

/******************Fonction Creation******************/
liste_rep CREATION(liste_rep l)
{
    int pos,t,rep;
    repertoire e;
    do
    {
        t=taille_liste_rep(l);
        do
        {
            printf("\nSaisir la position entre 1 et %d : ",t+1);fflush(stdin);
            scanf("%d",&pos);
        }while(pos<1||pos>t+1);
        e=saisie_repertoire(l);
        if(pos==1)
            l=insere_tete_tel(l,e);
        else
            if(pos==t+1)
                l=insere_queue_tel(l,e);
            else
                l=insere_pos_tel(l,e,pos);
        do
        {
            printf("Voulez vous ajouter un autre telephone? O/N (0 pour Non,1 pour Oui): ");fflush(stdin);
            scanf("%d",&rep);
        }while(rep!=1&&rep!=0);
    }while(rep==1);
    return l;
}

/******************Fonction Construction d'une Chaine******************/
int construction(char *ligne,int pos,char s,char *ch)
{
    int i,j;
    for(i=pos,j=0;ligne[i]!=s;i++)
            ch[j++]=ligne[i];
        ch[j]='\0';
    //puts(ch);
    return i+1;
}

/******************Fonction Enregistrement d'un Repertoire******************/
void enregistrement_repertoire(liste_rep l)
{
    int i;
    FILE *fp;
    fp=fopen("liste_repertoire.txt","w");
    while(l)
    {

        fprintf(fp,"|%s|%s|%s|%d/%d/%d|%s|%s|%s|%s|\n",l->info.numtel,l->info.nom,l->info.prenom,l->info.dn.j,l->info.dn.m,l->info.dn.a,l->info.adresse.rue,l->info.adresse.ville,l->info.adresse.codep,l->info.email);
        l=l->suiv;
    }
    fclose(fp);
    printf ("\nEnregistrement de la liste dans le fichier %s \n","fichier_rep.txt");
}

/******************Fonction Recuperation d'un Repertoire******************/
liste_rep recuperation_repertoire()
{

    FILE *fp;
    liste_rep p=NULL;
    repertoire e;
    int pos;
    char ligne[100];
    char ch[5];
    char etape[3];
    fp=fopen("liste_repertoire.txt","r");

    if(fp==NULL)
         printf("LISTE REPERTOIRE VIDE\\");
    else
       while(fgets(ligne,100,fp)!=NULL)
       {
            pos=construction(ligne,1,'|',e.numtel);
            pos=construction(ligne,pos,'|',e.nom);
            pos=construction(ligne,pos,'|',e.prenom);
            pos=construction(ligne,pos,'/',ch);
            e.dn.j=atoi(ch);
            pos=construction(ligne,pos,'/',ch);
            e.dn.m=atoi(ch);
            pos=construction(ligne,pos,'|',ch);
            e.dn.a=atoi(ch);
            pos=construction(ligne,pos,'|',e.adresse.rue);
            pos=construction(ligne,pos,'|',e.adresse.ville);
            pos=construction(ligne,pos,'|',e.adresse.codep);
            pos=construction(ligne,pos,'|',e.email);
            p=insere_queue_tel(p,e);
       }
    fclose(fp);
    return p;
}

/******************Fonction Menu Generale******************/
void menu_generale(liste_rep l)
{
    int choix;
    printf("\n\t\tMENU GENERAL\n");
    printf("1- Creation du repertoire telephonique\n");
    printf("2- Mise a jour des telephones\n");
    printf("3- Recherche, affichage et Tri\n");
    printf("4- Enregistrement et chargement dans un fichier\n");
    printf("5- Quitter\n");
    do
    {
        printf("\t\t\tDonner votre choix SVP: ");
        scanf("%d",&choix);
    }while(!(choix>=1&&choix<=5));

    switch(choix)
    {
        case 1:
        {
            l=CREATION(l);
            menu_generale(l);
            break;
        }
        case 2:
        {
            menu_maj(l);
            menu_generale(l);
            break;
        }
        case 3:
        {
            menu_recherche_affichage(l);
            menu_generale(l);
            break;
        }
        case 4:
        {
            menu_enregistrement_chargement(l);
            menu_generale(l);
            break;
        }
        case 5:
            break;
    }
}

/******************Fonction Menu Maj******************/
void menu_maj (liste_rep l)
{
    int choix1;
    printf("\n\t\tMENU MAJ\n");
    printf("1- Ajouter un nouvel telephone\n");
    printf("2- Supprimer un telephone\n");
    printf("3- Modifier les donnees d'un telephone\n");
    printf("4- Retour Menu generale\n");
    do
    {
        printf("\t\t\tDonner votre choix SVP: ");
        scanf("%d",&choix1);
    }while(!(choix1>=1&&choix1<=4));

    switch(choix1)
    {
        case 1:
        {
            menu_ajouter(l);
            menu_generale(l);
            break;
        }
        case 2:
        {
            menu_suppression(l);
            menu_generale(l);
            break;
        }
        case 3:
        {
            menu_modification(l);
            menu_generale(l);
            break;
        }
        case 4:
        {
            menu_generale(l);
            break;
        }
    }
}

/******************Fonction Menu Ajouter******************/
void menu_ajouter(liste_rep l)
{
    repertoire e;
    int choix;
    printf("\n\t\tMENU Ajouter\n");
    printf("1- Ajout en tete\n");
    printf("2- Ajout en queue\n");
    printf("3- Ajout dans une position\n");
    printf("4- Retour au Menu MAJ\n");

    do
    {
        printf("\t\t\tDonner votre choix SVP: ");
        scanf("%d",&choix);
    }while(!(choix>=1&&choix<=4));

    switch(choix)
    {
        case 1:
        {
            e=saisie_repertoire(l);
            l=insere_tete_tel(l,e);
            menu_maj(l);
            break;
        }
        case 2:
        {
            e=saisie_repertoire(l);
            l=insere_queue_tel(l,e);
            menu_maj(l);
            break;
        }
        case 3:
        {
            l=CREATION(l);
            menu_maj(l);
            break;

        }
        case 4:
        {
            menu_maj(l);
            break;
        }
    }
}

/******************Fonction Menu Suppression******************/
void menu_suppression(liste_rep l)
{
    int choix,pos;
    adr a;
    char tel[10],b[3];
    printf("\n\t\tMenu Suppression\n");
    printf("1- Suppression en tete\n");
    printf("2- Suppression en queue\n");
    printf("3- Suppression a partir d'une position\n");
    printf("4- Suppression d'un telephone donne\n");
    printf("5- Suppression des telephones d'une ville donnee\n");
    printf("6- Suppression des telephones d'un indicatif donne\n");
    printf("7- Retour au Menu MAJ\n");

    do
    {
        printf("\t\t\tDonner votre choix SVP: ");
        scanf("%d",&choix);
    }while(!(choix>=1&&choix<=7));

    switch(choix)
    {
        case 1:
        {
            l=supprimer_tete_tel(l);
            menu_maj(l);
            break;
        }
        case 2:
        {
            l=supprimer_queue_tel(l);
            menu_maj(l);
            break;
        }
        case 3:
        {   do
            {
                printf("\n\tDonner la position: ");
                scanf("%d",&pos);
            }while(!(pos>=1&&pos<=taille_liste_rep(l)));
            suppression_pos_tel(l,pos);
            menu_maj(l);
            break;
        }
        case 4:
        {
            do
            {
                printf("\n\tDonner le telephone: ");
                fflush(stdin);gets(tel);
            }while(!(valide_num(tel)!=0&&strlen(tel)==8&&recherche_tel(l,tel)));
            l=suppression_tel_donne(l,tel);
            menu_maj(l);
            break;
        }
        case 5:
        {
            do
            {
                printf("\n\tDonner la ville: ");
                fflush(stdin);gets(a.ville);
            }while(!(valide_ville(a)!=0&&recherche_ville(l,a.ville)));
            l=suppression_ville_donnee(l,a.ville);
            menu_maj(l);
            break;
        }
        case 6:
        {
            do
            {
                printf("\n\tDonner l'indicatif (2 chiffres): ");
                fflush(stdin);gets(b);
            }while(!(strlen(b)==2&&recherche_indicatif(l,b)));
            l=suppression_indicatif_donnee(l,b);
            menu_maj(l);
            break;
        }
        case 7:
        {
            menu_maj(l);
            break;
        }
    }
}

/******************Fonction Menu Modification******************/
void menu_modification (liste_rep l)
{
    int choix;
    char nump[10],numnouv[10];
    repertoire nouv;
    printf("\n\t\tMenu Modification\n");
    printf("1- Adresse\n");
    printf("2- Telephone\n");
    printf("3- Retour au Menu MAJ\n");

    do
    {
        printf("\t\t\tDonner votre choix SVP: ");
        scanf("%d",&choix);
    }while(!(choix>=1&&choix<=3));
    switch(choix)
    {
        case 1:
        {
            modification_adresse_donnee(l);
            menu_maj(l);
            break;
        }
        case 2:
        {

            modification_tel_donne(l);
            menu_maj(l);
            break;
        }
        case 3:
        {
            menu_maj(l);
            break;
        }
    }
}

/******************Fonction Menu Recherche et Affichage******************/
void menu_recherche_affichage(liste_rep l)
{
    int choix;
    printf("\n\t\tMenu Recherche et Affichage\n");
    printf("1- Contenu de la liste des telephones\n");
    printf("2- Recherche par numero de telephone\n");
    printf("3- Recherche par nom\n");
    printf("4- Recherche par indicatif telephone\n");
    printf("5- Recherche par ville\n");
    printf("6- Tri 1\n");
    printf("7- Tri 2\n");
    printf("8- Retour au Menu Generale\n");

    do
    {
        printf("\t\t\tDonner votre choix SVP: ");
        scanf("%d",&choix);
    }while(!(choix>=1&&choix<=8));

    switch (choix)
    {
        case 1:
        {
            affiche2(l);
            menu_generale(l);
            break;
        }
        case 2:
        {
            affiche_tel_donne(l);
            menu_generale(l);
            break;
        }
        case 3:
        {
            affiche_nom_donne(l);
            menu_generale(l);
            break;
        }
        case 4:
        {
            affiche_indicatif_donne(l);
            menu_generale(l);
            break;
        }
        case 5:
        {
            affiche_ville_donne(l);
            menu_generale(l);
            break;
        }
        case 6:
        {
            tri1(l);
            menu_generale(l);
            break;
        }
        case 7:
        {
            tri2(l);
            menu_generale(l);
            break;
        }
        case 8:
        {
            menu_generale(l);
            break;
        }
    }
}

/******************Fonction Enregistrement et Chargement******************/
void menu_enregistrement_chargement(liste_rep l)
{
    int choix;
    printf("\n\t\tMenu Enregistrement et Chargement\n");
    printf("1- Enregistrement\n");
    printf("2- Chargement\n");
    printf("3- Retour au Menu Generale\n");
    do
    {
        printf("\t\t\tDonner votre choix SVP: ");
        scanf("%d",&choix);
    }while(!(choix>=1&&choix<=3));

    switch(choix)
    {
        case 1:
        {
            enregistrement_repertoire(l);
            menu_generale(l);
            break;
        }
        case 2:
        {
            l=recuperation_repertoire();
            menu_generale(l);
            break;
        }
        case 3:
        {
            menu_generale(l);
            break;
        }
    }
}
