import java.io.*;
import java.util.Scanner;

public class ch08_04 {
	public static void main(String[] args){
		System.out.println("c:\\windows\\system.ini ������ �о� ����մϴ�.");
		try {
			Scanner Scanner = new Scanner(new FileReader("c:\\windows\\system.ini")); // ���Ϸκ��� �б� ���� ����
			int lineNumber = 1;
			while(Scanner.hasNext()) { // ���Ͽ� ���� ���� �ִ� ���� 
				String line = Scanner.nextLine();
				System.out.printf("%4d", lineNumber++); // ���ȣ ���
				System.out.println(": "+line); // �ҽ� ���� ���
			}
			Scanner.close();
		} catch (IOException e) {
			System.out.println("����� ������ �߻��߽��ϴ�.");
		}
	}
}