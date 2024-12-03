//{ Driver Code Starts
//Initial Template for C++
#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*Function to find diagonal sum
* N : size of array
* arr : input array
* Note : You have to mention argument also
*/
int diagonalSum(int** arr, int N) {
    int sum = 0;

    // Loop through the matrix and add primary and secondary diagonal elements
    for (int i = 0; i < N; i++) {
        sum += arr[i][i];         // Primary diagonal element
        sum += arr[i][N - 1 - i]; // Secondary diagonal element
    }

    // If N is odd, the middle element is counted twice
    if (N % 2 != 0) {
        sum -= arr[N / 2][N / 2];
    }

    return sum;

}

//{ Driver Code Starts.

// Driver code
int main() {
	
	int testcase;
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
        
        // Declaring pointer to pointer
        // to create 2D array
        int **arr;
        arr = new int*[N];
        
        // For every i, create a dynamic array
        // and take input
        for(int i = 0;i<N;i++){
            arr[i] = new int[N];
            for(int j = 0;j<N;j++){
                cin >> arr[i][j];
            }
        }
        
         cout << diagonalSum(arr, N) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
