#include <stdio.h>
#include <stdlib.h>

void generate_primes(int n, int v[], int number_of_primes ){
    /*
    tis function finds the all the prime numbers less than a given number n
    using the Sieve of Eratosthenes
    */
    if ( n == 0 || n == 1 ) return;
    int primes[n];
    primes[0] = 0;
    primes[1] = 0;
    int i;
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
    number_of_primes = 0;
    for ( i = 0; i < n; i++ ){
        if ( primes[i] == 1 ){
            v[number_of_primes] = i;
            number_of_primes ++;
        }
    }
    for ( i =0; i < number_of_primes; i++ )
        printf(" %d",v[i]);
}

void print_subsequence(int v[], int pos1, int pos2 ){
    /*
    this functions prints a subsequence found between the two given indexes as parameters
    */
    printf("%d", pos1);
    printf(" %d", pos2);
    printf("The sequence of numbers is: ");
    int i;
    for ( i = pos1; i <= pos2; i++ )
        printf(" %d", v[i]);
}

void determine_subsequence(int v[], int n, int pos1, int pos2 ){
    //function to determine the positions of the start/end of the increasing continuous subsequence
    //in the vector
    if ( n == 0 ) return;
    int i = 0;
    pos1 = 0;
    pos1 = 0;
    int lmax = 0;
    while (i < n - 1){
        int p1 = i;
        int p2 = p1 + 1;
        while ( v[p2] > v[p2-1] && p2 < n ) p2 ++;
        if ( p2 - p1 > lmax ){
            lmax = p2 - p1;
            pos2 = p2-1;
            pos1 = p1;
        }
        i = p2;
    }
    print_subsequence(v, pos1, pos2);
}

int main()
{
    int v[100], n;
    int ok = 1;
    while(ok == 1){
        printf("Choose your option: \n 1.Generate all primes smaller than a given number; \n 2.Find the longest increasing subsequence in a vector; \n 3.Exit;\n");
    int command;
    scanf("%d", &command);
    if(command == 3) break;

    else if (command == 1){
    int number_of_primes = 0;
    printf("Give the number n: \n");
    scanf("%d", &n);
    int v[n];
    printf("N is:%d ", n);
    printf("The prime numbers less than the given number are: \n");
    generate_primes(n, v, number_of_primes);
    printf("\n\n");
    }

    else if (command == 2){
    printf("How many numbers are in the vector? Enter n: ");
    scanf("%d", &n);
    printf("Give the vector of numbers: ");
    int i;
    for ( i = 0; i < n; i ++)
        scanf("%d", &v[i]);
    int pos1, pos2;
    determine_subsequence(v, n, pos1, pos2);
    printf("\n\n");
    }
    else printf("Invalid command!\n");
    }
    return 0;
}
