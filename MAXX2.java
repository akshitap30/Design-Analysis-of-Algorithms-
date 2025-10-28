public class MAXX2 {

    public static int maxSubarrayWithConstraint(int[] arr, int constraint) {

        int n = arr.length;

        if (n == 0 || constraint <= 0) return -1; // No feasible subarray

 

        int left = 0, sum = 0, best = -1;

 

        for (int right = 0; right < n; right++) {

            sum += arr[right];

 

            // shrink window until it's valid

            while (sum > constraint && left <= right) {

                sum -= arr[left];

                left++;

            }

 

            if (sum <= constraint) {

                best = Math.max(best, sum);

            }

        }

        return best;

    }

 

    public static void main(String[] args) {

        int[][] testCases = {

            {2, 1, 3, 4},    // case 1

            {2, 2, 2, 2},    // case 2

            {1, 5, 2, 3},    // case 3

            {6, 7, 8},       // case 4

            {1, 2, 3, 2, 1}, // case 5

            {1, 1, 1, 1, 1}, // case 6

            {4, 2, 3, 1},    // case 7

            {},              // case 8

            {1, 2, 3}        // case 9

        };

        int[] constraints = {5, 4, 5, 5, 5, 4, 5, 10, 0};

 

        for (int i = 0; i < testCases.length; i++) {

            int result = maxSubarrayWithConstraint(testCases[i], constraints[i]);

            if (result == -1) {

                System.out.println("No feasible subarray");

            } else {

                System.out.println("Best sum = " + result);

            }

        }

    }

}

 