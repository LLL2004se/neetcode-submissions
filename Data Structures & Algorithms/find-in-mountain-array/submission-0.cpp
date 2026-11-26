
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it or speculate about its implementation.
 * class MountainArray {
 * public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray &mountainArr, int n) {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }

    int binarySearch(MountainArray &arr, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = arr.get(mid);

            if (value == target) {
                return mid;
            }
            else if (value < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int reverseBinarySearch(MountainArray &arr, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = arr.get(mid);

            if (value == target) {
                return mid;
            }
            else if (value < target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peak = findPeak(mountainArr, n);

        // Search increasing part first
        int leftAns = binarySearch(mountainArr, 0, peak, target);

        if (leftAns != -1) {
            return leftAns;
        }

        // Search decreasing part
        return reverseBinarySearch(mountainArr, peak + 1, n - 1, target);
    }
};
