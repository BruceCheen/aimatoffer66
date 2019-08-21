#include <iostream> 
#include <vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();
        if (rows==0 || cols==0) 
		{
			cout<<"array.sise()==0 or array[0].size()==0"<<endl;
			return false;
		}
		if (array[0][0] > target || array[rows-1][cols-1] < target)
			return false;
		int r=0; int c=cols-1;
		
		while(c>=0 && r<=rows-1)
		{
			if(array[r][c] == target) return true;
			if(array[r][c] < target) r++;
			if(array[r][c] > target) c--;
			
		}
		return false;
    }
};

int main()
{
	vector<vector<int> > array;
	vector<int> vec1;
	for (int i=1; i<6; i++)
	{
		vec1.push_back(i);
	}
	//#######################
	vector<int> vec2;
	for (int i=2; i<7; i++)
	{
		vec2.push_back(i);
	}
	//#######################
	vector<int> vec3;
	for (int i=3; i<8; i++)
	{
		vec3.push_back(i);
	}
	//#######################
	vector<int> vec4;
	for (int i=4; i<9; i++)
	{
		vec4.push_back(i);
	}	
	//#######################
	vector<int> vec5;
	for (int i=5; i<10; i++)
	{
		vec5.push_back(i);
	}	
	array.push_back(vec1);
	array.push_back(vec2);
	array.push_back(vec3);
	array.push_back(vec4);
	array.push_back(vec5);
	Solution slove;
	
	if(slove.Find(8, array))
	{
		cout<<"Finded!"<<endl;
	}
	return 0;
}