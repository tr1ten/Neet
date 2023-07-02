public class Mva {
    
    // moore's voting algorithm for finding the elements that occur more than
    // n/2 times in an array n is the size of the array
     public static int findMajorityElement(int[] nums) {
         int count = 0, candidate = -1;

         // Finding majority candidate
         for (int index = 0; index < nums.length; index++) {
             if (count == 0) {
                 candidate = nums[index];
                 count = 1;
             } else {
                 if (nums[index] == candidate)
                     count++;
                 else
                     count--;
             }
         }

         // Checking if majority candidate occurs more than n/2 times
         count = 0;
         for (int index = 0; index < nums.length; index++) {
             if (nums[index] == candidate)
                 count++;
         }
         if (count > (nums.length / 2))
             return candidate;
         return -1;
     }

     public static void main(String[] args) {
         int[] arr = {1, 1, 1, 1, 2, 3, 4};
         int majority = findMajorityElement(arr);
         System.out.println("The majority element is: " + majority);
     }
 }


