#include <bits/stdc++.h>

using namespace std;

string isValid(string s) {
string result = "YES";

map<char,int>m;
for(int i=0;i<s.length();i++)
{
m[s[i]]++;
}

int maxCount = INT_MIN;
for( auto r1=m.begin();r1!=m.end();r1++)
{
    if(maxCount < r1->second)
    maxCount = r1->second;
}

map<char, int>::iterator r = m.begin();
int maxC = 0, notMax = 0;
for (; r != m.end(); r++) {
  int c = r->second;
  if ((maxCount - c) == 0)
    maxC++;
  else
    notMax++;
}

  int x = maxCount;
  bool flag = false;
    r = m.begin();
  for (; r != m.end(); r++) {
    int c = r->second;
   if((maxC == 1) && (maxCount > 2) && ((maxCount -c) > 1))    //abccc, aabcd
   {
       result="NO";
       return result;
   }
   else if((maxC > 1) && (notMax > 1)) //aabbcd
   {
       result="NO";
       return result;

   }
}
return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
