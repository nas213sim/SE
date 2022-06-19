#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
struct args{
  int x, y;
};
void *prod(void *arg){
    int *prod1;
    int x = ((struct args*)arg)->x;
    int y = ((struct args*)arg)->y;
    prod1 = x * y;
    pthread_exit((void*)prod1);
}
int main(){
    struct args *prod1 = (struct args *)malloc(sizeof(struct args));
    int a,b,c,d;
    struct args *prod2 = (struct args *)malloc(sizeof(struct args));
    int somme, res1, res2;
    pthread_t thread1,thread2;
    printf("Donnez les valeurs de a et b pr calculer leur produit: ");
    scanf("%d %d",&a,&b);
    prod1->x = a;
    prod1->y = b;
    res1 = pthread_create(&thread1, NULL, prod, (void*) prod1);
    printf("Donnez les valeurs de c et d pr calculer leur produit: ");
    scanf("%d %d",&c,&d);
    prod2->x = c;
    prod2->y = d;
    res2 = pthread_create(&thread2, NULL, prod, (void*) prod2);
    if(res1 != 0 && res2 != 0){
    fprintf(stderr, "Erreur de creation du thread");
    exit(1);
    }
    pthread_join(thread1, (void*)&res1);
    pthread_join(thread2, (void*)&res2);
    somme = res1 + res2;
    printf("la somme total entre ces 2 produits est : %d\n",somme);
    return 0;
}
