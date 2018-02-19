//This finds the %tage error in simulating N-body motion under mutual gravitational field, by Euler's method.
#include<iostream>
#include<cmath>
#include<vector>
#include<stdexcept>
using namespace std;

const double G    = 6.67408e-11;  //Universal gravitational constant.
const double EPS  = 1e-6;         //This is minimum allowed distance between any two bodies.
class body                        //Declaring a class (rather struct) of a body.
{
public:
  double mass;
  vector<double> pos, vel, acc;
  body()
  {
    pos.reserve(3); //To store x y and z coordinates.
    vel.reserve(3);
    acc.reserve(3);
  }
  ~body()
  { pos.clear();
    vel.clear();
    acc.clear();
  }
};

class Nbodies: public body
{
private:
  int N=0, filled=0;
  vector<body> list;  //This makes a vector of N bodies.
public:
  Nbodies(int n=0)  //Constructor that takes only the number of bodies as the argument.
  {
    list.reserve(n);
    N=n;
  }
  ~Nbodies(void)  //Useless destructor.
  { list.clear();
  }
  void append(double m, double x, double y, double z, double vx, double vy, double vz)  //append function like std::vector.
  { if(filled==N)
      throw invalid_argument("N-bodies already full. Please increase the size.");
    else
    {
      list[filled].mass=m;
      list[filled].pos={x,y,z};
      list[filled].vel={vx,vy,vz};
      list[filled].acc={0,0,0};
      filled++;
    }
  }
  void resize(int n)  //Resize function like std::vector.
  { if(N<=n)
    {
      list.resize(n);
      N=n;
    }
    else
    {
      cout<<"Warning: Some bodies maybe removed. Do you want to continue (Y/N):";
      char c;
      cin>>c;
      while(c!='Y' || c!='N') cin>>c;
      if(c=='Y')
      {
        N=n;
        list.resize(n);
      }
    }
  }
  int size(void)  //Returns size of the current N-body system.
  {
    int sz=N;
    return sz;
  }
  double dist(int i, int j) //Returns distance between ith and jth body. (0-based indexing.)
  { if(i>=filled || j>=filled)
      throw invalid_argument("body index out of bound. Please check the pairs.");
    else
    {
      double r=0;
      for(int k=0; k<3; k++) r+=(list[i].pos[k] - list[j].pos[k])*(list[i].pos[k]- list[j].pos[k]);
      r=sqrt(r);
      if(r<EPS)
        throw invalid_argument("too less distance");
      else
        return r;
    }
  }
  double PotentialEnergy(int i, int j)  //Calculates PE of interaction between ith and jth body.
  { double r=dist(i, j), E= G*list[i].mass*list[j].mass/r;
    return E;
  }
  double Force(int i, int j)            //Calculates force of interaction between ith and jth body.
  { double r=dist(i, j), f=G*list[i].mass*list[j].mass/(r*r);
    return f;
  }
  void computePosition(int i, double dtime) //Computes position of ith body if the time interval is dt.
  { if(i>=filled)
      throw invalid_argument("body index out of bound.");
    else
    { for(int k=0; k<3; k++)  list[i].acc[k]=0;
      for(int j=0; j<filled; j++)
      {
        if(j!=i)
        {
          double r=dist(i, j), force=Force(i, j);
          double diff[3]={list[i].pos[0]-list[j].pos[0], list[i].pos[1]-list[j].pos[1], list[i].pos[2]-list[j].pos[2]};
          for(int k=0; k<3; k++)
            list[i].acc[k]+=force*diff[k]/(r*list[i].mass);
        }
      }
      for(int k=0; k<3; k++)
      {
        list[i].vel[k]+=list[i].acc[k]*dtime; //dv = adt
        list[i].pos[k]+=list[i].vel[k]*dtime; //dx = vdt
      }
    }
  }
  double KineticEnergy(int i)                 //Re
  { double vsquare=0;
    for(int k=0; k<3; k++)  vsquare+=list[i].vel[k]*list[i].vel[k];
    double KE=0.5*list[i].mass*vsquare;
    return KE;
  }
};

int main()
{
  Nbodies b(2);                   //Declares a system of 2 bodies.
  b.append(100000, 0,0,0, 0,0,0); //First body has mass 1 kg and is located at (0,0,0) with v0 = (0,0,0).
  b.append(100000, 1,1,1, 0,0,0); //Second body has mass 1 kg and is located at (1,1,1) with v0=(0,0,0).

  double initial_energy=0, n=2;   //Calculates inital PE.
  for(int i=0; i<n; i++)
  { for(int j=i+1; j<n; j++)
    { double dE=b.PotentialEnergy(i, j);
      initial_energy+=dE;
    }
  }

  double T=100000, dt=0.1;
  for(double time_elapsed=0; time_elapsed<T; time_elapsed+=dt)  //Simluates their motion at intervals of dt.
  { for(int i=0; i<n; i++)
      b.computePosition(i, dt);
  }

  double final_energy=0;        //Calculates final PE+KE.
  for(int i=0; i<n; i++)
  { for(int j=i+1; j<n; j++)
    { double dE = b.PotentialEnergy(i, j);
      final_energy += dE;
    }
    final_energy += b.KineticEnergy(i);
  }
  cout<<"initial energy\tfinal energy\tPercentage error"<<endl;
  double error=(final_energy-initial_energy)*100 / initial_energy;
  cout<<initial_energy<<'\t'<<final_energy<<'\t'<<error;
return 0;
}
