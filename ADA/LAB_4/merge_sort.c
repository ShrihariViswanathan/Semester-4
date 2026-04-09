#include<stdio.h>


void merge(int s, int m, int e, int arr[]){
    int i = s; 
    int j = m+1;
    int k = 0;
    int final[e-s+1];

    while(i <= m && j <= e){
        
        if (arr[i] <= arr[j]){
            final[k] = arr[i];
            i++;
        } 

        else {
            final[k] = arr[j];        
            j++;
        }
        
        k++;
    }

    while (i <= m){
        final[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= e){
        final[k] = arr[j];        
        j++;
        k++;
    }

    for(int i = s; i <= e; i++){
        arr[i] = final[i - s];
    }

}


void merge_sort(int start, int end, int arr[]){
    if (start == end) {
        int *res = malloc(sizeof(int));
        res[0] = arr[start];
        return;
    }

    int mid = (start + end) / (int) 2;
    merge_sort(start, mid, arr);
    merge_sort(mid+1, end, arr);
    

    merge(start, mid, end, arr);

}




int main(){
    int n;
    printf("No.of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }


    merge_sort(0, n, arr);

    for (int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}
