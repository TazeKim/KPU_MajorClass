package java_training2; //�ٸ� ��Ű���� TV Ŭ������ �־ �����ϱ� ���� // ����Ʈ ��Ű���� �̰� ������ �̰� �׳� ��Ű�� �̸� ���󰡵��

class TV {
	private int size;
	public TV(int size) { this.size = size; }
	protected int getSize() { return size; }
}

class ColorTV extends TV {
	private int color;
	public ColorTV(int size, int color) {
		super(size); // ���� Ŭ������ ������ ������ ����. this.size = size;
		this.color = color;
	}
	protected int getColor() { return color; }
	public void printProperty() {
		System.out.println(getSize()+"��ġ "+getColor()+"�÷�");
	}
}

public class ch05_01 {
	public static void main(String args[]) {
		ColorTV myTV = new ColorTV(32, 1024);
		myTV.printProperty();
	}
}
