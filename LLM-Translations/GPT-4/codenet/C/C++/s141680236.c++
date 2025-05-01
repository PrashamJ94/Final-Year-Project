#include<iostream>
#include<string>
#include<stack>
#include<cstdlib>

using namespace std;

int main()
{
  int chonda, yamagami;
  stack<int> kinbo;
  string null;

  while(cin >> null)
    {
      if(null[0] == '+')
	{
	  chonda = kinbo.top();
	  kinbo.pop();
	  yamagami = kinbo.top();
	  kinbo.pop();
	  kinbo.push(chonda + yamagami);
	}
      else if(null[0] == '-')
	{
	    yamagami = kinbo.top();
	    kinbo.pop();
	    chonda = kinbo.top();
	    kinbo.pop();
	    kinbo.push(chonda - yamagami);
	}
      else if(null[0] == '*')
	{
	   chonda = kinbo.top();
	   kinbo.pop();
	   yamagami = kinbo.top();
	   kinbo.pop();
	   kinbo.push(chonda * yamagami);
	}
      else
	kinbo.push(stoi(null));
    }

  cout << kinbo.top() << endl;

  return 0;
}

// 
