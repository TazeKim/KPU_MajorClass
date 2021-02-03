import java.io.*;

public class ch08_03 {

	public static void main(String[] args) {
		BufferedReader fr = null;
		File f = new File("c:\\temp\\phone.txt");
		try {
			fr = new BufferedReader(new FileReader(f));
			System.out.println(f.getPath() + "�� ����մϴ�.");
			while(true) {
				String line = fr.readLine();
				if(line == null) // end of file
					break;
				line = line.toUpperCase();
				System.out.print(line+"\n");
			}
			fr.close();
		} 
		catch (IOException e) { // ������ ������ �� ���� ��� ����
			e.printStackTrace();
		}
	}

}