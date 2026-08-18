import java.util.*;

public
class Main
{

    static int largestInteger(int[] nums, int k)
    {
        int ans = -1;

        // Try every possible value
        for (int x = 0; x <= 50; x++)
        {

            int count = 0;

            // Check every subarray of size k
            for (int i = 0; i <= nums.length - k; i++)
            {

                boolean found = false;

                // Check whether x exists in this subarray
                for (int j = i; j < i + k; j++)
                {
                    if (nums[j] == x)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    count++;
                }
            }

            // x appears in exactly one subarray
            if (count == 1)
            {
                ans = x;
            }
        }

        return ans;
    }

public
    static void main(String[] args)
    {

        // Example 1
        int[] nums1 = {3, 9, 2, 1, 7};
        int k1 = 3;

        System.out.println("Output: " + largestInteger(nums1, k1));

        // Example 2
        int[] nums2 = {3, 9, 7, 2, 1, 7};
        int k2 = 4;

        System.out.println("Output: " + largestInteger(nums2, k2));

        // Example 3
        int[] nums3 = {0, 0};
        int k3 = 1;

        System.out.println("Output: " + largestInteger(nums3, k3));
    }
}