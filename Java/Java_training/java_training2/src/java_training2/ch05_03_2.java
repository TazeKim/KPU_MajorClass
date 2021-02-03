package java_training2;

class Dollar2Won extends Converter {
	public Dollar2Won(double ratio) {
		this.ratio = ratio;
	}
	protected double convert(double src) {
		return src/ratio;
	}
	protected String getSrcString() {
		return "�޷�";
	}
	protected String getDestString() {
		return "��";
	}
}

public class ch05_03_2 {

	public static void main(String args[]) {
		Dollar2Won toWon= new Dollar2Won(0.85); // 1�޷��� 1200��
		toWon.run();
	}
}
