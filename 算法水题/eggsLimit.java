import java.util.Scanner;

public class eggsLimit {
	public int eggsPrint(int M, int N){
		if(M <= 1 || N < 1)
			return 0;
		
		int[][] array = new int[M + 1][N + 1];
		//�����ȳ�ʼ������Ϊ���õ��߽�����ݣ�ͬʱ���ܰ�����ֵ��ʼ��������Ĭ��Ϊ0,Min�϶���0
		//�˳�ʼ����ֵ�պ��Ǵ˲�����ֵ�� ��Ը���Ϊ�߽�j = 1ʱȻ�����г�ʼֵΪINFҲ��
		for(int m = 1; m <= M; m++){
			for(int n = 1;  n <= N; n++){
				//��ÿ����������ʼ��Ϊ����
					array[m][n] = m;
			}
		}
		

			for(int m = 1; m <= M; m++){
				for(int n = 2;  n <= N; n++){
					//ö�ٴӵڼ��㶪
					for(int k = 1; k <= m; k++){
						//ÿ���ҵ�����a[i][j],������Ŀ�����,����a[i][j]���ҵ���С�ġ�������õ�ѡk��ʽ 
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
