import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class randomLetter extends JFrame{
	JLabel label; 
	randomLetter(){
		setTitle("Ŭ�� ������ �������α׷�"); // ���� ����
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // �ݱ� ��ư�� ������ �� ȭ�� �ݱ�
         
        label= new JLabel("c");
        label.setSize(100,50);
        label.setLocation(100,100);
        label.addMouseListener(new MyMouseAdapter());
        // Jabel ������Ʈ ���� �� MouseListener�� �ܴ�.
         
        add(label);
        setSize(500,500);
        setVisible(true);
        label.requestFocus();
	}
	class MyMouseAdapter extends MouseAdapter{
        int x,y;
        public void mousePressed(MouseEvent e) {
            x = (int)(Math.random()*400); // ������ ���� ����� ���� 400���� ����
            y = (int)(Math.random()*400); // ������ ���� ����� ���� 400���� ����
            label.setLocation(x,y);
        }
    }
}


public class ch10_06 {
	public static void main(String args[]) {
		new randomLetter();
	}
}
