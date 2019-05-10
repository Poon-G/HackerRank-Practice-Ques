#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) {
int row=arr.size();
int col=arr[0].size();
int sum=0;
int diag1=0,diag2=0;
for(int i=0;i<row;i++)
{
    diag1 +=arr[i][i];
    diag2 +=arr[i][row-i-1];
} 
if(diag1 > diag2)
sum = diag1 - diag2;
else
sum = diag2 - diag1;

return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
