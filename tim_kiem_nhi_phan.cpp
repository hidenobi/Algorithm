#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int Arr[], int left,int right, int x){
    
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (Arr[mid] == x)
            return mid; 
        if (Arr[mid] > x)
            right = mid - 1; 
        else if (Arr[mid] < x)
            left = mid + 1; 
    }
    return -1; 
}
int partition (int arr[], int low, int high){
    int pivot = arr[high];    
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
void quickSort(int arr[], int low, int high){
    if (low < high){
       int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(){
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n,x;
	cin >> n >> x;
	int a[n];
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	quickSort(a, 0, n-1);
	if(BinarySearch(a,0,n-1,x)!=-1) cout <<BinarySearch(a,0,n-1,x)+1;
	else cout <<"NO";
	cout<<endl;
	}
	return 0;
}