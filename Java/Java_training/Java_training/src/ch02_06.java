//369 ���α׷�
import java.util.Scanner;

public class ch02_06 {
	public static void main(String[] args) {
		
		System.out.print("1~99�� ���� �Է� : ");
		
		Scanner scanner = new Scanner(System.in);
		
		int i = scanner.nextInt();
		
		if(i /10 == 3 || i /10 == 6|| i /10 == 9)
		{
			if(i %10 == 3 || i %10 == 6|| i %10 == 9)
			{
				System.out.println("¦¦");
			}
			else
			{
				System.out.println("¦");
			}
		}
		else
		{
			if(i %10 == 3 || i %10 == 6|| i %10 == 9)
			{
				System.out.println("¦");
			}
			else
			{
				System.out.println("�ڼ� ��ħ");
			}
		}
	}
}
