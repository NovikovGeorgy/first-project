#include<iostream>
#include<cstdlib>
#include<time.h>
void swap(int* a, int* b){
	if (a != b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	}
}

int getMax(int* ar, int size){
	int right = size-1;
	int left = 0;
	while (left != right){
		while(ar[right] <= ar[left] && left != right){right--;}
		while(ar[left] <= ar[right] && left != right){left++;}
	}
	return right;
}

int getMin(int* ar, int size){
        int right = size-1;
        int left = 0;
        while (left != right){
                while(ar[right] >= ar[left] && left != right){right--;}
                while(ar[left] >= ar[right] && left != right){left++;}
        }
        return right;
}

void showEl_matrix(int* ar, int size, char del = ' ', int col = 10){
	for (int i = 0; i<size; i++){
		std::cout << ar[i] << del;
		if ((i+1)%col == 0 && i+1 != size){std::cout << '\n';}
	}
	std::cout << '\n';
}


void sortEl_I(int* ar, int size){
	int max;
	for (int i = size; i>1; i--){
		max = getMax(ar,i);
		swap(&ar[max], &ar[i-1]);
	}
}

void sortEl_D(int* ar, int size){
     int min;
      for (int i = size; i>1; i--){
         min = getMin(ar,i);
         swap(&ar[min], &ar[i-1]);
     }
}

void selectionSort_mod(int* ar, int size){
	int left = 0;
	int s  = size-1;
	int max;
	int min;
    for (;s > 1; s-=2, left++){
		max = getMax(ar+left, s+1) + left;
		min = getMin(ar+left, s+1) + left;
		swap(&ar[left], &ar[max]);
		swap(&ar[left+s], &ar[min]);
	}  
}


int main(){
	srand(time(NULL));
	int ar[101];
	for (int i = 0; i<101; i++){
		ar[i] = rand()/10000000;
	}
	showEl_matrix(ar, 101);
	sortEl_I(ar, 101);
	showEl_matrix(ar, 101);
	sortEl_D(ar, 101);
	showEl_matrix(ar, 101);
}
