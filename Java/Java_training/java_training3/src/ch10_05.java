import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class bigLetter extends JFrame{
	JLabel label;
	bigLetter(){
		setTitle("+,- Ű�� ��Ʈ ũ�� ����"); // ���� ����
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // �ݱ� ��ư�� ������ �� ȭ�� �ݱ�
         
        label= new JLabel("Love Java");
        label.setSize(200,50);
        label.setFont(new Font("Arial",Font.PLAIN,10));
        // Arial ��Ʈ�� 10�ȼ� ũ��
         
        label.addKeyListener(new MyKeyAdapter());
        // Jabel ������Ʈ ���� �� KeyListener�� �ܴ�.
         
        add(label);
        setSize(400,200);
        setVisible(true);
        label.requestFocus();
	}
	class MyKeyAdapter extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
            Font f = label.getFont();
            int size = f.getSize();
            switch(e.getKeyCode()) {
            case 45: // -Ű ������ ���
                if(size>5) { // 5���� Ŭ����
                    label.setFont(new Font("Arial", Font.PLAIN,size-5));
                }
                break;
            case 61: // +��=Ű ��� ���
                label.setFont(new Font("Arial", Font.PLAIN,size+5));
                break;
        }
		}    
	}
}

public class ch10_05 {
	public static void main(String args[]) {
		new bigLetter();
	}
}
