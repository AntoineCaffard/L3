#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct _stat{
    int nb_perm;
    int nb_comp;
} stat;


void createList(int tab[], int size){
    int i;
    
    for(i=0; i<size ;i++){
        tab[i] = rand() % 1000;
    }
}

void displayList(int tab[],int size){
    printf("\n");
    for(int i = 0; i<size;i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

unsigned int isSorted(int tab[], int size){
    int before = 0;
    int actual = 1;
    while(actual != size){
        if(tab[actual]<tab[before]){
            return 0;
        }
        before++;
        actual++;
    }
    return 1;
}

void selectionSort(int tab[],int size,stat* result){
    int i,j,c;
    result -> nb_comp = 0;
    result -> nb_perm = 0;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            result -> nb_comp ++;
            if ( tab[i] > tab[j] ) {
                c = tab[i];
                result -> nb_perm++;
                tab[i] = tab[j];
                result -> nb_perm++;
                tab[j] = c;
                result -> nb_perm++;
            }
        }
    }
}

void insertionSort(int tab[],int size, stat* result){
    int i,j,k,c;
    result -> nb_comp = 0;
    result -> nb_perm = 0;
    for(i=1;i<size;i++) {
        result -> nb_comp ++;
        if ( tab[i] < tab[i-1] ) { 
            j = 0;
            while ( tab[j] < tab[i] ) j++; 
            result -> nb_perm++;
            c = tab[i]; 
            for( k = i-1 ; k >= j ; k-- ){ 
                result -> nb_perm++;
                tab[k+1] = tab[k];
            }
            result -> nb_perm++;
            tab[j] = c; 
        }
    }   
}

void bubbleSort(int tab[], int size, stat* result){
    int i,j,tmp;
    result -> nb_comp = 0;
    result -> nb_perm = 0; 
    for (i=0 ; i < size-1; i++){
        for (j=0 ; j < size-i-1; j++){
            result -> nb_comp++;
            if (tab[j] > tab[j+1]) {
                result -> nb_perm++; 
                tmp = tab[j];
                result -> nb_perm++; 
                tab[j] = tab[j+1];
                result -> nb_perm++; 
                tab[j+1] = tmp;
            }
        }
    }
}

void fusion(int tableau[],int deb1,int fin1,int fin2,stat* result){
    int *table1;
    int deb2=fin1+1;
    int compt1=deb1;
    int compt2=deb2;
    int i; 
    table1=malloc((fin1-deb1+1)*sizeof(int));

    for(i=deb1;i<=fin1;i++){
        table1[i-deb1]=tableau[i];
        result->nb_perm++;
    }
                        
    for(i=deb1;i<=fin2;i++){        
        if (compt1==deb2){
            result->nb_comp++;
            break;
        } else if (compt2==(fin2+1)) {
            result->nb_comp+=2;
            tableau[i]=table1[compt1-deb1]; 
            result->nb_perm++;
            compt1++;
        } else if (table1[compt1-deb1]<tableau[compt2]) {
            result->nb_comp+=3;
            tableau[i]=table1[compt1-deb1];
            result->nb_perm++;
            compt1++;
        } else {
            result->nb_comp+=3;
            tableau[i]=tableau[compt2]; 
            result->nb_perm++;
            compt2++;
        }
    }
    free(table1);
}
        

void tri_fusion_bis(int tableau[],int deb,int fin, stat* result){
    result -> nb_comp++;
    if (deb!=fin) {
        int milieu=(fin+deb)/2;
        tri_fusion_bis(tableau,deb,milieu,result);
        tri_fusion_bis(tableau,milieu+1,fin,result);
        fusion(tableau,deb,milieu,fin,result);
    }
}

void tri_fusion(int tableau[],int longueur, stat* result) {
    result -> nb_comp = 0;
    result -> nb_perm = 0;
    result -> nb_comp++;
    if (longueur>0){
        tri_fusion_bis(tableau,0,longueur-1,result);
    }
}

void echanger(int tableau[], int a, int b,stat* result)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
    result -> nb_perm += 3;
}

void quickSort(int tableau[], int debut, int fin,stat*result)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];
    result->nb_comp++;
    if(debut >= fin)
        return;
    while(1)
    {
        do{
            droite--;
            result->nb_comp++;
        } while(tableau[droite] > pivot);
        do {
            result->nb_comp++;
            gauche++; 
        }while(tableau[gauche] < pivot);
        result->nb_comp++;
        if(gauche < droite)
            echanger(tableau, gauche, droite,result);
        else break;
    }
    quickSort(tableau, debut, droite,result);
    quickSort(tableau, droite+1, fin,result);
}

  void swap(int *a, int *b,stat* result) {
    int temp = *a;
    *a = *b;
    *b = temp;
    result->nb_perm+=3;
  }
  
  void heapify(int tab[], int n, int i,stat* result) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    result -> nb_comp++;
    if (left < n && tab[left] > tab[largest])
      largest = left;
    result -> nb_comp++;
    if (right < n && tab[right] > tab[largest])
      largest = right;
    result -> nb_comp++;
    if (largest != i) {
      swap(&tab[i], &tab[largest],result);
      heapify(tab, n, largest,result);
    }
  }
  
  void heapSort(int tab[], int n,stat* result) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(tab, n, i,result);
    for (int i = n - 1; i >= 0; i--) {
      swap(&tab[0], &tab[i],result);
      heapify(tab, i, 0,result);
    }
  }

