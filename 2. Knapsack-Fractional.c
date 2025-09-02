#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//structure to store the value and weight of each item
typedef struct Item{
    int val,wt;
}Item;

//Comparator function to sort items by value-to-weight ratio (descending order)
int comparator(const void* item1,const void* item2);
double knapSack(int W,Item items[],int n);


int main(){
    int n,W;
    //total capacity of the knapsack
    printf("\nEnter the weight of the bag: ");
    scanf("%d",&W);
    //number of items
    printf("\nEnter the number of entries: ");
    scanf("%d",&n);
    Item *items=(Item*)malloc(sizeof(Item)*n);
    //reading weights of all items
    printf("\nEnter the Weight of all entries: ");
    for(int i=0;i<n;i++){
        scanf("%d",&items[i].wt);
    }
    //reading values of all items
    printf("\nEnter the value of all entries: ");
    for(int i=0;i<n;i++){
        scanf("%d",&items[i].val);
    }

    double ans=knapSack(W,items,n);
    printf("%f",ans);
    free(items);
    return 0;
}

double knapSack(int W,Item items[],int n){
    //Sort items based on value-to-weight ratio in descending order
    qsort(items,n,sizeof(Item),comparator);
    int currentWt=0;// Current weight in knapsack
    double finalValue=0.0;// Total value accumulated
    for(int i=0;i<n;i++){
        // If full item can be included in knapsack
        if(currentWt+items[i].wt<=W){
            currentWt+=items[i].wt;
            finalValue +=items[i].val;
        }
        //If only a fraction of the item can be included
        else{
            int remain=W-currentWt;
            finalValue+=items[i].val*((double)remain/items[i].wt);
            break;//Since knapsack is full
        }
    }
    return finalValue;
}

int comparator(const void* item1,const void* item2){
    Item* a=(Item*)item1;
    Item* b=(Item*)item2;
    //Computing value-to-weight ratio of both items
    double r1=(double)(a->val)/(a->wt);
    double r2=(double)(b->val)/b->wt;
    //sorting in descending order
    return r1>r2?-1:1;
}