import java.util.Scanner;

abstract class Converter {
    abstract protected double convert(double src);
    abstract protected String srcString();
    abstract protected String destString();
    protected double ratio;

    public void run() {
        Scanner scanner = new Scanner(System.in);
        System.out.println(srcString() + "�� " + destString() + "�� �ٲߴϴ�.");
        System.out.print(srcString() + "�� �Է��ϼ���>> ");
        double val = scanner.nextDouble();
        double res = convert(val);
        System.out.println("��ȯ ���: " + res + destString() + "�Դϴ�");
        scanner.close();
    }
}

class Won2Dollar extends Converter {
    public Won2Dollar(double ratio) {
        this.ratio = ratio;
    }

    @Override
    protected double convert(double src) {
        return src / ratio;
    }

    @Override
    protected String srcString() {
        return "��";
    }

    @Override
    protected String destString() {
        return "�޷�";
    }

}
public class ch05_03 {
    public static void main(String args[]) {
        Won2Dollar toDollar = new Won2Dollar(1200);
        toDollar.run();
    }

}