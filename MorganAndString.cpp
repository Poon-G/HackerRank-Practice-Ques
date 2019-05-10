#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

// Complete the morganAndString function below.
string morganAndString(string a, string b) {
string result="";
//a+='z';
//b+='z';
long m=a.size();
long n=b.size();
long i=0,j=0;
cout<<m<<" "<<n<<endl;
while((i<m) && (j<n))
{
    if(a[i] < b[j])
    {
        result +=a[i];
        i++;
    }
    else if(a[i] > b[j])
    {
        result +=b[j];
        j++;
    }
    else
    {
        int x=i,y=j;
        while(a[x]==b[y])
        {
            x++;
            y++;
        }
        if((x<m) && (y<n) && (a[x] < b[y]))
        {
          result += a[i++];
          while ((i < m) && (a[i] == a[i - 1]))
            result += a[i++];

            x =i;
        }
        else if ((x < m) && (y < n) && (a[x] > b[y])) {
          result += b[j++];
          while ((j < n) && (b[j] == b[j - 1]))
            result += b[j++];

            y=j;
        }
        else if(x<m)
        {
            result += a[i++];
        }
        else
        {
        result += b[j++];
        }
    }
}

while(i<m)
    {
        result+=a[i];
        i++;
    }

while (j < n) {
    result += b[j];
    j++;
  }
return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
