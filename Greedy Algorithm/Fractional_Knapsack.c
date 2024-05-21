#include<stdio.h>
struct sack{
    double cost;
    double weight;
    double ratio;
};
void knapsack(struct sack *s, int n_objects, int sack_capacity);
void sort(struct sack *s, int n);

void knapsack(struct sack *s, int n_objects, int sack_capacity){
    double total_profit=0.0, total_weight=0.0;
    for(int i=0; i<n_objects; i++){   
        if(sack_capacity==0){  //If knapsack capacity is zero --->break
            break;
        }
        if(s[i].weight<sack_capacity){ //if knapsack capacity > object weight
            total_profit+=s[i].cost;
            sack_capacity-=s[i].weight;
        }else{                          //if knapsack capacity < object weight
            double temp = s[i].weight;
            s[i].weight = sack_capacity;
            total_profit += (s[i].cost*sack_capacity)/temp;
            sack_capacity -= s[i].weight;
        }
    }
    printf("Weight Remaining: %lf\n",sack_capacity);
    printf("Final Price: %lf",total_profit);
    
}
void sort(struct sack *s, int n){
    // int max = s[0].ratio;
    int flag;
    for(int i=0; i<n-1; i++){
        flag = 0;
        for(int j=0; j<n-i-1; j++){
            if(s[j].ratio<s[j+1].ratio){
            struct sack temp = s[j];
            s[j] = s[j+1];
            s[j+1] = temp;
            flag = 1;
            }
        }
        if(flag==0){
            break;
        }
        
    }
    
}
int main(){
    struct sack s[10];
    int n,c;
    printf("Enter the number of objects: "); //No of objects
    scanf("%d",&n);
    printf("Enter the knapsack capacity: "); //Knapsack Capacity
    scanf("%d",&c);
    printf("-------------Enter the costs and weights of the objects----------\n"); //Cost and Weight of each object
    for(int i=0; i<n; i++){
        printf("Enter the cost of object - %d: ",i+1);
        scanf("%lf",&s[i].cost);
        printf("Enter the weight of object - %d: ",i+1);
        scanf("%lf",&s[i].weight);
        s[i].ratio = s[i].cost/s[i].weight;
    }
    sort(s, n);  //Sorting the objects in ascending order according to profit-weight ratio.
    knapsack(s, n, c);
    return 0;
}