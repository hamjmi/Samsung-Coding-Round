#include<iostream>
using namespace std;
int main()
{
	int a[] = {1,2,3,4,5,5,6};
	int n = sizeof(a)/sizeof(a[0]);
	//cout<<n<<endl;
	int k = 3;
	int i, last, stones1, stones2,stones, count;
    stones1 = 0;
    stones2 = 0;
    for (i = k; i < n && a[k - 1] == a[i]; i++);
    last = a[i - 1];
    for (i = 0; i < k; i++)
    {
    	stones1 += a[n - 1 - i];
    }
    for (i = 0, count = 0; count < k; i++)
    {
        if ((a[n - i - 1] > last) )
        {
            stones2 += last;
        }
        else
        {
        	stones2 += a[n- i - 1];
            count++;
        }
    }
	stones = min(stones1, stones2);
	cout<<stones1<<" "<<stones2<<endl;
	cout<<stones;
}
