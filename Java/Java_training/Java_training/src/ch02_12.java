import java.util.Scanner;

public class ch02_12 {

 public static void main(String[] args) {
  Scanner scanner = new Scanner(System.in);
  System.out.print("����>>");
  int op1 = scanner.nextInt();
  String op = scanner.next();  
  int op2 = scanner.nextInt();
  
  int res = 0;
  if(op.equals("+")) 
   res = op1 + op2;
  else if(op.equals("-")) 
   res = op1 - op2;
  else if(op.equals("*")) 
   res = op1 * op2;
  else if(op.equals("/")) {
   if(op2 == 0) { 
    System.out.print("0���� ���� �� �����ϴ�.");
    scanner.close();
    return;
   }
   else
    res = op1 / op2;
  }
  else {
   System.out.print("��Ģ������ �ƴմϴ�.");
   scanner.close();
   return;
  }
  System.out.print(op1 + op + op2 + "�� ��� ����� " + res);
  scanner.close();
 }

}