void test(unsigned int nb_listes, unsigned int taille_mini, unsigned int nb_expression){
    int n,m;
    stat result[5][nb_listes*taille_mini+1];
    for(n = 0; n<5; n++){
        for(m = 0; m<=nb_listes*taille_mini;m++){
            result[n][m].nb_comp=0;
            result[n][m].nb_perm=0;
        }
    } 
    FILE *file;
    file = fopen("tp1.csv","w+");
    int i,j;
    int indice = 0;
    printf("Tri Insertion : \n");
    fprintf(file,"Tri Insertion : ",NULL);
    for(i=taille_mini; i<=nb_listes*taille_mini+1;i+=taille_mini){
        printf("\nTaille de %d \n",i);
        fprintf(file,"%d( ",i);
        int tab[i];
        for(j = 0; j< nb_expression; j+=1){
            createList(tab,i);
            insertionSort(tab,i,&result[0][indice]);
            printf("%d %d\n",result[0][indice].nb_comp, result[0][indice].nb_perm );
            fprintf(file,"%d,%d ",result[0][indice].nb_comp, result[0][indice].nb_perm );
            indice += 1;
        }
        fprintf(file,") ",NULL); 
    }
    printf("\n--------------------------------------\n\n");
    fprintf(file,"\n",NULL);
    indice = 0;
    printf("Tri Selection : \n");
    fprintf(file,"Tri Selection : ",NULL);
    for(i=taille_mini; i<=nb_listes*taille_mini+1;i+=taille_mini){
        int tab[i];
        printf("\nTaille de %d \n",i);
        fprintf(file,"%d( ",i);
        for(j = 0; j< nb_expression; j+=1){
            createList(tab,i);
            selectionSort(tab,i,&result[1][indice]);
            printf("%d %d\n",result[1][indice].nb_comp, result[1][indice].nb_perm );
            fprintf(file,"%d,%d ",result[1][indice].nb_comp, result[1][indice].nb_perm );
            indice += 1;
        }
        fprintf(file,") ",NULL); 
    }
    printf("\n--------------------------------------\n\n");
    fprintf(file,"\n",NULL);
    indice = 0;
    printf("Tri a Bulles : \n");
    fprintf(file,"Tri a Bulles : ",NULL);
    for(i=taille_mini; i<=nb_listes*taille_mini+1;i+=taille_mini){
        int tab[i];
        printf("\nTaille de %d \n",i);
        fprintf(file,"%d( ",i);
        for(j = 0; j< nb_expression; j+=1){
            createList(tab,i);
            bubbleSort(tab,i,&result[2][indice]);
            printf("%d %d\n",result[2][indice].nb_comp, result[2][indice].nb_perm );
            fprintf(file,"%d,%d ",result[2][indice].nb_comp, result[2][indice].nb_perm );
            indice += 1;
        }
        fprintf(file,") ",NULL);
    }
    printf("\n--------------------------------------\n\n");
    fprintf(file,"\n",NULL);
    indice = 0;
    printf("Tri Fusion : \n");
    fprintf(file,"Tri Fusion : ",NULL);
    for(i=taille_mini; i<=nb_listes*taille_mini+1;i+=taille_mini){
        int tab[i];
        printf("\nTaille de %d \n",i);
        fprintf(file,"%d( ",i);
        for(j = 0; j< nb_expression; j+=1){
            createList(tab,i);
            tri_fusion(tab,i,&result[3][indice]);
            printf("%d %d\n",result[3][indice].nb_comp, result[3][indice].nb_perm );
            fprintf(file,"%d,%d ",result[3][indice].nb_comp, result[3][indice].nb_perm );
            indice += 1;
        }
        fprintf(file,") ",NULL);
    }
    printf("\n--------------------------------------\n\n");
    fprintf(file,"\n",NULL);
    indice = 0;
    printf("Tri Rapide : \n");
    fprintf(file,"Tri Rapide : ",NULL);
    for(i=taille_mini; i<=nb_listes*taille_mini+1;i+=taille_mini){
        int tab[i];
        printf("\nTaille de %d \n",i);
        fprintf(file,"%d( ",i);
        for(j = 0; j< nb_expression; j+=1){
            createList(tab,i);
            tri_fusion(tab,i,&result[4][indice]);
            printf("%d %d\n",result[4][indice].nb_comp, result[4][indice].nb_perm );
            fprintf(file,"%d,%d ",result[4][indice].nb_comp, result[4][indice].nb_perm );
            indice += 1;
        }
        fprintf(file,") ",NULL);
    }
    printf("\n--------------------------------------\n\n");
    fprintf(file,"\n",NULL);
    indice = 0;
    printf("Tri par Tas : \n");
    fprintf(file,"Tri par Tas : ",NULL);
    for(i=taille_mini; i<=nb_listes*taille_mini+1;i+=taille_mini){
        int tab[i];
        printf("\nTaille de %d \n",i);
        fprintf(file,"%d( ",i);
        for(j = 0; j< nb_expression; j+=1){
            createList(tab,i);
            tri_fusion(tab,i,&result[5][indice]);
            printf("%d %d\n",result[5][indice].nb_comp, result[5][indice].nb_perm );
            fprintf(file,"%d,%d ",result[5][indice].nb_comp, result[5][indice].nb_perm );
            indice += 1;
        }
        fprintf(file,") ",NULL);
    }
    fclose(file);
}

int main(void){
    srand(time(NULL));
    test(2,10,2);
    return 0;
}