package java_training2;

class Point3D extends Point {
	private int z;
	public Point3D(int x, int y, int z) {
		super(x, y);
		this.z = z;
	}
	public int getZ() {
		return z;
	}
	public void moveUp() {
		z++;
	}
	public void moveDown() {
		z--;
	}
	public String toString() {
		return ("("+getX()+","+getY()+","+getZ()+")�� ��");
	}
	protected void move(int x, int y, int z) { 
		move(x, y);
		this.z = z; }
	
}

public class ch05_07 {
	public static void main(String args[]) {
		Point3D p = new Point3D(1, 2, 3); // 1, 2, 3�� ���� x, y, z���� ��.
		System.out.println(p.toString() + "�Դϴ�.");
		
		p.moveUp(); // z ������ ���� �̵�
		System.out.println(p.toString() + "�Դϴ�.");
		
		p.moveDown(); // z ������ �Ʒ��� �̵�
		p.move(10, 10); // x, y ������ �̵�
		System.out.println(p.toString() + "�Դϴ�.");
		
		p.move(100, 200, 300); // x, y, z ������ �̵�
		System.out.println(p.toString() + "�Դϴ�.");
	}
}
