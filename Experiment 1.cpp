//Experiment 1
//UID: 24BCS12643


// 1. Recurrence Relation: T(n)=3T(n/2​)+O(nlogn)

// 2. Master Theorem Complexity: T(n) = O(n^log​3 base2)
// It is the CASE 1 of master theorem where f(n) = O(n^loga-ε base b)



// 3. Modified Code for Opr count, Recursion Depth and Execution Time:

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long operations = 0;
int maxDepth = 0;

void complexRec(int n, int depth) {

    maxDepth = max(maxDepth, depth);

    if (n <= 2) {
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }

    reverse(small.begin(), small.end());
    operations += n;

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {

    vector<int> testSizes = {16, 32, 64, 128};

    for (int n : testSizes) {

        operations = 0;
        maxDepth = 0;

        auto start = high_resolution_clock::now();
        complexRec(n, 1);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);

        cout << "Input Size n = " << n << endl;
        cout << "Operations Count = " << operations << endl;
        cout << "Maximum Recursion Depth = " << maxDepth << endl;
        cout << "Execution Time = " << duration.count() << " ms" << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}
