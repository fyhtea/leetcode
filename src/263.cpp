/*************************************************************************
	> File Name: 263.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月29日 星期一 10时47分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    
    bool is_in_vec(int e, vector<int> vec){
        vector<int>::iterator it;  
        it=find(vec.begin(),vec.end(),e);  
        if (it!=vec.end()){  
            return true;  
        }  
        else{  
            return false;  
        } 
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        int f[n+1][n+1] = {0};
        map<pair<int,int>, vector<vector<int>>> fmap;
        bool flag=true;
        for(int i=1;i<=9 && i<=n;i++){
            f[1][i] = 1;
            vector<int> vec;
            vec.push_back(i);
            fmap[make_pair(1,i)].push_back(vec);
        }
        
        
       
        
        for(int i=3;i<=n;i++){
            for(int j=2;j<i-j+1;j++){
                
                for(int m=1;m<i && m<=9;m++){
                    
                    if(f[j-1][i-m]==1 ){
                        for(auto vec:fmap[make_pair(j-1,i-m)]){
                            
                            if(!is_in_vec(m, vec)){
                                f[j][i] = 1;
                                
                                vector<int> svec;
                                svec.push_back(m);
                                for(auto e:vec){
                                    svec.push_back(e);
                                }
                                sort(svec.begin(), svec.end());
                                
                                flag = true;
                                

                                for(auto vect:fmap[make_pair(j,i)]){
                                    if(svec == vect){
                                            flag = false;
                                    }
                                }
                                    
                                if(flag){
                                        
                                    fmap[make_pair(j,i)].push_back(svec);
                                }
                            }
                            
                        }
                    }
                }
            }
        }
        return fmap[make_pair(k,n)];
    }
};
