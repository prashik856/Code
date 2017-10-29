//We have our array as arr[];

void sort(int *arr,int n,int low,int high){
	if(low>=high) return	
	if(low<high){
		mid=(low+high)/2;
		sort(arr,n,low,mid);
		sort(arr,n,mid+1,high);
		merging(arr,n,low,mid,high);
		}
	}

void merging(int *arr,int n, int low, int mid, int high){
	int l1,l2,i=low;
	int b[n];
	for(l1=low,l2=mid+1,i=low; l1<=mid && l2<=high; i++){
		if(arr[l1]<arr[l2]) b[i]=a[l1++];
		else b[i]=arr[l2++];
		}
	while(l1<=mid) b[i++]=arr[l1++];
	while(l2<=high) b[i++]=arr[l2++];
	for(int i=low; i<=high; i++) b[i]=a[i];
	}
