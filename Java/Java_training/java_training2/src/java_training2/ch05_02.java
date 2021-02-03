package java_training2;

class IPTV extends ColorTV {
	private String IP;
	public IPTV(String IP, int size, int color) {
		super(size, color);
		this.IP = IP;
	}
	protected String getIP() {
		return IP;
	}
	public void  printProperty() {
		System.out.print("���� IPTV�� "+getIP()+" �ּ��� ");
		super.printProperty();
	}
}



public class ch05_02 {
	public static void main(String args[]) {
		IPTV iptv = new IPTV("192.1.1.2", 32, 2048); // "192.1.1.2" �ּҿ� 32��ġ, 2048 �÷�
		iptv.printProperty();
	}
}