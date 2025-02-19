import java.lang.Math;
public class distanceCalRecursive {

    //Recursive function to calculate the distance between two pints
    public static float distanceRecursive(int[] p1 , int[] p2 , int numDimensions){
        //Base case if numDimensions is equal to 1
      if(numDimensions  == 1){
          return (float) Math.pow(p2[numDimensions-1] - p1[numDimensions-1] , 2);
      }
      else{
          //Recursive case : sum squared differences recursively
          return (float) Math.pow(p2[numDimensions-1] - p1[numDimensions -1] , 2)
                  + distanceRecursive(p1,p2,numDimensions-1);
      }
    }


    public static void main(String[] args){
        //Define the points here
        int[] p1 = {3,4,5};
        int[] p2 = {6,7,8};

        int numDimensions = 3;

        // calling the function
        float sumSquared = distanceRecursive(p1,p2,numDimensions);
        System.out.println("Recursive Distance : " + Math.sqrt(sumSquared));
    }
}

