import java.util.Scanner;

public class ch02_01 {
	
	public static void main(String[] args) {
		System.out.print("��ȭ�� �Է��ϼ���(���� ��)>>");
		Scanner scanner = new Scanner(System.in);
		int won = scanner.nextInt();// nextInt -> ������ �Է�
		
		double dollar = won*0.00085; // 
		
		System.out.println(won + "���� $ " + dollar + "�Դϴ�.");
		
		scanner.close();
	}

}
