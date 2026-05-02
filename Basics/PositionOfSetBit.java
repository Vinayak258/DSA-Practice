public class PositionOfSetBit {
    
    public static int findPosition(int num){

        if((num > 0 ) && (num & (num-1)) == 0){

            int n = num;
            int count = 0;

            while(n >= 1){
                n = n/2;
                count++;
            }

            return count;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(findPosition(8));
        System.out.println(findPosition(12)); 
    }
}