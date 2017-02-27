#include <stdio.h>
#include <stdlib.h>

void generate_eratosthenes(int v[], int* number_of_primes){
//function to generate all the prime numbers between 1 and 100000
//first generate the prime numbers between 1 and 300, extract the primes and then repeat the procedure
//regarding the value of n in other function
    int i;
    int primes[1000];
    primes[0] = 0;
    primes[1] = 0; int n=1000;
    for ( i = 2; i < n; ++i ){
        primes[i] = 1;
    }

    for ( i = 2; i < n; i++ ){
        if ( primes[i] == 1 ){
            int k = 2*i;
            while ( k < n ){
                primes[k] = 0;
                k += i;
            }
        }
    }
    *number_of_primes = 0;
    for ( i = 0; i < n; i++ ){
        if ( primes[i] == 1 ){
            v[*number_of_primes] = i;
            (*number_of_primes) ++;
        }
    }
    }

void print_array(int v[], int length){
printf("The array is: \n");
int i;
for ( i = 0; i < length; ++i ) printf("%d   ", v[i], " ");
}

void find_additional_primes(int v[], int number_of_primes, int step_count){
//this function finds the next primes found between the indexes number_of_primes and 2*number_of_primes
//using the same principle of eratosthenes sieve
//step_count represents the stage in the process at which we are found to know from where to start with indexing
int i ;
int primes[301];

for ( i = 0; i < 301; ++i ){primes[i] = 1;}
int counter = (step_count-1)*301;
for ( i = 0; i < number_of_primes; ++i ){
    int k = 2*v[i];
    while ( k < step_count*301 ){
        primes[k-counter] = 0;
        k += v[i];
    }

}
    for (i=0; i < step_count*301; ++i ){
        if ( primes[i] == 1 ){ v[number_of_primes] = i; number_of_primes ++;  }
    }
}

void run_prime_menu(){
    int n;
    printf("\n Give the number of prime numbers you wish to generate: ");
    scanf("%d", &n);
    if ( n <= 0 ){
    printf("There is no prime number less than 0!");
    return;}
    if ( n == 1 ){ printf("2 \n"); return;}
    int number_of_primes=0, v[1000];
    int *p = &number_of_primes;
    generate_eratosthenes(v, p);
        print_array(v, n);
}

int cmmdc( int a, int b ){
    while ( a != b && a != 1 && b != 1 ){
        if ( a > b ){a = a%b; b = a; } else { b = b % a; a = b; }
    } return a;
}

void determine_subsequence(int v[], int n, int* p, int* q){
    if ( n == 0 ) {printf("There is no number in the vector..."); return;}
    if ( n == 1 ) return v[0];
    int p1 = 0, p2 = 0;
    int maxdist = 0;
    while( n - p2 > maxdist ){
        ++ p2;
        while ( p2 < n && cmmdc(v[p2], v[p2-1]) == 1 ){
            ++ p2;
        }
        if ( p2 - p1 > maxdist ){ maxdist = p2 - p1; *p = p1; *q = p2; }
    }
}

void print_subsequence(int pos1, int pos2, int v[]){
printf("\n\nThe subsequence is: \n");
int i;
for ( i = pos1; i <= pos2; ++i ) printf("%d  ", v[i]);
}

void run_sequence_menu()
{
    printf("Give the length of the vector: ");
    int n;
    scanf("%d", &n);
    printf("\n\n Now give the elements of the vector: \n");
    int v[n+1];
    int i;
    for ( i= 0; i < n; ++i ) scanf("%d", &v[i]);
    int pos1 = 0, pos2 = 0;
    int *p = &pos1, *q = &pos2;
    determine_subsequence(v, n, p, q);
    print_subsequence(pos1, pos2, v);
}

int main()
{
    int ok = 1;
    printf("---");
printf("%d", cmmdc(12, 14));
    while(ok == 1){
        printf("Choose your option: \n 1.Generate the first n prime numbers \n 2.Find the longest continuous subsequence in a vector of relatively prime numbers; \n 3.Exit \n");
        int option;
        scanf("%d", &option);
        if ( option == 1 ){
            int v[11];
                run_prime_menu();}
        else if (option == 2)
            run_sequence_menu();
        else if ( option == 3 )
            break;
        else printf("-Unavailable option-");
    }
    return 0;
}
