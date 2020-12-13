#ifndef PROJET_HOUSSEM_H_INCLUDED
#define PROJET_HOUSSEM_H_INCLUDED

typedef struct
{
    int j;
    int m;
    int a;
}date;

typedef struct
{
    char rue[20];
    char ville[20];
    char codep[10];
}adr;

typedef struct
{
    char numtel[10];
    char nom[21];
    char prenom[21];
    date dn;
    adr adresse;
    char email[30];
}repertoire;

struct cellule1
{
    repertoire info;
    struct cellule1* suiv;
};
typedef struct cellule1* liste_rep;

/*************************************************************************/

int taille_liste_rep(liste_rep l);
liste_rep recherche_tel(liste_rep l, char mat[]);
liste_rep recherche_nom(liste_rep l, char mat[]);
liste_rep recherche_ville(liste_rep l, char mat[]);
liste_rep recherche_indicatif(liste_rep l, char mat[]);
int valide(date d);
int valide_num (char num[]);
int valide_codep(adr x);
int valide_ville(adr x);
int valide_nom(char x[]);
int valide_email(char x[]);
date saisie_date();
repertoire saisie_repertoire(liste_rep l);
liste_rep insere_tete_tel(liste_rep l ,repertoire e);
liste_rep insere_queue_tel(liste_rep l,repertoire e);
liste_rep insere_pos_tel(liste_rep l,repertoire e,int pos);
liste_rep supprimer_tete_tel(liste_rep l);
liste_rep supprimer_queue_tel(liste_rep l);
void suppression_pos_tel(liste_rep l,int pos);
liste_rep suppression_tel_donne(liste_rep l,char num[]);
liste_rep suppression_ville_donnee(liste_rep l,char v[]);
liste_rep suppression_indicatif_donnee(liste_rep l,char ind[]);
void modification_tel_donne(liste_rep l);
void modification_adresse_donnee(liste_rep l);
void affiche_tel_donne(liste_rep l);
void affiche_nom_donne(liste_rep l);
void affiche_indicatif_donne(liste_rep l);
void affiche_ville_donne(liste_rep l);
void affiche1(liste_rep l,char x[]);
void affiche2(liste_rep l);
void tri1(liste_rep l);
void tri2(liste_rep l);
liste_rep CREATION(liste_rep l);
int construction(char *ligne,int pos,char s,char *ch);
void enregistrement_repertoire(liste_rep l);
liste_rep recuperation_repertoire();
void menu_generale(liste_rep l);
void menu_maj (liste_rep l);
void menu_ajouter(liste_rep l);
void menu_suppression(liste_rep l);
void menu_modification (liste_rep l);
void menu_recherche_affichage(liste_rep l);
void menu_enregistrement_chargement(liste_rep l);

#endif // PROJET_HOUSSEM_H_INCLUDED
