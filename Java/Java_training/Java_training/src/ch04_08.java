import java.util.Scanner;

class Phone {
	private String name;
	private String tel;
	
	public Phone(String name, String tel) {
		this.name = name;
		this.tel = tel;
	}
	
	public String getName() {
		return name;
	}
	
	public String getTel() {
		return tel;
	}
}

class phoneBook {
	Scanner sc = new Scanner(System.in);
	int num; // �ο���
	Phone phone[];
	String name;
	String tel;
	
	public void getNum() {
		System.out.print("�ο���>>");
		num = sc.nextInt();	
		phone = new Phone[num];
	}
	
	public void getInfo() {
		for(int i=0; i<num; i++) {
			System.out.print("�̸��� ��ȭ��ȣ(�̸��� ��ȣ�� �� ĭ���� �Է�)>>");
			name = sc.next();
			tel = sc.next();
			phone[i] = new Phone(name, tel);
		}
		System.out.println("����Ǿ����ϴ�...");
	}
	
	public void Search() {
		boolean state = false;
		while(true) {
			System.out.print("�˻��� �̸�>>");
			name = sc.next();
		
			if(name.equals("�׸�")) {
			break;
			}
		
			for(int i=0; i<num; i++) {
				if(name.equals(phone[i].getName())) {
						System.out.println(name+"�� ��ȣ�� "+phone[i].getTel()+" �Դϴ�.");
						state = true;
				}
			}
			
			if(state == false)
				System.out.println(name+" �� �����ϴ�.");
		}
	}
	

}
public class ch04_08{
	public static void main(String args[]) {
		phoneBook phonebook = new phoneBook();
		phonebook.getNum();
		phonebook.getInfo();
		phonebook.Search();
	}
}


