#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	cout.precision(5);
	cout.setf(ios::fixed);
	int i,j,k,n;
	cout<<"\nEnter the number of equation\n";
	cin>>n;
	double a[n][n+1],x[n],x0[n],r[n];
	double ep;
	//augmented matrix entry
	cout<<"\nEnter the augmented matrix row wise\n";
	for(i=0;i<n;i++)
		for(j=0;j<=n;j++)
			cin>>a[i][j];
//	pivotisation
	for(i=0;i<n;i++)
	{
		for(k=i+1;k<n;k++)
		{
			if(a[i][i]<a[k][i])
				{
					for(j=0;j<=n;j++)
					{
					double temp=a[i][j];
					a[i][j]=a[k][j];
					a[k][j]=temp;
					}
				}
		}
	}
	//convergency test
	bool converge=true;

	for(int i=0;i<n;i++)
	{
			double sum=0.0;
	
		for(int j=0;j<n;j++)
		{
		
			if(i==j)
				continue;
		sum+=abs(a[i][j]);
		}
		if(abs(a[i][i])<=sum)
		{
		
			converge=false;
			break;
		}
	}
	if(converge==true)
	{
	 cout<<"\nEnter the initial guesses:\n";
		for(j=0;j<n;j++)
			{
			cin>>x0[j];
			
			}
		cout<<"\nEnter the desired accracy:\n";
		cin>>ep;	
 		do
			{
				for(i=0;i<n;i++)
				{
				
				x[i]=x0[i];
				x0[i]=a[i][n]/a[i][i];
				for(j=0;j<n;j++)
					if(j!=i)
						x0[i]=x0[i]-(a[i][j]/a[i][i])*x[j];
				}
		}while(abs(x[0]-x0[0])>ep||abs(x[1]-x0[1])>ep||abs(x[2]-x0[2])>ep);
				
	cout<<"\nThe three roots are\nx= "<<x0[0]<<"\ny= "<<x0[1]<<"\nz= "<<x0[2];
	}
	else
		cout<<"\nThis system can't be solved in jacobi iteration method\n";
		
		
}