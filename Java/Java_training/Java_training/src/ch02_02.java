import java.util.Scanner;

public class ch02_02 {
	
	public static void main(String args[]) {
		System.out.print("�� �ڸ� ������ �Է� : ");
		Scanner scanner = new Scanner(System.in);
		
		int num = scanner.nextInt();
		
		if(num /10 == num % 10)
			System.out.println("�����ϴ�.");
		else
			System.out.println("�ٸ��ϴ�.");
			
		scanner.close();
	}

}
