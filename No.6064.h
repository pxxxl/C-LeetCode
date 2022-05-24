#pragma once
#include"1.h"

//³¬Ê±
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        vector<int> floor({0});
        floor.resize(top + 1, 0);
        floor[bottom] = 1;
        int max = -1;

        for (auto& v : special) {
            floor[v] = -1;
        }

        for (int i = bottom + 1; i <= top; i++) {
            if (floor[i] == -1) {
                continue;
            }
            else if (floor[i - 1] == -1) {
                floor[i] = 1;
                if (floor[i] > max) {
                    max = floor[i];
                }
            }
            else {
                floor[i] = floor[i - 1] + 1;
                if (floor[i] > max) {
                    max = floor[i];
                }
            }
        }

        if (max == -1) {
            return 0;
        }

        return max;
    }
};

//³¢ÊÔ¶þ
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
		quickSort(special, special.size(),true);
		int past = special[0];
		int max = 0;
		for (int i = 1; i < special.size(); i++) {
			if (special[i] - past - 1 > max) {
				max = special[i] - past - 1;
			}
			past = special[i];
		}
		if (special[0] - bottom > max) {
			max = special[0] - bottom;
		}
		if (top - special[special.size() - 1] > max) {
			max = top - special[special.size() - 1];
		}
		return max;
    }
	void quickSort(vector<int>& arr, int length, bool flag) {
		quickSortDetail(arr, 0, length, flag);
		return;
	}

	void quickSortDetail(vector<int>& arr, int start, int end, bool flag) {
		if (start + 1 >= end) {
			return;
		}
		int pivot = arr[start];
		int left = start;
		int right = end - 1;
		bool blank_in_left = true;
		while (right > left) {
			if (blank_in_left) {
				if ((arr[right] > pivot) == flag) {
					right--;
				}
				else {
					arr[left] = arr[right];
					left++;
					blank_in_left = false;
				}
			}
			else {
				if ((arr[left] < pivot) == flag) {
					left++;
				}
				else {
					arr[right] = arr[left];
					right--;
					blank_in_left = true;
				}
			}
		}
		arr[right] = pivot;
		quickSortDetail(arr, start, right, flag);
		quickSortDetail(arr, right + 1, end, flag);
	}
};

