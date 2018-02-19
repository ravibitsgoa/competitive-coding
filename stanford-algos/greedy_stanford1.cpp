#include<utility>
#include<iostream>
#include<algorithm>
using namespace std;
/*
Your task in this problem is to run the greedy algorithm that schedules jobs in
decreasing order of the difference (weight - length). If two jobs have equal difference
(weight - length), you should schedule the job with higher weight first.
You should report the sum of weighted completion times of the resulting schedule
*/
bool compareJobs(const pair<int, int>& j1, const pair<int, int>& j2)
{ int x=j1.first - j1.second;
  int y=j2.first - j2.second;
  if(x!=y)
    return x > y;
  else
    return j1.first > j2.first;
}
int main()
{ int jobs;
  cin>>jobs;
  pair<int, int> job[jobs];
  for(int i=0; i<jobs; i++)
  { cin>>job[i].first;
    cin>>job[i].second;
  }
  sort(job, job+jobs, compareJobs);
  long long weighted_Completion_Time=0, time_elapsed=0;
  for(int i=0; i<jobs; i++)
  { time_elapsed+=job[i].second;
    weighted_Completion_Time+=job[i].first*time_elapsed;
  }
  cout<<weighted_Completion_Time;
return 0;
}
