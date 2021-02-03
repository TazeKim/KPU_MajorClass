import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

 
//JLabel ������Ʈ�� Mouse �̺�Ʈ�� ���� �� �ִ�. JLabel ������Ʈ�� ���콺�� �ø���
//"Love Java"��, ������ "�����"�� ��µǵ��� ���� �������α׷��� �ۼ��϶�.
class MouseUpDownEx extends JFrame{
 
	MouseUpDownEx(){
        setTitle("���콺 �ø��� ������ ����"); // ���� ����
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // �ݱ� ��ư�� ������ �� ȭ�� �ݱ�
         
        JLabel label = new JLabel("Love Java");
         
        // Jabel ������Ʈ ���� �� MouseListener�� �ܴ�.
        label.addMouseListener(new MyMouseAdapter());
         
        label.setSize(200,50);
        add(label);
        setSize(400,200);
        setVisible(true);
         
    }
 
}
public class ch10_01{
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        new MouseUpDownEx();
    }
}
// MouseAdapter�� ��� �޴� MyMouseAdapter Ŭ����
class MyMouseAdapter extends MouseAdapter{
    public void mouseEntered(MouseEvent e) {
        // ���콺�� label ������Ʈ ���� �ö���� ��
        JLabel l = (JLabel)e.getSource();
        l.setText("�����");
    }
    public void mouseExited(MouseEvent e) {
        // ������Ʈ ���� �ö�� ���콺�� �����ͤ�Ʈ�� ����� ��
        JLabel l = (JLabel)e.getSource();
        l.setText("Love Java");
    }
}