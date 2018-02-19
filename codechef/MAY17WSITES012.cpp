#include<algorithm>
#include<string>
#include<iostream>
#define endl '\n'     //Obvious: to avoid flushes.
using namespace std;
int main()
{ long unsigned int n;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cin>>n;
  pair<string, char> sites [n];
  char x;
  string name;
  for(int i=0; i<n; i++)
  { cin>>x>>name;
    sites[i]={name, x};
  }
  sort(sites, sites+n);//This sorts all the website, making the most similar ones next to each other.
  int filter=0;
  string filters[n];
  for(int i=0; i<n; i++)
  { if(sites[i].second == '+')//Is any legit website blocked by a previous filter? (test case # 13 & 14 will pass due to this.)
    { for(int k=0; k<filter; k++)
      { if(filters[k][0]!=(sites[i].first)[0]) //There's no point in comparing the filter and the website if the first char don't match.
          continue;
        size_t found = (sites[i].first).find(filters[k]);
        if(found==0) //This means the filter is found at starting of ith string.
        { cout<<-1; return 0;
        }
      }
    }

    else
    {
      //Let's check if current website is already blocked or not.
      bool blockedornot=0;
      for(int k=0; k<filter; k++)
      { if(filters[k][0]!=(sites[i].first)[0]) //There's no point in comparing the filter and the website if the first char don't match.
          continue;
        size_t found = (sites[i].first).find(filters[k]);
        if(found==0) //This means the filter is found at starting of ith string.
        { blockedornot=1;
          break;
        }
      }
      if(blockedornot==1)//Do nothing if current website is already blocked.
        continue;

      int temp=filter;
      for(int j=i-1; j>-1; j--)
      { if(sites[j].second=='+')  //To find the first allowed website just before the current one.
        { int k=0;
          char newfilter[(sites[i].first).length()];
          while((k<(sites[i].first).length()) && (k<(sites[j].first).length()) && ((sites[i].first)[k]==(sites[j].first)[k])) //To add all the same characters to the filter.
          { newfilter[k]=(sites[i].first)[k];
            k++;
          }

          if(k==(sites[i].first).length())//This means ith website is subset of jth website. So designing a filter is impossible task...
          { cout<<-1;
            return 0;
          }
          newfilter[k]=(sites[i].first)[k]; //To add the first differing character.
          newfilter[k+1]='\0'; //To remove the garbage characters.
          filters[filter++]=newfilter;
          break;
        }
      }
      //This finds the lexographically previous allowed (+) website, before the current one.
      //Then, compares it char by char with the current website, makes a filter, and adds it into the list of filters.

      for(int j=i; j<n; j++)
      { if(sites[j].second=='+')
        { int k=0;
          char newfilter[(sites[i].first).length()];
          while(k<(sites[i].first).length() && (k<(sites[j].first).length()) && (sites[i].first)[k]==(sites[j].first)[k])
          { newfilter[k]=(sites[i].first)[k];
            k++;
          }
          if(k==(sites[i].first).length())
          { cout<<-1;
            return 0;
          }
          newfilter[k]=(sites[i].first)[k];
          newfilter[k+1]='\0';
          if(filter>0 && k>=filters[filter-1].length() && 0 == (sites[i].first).find(filters[filter-1]))//If this overlaps with the last filter.
          { filters[filter-1]=newfilter;
          }//e.g. last filter -> "codec" & current one is "codechef".
          else if(filter==0 || 0 != (sites[i].first).find(filters[filter-1]))
          { filters[filter++]=newfilter;
	        }//If this is the first ever filter to be stored or this is the first filter of ith (THIS) website.

          break;
        }
      }// This just finds the lexographically next allowed (+) website after the current blocked website.
      //Then, compares it char by char with the current website, makes a filter, which replaces the previous filter if be long enough.

      if(temp==filter && filter>0 && filters[filter-1][0]!=(sites[i].first)[0])
      { char newfilter=(sites[i].first) [0];
        filters[filter++]=newfilter;
	    }
      else if(temp==filter && filter==0)
      { char newfilter=(sites[i].first) [0];
        filters[filter++]=newfilter;
	    }
    }
  }
  cout<<filter<<endl;         //Print the number of filters.
  for(int i=0; i<filter; i++)
    cout<<filters[i]<<endl;   //And, the filters.
return 0;
}
