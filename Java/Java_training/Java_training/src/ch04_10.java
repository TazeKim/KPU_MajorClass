import java.util.Scanner;

class Dictionary {
	private static String [] kor = { "���", "�Ʊ�", "��", "�̷�", "���" };
	private static String [] eng = { "love", "baby", "money", "future", "hope" };
	public static String kor2Eng(String word) {
		for(int i=0; i<kor.length; i++) {
			if(word.equals(kor[i])) {
				return eng[i];
			}
		}
		return null;
	}
}

public class ch04_10 {
	Scanner sc = new Scanner(System.in);
	String word;
	
	public void Run() {
		while(true) {
			System.out.print("�ѱ� �ܾ�?");
			word = sc.next();
			if(word.equals("�׸�")) {
				break;
			}
			String result = Dictionary.kor2Eng(word);
			if(result==(null))
				System.out.println(word+"��(��) ���� ������ �����ϴ�.");
			else
				System.out.println(word+"��(��) "+result);
		}
	}
	public static void main(String[] args) {
		ch04_10 dicapp = new ch04_10();
		System.out.println("�ѿ� �ܾ� �˻� ���α׷��Դϴ�.");
		dicapp.Run();
	}
}
