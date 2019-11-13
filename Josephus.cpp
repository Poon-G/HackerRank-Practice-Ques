int josephus(int n, int k)
{
  vector<int>v;
  for(int i=1;i<=n;i++)
  v.push_back(i);
  
  if(v.size()==1)
  return v[0];
  
  int i=0;
  while(v.size()!=1){
      int s=v.size(), x=k-1;
      while(x!=0){
          i=(i+1)%s;
          x--;
      }
      v.erase(v.begin() + i);
  }
    return v[0];
}
