/*
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		double x1,x2,y1,y2;
		double r1,r2,r3;
		double count;
		
		count = scan.nextInt();
		
		for(int i=0; i<count; i++) {
			x1 = scan.nextDouble();
			y1 = scan.nextDouble();
			r1 = scan.nextDouble();
			x2 = scan.nextDouble();
			y2 = scan.nextDouble();
			r2 = scan.nextDouble();
			
			r3 = Math.sqrt( Math.pow((x1-x2),2) + Math.pow((y1-y2), 2)) ;

			if(r3==0 && r1==r2) {
				System.out.println("-1");
			}else if(r3 < r1 + r2 && Math.abs(r2-r1)<r3) {			//������ �ΰ� �� �� ����
				System.out.println("2");
			}else if(r3 == r2+r1 || Math.abs(r2-r1)==r3 ){ 		//������ �Ѱ� �� �� ����
				System.out.println("1");
			}else if(r3>r1+r2 || Math.abs(r2-r1) > r3 || (r3==0 && r2!=r1)) {	//������ ���� �� ���� 		1. �ο��� ������ ���� �� 2. �ѿ��� �ٸ� �ѿ� �ȿ� ���� �� 3. ���ɿ�
				System.out.println("0");		
			}
		}
	}
}
*/