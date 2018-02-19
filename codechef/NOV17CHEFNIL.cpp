/*#include <iostream>
#include <vector>
using namespace std;

long long score(int m, int n, const vector<vector<vector<int> > > &A, int i, int j, int idir, int jdir, int print)
{
	long long temp=0;
	for(int t=0; t<m; t++)
	{	temp+= A[t][i][j];
		if(print)
			cout << i+1 << ' ' << j+1 <<'\n';
		if(jdir==1 && j<n-1)
			j++;
		else if(jdir==1 && j==n-1)
		{	if(i+idir >=0 && i+idir<n)
			{
				i+= idir;
				jdir= -1;
			}
			else
				break;
		}
		else if(jdir==-1 && j>0)
			j--;
		else if(jdir==-1 && j==0)
		{	if(i+idir >=0 && i+idir<n)
			{
				i+= idir;
				jdir= 1;
			}
			else
				break;
		}
		else
			break;
	}
	return temp;
}

long long spiral(int layer, int n, const vector<vector<vector<int> > > &A, int k, int l, int idir, int jdir, int print)
{
    int i, m=n;
 
    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
	int lay=0;
	long long ans=0;
    while (k < m && l < n && lay<layer)
    {
        // Print the first row from the remaining rows 
        for (i = l; i < n && lay<layer; ++i)
        {
			ans += A[lay][k][i];
            if(print)
				cout<< k+1 << ' ' << i+1 <<'\n';
			lay++;
        }
        k++;
 
        // Print the last column from the remaining columns 
        for (i = k; i < m && lay<layer; ++i)
        {	ans += A[lay][i][n-1];
            if(print)
				cout<< i+1 << ' ' << n <<'\n';
			lay++;
        }
        n--;
 
        // Print the last row from the remaining rows 
        if ( k < m)
        {
            for (i = n-1; i >= l && lay<layer; --i)
            {
				ans+= A[lay][m-1][i];
                if(print)
					cout << m << ' ' << i+1 << '\n';
				lay++;
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; (i >= k) && (lay<layer); --i)
            {
				ans+= A[lay][i][l];
				if(print)
					cout << i+1 <<' ' << l+1 <<'\n';
				lay++;
            }
            l++;    
        }        
    }
	return ans;
}
/*
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin>>n>>m;
	vector<vector<vector<int> > > A(m, vector<vector<int> >(n, vector<int>(n)));
	
	for(int i=0; i<m; i++)
	{	for(int j=0; j<n; j++)
		{	for(int k=0; k<n; k++)
			{	cin>>A[i][j][k];
			}
		}
	}
	
	int im=0, jm=0, idirm=1, jdirm=1;
	long long ans=0;
	for(int i=0; i<n; i++)
	{	for(int j=0; j<n; j++)
		{	int idir=1, jdir=1;
			long long temp= score(m, n, A, i, j, idir, jdir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm = idir;
				jdirm = jdir;
			}
		}
	}
	for(int i=n-1; i>=0; i--)
	{	for(int j=0; j<n; j++)
		{	int idir=-1, jdir=1;
			long long temp= score(m, n, A, i, j, idir, jdir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
			}
		}
	}
	for(int i=n-1; i>=0; i--)
	{	for(int j=n-1; j>=0; j--)
		{	int idir=-1, jdir=-1;
			long long temp= score(m, n, A, i, j, idir, jdir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
			}
		}
	}
	for(int i=0; i<n; i++)
	{	for(int j=n-1; j>=0; j--)
		{	int idir=1, jdir=-1;
			long long temp= score(m, n, A, i, j, idir, jdir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
			}
		}
	}
	bool s=0;
	for(int i=0; i<n; i++)
	{	for(int j=0; j<n; j++)
		{	int idir=1, jdir=1;
			long long temp= score(m, n, A, j, i, jdir, idir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
				s=1;
			}
		}
	}
	for(int i=0; i<n; i++)
	{	for(int j=n-1; j>=0; j--)
		{	int idir=1, jdir=-1;
			long long temp= score(m, n, A, j, i, jdir, idir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
				s=1;
			}
		}
	}
	for(int i=n-1; i>=0; i--)
	{	for(int j=0; j<n; j++)
		{	int idir=-1, jdir=1;
			long long temp= score(m, n, A, j, i, jdir, idir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
				s=1;
			}
		}
	}
	for(int i=n-1; i>=0; i--)
	{	for(int j=n-1; j>=0; j--)
		{	int idir=-1, jdir=-1;
			long long temp= score(m, n, A, j, i, jdir, idir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
				s=1;
			}
		}
	}
	bool piral=0;
	/*for(int i=0; i<n; i++)
	{	for(int j=0; j<n; j++)
		{	int idir=-1, jdir=-1;
			long long temp= spiral(m, n, A, i, j, idir, jdir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
				piral=1;
				s=0;
			}
		}
	}
	for(int i=0; i<n; i++)
	{	for(int j=0; j<n; j++)
		{	int idir=-1, jdir=-1;
			long long temp= spiral(m, n, A, j, i, jdir, idir, 0);
			if(temp > ans)
			{	ans = temp;
				im=i;
				jm=j;
				idirm= idir;
				jdirm= jdir;
				piral=1;
				s=1;
			}
		}
	}*/
	/*if(s && !piral)
		score(m, n, A, jm, im, jdirm, idirm, 1);
	//else if(s && piral)
		//spiral(m, n, A, jm, im, idirm, jdirm, 1);
	//else if(piral)
		//spiral(m, n, A, im, jm, idirm, jdirm, 1);
	else
		score(m, n, A, im, jm, idirm, jdirm, 1);
	
}*/