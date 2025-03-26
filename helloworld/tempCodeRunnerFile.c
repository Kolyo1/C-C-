void AlternatingPattern(int n, int arr[]){
    int pattern = 1;
    for(int i = 1; i < n-1; i++){
        if (!((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]))){
            pattern = 0;
            break;
        }
    }
    if (pattern)
    {
        printf("The array has an alternating pattern\n");
    }
    else{
        printf("The array does not have an alternating pattern\n");
    }
    
}