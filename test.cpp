#include <iostream>
#include "generator.h"

#include"No.143.h"



int main()
{
	vector<int> a({ 1,0,-1,0,-2,2 });
	auto l1 = LLGenerate({ 1,2,3,4 });
	auto l2 = LLGenerate({ 1,3,4 });
	auto l3 = LLGenerate({ 1,2 });
	vector<ListNode*> m = { l1, l2, l3 };
	Solution s;
	s.reorderList(l1);
}