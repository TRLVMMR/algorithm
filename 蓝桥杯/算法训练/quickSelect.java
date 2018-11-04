import java.util.Scanner;


public class quickSelect{

	public static int[] quick_select(int[] a, int k, int left, int right){
		
		int sign = a[left];
		
		if(right < left)
			return a;
		
		int i = right, j = left;
		
		while(i > j){
			//标志位必须是 >=，否则如果a[i] == a[j] 且i != j就会进行无限交换。。。
			//使用>号，使i顶多等于j,此时后面有处理 
			while(a[i] >= sign && i > j)
				i--;
			while(a[j] <= sign && i > j)
				j++;
			
			if(i == j){
				a[left] = a[i];
				a[i] = sign;
				break;
			}
			else{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

		}
		
		int temp = right - i + 1;
		//右边比flag大的数有temp个
		if(k == temp){

		}
		else if(k < temp)
			quick_select(a, k, i + 1, right);
		else
			quick_select(a, k - temp, left, i - 1);
		
		return a;
	}

	public static void main(String arg[]){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] array = new int[n + 1];
		for(int i = 1; i <= n; i++){
			array[i] = scan.nextInt();	
		}
		int m = scan.nextInt();
		for(int i = 0; i < m; i++){
			int l = scan.nextInt();
			int r = scan.nextInt();
			int k = scan.nextInt();
			int a[] = array.clone();
			int[] result = quick_select(a, k, l, r);
			//System.out.print(result);
			System.out.println(result[r - k + 1]);

		}
			
	}
	
	
}
