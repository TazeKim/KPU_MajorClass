import java.util.Scanner;

public class ch03_14 {
	public static void main(String[] args) {
		
		 String course [] = { "Java", "C++", "HTML5", "��ǻ�ͱ���", "�ȵ���̵�" };
		  int score [] = {95, 88, 76, 62, 55};
		  
		  Scanner scanner = new Scanner(System.in);
		  
		  while(true) {
		   System.out.print("���� �̸�>>");
		   String name = scanner.next();
		   if(name.equals("�׸�")) 
		    break;

		   int i;
		   for(i=0; i<course.length; i++) {
		    if(course[i].equals(name)) {
		     System.out.println(name + "�� ������ " +  score[i]);
		     break;
		    }
		   }
		   
		   if(i==score.length) // ������� �߸��� ���
		    System.out.println("���� �����Դϴ�.");
		  }
		  
		  scanner.close();
	}

}
