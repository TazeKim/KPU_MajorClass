import java.util.Scanner;

class Circle{
	private double x, y;
	private int radius;
	public Circle(double x, double y, int radius) { // x, y, radius �ʱ�ȭ
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	public void show() {
		System.out.println("("+x+","+y+")"+radius);
	}
	public int getR() {
		return radius;
	}
}

public class ch04_06 {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		Circle c[] = new Circle[3]; // 3���� Circle �迭 ����
		for(int i=0; i<c.length; i++) {
			System.out.print("x, y, radius >>");
			double x = scanner.nextDouble(); // x �� �б�
		    double y = scanner.nextDouble(); // y �� �б�
		    int radius = scanner.nextInt(); // ������ �б�
		    c[i] = new Circle(x, y, radius); // Circle ��ü ����
		}
		
		int tmp = 0;
		for(int i=1; i<c.length; i++)
		{
			if(c[tmp].getR() < c[i].getR())
				tmp = i;		
		}
		
		System.out.print("���� ������ ū ���� ");
		c[tmp].show();
		scanner.close();
	}
}
