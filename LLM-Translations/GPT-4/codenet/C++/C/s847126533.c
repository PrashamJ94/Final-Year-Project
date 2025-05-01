#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool check(int n, int wei, int* book, int book_size)
{
  int tmp=wei;
  n--;
  for(int i=0;i<book_size;i++)
    {
      if(tmp<book[i])
	{
	  if(n>0)
	    {
	      n--;
	      tmp=wei;
	      if(tmp<book[i])
		return false;
	    }
	  else
	    return false;
	}
      tmp-=book[i];
    }
  return true;
}

int main()
{
  int m,n;
  while(scanf("%d %d", &m, &n),m)
    {
      int* book = (int*) malloc(n * sizeof(int));
      for(int i=0;i<n;i++)
	{
	  int tmp;
	  scanf("%d", &tmp);
	  book[i] = tmp;
	}

      int l=0;
      int r=1500000;
      int ans;
      while(l<r)
	{
	  if(check(m,(l+r)/2,book,n))
	    {
	      ans=(l+r)/2;
	      if(r==(l+r)/2)
		break;
	      r=(l+r)/2;

	    }
	  else
	    {
	      if(l==(l+r)/2)
		break;
	      l=(l+r)/2;
	    }
	}
      printf("%d\n", ans);
      free(book);
    }
    return 0;
}
// 
