	class TV{ 		// public�� �� ���Ͽ� �ѹ� �����ϰ� �ۺ� Ŭ���� �ȿ� �� �ۺ� Ŭ���� ��� ����
		private String TVa;
		private int date;
		private int inch;
		
		public TV(String TV, int date, int inch){ // ������ 
			this.TVa = TV;
			this.date = date;
			this.inch = inch;
			
		}
		public void show(){			// void �� ��°� ���� ()�� �ƹ��͵� ���� -> �Է°� ����
			System.out.println(this.TVa + "���� ����" + this.date + "����" + this.inch + "��ġ TV");
		}
		
	}
public class ch04_01 {
	public static void main(String[] args) {
		TV myTV = new TV("LG", 2017, 32);
		myTV.show();
	}

}
