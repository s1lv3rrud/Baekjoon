import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(n --> 0) {
			int x = Integer.parseInt(st.nextToken());
			
			int sum = 0;
			if(x > 1) {
				sum = 1;
			}
			
			for(int i = 2; i * i <= x; i++) {
				if(x % i == 0) {
					sum += i;
					if(i * i != x) {
						sum += x / i;
					}
				}
			}
			sb.append(sum > x ? "abundant" : sum < x ? "deficient" : "perfect").append("\n");
		}
		System.out.print(sb);
	}
}