import java.util.*;

public class grader{
	static long _M, h, hl;
	static int count;
	private static Scanner scanner = new Scanner(System.in);
	public static long Init(){
		long x;
		x = scanner.nextInt();
		return x;
	}
	public static boolean is_broken(long k){
		count++;
		if(count > 60){
			System.out.println("Wrong Answer: too many queries");
			System.exit(0);
		}
		if(k > _M){
			System.out.println("Wrong Answer: invalid broken query");
			System.exit(0);
		}
		return k > h;
	}
	public static void main(String args[]){
		int i;
		_M = Init();
		h = Init();
		count = 0;
		hl = Egg.height_limit(_M);
		if(hl == h)
			System.out.println("Accepted: " + count);
		else
			System.out.println("Wrong Answer: incorrect height");
	}
}