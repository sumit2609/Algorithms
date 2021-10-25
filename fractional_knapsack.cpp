#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool static cmp(Item i1, Item i2){
    double x = i1.value/(double)i1.weight;
    double y = i2.value/(double)i2.weight;

    return x>y;
}

double fractionalKnapsack(int w, Item arr[], int n)
{
    sort(arr,arr+n,cmp);

    double maxValue = 0;
    int currWeight = 0;

    for(int i = 0; i<n; i++){
        if(currWeight+arr[i].weight<=w){
            currWeight += arr[i].weight;
            maxValue += arr[i].value;
        }else{
            int remain = w-currWeight;
            maxValue += (arr[i].value/(double)arr[i].weight) * remain;
            break;
        }
    }
    
    return maxValue;
}


int main(){
    int n,w;

    cin>>n>>w;
    Item arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i].value>>arr[i].weight;
    }

    cout<<fractionalKnapsack(w,arr,n);

}
