import java.io.*;
import java.util.Scanner;

public class ch08_02 {

	public static void main(String[] args) {
		FileWriter fw = null;
		BufferedReader fr = null;
		File f = new File("c:\\temp\\phone.txt");
		try {
			fw = new FileWriter(f);
			fr = new BufferedReader(new FileReader(f));
			Scanner scanner = new Scanner(System.in);
			
			System.out.println("��ȭ��ȣ �Է� ���α׷��Դϴ�.");
			while(true) {
				System.out.print("�̸� ��ȭ��ȣ >> ");
				String line = scanner.nextLine(); // ������ �д´�.
				int c = fr.read();
				
				if(line.equals("�׸�"))
						break; // �Է� ����
				fw.write(line+"\n"); // �� �� ��� �����ϱ� ���� "\r\n"�� ���δ�.
			}
			fw.close();
			System.out.println(f.getPath()+"�� �����Ͽ����ϴ�.");
			while(true) {
				String line_con = fr.readLine();
				if(line_con == null)
					break;
				System.out.println(line_con+"\n");
			}
			scanner.close();

			fr.close();

		} 
		catch (IOException e) { // ������ ������ �� ���� ��� ����
			e.printStackTrace();
		}
	}
}