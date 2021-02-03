package java_training2;

abstract class PairMap {
	protected String keyArray []; // key ���� �����ϴ� �迭
	protected String valueArray []; // value ���� �����ϴ� �迭
	abstract String get(String key); // key ���� ���� value ����. ������ null ����
	abstract void put(String key, String value); // key�� value�� ������ ����. ������ key�� ������, ���� value�� ����
	abstract String delete(String key); // key ���� ���� ������(value�� �Բ�) ����. ������ value �� ����
	abstract int length(); // ���� ����� ������ ���� ����
}

class Dictionary extends PairMap {
	private int num;
	private int cnt = 0;
	public Dictionary(int num) {
		this.num = num;  //�迭�� �� ũ��� ������ ���ϰ�
		keyArray = new String[num];// �� �迭 ũ�⸸ŭ �迭 ����
		valueArray = new String[num]; // �� �迭 ũ�⸸ŭ �迭 ����
	}
	@Override
	public String get(String key) {
		for(int i=0; i<cnt; i++) {
			if(key.equals(keyArray[i])) {
				return valueArray[i];
			}
		}
		return null;
	}
	@Override
	public void put(String key, String value) {
		if(cnt==num) {
			System.out.println("�迭�� �� á���ϴ�.");
			return;
		} // ���̻� ������ ������ ���� ��
		
		for(int i=0; i<cnt; i++) {
			if(key.equals(keyArray[i])) {
				valueArray[i] = value; 
				return;
			}
		} // �̹� �����ϴ� key ���� ��
		
		keyArray[cnt] = key;
		valueArray[cnt] = value;
		cnt++;
	}
	@Override
	public String delete(String key) {
		for(int i=0; i<cnt; i++) {
			if(key.equals(keyArray[i])) {
				valueArray[i] = "null";
				return "null";
			}
		}
		return "�ش� �̸��� �������� �ʽ��ϴ�.";
	}
	@Override
	public int length() {
		return cnt;
	}
}

public class ch05_10 {
	public static void main(String[] arsg) {
		Dictionary dic = new Dictionary(10);
		dic.put("Ȳ����", "�ڹ�");
		dic.put("���繮", "���̼�");
		dic.put("���繮", "C++"); // ���繮�� ���� C++�� ����
		System.out.println("���繮�� ���� " + dic.get("���繮")); // ���繮 ������ ���
		System.out.println("Ȳ������ ���� " + dic.get("Ȳ����")); // Ȳ���� ������ ���
		dic.delete("Ȳ����"); // Ȳ���� ������ ����
		System.out.println("Ȳ������ ���� " + dic.get("Ȳ����")); // ������ ������ ����
	}
}


