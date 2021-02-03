import java.util.Calendar;
import java.util.Scanner;

class Player {
	private String name;
	private int second;
	public Player(String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public void setSecond(int second) {
		this.second = second;
	}
	public int getSecond() {
		return second;
	}
}

class TimeGame {
	Scanner sc = new Scanner(System.in);
	private Player[] player;
	public void Set() {
		player = new Player[2];
		player[0] = new Player("Ȳ����");
		player[1] = new Player("���繮");
	}
	public void Run() {
		System.out.println("10�ʿ� ����� ����� �̱�� �����Դϴ�.");
		for(int i=0; i<player.length; i++) {
			System.out.println(player[i].getName() + "���� <Enter>Ű >>");
			String key = sc.nextLine();
			int startSecond = Calendar.getInstance().get(Calendar.SECOND);
			System.out.println("���� �� �ð� = " + startSecond);
			
			System.out.println("10�� ���� �� <Enter>Ű >>");
			key = sc.nextLine();
			int endSecond = Calendar.getInstance().get(Calendar.SECOND);
			System.out.println("���� �� �ð� = " + endSecond);
			
			if(endSecond < startSecond)
				player[i].setSecond(endSecond-startSecond+60);
			else
				player[i].setSecond(endSecond-startSecond);
		}
	}
	public void Result() {
		for(int i=0
				; i<player.length; i++) {
			System.out.print(player[i].getName() + "�� ��� " + player[i].getSecond() + ", ");
		}
		
		if(Math.abs(player[0].getSecond() - 10) < Math.abs(player[1].getSecond() - 10))
			System.out.println("���ڴ� " + player[0].getName());
		else
			System.out.println("���ڴ� " + player[1].getName());
	}
}

public class ch06_06 {
	public static void main(String[] args) {
		TimeGame tg = new TimeGame();
		tg.Set();
		tg.Run();
		tg.Result();
	}
}