#include <bits/stdc++.h>
using namespace std;

namespace hashutils {
  template<typename T>
  inline size_t hash(const T& v) {
    return std::hash<T>()(v);
  }
 
  /* hash based off of a pointer dereference */
  template<typename T>
  struct PointerDereferenceHash {
    inline size_t operator()(const T& pointer) const {
      return hash(*pointer);
    }
  };
 
  /* equality based off of pointer dereference */
  template<typename T>
  struct PointerDereferenceEqualTo {
    inline bool operator()(const T& lhs, const T& rhs) const {
      return *lhs == *rhs;
    }
  };
 
  template<typename K,typename V>
  using unordered_pointer_dereference_map = unordered_map<K,V,PointerDereferenceHash<K>,PointerDereferenceEqualTo<K>>;
}
namespace hashutils {
  class HashCombiner {
  private:
    size_t h;
  public:
    HashCombiner() : h(0) {}
    template <class T>
    inline HashCombiner& operator<<(const T& obj) {
      /* adapted from boost::hash_combine */
      h ^= hash(obj) + 0x9e3779b9 + (h << 6) + (h >> 2);
      return *this;
    }
    operator size_t() const { return h; }
  };
 
  /* hash any container */
  template<typename T>
  struct ContainerHash {
    size_t operator()(const T& v) const {
      HashCombiner h;
      for(const auto& e : v) {
        h << e;
      }
      return h;
    }
  };
}
namespace std {
  template<typename T>
  struct hash<vector<T> > : hashutils::ContainerHash<vector<T> > {};
}
int main()
{	
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	    cin >> arr[i];
	set<size_t> ans;
	hash<vector<int> > hmm;
	for(int i=0; i<n; i++)
	{   vector<int> v;
	    v.push_back(arr[i]);
	    for(int j=i+1; j<n; j++)
	    {   v.push_back(arr[j]);
	        ans.insert(hmm(v));
	    }
	}
	cout << ans.size();
}