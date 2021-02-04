#include <stdio.h>
#include <stdlib.h>


int  Partition(int tab [],int d,int f)
{
    int i=d-1; //car dans la boucle do while ci-dessous i est incrémenté avant d'etre tester(ce qu'on ne souhaite pas).
    int j=f+1;//car dans la boucle do while j ci-dessous est décrémenté avant d'etre tester.(ce qu'on ne souhaite pas).
    int aux; // variable auxiliaire qui servira pour la permutation
    int pivot=tab[(d+f)/2]; // choix du pivot

    while (1) // ceci est  une boucle infini dont la seul condition d'arret est un break ou return. donc, on va repété ce qui suit jusqu'à ce qu'on rencontre un break ou un return.
    { do {i++;}while(tab[i]<pivot);// cette action va etre repété jusqu'a ce qu'on trouve une valeur à gauche supérieur au pivot
      do {j--;}while(tab[j]>pivot);//cette action va etre repété jusqu'a ce qu'on trouve une valeur à droite supérieur au pivot

// après avoir trouver deux valeurs qui encadre le pivot et si leur indice son != (i<j) alors on les permutes
      if (i<j)
      {aux=tab[i];
      tab[i]=tab[j];
      tab[j]=aux;
      }
      //dans le cas contraire (i>j ou i=j) on retourne la position du pivot
      else {return j;}//// le pivot n'a pas une position fix. elle change après chaque itération.du coup on l'envoi
    }
}


void tri_rapide(int tab [],int d, int f) //il s'effectue par partitionnement successive suivant un élément appelé pivot
{ int p;
  if(d>=f){return;} // soi le tableau est nul(n'hexiste pas) soi le tableau à un élément et du coup est trié
      else
        {
        p=Partition(tab,d,f); // cette fonction partitionne le tableau et nous retourne la position du pivot
                              // partitioner reviens à mettre à gauche du pivot tous les valeurs qui lui son inférieur  et à droite du pivot tous les valeurs qui lui son supérieur

        tri_rapide(tab,d,p); // on récupère le sous tableau a gauche du pivot et on le tri(le partitionne) récussivement avec la fonction tri_rapide jusqu'a ce qu'il soi trié (ordonné)
        //NB:le fait d'aller jusqu'a p ne pause pas de problème car le nouveau pivot sera toujours selon ça position < ou > à ancien pivot (execute le code sur une feiuille pour mieux comprendre).(c'est comme s'il est fixe)
        tri_rapide(tab,p+1,f);// on récupère le sous tableau à droite du pivot et on le tri(le partitionne) récussivement avec la fonction tri_rapide jusqu'a ce qu'il soi trié (ordonné)
        }
}

void fusion(int tab[],int d,int mil,int f)
{
   int i=d;// pour parcourir la partie de gauche (du tableau) [d...mil]
   int j=mil+1;//pour parcourir la partie de droite ( du tableau) [mil+1...f]
   int k;//pour parcourir le tableau intermediaire (auxiliare)
   int temp[f+1];////on cree un tableau auxiliaire

 for (k=0;k<=f;k++) // ici, on recupère la/les partie de tab qu'on veut trier et fusionner , on les trient et ont les fusionnent en les insérant dans
 // temp.(on dira qu'on à trié et fusionné les deux tableau recu en paramètre en les insérant dans temp (en realité c'est pas deux tableau mais une partie du tableau de depart))
    {
    if (i>mil){temp[k]=tab[j];j++;}

    else if (j>f){temp[k]=tab[i];i++;}

    else if (tab[i]<tab[j]){temp[k]=tab[i];i++;}

    else {temp[k]=tab[j];j++;};
   } // après cette etape, tab est vide et temp est
   //remplie/trié avec les éléments de tab

     for(i=d,j=0;i<=f;i++,j++){tab[i]=temp[j];} // ici, on rempli tab avec temp en conserve toujours les indices de tab de depart.
   //tu peut remplacer j par n'importe quelle autre lettre mais ça valeur doit toujours commencé par 0 (son role est de parcourir temp).tu peut remplacer i par n'importe quelle autre lettre mais ça valeur doit toujours commencé par la lettre d (son role est de parcourir tab) car le debut et la fin varie selon le niveau de l'appel recursif.
}


void tri_fusion(int tab[],int d,int f) // wikipédia explique bien le principe. il s'effectue par diviion successive
{
        int mil;
     if(d>=f){return;} // car un tableau à un élément est trié (soi le tableau est nul(n'hexiste pas) soi le tableau à un élément)
      else
        { mil=(f+d)/2; // divise le tableau en deux

     tri_fusion(tab,d,mil); // on tri la première moitié tu tableau
     tri_fusion(tab,mil+1,f); // on tri la deuxième moitié du tableau

     fusion(tab,d,mil,f); //on fusionne les deux tableaux en gardan une logique de tri
        }
}


