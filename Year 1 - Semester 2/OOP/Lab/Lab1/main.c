#include<stdio.h>
#include<stdlib.h>
#define N 20

int is_prime(int val) {
	/*
	* :param val: positive integer
	* : return: 0 if the number is not prime, 1 otherwise
	*/
	if(val == 0 || val == 1 || (val != 2 && val % 2 == 0))
		return 0;

	for(int d = 3; d * d <= val; d += 2)
		if(val % d == 0)
			return 0;

	return 1;
}

int* all_prime_numbers_smaller_than_n(int n){
	/*
	* :param n: positive integer, the value until which will be generated the prime numbers
	* :return : a pointer, list of integers, each value of the list being a prime number
	*/
	int* prime_list = (int*)malloc(sizeof(int) * 0);
	int lenght = 0;
	for(int curr_val = 2; curr_val < n; curr_val++)
		if(is_prime(curr_val)){
			lenght++;
			int* tmp = (int*)realloc(prime_list, lenght * sizeof(int));
			if(tmp){
				prime_list = tmp;
			}
			*(prime_list + lenght - 1) = curr_val;
		}
	return prime_list;
}

int nr_prime_nr_until_n(int n){
	/*
	* :param n: positive integer, the value until we must to search
	* :return : the number of prime number until n
	*/
	int nr = 0;
	for(int curr_val = 2; curr_val < n; curr_val++)
		if(is_prime(curr_val))
			nr++;
	return nr;
}

int* longest_subsequence_with_sum_of_2nr_prime(int* v, int n, int* lung) {
	/*
	* :param v: a list of integers
	* :param n: the length of the list
	* :param lenght: the lenght of the subsequence
	*  return : pointer, the maximum subsequence of elements of the array
	*			containing where each element contain the same digits as the other ones.
	*/
	int l[101] = {0}, u[101] = {0};
	l[n - 1] = 1, u[n - 1] = -1;
	for(int i = n - 2; i >= 0; i--) {
		l[i] = 1, u[i] = -1;
		for(int j = i + 1; j < n; j++) {
			int a = *(v + i), b = *(v + j);
			if(is_prime(a+b) == 1 && l[i] < l[j] + 1) {
				l[i] = l[j] + 1;
				u[i] = j;
			}
		}
	}

	int pmax = 0;
	for(int i = 0; i < n; i++)
		if(l[pmax] < l[i]){
			pmax = i;
		}

	*lung = l[pmax];
	int i = 0;
	int* list = (int*)malloc(sizeof(int) * l[pmax]);
	if(list == NULL)
		return NULL;

	printf("\n");
	while(pmax != -1)
	{
		*(list + i) = *(v + pmax);
		i++;
		pmax = u[pmax];
	}
	return list;
}

void print_array(int v[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

void a(){
	int n;
	printf("Enter n: "); scanf_s("%d", &n); printf("\n");
	int nr = nr_prime_nr_until_n(n); // 8 prime numbers smaller than 20
	int* v = (int*)malloc(sizeof(int) * nr);
	v = all_prime_numbers_smaller_than_n(n);
	print_array(v, nr);
}

void b(){
	int n;
	int v[100]; // 3, 1, 6, 7, 4, 5, 8, 1, 4; sequences: 1, 6, 7, 4 , 1, 4

	printf("Enter size: "); scanf_s("%d", &n); printf("\n");
	printf("Read elements:\n");
	for(int i = 0; i < n; i++){
		printf("Enter v[%d] = ", i); scanf_s("%d", &v[i]); printf("\n");
	}
	int subsLength = 0;
	int* subs = (int*)malloc(n * sizeof(int));
	subs = longest_subsequence_with_sum_of_2nr_prime(v, n, &subsLength);
	print_array(subs, subsLength);

}
int menu(){
	while(1){
		printf("1. Generate all the prime numbers smaller than a given natural number n.\n2.Given a vector of numbers, find the longest increasing subsequence, such the sum of that any 2 consecutive elements is a prime number.\n3.Exit\n");
		int option;
		printf("Enter n (1, 2, 3): "); scanf_s("%d", &option); printf("\n");
		if(option == 1){
			a();
		}
		else if(option == 2){
			b();
		}
		else if(option == 3){
			break;
		}
		else{
			printf("\nWrong option, try again!!\n");
		}
	}
}
int main(int argc, char** argv[]){

	menu();
}