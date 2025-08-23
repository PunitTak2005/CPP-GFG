// Function to check if books can be allocated to
// all k students without exceeding 'pageLimit'
bool check(int arr[], int n, int k, int pageLimit) {

    // Starting from the first student
    int cnt = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++) {

        // If adding the current book exceeds the page
        // limit, assign the book to the next student
        if (pageSum + arr[i] > pageLimit) {
            cnt++;
            pageSum = arr[i];
        } else {
            pageSum += arr[i];
        }
    }

    // If books can assigned to less than k students then
    // it can be assigned to exactly k students as well
    return (cnt <= k);
}

int findPages(int arr[], int n, int k) {

    // If number of students are more than total books
    // then allocation is not possible
    if (k > n)
        return -1;

    // Maximum element of the array is minimum page limit
    int lo = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > lo)
            lo = arr[i];

    // Summation of all element is maximum page limit
    int hi = 0;
    for (int i = 0; i < n; i++)
        hi += arr[i];

    int res = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (check(arr, n, k, mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return res;
}
