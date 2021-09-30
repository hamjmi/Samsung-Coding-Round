/* test case;
input:
8
-2 2
2 2
4 4
6 4
6 8
4 -3
6 -4
-1 -5

output:
-----------------------------
total points = 5
-----------------------------
-2 2
6 8
6 4
6 -4
-1 -5

*/
#include<iostream>
using namespace std;
struct point
{
	int x,y;
};
int n;
point collinear[20];
point original[20];
int coll=-1;
int ori=-1;
int cross(point a,point b,point c)
{
	int x1=a.x-b.x;
	int x2=a.x-c.x;
	int y1=a.y-b.y;
	int y2=a.y-c.y;
	return ((y2*x1)-(y1*x2));
}
int distance(point a,point b,point c)
{
	int x1=a.x-b.x;
	int x2=a.x-c.x;
	int y1=a.y-b.y;
	int y2=a.y-c.y;
	int dis1=(y1*y1)+(x1*x1);
	int dis2=(y2*y2)+(x2*x2);
	return (dis1-dis2);
}
int safe(int val)
{
	for(int i=0;i<=ori;i++)
	{
		if((original[i].x==collinear[val].x) && (original[i].y==collinear[val].y))
		{
			return 0;
		}
	}
	return 1;
}
void convexHull(point p[])
{
	point start=p[0];
	for(int i=1;i<n;i++)
	{
		if(start.x>p[i].x)
			start=p[i];
	}
	ori++;
	original[ori]=start;
	point current=start;
	while(true)
	{
		point target=p[0];
		for(int i=1;i<n;i++)
		{
			int val=cross(current,target,p[i]);
			if(val>0)
			{
				target=p[i];
				coll=-1;
			}
			else if(val==0)
			{
				int dis=distance(current,target,p[i]);
				if(dis<0)
				{
					coll++;
					collinear[coll]=target;
					target=p[i];
				}
				else
				{
					coll++;
					collinear[coll]=p[i];
				}
			}
		}
		for(int i=0;i<=coll;i++)
		{
			if(safe(i))
			{
				ori++;
				original[ori]=collinear[i];
			}
		}
		coll=-1;
		if((target.x==start.x)&&(target.y==start.y))
			break;
		ori++;
		original[ori]=target;
		current=target;	
	}
}
int main()
{
	cin>>n;
	point p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	convexHull(p);
	cout<<"\n-----------------------------\n";
	cout<<"total points = "<<(ori+1)<<endl;
	cout<<"-----------------------------\n";
	for(int i=0;i<=ori;i++)
		cout<<original[i].x<<" "<<original[i].y<<endl;
	cout<<endl;
}
