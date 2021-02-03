import java.util.Scanner;

class Person {
	private String name;
	
	public Person(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public String turn() { // ���� ���ƿ��� EnterŰ �Է¹ޱ�
		Scanner sc = new Scanner(System.in);
		System.out.print("["+name+"]:");
		return sc.nextLine();
	}
	
	public boolean RandomNum() { // �������� 3�� ���� �� ��ġ�ϴ��� Ȯ��
		int num[] = new int[3];
		
		for(int i=0; i<3; i++) {
			num[i] = (int)(Math.random()*3+1);
			System.out.print(num[i]+"\t"); // ���� �ѹ� ���
		}
		
		boolean result = true;
		for(int i=0; i<3; i++) {
			if(num[0] != num[i]) {
				result = false; // ����ġ
				break;
			}
		}
		return result;
	}
}

class GamblingGame {
	Person person[];
	Scanner sc = new Scanner(System.in);
	
	public GamblingGame() {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("���� ���ӿ� ������ ���� ����>>");
		int num = sc.nextInt();
		
		person = new Person[num]; // �ο���ŭ Person ����
		
		for(int i=0; i<person.length; i++) {
			System.out.print((i+1) + "��° ���� �̸�>>");
			person[i] = new Person(sc.next());
		}
	}
	
	public void Run() {
		while(true) {
			for(int i=0; i<person.length; i++) {
				String s = person[i].turn();
				if(s.equals("")) {
					System.out.println("<Enter>");
				}
				else {
					System.out.println("<Enter>Ű�� �Է� �����մϴ�.");
					return;
				}
				
				// RandomNum()���� ���� ���ڰ� ���� ���� �� �� ��
				if(person[i].RandomNum()) {
					System.out.println(person[i].getName() + "���� �̰���ϴ�!");
					return;
				}
				else
					System.out.println("�ƽ�����!");
			}
		}
	}
}

public class ch06_10 {
	public static void main(String[] args) {
		GamblingGame game = new GamblingGame();
		game.Run();
	}
}

