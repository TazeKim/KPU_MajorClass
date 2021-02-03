import javax.swing.*;
import java.awt.*;
class LandomLayoutEx extends JFrame{
	public LandomLayoutEx() {
		setTitle("Random Labels");
	
		setVisible(true);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(null);//���Ƿ� �����ؼ� ��ġ�ؾ��ϱ� ������
		for(int i = 0; i < 20; i++) {
			JLabel label = new JLabel();
			int x = (int)(Math.random()*200)+50; // 50~250
            int y = (int)(Math.random()*200)+50; // 50~250
            label.setLocation(x,y); // label�� (x,y)�� ��ġ
            label.setBackground(Color.BLUE);
            label.setSize(10,10); // label ũ�⸦ 10*10���� ����
            c.add(label);//����Ʈ �ҿ� �� �߰�
            label.setOpaque(true); // label�� ������ ���̰� ��
		}
		setSize(300,300);
	}
}
public class ch09_05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new LandomLayoutEx();
	}

}
