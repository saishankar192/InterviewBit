int Solution::solve(vector<int> &A) {
    return *max_element(A.begin(), A.end()) + *min_element(A.begin(),A.end());
}
