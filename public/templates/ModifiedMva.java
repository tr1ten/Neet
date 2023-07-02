import java.util.ArrayList;
import java.util.List;

public class Modified_Mva {

        public static List<Integer> findMajorityElements(int[] nums) {
            List<Integer> result = new ArrayList<>();
            int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;

            for (int num : nums) {
                if (num == candidate1) {
                    count1++;
                } else if (num == candidate2) {
                    count2++;
                } else if (count1 == 0) {
                    candidate1 = num;
                    count1 = 1;
                } else if (count2 == 0) {
                    candidate2 = num;
                    count2 = 1;
                } else {
                    count1--;
                    count2--;
                }
            }

            count1 = 0;
            count2 = 0;

            for (int num : nums) {
                if (num == candidate1) {
                    count1++;
                } else if (num == candidate2) {
                    count2++;
                }
            }

            int n = nums.length;
            if (count1 > n / 3) {
                result.add(candidate1);
            }
            if (count2 > n / 3) {
                result.add(candidate2);
            }
            System.out.println(result);
            return result;
        }

        public static void main(String [] args){
            int [] arr =  new int[]{1,4,5,2,2,1,1,1,3,2,3,2,4,1,2,2,1,1,1,2};

           findMajorityElements(arr);
        }
    }


