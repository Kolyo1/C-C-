#include <stdio.h> 
#include <math.h>
void GetSum(int n){
    int sum = 0;
    int num;
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        if( -5000<= num && num <= 5000){
            arr[i] = num;
            sum += arr[i];
        }
    }
    printf("Sum: %d\n", sum);
}

void GetMax(int n){
    int max = -5000;
    int num;
    int arr[n];
    for(int i = 0; i<n;i++){
        scanf("%d", &num);
        if(-5000 <= num && num <= 5000){
            arr[i] = num;
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("Max numbe: %d\n", max);
}

void GetAvg(int n){
    int sum = 0;
    int num;
    int arr[n];
    for(int i = 0; i<n;i++){
        scanf("%d", &num);
        if(-5000 <= num && num<= 5000){
            arr[i] = num;
            sum += arr[i];
        }
    }
    printf("Average: %.3f\n", sum / (double)(n));
}

void GetCenter(int n){
    int num, sum = 0;
    int arr[n];
    for(int i = 0; i<n;i++){
        scanf("%d", &num);
        if(-5000 <= num && num <= 5000){
            arr[i] = num;
            sum += arr[i];
        }
    }
    double avg = sum / (double)(n);
    int center = arr[0];
    int centerIndex = 0;
    double minDiff = fabs(avg - arr[0]);
    for (int i = 1; i < n; i++){
        double diff = fabs(avg - arr[i]);
        if(diff < minDiff){
            minDiff = diff;
            center = arr[i];
            centerIndex = i;
        }
    }
    printf("средна стойност : %.2f.\n Най-близка стойност %d на %d-то място\n", avg,center,centerIndex+1);
}

int main(){
    int n;
    scanf("%d", &n);
    //GetSum(n);
    //GetMax(n);
    //GetAvg(n);
    GetCenter(n);
    return 0;
}