import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class ChangeContentPane extends JFrame{
	JPanel contentPane = new JPanel();
	ChangeContentPane(){
        setTitle("�巡�� ���� ���� ����"); // ���� ����
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // �ݱ� ��ư�� ������ �� ȭ�� �ݱ�
        
        setContentPane(contentPane);
        contentPane.addMouseMotionListener(new MyMouseMotionAdapter());
        contentPane.addMouseListener(new MyMouseAdapter());
        contentPane.setBackground(Color.GREEN);

        setSize(400,200);
        setVisible(true);
         
    }
	class MyMouseMotionAdapter extends MouseMotionAdapter{
		public void mouseDragged(MouseEvent e) {
			contentPane.setBackground(Color.YELLOW);
		}
	}
	class MyMouseAdapter extends MouseAdapter{
		public void mouseReleased(MouseEvent e) {
			contentPane.setBackground(Color.GREEN);
		}
		public void mouseClicked(MouseEvent e) {
			contentPane.setBackground(Color.black);
		}
		public void mousePressed(MouseEvent e) {
			contentPane.setBackground(Color.RED);
		}
	}
 
}

public class ch10_02 {
	public static void main(String args[]) {
		new ChangeContentPane();
	}
}
