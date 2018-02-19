#include<iostream>
using namespace std;
class movie
{	private: string name; int year; float rating;
	public:
	movie(string n, int y, float r)
	{	name=n; 
		if(y>=1800 && y<=2017)
			year=y;
		else
			cout<<"Enter year properly. Error."; 
		rating =r;
	}
	string getName()
	{	return name;
	}
	int getYear()
	{	return year;
	}
	float getRating()
	{	return rating;
	}
};
int main(void)
{	cout<<"Enter names, years and ratings resp of your 3 favorite movies"<<endl;
	string n; int y; float r;
	cin>>n>>y>>r;
	movie m0(n,y,r);
	cin>>n>>y>>r;
	movie m1(n,y,r);
	cin>>n>>y>>r;
	movie m2(n,y,r);
	cout<<endl;
	cout<<m0.getName()<<' '<<m0.getYear()<<' '<<m0.getRating()<<endl;
	cout<<m1.getName()<<' '<<m1.getYear()<<' '<<m1.getRating()<<endl;
	cout<<m2.getName()<<' '<<m2.getYear()<<' '<<m2.getRating()<<endl;
	//cout<<m0.name;
return 0;
}
