import java.util.*;

class Scholarship{
	private Scanner scanner = new Scanner(System.in);
	private HashMap<String, Double> scoreMap = new HashMap<String, Double>();
	
	public void read() {
		System.out.println("�̷� ���б� ���� �ý����Դϴ�.");
		for(int i =0; i< 5; i++) {
			System.out.print("�̸��� ����>> ");
			String name = scanner.next();
			double score = scanner.nextDouble();
			scoreMap.put(name, score);
		}
	}
	public void select() {
		System.out.print("���л� ���� ���� ���� �Է�>> ");
		double cutline = scanner.nextDouble();
		
		System.out.println("���л� ���: ");
		Set<String> nameSet = scoreMap.keySet();
		Iterator<String> it = nameSet.iterator();
		while(it.hasNext()) {
			String name = it.next();
			Double value = scoreMap.get(name);
			if(value>cutline)
				System.out.println(name + " " + value + "���л� �հ�");
			
		}
	}
	
}

public class ch07_07 {

	public static void main(String[] args) {
		Scholarship ship = new Scholarship();
		ship.read();
		ship.select();
	}

}