void tri_insertion(int tab[], int n)// principe: on repère une liste trié, et on insère les éléments dans cette liste en gardant l'ordre de tri.
                                    //c'est comme si on remplissait en ordre un tableau avec les éléments d'un autres tableau
{      int i,j,aux;
  for(i=0;i<n-1;i++){// pour parcourir le premier tableau (i=taille de la partie du tableau trié par j)
    for(j=i;j>=0;j--){ //pour parcourir le deuxième tableau (j va trié le tableau de 0 jusqu'a i)
        if (tab[j+1]<tab[j]){aux=tab[j+1];tab[j+1]=tab[j];tab[j]=aux;}//comparaison et permutation sucessive
        else j=-1;// pour éviter de refiare des comparaison déja faitent
    };
  }
}


void tri_selection(int tab[], int n) //on l'appel d'apres moi tri par selection car, à chaque itération/parcour, on selectionne/récupère l'indice de l'élément le plus grand/peti du tableau et en suite, on
                                    //place la valeur du tableau associé à cet l'indice au début/fin du tableau et ainsi de suite.
  { int i,j,posmin,aux;

    for(i=0;i<n-1;i++){//on decale d'une case vers la droite à partir du début à chaque fois qu'on trouve et tri un min.
        posmin=i;
    for (j=i+1;j<n;j++){if (tab[posmin]>tab[j]) posmin=j;};// on parcour le tableau pour récuperer la position de l'élément le plus petit.
        aux=tab[i];tab[i]=tab[posmin]; tab[posmin]=aux; // on position l'élément le plus petit au début du tableau.
        }
    }


void tri_bull(int tab[], int n) // but: parcourir un tableau/liste en permutant toute paire d'éléments consécutifs non ordonnés
{ int i,j,perm;
     for (i=n-1;i>=0;i--){ //(On tri en ordre croissant) Après le premier parcours par exmple, le plus grand élément se trouvera dans la dernière case du tableau en tab[n], et il reste donc à appliquer le même procéder sur le tableau composé des éléments tab[1],…,tab[n-1].
        for (j=0;j<i;j++){ // cette boucle va parcourir le tableau en Comparant le 1er et le 2ème élément; s’ils sont désordonnés
                           //on les permute; ainsi de suite jusqu'a le plus grand élément soi positionné à la fin du tableau.
            if (tab[j]>tab[j+1])
             { perm = tab[j];
               tab[j]= tab[j+1];
               tab[j+1] = perm;
             };
        };
    }
}

int main()
{   int n,i,x;
    int tab[100];
printf("Bienvenu dans ce didacticiel qui r%csume quelques m%cthodes de tri de listes/tableaux.\n",130,130);
printf("Pour commencer, entrer le nombre d'%cl%cments (taille) de votre tableau (max 100) :\n",130,130);
   scanf("%d",&n);
    while (n<=0){
   printf("erreur: la taille du tableau entrer est incorect\n");
printf("Entrer le nombre d'%cl%cments (taille) de votre tableau :\n",130,130);
   scanf("%d",&n);
    }
printf("entrer les %cl%cments de votre tableau :\n",130,130);
     for(i=0;i<n;i++){scanf("%d",&tab[i]);}
printf("Voici votre tableau avant le tri :\n\n");
     for(i=0;i<n;i++){printf("%2d|",tab[i]);}
     printf("\n\nchoisir une m%cthode de tri parmi les suivantes (le num%cro) :\n",130,130);
     printf("\nNB:le tri s'%cffectura en ordre croissant.\n",130);
     printf("\n1. tri bull\n");
     printf("2. tri selection\n");
     printf("3. tri insertion\n");
     printf("4. tri fusion\n");
     printf("5. tri rapide\n\n");
     scanf("%d",&x);

     switch (x){
            case 1:printf("\nVoici votre tableau apr%cs un tri bull  :\n",138);tri_bull(tab,n);break;
            case 2:printf("Voici votre tableau apr%cs un tri par selection :\n",138);tri_selection(tab,n);break;
            case 3:printf("Voici votre tableau apr%cs un tri par insertion :\n",138);tri_insertion(tab,n);break;
            case 4:printf("Voici votre tableau apr%cs un tri par fusion :\n",138);tri_fusion(tab,0,n-1);break;
            case 5:printf("Voici votre tableau apr%cs un tri rapide :\n",138);tri_rapide(tab,0,n-1);break;
            default: printf("\nla valeur entrer ne figure pas dans la liste.\n"); printf("Voici votre tableau avant le tri :\n");
            }

    //NB: tri_fusion(tab,0,n-1); //on envoi un tableau(son nom)=>"tab"<= qui commence par (indice du 1er élément) 0 et se termine par (indice du dernier élément)n-1.

   for(i=0;i<=n-1;i++){printf("%2d|",tab[i]);} // pour afficher le resultat final.
   printf("\n\nMerci;)\n");

    return 0;
}
