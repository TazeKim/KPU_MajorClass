package java_training2;
import java.util.Scanner;

interface Stack {
	int length(); // ���� ���ÿ� ����� ���� ����
	int compacity(); //������ ��ü ���� ������ ���� ����
	String pop(); // ������ ��(top)�� �Ǽ� ����
	boolean push(String val); // ������ ��(top)�� ����� ���� ����
}

class StringStack implements Stack {
	private String arr[]; // ���ڿ� ������ �迭 ����
	private int top; // 
	public StringStack(int num) {  //���� ����ִ� �Լ�
		arr = new String[num];     //  �迭 ����
		top = 0; //ž �ʱ�ȭ ���� �����
	}
	@Override
	public int length() {
		return top;
	}
	@Override
	public int compacity() {
		return arr.length;
	}
	@Override
	public String pop() {  //�� �˰���
		if(top==0) // 0�̸� ����ִ�
			return "�������";
		else {
			String str = arr[top-1]; // �ϳ� ���´�
			top--; //ž �ϳ� ������.
			return str; //���� �ܾ� ����
		}
	}
	@Override
	public boolean push(String val) { //Ǫ�� �˰���
		if(top == arr.length) //������ ���̶� ž�� �������� �׸���
			return false;
		else {
			arr[top] = val;
			top++;
			return true;
		}
	}
}

public class ch05_09 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringStack s;
		
		System.out.print("�� ���� ���� ������ ũ�� �Է� >> ");
		s = new StringStack(sc.nextInt());
		
		while(true) {
			System.out.print("���ڿ� �Է� >> ");
			String str = sc.next();
			
			if(str.equals("�׸�")) {
				break;
			}
			
			boolean result = s.push(str);
			if(result==false)
				System.out.println("������ �� ���� Ǫ�� �Ұ�!");
		}
		
		System.out.print("���ÿ� ����� ��� ���ڿ� �� : ");
		for(int i=0; i<s.length(); i++) {
			System.out.print(s.pop()+" ");
		}
	}
}




