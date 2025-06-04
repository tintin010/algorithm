import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x = Integer.parseInt(br.readLine());
		int arr[][] = new int [x][2];
		for(int i=0; i<x; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			arr[i][0]= Integer.parseInt(st.nextToken());
			arr[i][1]= Integer.parseInt(st.nextToken());
		}
		for(int i=0; i<x; i++) {
			int rank=1;
			for(int j=0; j<x; j++) {
				if(j==i) continue;
				if(arr[i][0]<arr[j][0]) {
					if(arr[i][1]<arr[j][1])
						rank++;
				}
			}
			System.out.print(rank+" ");
		}
    }
}