import java.util.Scanner;

public class eggsLimit {
	public int eggsPrint(int M, int N){
		if(M <= 1 || N < 1)
			return 0;
		
		int[][] array = new int[M + 1][N + 1];
		//必须先初始化，因为会用到边界的数据，同时，能把其他值初始化，数组默认为0,Min肯定是0
		//此初始化的值刚好是此层的最大值， 你愿意分为边界j = 1时然后所有初始值为INF也行
		for(int m = 1; m <= M; m++){
			for(int n = 1;  n <= N; n++){
				//把每层最大次数初始化为层数
					array[m][n] = m;
			}
		}
		

			for(int m = 1; m <= M; m++){
				for(int n = 2;  n <= N; n++){
					//枚举从第几层丢
					for(int k = 1; k <= m; k++){
						//每层找到最大的a[i][j],代表最坏的可能性,所有a[i][j]中找到最小的。代表最好的选k方式 
						array[m][n] = Math.min(array[m][n], 1 + Math.max(array[k - 1][n - 1], array[m - k][n]));
					}
			}
		}
		return array[M][N];
	}

	public static void main(String arg[]){
		eggsLimit e = new eggsLimit();
		Scanner scan = new Scanner(System.in);
		int M = scan.nextInt();
		int N = scan.nextInt();
		int result = e.eggsPrint(M, N);
		System.out.print(result);
	}

}
