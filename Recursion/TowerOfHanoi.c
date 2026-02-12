#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c → %c\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move remaining disk to destination
    printf("Move disk %d from %c → %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    printf("\nSteps to solve Tower of Hanoi:\n\n");
    towerOfHanoi(n, 'A', 'B', 'C');
    
    // Using %lld for long long to handle larger numbers of moves
    printf("\nTotal moves required = %lld\n", (1LL << n) - 1); // (2^n - 1)
    
    return 0;
}
