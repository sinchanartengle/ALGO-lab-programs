#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
// Function to read input into an array
// void read(int arr[],int n);

// Recursive 0/1 Knapsack function
int knapsack(int ind,int W,int wt[],int val[]);

int main() {
    srand(time(0));
    int W=0,n=10;
    FILE *f;
    clock_t t;
    f=fopen("KnapAvg.txt","a");
    int *val=NULL,*wt=NULL;
    while(n<=130){
        //Allocating Space Dynamically
        val=(int*)malloc(sizeof(int)*n);
        wt=(int*)malloc(sizeof(int)*n);
        //Average Case
        for(int i=0;i<n;i++){
            val[i]=rand()%n;
            wt[i]=rand()%n;
        }   
        //Knapsack Size
        W=n;
        t=clock();
        knapsack(n-1,W,wt,val);
        t=clock()-t;
        fprintf(f,"%d\t%f\n",n,(float)t/CLOCKS_PER_SEC);
        printf("%d\t%f\n",n,(float)t/CLOCKS_PER_SEC);
        free(val);
        free(wt);
        n+=20;
    }
    fclose(f);
    return 0;
}
int knapsack(int ind,int W,int wt[],int val[]){
    //Base Case
    if(ind==0){
        if(wt[0]<=W)
            return val[0];
        return 0;
    }
    // Do not take current item
    int notTake=0+knapsack(ind-1,W,wt,val);
    int take=INT_MIN;
    //Take current item (if it fits)
    if(wt[ind]<=W){
        take=val[ind]+knapsack(ind-1,W-wt[ind],wt,val);
    }
    // Return the maximum of both choices
    return take>notTake?take:notTake;
}

/*
Space Complexity = O(n) (recursive stack space)
Time Complexity = O(2ⁿ)
https://media.geeksforgeeks.org/wp-content/uploads/20250312122618748210/Recursion-Tree-for-01-KnapSack-2.webp
*/

/*
void read(int arr[],int n){
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

int main() {
    int W,n;
    // Reading the total capacity of the knapsack
    printf("\nEnter the weight of the bag: ");
    scanf("%d",&W);
     // Reading the number of items
    printf("\nEnter the number of elements in array: ");
    scanf("%d",&n);
    //Allocating Space Dynamically
    int* val=(int*)malloc(sizeof(int)*n);
    int* wt=(int*)malloc(sizeof(int)*n);
    // Reading weights and values
    printf("\nEnter the elements of Weight Array: ");
    read(wt,n);
    printf("\nEnter the elements of corresponding Values(Profit) Array: ");
    read(val,n);
    printf("The Max. Profit is: %d",knapsack(n-1,W,wt,val));
    // Freeing dynamically allocated memory
    free(val);
    free(wt);
    return 0;
}
*/