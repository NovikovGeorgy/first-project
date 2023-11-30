#include<iostream>
#include<cstdlib>
#include<time.h>
int getMax(const int* ar, int size){
    int right = size-1;
    int left = 0;
    while (right != left){
        while (ar[right] <= ar[left] && right != left) {right--;}
        while (ar[left] <= ar[right] && right != left) {left++;}   
    }
    return right;
}

int getMin(const int* ar, int size){
    int right = size-1;
    int left = 0;
    while (right != left){
        while (ar[right] >= ar[left] && right != left) {right--;}
        while (ar[left] >= ar[right] && right != left) {left++;}   
    }
    return right;
} 

void showEl_line(const int* ar, int size, char del = ' ') {
    for (int i=0; i<size; i++){std::cout << ar[i] << del;}
    std::cout << '\n';
}

void showEl_matrix(const int* ar, int size, char del = ' ', int col = 5) {
	for (int i=0; i<size; i++){
		std::cout << ar[i] << del;
		if ((i+1)%col == 0){ std::cout << '\n';}
	}
	std::cout << '\n';
}


void swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void Sortarr(int* ar, int size){
	for (; size >1; size--){
		int max = getMax( ar, size);
		if (size-1 != max){
			swap(&ar[max], &ar[size-1]);
		}
	}
}

int main(){
	srand(time(NULL));
	int ar[100];
	for (int i = 0; i<100; i++){ ar[i] = rand()/1000000;}
	std::cout << getMin(ar, 100) << "\n";
	std::cout << getMax(ar,  100) << "\n";
	showEl_matrix(ar, 100, ' ');
	std::cout << '\n';
    swap(&ar[5], &ar[10]);
	showEl_matrix(ar, 100, ' ');
	std::cout << '\n';
	Sortarr( ar, 100);
    showEl_matrix(ar, 100, ' ');
}	
