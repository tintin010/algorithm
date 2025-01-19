import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

class Main {
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;
    static int[] op = new int[4];
    static int[] num;
    static int n;
    public static void main(String[] args) throws IOException {
//        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        num = new int[n];
        for(int i=0; i<n; i++) num[i] = sc.nextInt();//숫자입력
        for(int i=0; i<4; i++) op[i] = sc.nextInt();//연산자 입력
        calc(num[0], 1);
        System.out.println(max);
        System.out.println(min);
    }
    public static void calc(int cn, int ci) {   //
        if(ci == n){
            max = Math.max(max, cn);
            min = Math.min(min, cn);
//            System.out.println(max+"임시");
//            System.out.println(min+"임시");
            return;
        }
        for(int i=0; i<4; i++){
            if(op[i] > 0){
                op[i]--;
                switch (i){
                    case 0:{
//                        System.out.println(" + ");
                        calc(cn + num[ci], ci+1);
                        break;
                    }
                    case 1:{
//                        System.out.println(" - ");
                        calc(cn - num[ci], ci+1);
                        break;
                    }
                    case 2:{
//                        System.out.println(" * ");
                        calc(cn * num[ci], ci+1);
                        break;
                    }
                    case 3:{
//                        System.out.println(" / ");
                        calc(cn / num[ci], ci+1);
                        break;
                    }
                }
                op[i]++;
            }
        }
    }
}


