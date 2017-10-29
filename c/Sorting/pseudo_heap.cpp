int main(){
arr[n];
heap(arr,n);
}

void heap(int *arr, int n){
	for(int i=n/2-1; i>=0; i--){
		heapify(arr,n,i)
		}
	for(int i=n-1; i>=0; i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
		}
	}

void heapify(int arr, int n, int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[longest]) longest=l;
	if(r<n && arr[r]>arr[longest]) longest=r;
	if(longest!=i) swap(arr[i],arr[longest]);
	heapify(arr,n,longest);	
	}
