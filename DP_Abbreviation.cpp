#include <bits/stdc++.h>

using namespace std;
bool isLower(char c) {
  if (c >= 'a' && c <= 'z')
    return true;

  return false;
}

char toLower(char c){
    return (char)(c-32);
}
// Complete the abbreviation function below.
string abbreviation(string a, string b) {
int m = a.size();
int n = b.size();
bool lcs[m+1][n+1];

for(int i=0;i<=m;i++)
for(int j=0;j<=n;j++)
    lcs[i][j]=false;

lcs[0][0]=true;

for(int i = 1; i <= m; i++){
    if(isLower(a[i-1])) lcs[i][0] = true;
        else break;
}

for(int i = 1; i <=m; i++)
            for(int j = 1; j <=n; j++){
            if(isupper(a[i-1])){
                  if(a[i-1] == b[j-1] && lcs[i-1][j-1] )
                      lcs[i][j] = true;
                  else lcs[i][j] = false;
              }
            else{
                if(toLower(a[i-1]) == b[j-1] && lcs[i-1][j-1]) lcs[i][j] = 1;
                else lcs[i][j] = lcs[i-1][j];
            }                 
           } 
           
/* 
for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++){       
         if(a[i-1] == b[j-1]){  //upper
          // lcs[i][j] = true;
          if(lcs[i-1][j-1])
          lcs[i][j] = true;
          else lcs[i][j] =false;
           //  lcs[i][j] = lcs[i-1][j-1];
            }
        else if ((isLower(a[i-1])) && (toLower(a[i-1])==b[j-1])) {
             // lcs[i][j] = true;
             if (lcs[i - 1][j - 1])
               lcs[i][j] = true;
             else
               lcs[i][j] = lcs[i - 1][j];
             //lcs[i][j] = lcs[i - 1][j - 1];
        }
        else if((!isLower(a[i-1])) && (a[i-1]!=b[i-1])){
            lcs[i][j] = false;
            //if (lcs[i - 1][j - 1])
            //  lcs[i][j] = true;
           // else
            //  lcs[i][j] = false;
            }
            else{
              lcs[i][j] = lcs[i - 1][j];
            }
    }*/
    
/*
for (int i = 0; i < m+1; i++) {
  for (int j = 0; j < n+1; j++)
    cout << lcs[i][j] << endl;
}*/
  if (lcs[m][n])
    return "YES";

  return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
