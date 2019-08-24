/*
	题目描述：
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
	假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如
	输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
	则重建二叉树并返回。
 */

#include <iostream>
#include <vector>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() != vin.size()) return NULL;
		int num_nodes = pre.size();
		TreeNode* root = reConstructBinaryTree(pre, 0, num_nodes - 1, vin, 0, num_nodes - 1);
		return root;
	}
	TreeNode* reConstructBinaryTree(const vector<int> &pre, int pre_start, int pre_end, const vector<int> &vin, int vin_start, int vin_end)
	{
		if (pre_start > pre_end || vin_start > vin_end) return NULL;
		TreeNode* root = new TreeNode(pre[pre_start]);

		for(int i= vin_start; i<=vin_end; i++)
		{
			//在中序序列中寻找先序序列中的头节点
			if(vin[i] == root->val)
			{
				root->left = reConstructBinaryTree(pre, pre_start + 1, pre_start + i - vin_start, vin, vin_start, i - 1);
				root->right = reConstructBinaryTree(pre, pre_start + i - vin_start + 1, pre_end, vin, i + 1, vin_end);
			}
		}
		return root;
	}
};

int main()
{
	Solution solve;

	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = solve.reConstructBinaryTree(pre, vin);
	cout << "end!";
}


