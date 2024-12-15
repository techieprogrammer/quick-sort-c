#include<stdio.h>
int Arr[] = {43,45,98,23,21,5,1,8,2,6,77,18,4};

int pivot(int *Arr,int low,int high) {
    int v = Arr[high];
    int i, s, j = low;
    for(i = low;i < high;i++) {
        if(Arr[i] <= v) {
            s = Arr[j];
            Arr[j] = Arr[i];
            Arr[i] = s;
            j = j+1;
        }
    }
    s = Arr[j];
    Arr[j] = Arr[high];
    Arr[high] = s;
    return j;
}

void quicksort(int *Arr,int low,int high) {
    if(low < high) {
        int p = pivot(Arr,low,high);
        quicksort(Arr,low,p - 1);
        quicksort(Arr,p + 1, high);
    }
}

int main() {
    int i, n = sizeof(Arr)/sizeof(Arr[0]);
    printf("Before Sort:\n");
    for(i = 0;i < n;i++) {
        printf("%d ",Arr[i]);
    }
    printf("\n");
    
    quicksort(Arr,0,n-1);

    printf("After Sort:\n");
    for(i = 0;i < n;i++) {
        printf("%d ",Arr[i]);
    }
    printf("\n");
    return 0;
}